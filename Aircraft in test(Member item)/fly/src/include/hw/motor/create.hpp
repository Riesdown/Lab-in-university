#pragma once

#include <Arduino.h>
#include <sys/some_define/define.hpp>
#include <memory>

#include <hw/motor/brushless/motor.hpp>
#include <hw/motor/method/method.hpp>



using namespace std;









namespace GET_MOTOR 
{

    class FACTORY 
    {
        public:
            using methodptr_pwm = unique_ptr<MOTOR_PWM::METHOD>; 

            static methodptr_pwm Create_Brushless(u8 CHANNEL, u8 PIN_PWM, u32 min_us = 1000, u32 max_us = 2000, u32 fre = 400, u8 pwm_step = 14)
            {
                return methodptr_pwm(new BL_MOTOR(CHANNEL, PIN_PWM, min_us, max_us, fre, pwm_step) );
            }
    };
}
