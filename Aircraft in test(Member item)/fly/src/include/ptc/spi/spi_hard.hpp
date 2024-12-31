#pragma once


#include <SPI.h>
#include <Arduino.h>
#include <sys/some_define/define.hpp>


class SPI_HARD
{
    private:
        u32 _speed;
        SPIClass _spi;
        u8 _ss_pin;
        u8 _sck_pin;
        u8 _miso_pin;
        u8 _mosi_pin;
    private:
        inline void Start();
        inline void Stop();
    public:
        // 接线 + 速度 + 模式
        SPI_HARD(u8 ss_pin, u8 sck_pin, u8 miso_pin, u8 mosi_pin, u32 speed = 1000, u8 spi_bus = HSPI);
        
        // 数据交换
        inline u8 SwapByte(u8 data);

        // 初始化
        void Init();

        // 读取寄存器
        u8 Get_Reg(u8 reg);

        // 写入寄存器
        void Set_Reg(u8 reg, u8 data);

        // 读取寄存器缓冲区
        void Set_Reg_Buffer(u8 reg, u8 *data, u8 len);

        // 写入寄存器缓冲区
        void Get_Reg_Buffer(u8 reg, u8 *data, u8 len);

};




