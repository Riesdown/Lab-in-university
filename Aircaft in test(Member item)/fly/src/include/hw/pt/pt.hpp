#pragma once

#include <Arduino.h>
#include <sys/some_define/define.hpp>


class PT
{
    private:
        u8 _resolution;
        u8 _pin;
        adc_attenuation_t _mode;


    public:
        // 引脚 + 分辨率 + 模式
        PT(u8 pin, u8 resolution = 12, adc_attenuation_t mode = ADC_11db);
        
        // 初始化
        void Init();

        // 获取AD值
        void Get_AD(u16 &AD) const;

};











