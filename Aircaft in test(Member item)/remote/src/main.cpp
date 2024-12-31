#include <Arduino.h>
#include <SYS/Some_Define/SomeDefine.hpp>

#include <HW/WIFI/WIFI.hpp>
#include <APP/OTA/OTA.hpp>
#include <HW/OLED/OLED.hpp>

#include <HW/BL_Motor/BL_Motor.hpp>
#include <APP/Serial/Serial.hpp>
#include <HW/PT/Pt.hpp>
// #include <HW/NR24/NR24.hpp>
#include <HW/KEY/Key.hpp>

#include <APP/UKF/UKF.hpp>

// 放最后
#include <SYS/Sys_Fun/Fun.hpp>
#include <SYS/Init/Init.hpp>
#include <WORK/Flag/Flag_WORK.hpp>
#include <WORK/Debug/Debug_Work.hpp>
#include <WORK/Send_DATA/Send_Data_WORK.hpp>
#include <APP/Debug/Debug.hpp>
#include "WORK/Debug/OLED_Interface.hpp"



void setup() 
{
    All_Init();
    All_Interface();
    // Create_Task(DefaultSerial_RTOS, 2000, 2, &TASK_DefaultSerial_RTOS, 0); 


    Create_Task(Send_Data_RTOS, 3000, 1, &TASK_Send_Data_RTOS, 0); 

}


u8 interface = 0;
void loop()
{
    if (key_front.Get_Key() ) interface--;
    if (key_back.Get_Key() ) interface++;

    if (key_unlock.Get_Key())  mode_data.unlock++;

    interface = (interface == 255) ? 0 : (interface >= 100) ? 100 : interface;

    OLED_Interface_Replace(interface);
    
    OLED_ShowNum(4, 14, interface, 3);

    delay(20);

}
