#pragma once

#include <APP/Debug/Debug.hpp>


void DefaultSerial_RTOS(void* param)
{
    while(1)
    {
        // serial_bebug.ListData();

        // if(serial_bebug.GetData() == "restart")          ESP.restart();
        delay(100);
    }
}













