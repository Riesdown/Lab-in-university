#pragma once

#include <Arduino.h>
#include <SYS/Some_Define/SomeDefine.hpp>
#include <vector>
#include <numeric>


constexpr size_t SEND_DATA_SIZE = 16; 
static byte senddata[SEND_DATA_SIZE] = 
{
    0x66, 0x66, 0x66, 0x66,
    0x12, 0x34, 0x56, 
    0, 0, 
    0, 
    0,      
    0, 0, 
    0, 0,
    0
}; 

struct SENDDATA 
{
    u16 power;
    u8 roll;
    u8 pitch;
    u16 yaw;
    u16 mode;

    void Reset() 
    {
        power = 0;
        roll = 0;
        pitch = 0;
        yaw = 0;
        mode = 0;
    }
};



struct MODE_DATA
{
    u8 unlock : 1;
};
MODE_DATA mode_data;



static u8 Get_Checksum(const std::vector<u8>& data)
{
    u8 checksum = 0;
    for(const auto& byte : data)    checksum += byte;
    return checksum & 0xFF;
}


static void UpdateSendData(const AD_DATA& adData, SENDDATA& send_later)
{
    send_later.power = adData.left_y;
    send_later.roll = adData.right_x_i16;
    send_later.pitch = adData.right_y_i16;


    senddata[7] = send_later.power >> 8;
    senddata[8] = send_later.power & 0xFF;

    senddata[9] = send_later.roll;

    senddata[10] = send_later.pitch;

    send_later.yaw = 0;
    senddata[11] = send_later.yaw >> 8;
    senddata[12] = send_later.yaw & 0xFF;

    send_later.mode = mode_data.unlock;
    senddata[13] = send_later.mode >> 8;
    senddata[14] = send_later.mode & 0xFF;




}


static void SendData_Check()
{
    std::vector<u8> data(senddata, senddata + SEND_DATA_SIZE - 1);
    u8 checksum = Get_Checksum(data);
    senddata[15] = checksum;

    serial1_work.SendHexData(senddata, sizeof(senddata));
    // nr24.Send_Data(senddata);

}


static constexpr f64 l_y_p = 1.5;
static constexpr f64 l_y_r = 8.251999881450788;
static constexpr f64 l_y_q = 0.003125;

static constexpr f64 r_x_p = 2.3979622645090806;
static constexpr f64 r_x_r = 0.5121322980639116;
static constexpr f64 r_x_q = 6.103515625e-06;

static constexpr f64 r_y_p = 5.548646114780239;
static constexpr f64 r_y_r = 0.1;
static constexpr f64 r_y_q = 0.0001953125;

f32 lam = 0.01;

UKF l_y(lam, l_y_p, l_y_r, l_y_q);
UKF r_x(lam, r_x_p, r_x_r, r_x_q);
UKF r_y(lam, r_y_p, r_y_r, r_y_q);



AD_DATA adData;

template <typename T>
struct SLIDINGWINDOW
{
    private:
        std::vector<T> window;
        size_t max_size;

    public:
        explicit SLIDINGWINDOW(size_t size) : max_size(size) {}

        T Filter(T new_value) 
        {
            if (window.size() >= max_size)  window.erase(window.begin()); 
            window.push_back(new_value); 
            T sum = std::accumulate(window.begin(), window.end(), static_cast<T>(0));
            return sum / window.size();
        }
};

constexpr size_t WINDOW_SIZE = 10;

SLIDINGWINDOW<f64> l_y_window(WINDOW_SIZE);
SLIDINGWINDOW<f64> r_x_window(WINDOW_SIZE);
SLIDINGWINDOW<f64> r_y_window(WINDOW_SIZE);


struct DEAL_REMOTE_DATA 
{
    private:
        bool Run_Time(u16 run_time);




    public:
        struct RANGE
        {
            u16 _l_y_min, _l_y_max;

            u16 _r_x_mid;

            u16 _r_y_mid;

            f32 zone_l_y_min, zone_l_y_max;

            f32 zone_r_x_mid_add, zone_r_x_mid_sub;

            f32 zone_r_y_mid_add, zone_r_y_mid_sub;

            u16 l_y_range, r_x_range, r_y_range;
        };
        RANGE & _range;
        AD_DATA Deal(AD_DATA& ad_data);
        DEAL_REMOTE_DATA(RANGE& range);
};
DEAL_REMOTE_DATA::DEAL_REMOTE_DATA(RANGE& range): 
    _range(range)
{


}


