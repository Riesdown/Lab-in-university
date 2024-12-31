#pragma once


TaskHandle_t TASK_DefaultSerial_RTOS;
TaskHandle_t TASK_Send_Data_RTOS;





//当点击发送后，暂停所有任务，只能使用暂停，且只能使用句柄暂停
void Close_AllWork()
{
    vTaskSuspend(TASK_DefaultSerial_RTOS);
    vTaskSuspend(TASK_Send_Data_RTOS);

}

