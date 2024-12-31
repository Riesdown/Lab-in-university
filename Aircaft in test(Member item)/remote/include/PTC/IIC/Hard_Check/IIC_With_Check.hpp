#pragma once


#include <PTC/IIC/IIC_HARD.hpp>


class FROM_IIC_HARD
{
    protected:
        IIC_HARD& _i2c;

    public:
        FROM_IIC_HARD(IIC_HARD& i2c) : _i2c(i2c) {}

        virtual void Init() { _i2c.Init(); }
        virtual void Set_Reg(u8 addr, u8 regAddr, u8 data) { _i2c.Set_Reg(addr, regAddr, data); }
        virtual u8 Get_Reg(u8 addr, u8 regAddr) { return _i2c.Get_Reg(addr, regAddr); }
        virtual void Check_IIC_Connect() { _i2c.Check_IIC_Connect(); }
};


class IIC_HARD_WITH_CHECK : public FROM_IIC_HARD
{
    public:
        IIC_HARD_WITH_CHECK(IIC_HARD& i2c): FROM_IIC_HARD(i2c) {}

        u8 Get_Reg(u8 addr, u8 regAddr) override;
};

u8 IIC_HARD_WITH_CHECK::Get_Reg(u8 addr, u8 regAddr)
{
    u8 result = _i2c.Get_Reg(addr, regAddr);
    if(result == 0xFF)    Serial.println("读取失败");
    return result;
}




