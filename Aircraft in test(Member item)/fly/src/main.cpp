
#include <Arduino.h>
#include <sys/some_define/define.hpp>
#include <sys/init/all_init.hpp>
#include <sys/lib/lib.hpp>
#include <sys/fun/fun.hpp>

// work
#include <work/default/default.hpp>
#include <work/mpu/geta_data.hpp>
#include <work/ui/ui.hpp>
#include <work/remote/remote.hpp>
#include <work/motor/motor.hpp>
#include <work/ota/ota.hpp>
void setup() 
{
    // 初始化
    All_Init();

    // 默认调试
    Create_Task(Default_Debug, 5000, 0, &TASK_Default_Debug, 1); 

    // 获取MPU数据
    Create_Task(MPU_Get_Data, 5000, 2, &TASK_MPU_Get_Data, 0); 
    // 获取MPU数据 - 附加任务
    Create_Task(MPU_Get_Data_Pany, 5000, 2, &TASK_MPU_Get_Data_Pany, 0); 

    // 获取遥控数据
    Create_Task(Remote_Get_Data, 5000, 1, &TASK_Remote_Get_Data, 1); 
    // 获取遥控数据 - 附加任务
    Create_Task(Remote_Get_Data_Pany, 5000, 2, &TASK_Remote_Get_Data_Pany, 1); 

    // 电机控制
    Create_Task(Motor_Control, 5000, 2, &TASK_Motor_Control, 1); 

    // 连接UI界面
    Create_Task(IU_Connect_Send, 5000, 2, &TASK_IU_Connect_Send, 0); 
    Create_Task(IU_Connect_Get, 5000, 2, &TASK_IU_Connect_Get, 0); 
    // // OTA
    // Create_Task(OTA_With_UDP, 5000, 2, &TASK_OTA_With_UDP, 0);
}

void loop() 
{
    delay(10);
}

