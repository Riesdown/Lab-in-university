#pragma once
#include <Arduino.h>

#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <utility> // for std::forward



namespace DEBUG
{
    class SERIAL_DEBUG
    {
        private:
            HardwareSerial &_serial; 
            String _rx_string;

        public:
            explicit SERIAL_DEBUG(HardwareSerial &serial);
            void ListData();
            virtual void ProcessData(const String &data);
            String GetData() const { return _rx_string; }
    };


    SERIAL_DEBUG::SERIAL_DEBUG(HardwareSerial &serial):
        _serial(serial)
    {
    }

    void SERIAL_DEBUG::ProcessData(const String &data)
    {
        Serial.println("ESP_DefaultSerial Get: " + data);
    }

    void SERIAL_DEBUG::ListData()
    {
        if (_serial.available())
        {
            // String 转换为 std::string
            String inputString = _serial.readString();
            _rx_string = inputString;
            ProcessData(inputString);
        }
    }
};

