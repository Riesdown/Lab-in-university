#pragma once

#include <Arduino.h>
#include <SYS/Some_Define/SomeDefine.hpp>


//SERIAL_XYZ  x:数据位数（5, 6, 7, 或 8） y:校验方式（N: 无校验, E: 偶校验, O: 奇校验） Z: 停止位（1 或 2）

class SERIAL_WORK
{
    private:
        u32 _baudrate;
        u8 _rx_pin;
        u8 _tx_pin;
        u32 _mode;
        HardwareSerial &_serial;


    public:
        SERIAL_WORK(u32 baudrate, u8 rx_pin, u8 tx_pin, u32 mode = SERIAL_8N1, HardwareSerial &serial = Serial1);
        void Init();
        void GetData(String& _rx_string);
        void SendHexData(const byte* data, size_t length);
        void SendData(const String tx_string);

};

SERIAL_WORK::SERIAL_WORK(u32 baudrate, u8 rx_pin, u8 tx_pin, u32 mode, HardwareSerial &serial):
    _baudrate(baudrate), _rx_pin(rx_pin), _tx_pin(tx_pin), _mode(mode),
    _serial(serial)
{

}

void SERIAL_WORK::Init()
{
    _serial.begin(_baudrate, SERIAL_8N1, _rx_pin, _tx_pin);
    _serial.setTimeout(1);
}

void SERIAL_WORK::GetData(String& _rx_string)
{
    if(_serial.available())
    {
        String inputString = _serial.readString();
        _rx_string = inputString;
    }
}

void SERIAL_WORK::SendHexData(const byte* data, size_t length)
{
    if(data != nullptr && length > 0)    _serial.write(data, length);
}

void SERIAL_WORK::SendData(const String tx_string)
{
    _serial.println(tx_string);
}


