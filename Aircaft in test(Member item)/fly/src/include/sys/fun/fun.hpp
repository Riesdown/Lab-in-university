#pragma once
#include <Arduino.h>


extern TaskHandle_t TASK_Default_Debug;
extern TaskHandle_t TASK_MPU_Get_Data;
extern TaskHandle_t TASK_MPU_Get_Data_Pany;
extern TaskHandle_t TASK_IU_Connect_Send;
extern TaskHandle_t TASK_IU_Connect_Get;

extern TaskHandle_t TASK_Remote_Get_Data;
extern TaskHandle_t TASK_Remote_Get_Data_Pany;
extern TaskHandle_t TASK_Motor_Control;
extern TaskHandle_t TASK_OTA_With_UDP;


void Close_AllWork();