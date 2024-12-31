#include <sys/some_define/define.hpp>
#include <ptc/spi/spi_hard.hpp>





SPI_HARD::SPI_HARD(u8 ss_pin, u8 sck_pin, u8 miso_pin, u8 mosi_pin, u32 speed, u8 spi_bus):
    _speed(speed),
    _spi(spi_bus),
    _ss_pin(ss_pin),
    _sck_pin(sck_pin),
    _miso_pin(miso_pin),
    _mosi_pin(mosi_pin)
{

}

void SPI_HARD::Init()
{
    pinMode(_ss_pin, OUTPUT);
    digitalWrite(_ss_pin, HIGH); 

    _spi.begin(_sck_pin, _miso_pin, _mosi_pin, _ss_pin);
}



inline void SPI_HARD::Start()
{
    // GPIO_WRITE_BIT1(0, _ss_pin);  
    digitalWrite(_ss_pin, LOW);
    _spi.beginTransaction(SPISettings(_speed, MSBFIRST, SPI_MODE0));
}


inline void SPI_HARD::Stop()
{
    _spi.endTransaction(); 
    // GPIO_WRITE_BIT1(1, _ss_pin);
    digitalWrite(_ss_pin, HIGH);
}

inline u8 SPI_HARD::SwapByte(u8 data)
{
    return _spi.transfer(data);
}

u8 SPI_HARD::Get_Reg(u8 reg)
{
    Start();
    SwapByte(reg | 0x80);
    u8 data = SwapByte(0xff);
    Stop();
    return data;
}


void SPI_HARD::Set_Reg(u8 reg, u8 data)
{
    Start();
    SwapByte(reg);
    SwapByte(data);
    Stop();
}

void SPI_HARD::Set_Reg_Buffer(u8 reg, u8 *data, u8 len)
{
    Start();
    SwapByte(reg);
    for (u8 i = 0; i < len; i++)
    {
        SwapByte(data[i]);
    }
    Stop();
}



void SPI_HARD::Get_Reg_Buffer(u8 reg, u8 *data, u8 len)
{
    Start();
    SwapByte(reg);
    for (u8 i = 0; i < len; i++)
    {
        data[i] = SwapByte(0xff);
    }
    Stop();
}


