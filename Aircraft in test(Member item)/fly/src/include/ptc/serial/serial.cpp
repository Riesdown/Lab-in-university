#include <sys/some_define/define.hpp>
#include <ptc/serial/serial.hpp>




SERIAL_WORK::SERIAL_WORK(u32 baudrate, u8 rx_pin, u8 tx_pin, HardwareSerial &serial, u32 mode):
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

void SERIAL_WORK::GetBinaryData(byte* buffer, size_t length)
{
    _serial.readBytes(buffer, length); 
}

void SERIAL_WORK::SendHexData(const byte* data, size_t length)
{
    if(data != nullptr && length > 0)    
        _serial.write(data, length);
}

void SERIAL_WORK::SendData(const String tx_string)
{
    _serial.println(tx_string);
}
