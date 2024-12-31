#pragma once

#include "hw/attitude/data/data.hpp"
#include <sys/some_define/define.hpp>
#include "hw/attitude/method/method.hpp"
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;
using namespace ATTITUDE_DATA;


static constexpr u8 unlock[5] = {0xFF, 0xAA, 0x69, 0x88, 0xB5};
static constexpr u8 save[5] = {0xFF, 0xAA, 0x00, 0x00, 0x00};


template <typename nine_axis_data>
class GY901S :public GET_ATTITUD::METHOD<nine_axis_data>
{
    private:
        u32 _baudrate;
        u8 _rx_pin;
        u8 _tx_pin;
        HardwareSerial &_serial;
        ANGLE _angle_true;
        nine_axis_data _nine_axis_data_true;
        vector<f32> pitch_history;
        vector<f32> roll_history;
        vector<f32> yaw_history;

    private:
        f32 Get_Aver(const vector<f32>& data);
        void Data_Clear();
    public:
        // 波特率 + 接收，发送引脚 + 硬件串口
        GY901S(u32 baudrate, u8 rx_pin, u8 tx_pin, HardwareSerial &serial);
        
        // 初始化
        void Init() override;

        // 获取数据-未使用
        void GetData(nine_axis_data& data) override; 

        // 数据处理
        void Data_process(u8* data);

        // 获取数据 -------- 数据处理 + 数据获取 -》 角度数据
        void GetData(ANGLE& angle, nine_axis_data& data);

        // 校准
        void Angle_Calibrate();

        // Z轴归0
        void Z_To_Zero();

        // X，Y轴归0
        void XY_To_Zero();



};












