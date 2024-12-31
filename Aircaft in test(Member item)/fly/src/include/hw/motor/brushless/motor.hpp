#pragma once

#include <sys/some_define/define.hpp>
#include <hw/motor/method/method.hpp>


class BL_MOTOR: public MOTOR_PWM::METHOD
{
    private:
        u32 _min_us;
        u32 _max_us;
        mutable u32 _fre;
        u8 _CHANNEL;
        u8 _pwm_step;
        u32 _pwm;

        inline u32 Us_TOPWM(u16 pulseWidth) const;


    public:
        // PWM通道 + PWM引脚 + 最小脉宽 + 最大脉宽 + 频率 + PWM最大步长
        BL_MOTOR(u8 CHANNEL, u8 PIN_PWM, u32 min_us = 1000, u32 max_us = 2000, u32 fre = 400, u8 pwm_step = 14);
        
        // 设置PWM占空比
        void Set_Power(u32 power) override;

        // 电调校准
        void Check();

        // 获取频率
        u32 Get_Frequency() const { return _fre; }

        // 获取pwm
        u16 Get_PWM()   const { return _pwm; }
};


