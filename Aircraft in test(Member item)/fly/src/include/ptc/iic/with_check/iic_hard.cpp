#include <sys/some_define/define.hpp>
#include <ptc/iic/iic_hard.hpp>

#include <ptc/iic/with_check/iic_hard.hpp>



u8 IIC_HARD_WITH_CHECK::Get_Reg(u8 addr, u8 regAddr)
{
    u8 result = _i2c.Get_Reg(addr, regAddr);
    if(result == 0xFF)    Serial.println("读取失败");
    return result;
}