bool DEAL_REMOTE_DATA::Run_Time(u16 run_time)
{
    static u32 old_time = 0;
    if (millis() - old_time > run_time) 
    {
        old_time = millis();
        return true;
    }
    return false; 
}



AD_DATA  DEAL_REMOTE_DATA::Deal(AD_DATA& ad_data)
{


    ad_data.left_y = MAP(ad_data.left_y, _range._l_y_min * (1 + _range.zone_l_y_min), _range._l_y_max * (1 - _range.zone_l_y_max), 0, _range.l_y_range);


    if (ad_data.right_x > _range._r_x_mid * (1 + _range.zone_r_x_mid_add)) if (Run_Time(100)) ad_data.right_x_i16++;
    if (ad_data.right_x < _range._r_x_mid * (1 - _range.zone_r_x_mid_sub)) if (Run_Time(100)) ad_data.right_x_i16--;
    

    if (ad_data.right_y > _range._r_y_mid * (1 + _range.zone_r_y_mid_add)) if (Run_Time(100)) ad_data.right_y_i16++;
    if (ad_data.right_y < _range._r_y_mid * (1 - _range.zone_r_y_mid_sub)) if (Run_Time(100)) ad_data.right_y_i16--;

    ad_data.right_x_i16 = constrain(ad_data.right_x_i16, -_range.r_x_range, _range.r_x_range);
    ad_data.right_y_i16 = constrain(ad_data.right_y_i16, -_range.r_y_range, _range.r_y_range);

    if (ad_data.right_x < _range._r_x_mid * (1 + _range.zone_r_x_mid_add) && ad_data.right_x > _range._r_x_mid * (1 - _range.zone_r_x_mid_sub)) ad_data.right_x_i16 = 0;
    if (ad_data.right_y < _range._r_y_mid * (1 + _range.zone_r_y_mid_add) && ad_data.right_y > _range._r_y_mid * (1 - _range.zone_r_y_mid_sub)) ad_data.right_y_i16 = 0;


    return ad_data;

}






DEAL_REMOTE_DATA::RANGE range = 
{
    ._l_y_min = 600, ._l_y_max = 3600,

    .zone_l_y_min = 0.2, .zone_l_y_max = 0.05,

    .zone_r_x_mid_add = 0.05, .zone_r_x_mid_sub = 0.3,

    .zone_r_y_mid_add = 0.3, .zone_r_y_mid_sub = 0.3,

    .l_y_range = 4000, .r_x_range = 10, .r_y_range = 10
};


DEAL_REMOTE_DATA deal(range);


void Get_Right_Range(DEAL_REMOTE_DATA::RANGE& range)
{
    f32 _r_x_mid, _r_y_mid;
    u16 _r_x_mid_now, _r_y_mid_now;

    for (u8 i = 0; i < 100; i++)
    {
        pts.pt_rightx.Get_AD(_r_x_mid_now);
        pts.pt_righty.Get_AD(_r_y_mid_now);
        // _r_x_mid += _r_x_mid_now;
        _r_y_mid += _r_y_mid_now;
    }
    range._r_x_mid = _r_x_mid / 100;
    range._r_y_mid = _r_y_mid / 100;

}

void Send_Data_RTOS(void *param) 
{
    SENDDATA sendData;
    Get_Right_Range(range);

    mode_data.unlock = 1; // 锁




    while (true) 
    {
        pts.pt_leftx.Get_AD(adData.left_y);
        // pts.pt_rightx.Get_AD(adData.right_x);
        pts.pt_righty.Get_AD(adData.right_y);

        // adData.left_y = l_y.Filter(static_cast<f64>(adData.left_y));
        // adData.right_x = r_x.Filter(static_cast<f64>(adData.right_x));
        // adData.right_y = r_y.Filter(static_cast<f64>(adData.right_y));

        // adData.left_y = l_y_window.Filter(adData.left_y);
        // adData.right_x = r_x_window.Filter(adData.right_x);
        // adData.right_y = r_y_window.Filter(adData.right_y);

        // adData.left_y = 4096 - adData.left_y;


        adData_filt = deal.Deal(adData);

        UpdateSendData(adData_filt, sendData);

        SendData_Check();

        delay(10);
    }
}
