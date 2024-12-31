#pragma once


#define RX_PIN 11 
#define TX_PIN 10

SERIAL_WORK serial1_work(115200, RX_PIN, TX_PIN, Serial1);


struct PTs
{
    PT pt_leftx;
    PT pt_rightx;
    PT pt_righty;

    PTs() : pt_leftx(15), pt_rightx(16), pt_righty(17) {}
}pts;


static constexpr u8 KEY_FRONT_PIN = 6;
static constexpr u8 KEY_BACK_PIN = 7;
static constexpr u8 KEY_UNLOCK_PIN = 3;


KEY key_front(KEY_FRONT_PIN, "down");
KEY key_back(KEY_BACK_PIN, "down");
KEY key_unlock(KEY_UNLOCK_PIN, "down");

// 66 66 66 66 12 34 56 00 9A 00 B7 00 00 00 00 85 
/******变量******************************************************** */
struct AD_DATA 
{
    u16 left_y;
    u16 right_x;
    u16 right_y;
    i16 right_x_i16;
    i16 right_y_i16;

    void Reset() 
    {
        left_y = 0;
        right_x = 0;
        right_y = 0;
    }
};
AD_DATA adData_filt;


void All_Init()
{
    serial1_work.Init();

    pts.pt_leftx.Init();
    pts.pt_rightx.Init();
    pts.pt_righty.Init();

    OLED_Init();
    key_front.Init();
    key_back.Init();


}

