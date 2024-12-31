#include <sys/some_define/define.hpp>
#include <hw/pt/pt.hpp>



PT::PT(u8 pin, u8 resolution, adc_attenuation_t mode):
    _pin(pin), _resolution(resolution), _mode(mode)
{
    
}


void PT::Init()
{
    analogReadResolution(_resolution);
    /*
        ADC_0db：没有衰减，ADC可以读取最高1.1V的电压。
        ADC_2_5db：2.5dB的衰减，ADC可以读取最高1.5V的电压。
        ADC_6db：6dB的衰减，ADC可以读取最高2.2V的电压。
        ADC_11db：11dB的衰减，ADC可以读取最高3.3V的电压。
    */
    analogSetAttenuation(_mode);
}



void PT::Get_AD(u16 &AD) const
{
    AD = analogRead(_pin);
}

