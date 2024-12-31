#pragma once

#include <Arduino.h>
#include <SYS/Some_Define/SomeDefine.hpp>


/*
ADC1 通道（ADC1 由 GPIO34 至 GPIO39 提供）
ADC1_CH0: GPIO34
ADC1_CH1: GPIO35
ADC1_CH2: GPIO36 (SVP)
ADC1_CH3: GPIO37
ADC1_CH4: GPIO38
ADC1_CH5: GPIO39


ADC2 通道（ADC2 由 GPIO0 至 GPIO15 提供）
ADC2_CH0: GPIO0
ADC2_CH1: GPIO2
ADC2_CH2: GPIO4
ADC2_CH3: GPIO12
ADC2_CH4: GPIO13
ADC2_CH5: GPIO14
ADC2_CH6: GPIO15
*/


class PT
{
    private:
        u8 _resolution;
        u8 _pin;
        adc_attenuation_t _mode;


    public:
        PT(u8 pin, u8 resolution = 12, adc_attenuation_t mode = ADC_11db);
        void Init();
        void Get_AD(u16 &AD) const;

};


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










