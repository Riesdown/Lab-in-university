#pragma once

#include <sys/some_define/define.hpp>



void TIM_Update_Inter_Mode(hw_timer_t *Timx, u8 tim_num, u32 num, void (*fn)(void));
void Create_Task(TaskFunction_t fun, u32 size, u32 priority, TaskHandle_t* Task_Handle, u32 core);










