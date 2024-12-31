#pragma once

#include <sys/some_define/define.hpp>


class SERIAL_WORK
{
    private:
        u32 _baudrate;
        u8 _rx_pin;
        u8 _tx_pin;
        u32 _mode;
        HardwareSerial &_serial;

    public:
        // 波特率 + 引脚 + 硬件串口
        SERIAL_WORK(u32 baudrate, u8 rx_pin, u8 tx_pin, HardwareSerial &serial, u32 mode = SERIAL_8N1);
        
        // 初始化
        void Init();

        // 接收数据-String
        void GetData(String& _rx_string);

        // 接收数据-Byte
        void GetBinaryData(byte* buffer, size_t length);
        
        // 发送数据-Byte
        void SendHexData(const byte* data, size_t length);

        // 发送数据-String
        void SendData(const String tx_string);
};

