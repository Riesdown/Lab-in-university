#pragma once

#include <Arduino.h>
#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <utility> 
#include <sys/some_define/define.hpp>



class SERIAL_DEBUG
{
    private:
        HardwareSerial &_serial; 
        String _rx_string;
        u32 _baudrate;
        u8 _rx_pin;
        u8 _tx_pin;

    protected:
        virtual void ProcessData(const String &data);
    public:
        // 波特率 + 读，写引脚 + 串口对象
        explicit SERIAL_DEBUG(u32 baudrate, u8 rx_pin, u8 tx_pin, HardwareSerial &serial);
        
        // 波特率 + 串口对象
        explicit SERIAL_DEBUG(u32 baudrate, HardwareSerial &serial);

        // 打印接收到的数据
        void ListData();

        // 获取数据（String类型）
        String GetData() const { return _rx_string; }

        // 获取数据（std::string类型）
        void GetData_stdstring(std::string &data) { data = _rx_string.c_str(); }
        
        // 初始化
        void Init();
        
};


