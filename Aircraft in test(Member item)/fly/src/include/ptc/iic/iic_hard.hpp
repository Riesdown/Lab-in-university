#pragma once

#include <Arduino.h>
#include <sys/some_define/define.hpp>
#include <Wire.h>

class IIC_HARD
{
    private:
        u8 _sda; 
        u8 _scl;  
        u32 _speed;  


    public:
        // 引脚 + 速度
        IIC_HARD(u8 sda, u8 scl, u32 i2c_speed);

        // 初始化
        void Init();

        // 扫描设备
        void Check_IIC_Connect();

        // 读取寄存器
        u8 Get_Reg(u8 addr, u8 regAddr);

        // 写入寄存器
        void Set_Reg(u8 addr, u8 regAddr, u8 data);

};





