#pragma once

#include <SYS/Some_Define/SomeDefine.hpp>

class BL_MOTOR
{
private:
    u32 _min_us;
    u32 _max_us;
    u32 _fre;
    u8 _CHANNEL;
    u8 _pwm_step;

    inline u32 Us_TOPWM(u16 pulseWidth) const;


public:
    BL_MOTOR(u8 CHANNEL, u8 PIN_PWM, u32 min_us = 1100, u32 max_us = 1940, u32 fre = 400, u8 pwm_step = 16);
    void Set_Power(u32 power);
    void Check();

    u32 Get_Frequency() const { return _fre; }
};


BL_MOTOR::BL_MOTOR(u8 CHANNEL, u8 PIN_PWM, u32 min_us, u32 max_us, u32 fre, u8 pwm_step):
    _min_us(min_us),
    _max_us(max_us),
    _fre(fre),
    _CHANNEL(CHANNEL),
    _pwm_step(pwm_step)
{
    ledcSetup(_CHANNEL, _fre, _pwm_step);  
    ledcAttachPin(PIN_PWM, _CHANNEL); 
    Check();
}


void BL_MOTOR::Set_Power(u32 power)
{
    u32 pwm_te = MAP(power, 0, 1000, _min_us, _max_us); 
    u32 pwm = Us_TOPWM(pwm_te); 
    ledcWrite(_CHANNEL, pwm);  
}


void BL_MOTOR::Check()
{
    Set_Power(0);
    delay(5000);
}


inline u32 BL_MOTOR::Us_TOPWM(u16 pulseWidth) const
{
    return pulseWidth * (1 << _pwm_step) / (1000000 / _fre); 
}

