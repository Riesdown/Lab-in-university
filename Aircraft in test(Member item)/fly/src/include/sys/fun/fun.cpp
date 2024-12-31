#include "fun.hpp"
#include <sys/some_define/define.hpp>




TaskHandle_t TASK_OTA_With_UDP;


TaskHandle_t TASK_Default_Debug;
TaskHandle_t TASK_MPU_Get_Data;
TaskHandle_t TASK_MPU_Get_Data_Pany;
TaskHandle_t TASK_IU_Connect_Send;
TaskHandle_t TASK_IU_Connect_Get;
TaskHandle_t TASK_Remote_Get_Data;
TaskHandle_t TASK_Remote_Get_Data_Pany;
TaskHandle_t TASK_Motor_Control;

void Close_AllWork()
{
    // vTaskSuspend(TASK_Default_Debug);
    // vTaskSuspend(TASK_MPU_Get_Data);
    // vTaskSuspend(TASK_MPU_Get_Data_Pany);
    // vTaskSuspend(TASK_IU_Connect);
    // vTaskSuspend(TASK_Remote_Get_Data);
    // vTaskSuspend(TASK_Remote_Get_Data_Pany);
    // vTaskSuspend(TASK_Motor_Control);
}

