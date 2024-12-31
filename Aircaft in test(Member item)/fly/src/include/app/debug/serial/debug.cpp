#include <sys/some_define/define.hpp>
#include "app/debug/serial/debug.hpp"

SERIAL_DEBUG::SERIAL_DEBUG(u32 baudrate, u8 rx_pin, u8 tx_pin, HardwareSerial &serial):
    _serial(serial), _baudrate(baudrate), _rx_pin(rx_pin), _tx_pin(tx_pin)
{
}

SERIAL_DEBUG::SERIAL_DEBUG(u32 baudrate, HardwareSerial &serial):
    _serial(serial), _baudrate(baudrate)
{
}

void SERIAL_DEBUG::Init()
{
    if(_rx_pin) _serial.begin(_baudrate, SERIAL_8N1, _rx_pin, _tx_pin);
    else _serial.begin(_baudrate);

    _serial.setTimeout(100);
}

void SERIAL_DEBUG::ProcessData(const String &data)
{
    Serial.println("ESP_DefaultSerial Get: " + data);
}

void SERIAL_DEBUG::ListData()
{
    if (_serial.available())
    {
        _rx_string.clear();
        String inputString = _serial.readString();
        _rx_string = inputString;
        ProcessData(inputString);
    }
}