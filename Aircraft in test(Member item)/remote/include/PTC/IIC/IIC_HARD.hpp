#pragma once

#include <Arduino.h>
#include <SYS/Some_Define/SomeDefine.hpp>
#include <Wire.h>

class IIC_HARD
{
    private:
        u8 _sda; 
        u8 _scl;  
        u32 _speed;  


    public:
        IIC_HARD(u8 sda, u8 scl, u32 i2c_speed);

        void Init();
        void Check_IIC_Connect();
        u8 Get_Reg(u8 addr, u8 regAddr);
        void Set_Reg(u8 addr, u8 regAddr, u8 data);

};

IIC_HARD::IIC_HARD(u8 sda, u8 scl, u32 speed):
    _sda(sda), _scl(scl), _speed(speed)
{

}

void IIC_HARD::Set_Reg(u8 addr, u8 regAddr, u8 data)
{
    Wire.beginTransmission(addr);
    Wire.write(regAddr);
    Wire.write(data);
    Wire.endTransmission();
}


u8 IIC_HARD::Get_Reg(u8 addr, u8 regAddr)
{
    Wire.beginTransmission(addr);
    Wire.write(regAddr);
    Wire.endTransmission(false);
    Wire.requestFrom(addr, (u8)1);
    if(Wire.available()) return Wire.read();
    return 0xFF;
}


void IIC_HARD::Init()
{
    Wire.begin(_sda, _scl, _speed);
    Wire.setTimeout(5); 

}

void IIC_HARD::Check_IIC_Connect()
{
    u8 flag;
    printf("\nIIC 设备扫描：");
    for (u8 addr = 1; addr < 127; addr++) 
    {
        Wire.beginTransmission(addr);
        if(Wire.endTransmission() == 0) 
        {
            printf("找到IIC设备 0x%02X\n", addr);
            flag = 1;
        }
    }

}







