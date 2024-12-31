#pragma once


#include <ptc/iic/iic_hard.hpp>
#include <sys/some_define/define.hpp>

class FROM_IIC_HARD
{
    protected:
        IIC_HARD& _i2c;

    public:

        // 硬件IIC
        FROM_IIC_HARD(IIC_HARD& i2c) : _i2c(i2c) {}

        // 初始化
        virtual void Init() { _i2c.Init(); }

        // 设置寄存器
        virtual void Set_Reg(u8 addr, u8 regAddr, u8 data) { _i2c.Set_Reg(addr, regAddr, data); }
        
        // 获取寄存器
        virtual u8 Get_Reg(u8 addr, u8 regAddr) { return _i2c.Get_Reg(addr, regAddr); }
        
        // 扫描
        virtual void Check_IIC_Connect() { _i2c.Check_IIC_Connect(); }
};


class IIC_HARD_WITH_CHECK : public FROM_IIC_HARD
{
    public:
        // 扫描
        IIC_HARD_WITH_CHECK(IIC_HARD& i2c): FROM_IIC_HARD(i2c) {}
        
        // 获取寄存器
        u8 Get_Reg(u8 addr, u8 regAddr) override;
};

