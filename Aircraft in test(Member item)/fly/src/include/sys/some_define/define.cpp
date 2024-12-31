#include <Arduino.h>
#include "define.hpp"
#include <stdint.h>


void GPIO_Write_Bit(u8 value, u8 pin) 
{
    if (value)  *(volatile unsigned int*)GPIO_OUT_W1TS_REG = (1 << pin);
    else        *(volatile unsigned int*)GPIO_OUT_W1TC_REG = (1 << pin);
}

u8 GPIO_Read_Bit(u8 pin) 
{
    return (*(volatile unsigned int*)GPIO_IN_REG & (1 << pin)) != 0;
}

f64 MAP(f64 x, f64 in_min, f64 in_max, f64 out_min, f64 out_max) 
{
    if (x < in_min) return out_min;
    else if (x > in_max) return out_max;
    else return out_min + ((x - in_min) * (out_max - out_min) / (in_max - in_min));
}


