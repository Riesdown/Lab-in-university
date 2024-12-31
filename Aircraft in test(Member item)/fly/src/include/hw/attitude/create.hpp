#pragma once

#include <Arduino.h>
#include <sys/some_define/define.hpp>
#include <memory>
#include "hw/attitude/method/method.hpp"
#include "hw/attitude/gy910s/gy910s.hpp"

using namespace std;
using namespace ATTITUDE_DATA;





namespace GET_ATTITUD 
{
    template <typename nine_axis_data>
    class FACTORY 
    {
        public:
            using methodptr = unique_ptr<METHOD<nine_axis_data>>;  

            // 创建GY901S陀螺仪
            static methodptr Create_GY901S(u32 baudrate, u8 rx_pin, u8 tx_pin, HardwareSerial &serial)
            {
                return methodptr(new GY901S<nine_axis_data>(baudrate, rx_pin, tx_pin, serial));
            }
    };
}