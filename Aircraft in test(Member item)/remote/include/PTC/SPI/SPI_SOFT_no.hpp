#pragma once

#include <Arduino.h>
#include <SYS/Some_Define/SomeDefine.hpp>
/***********************修改*************************************************************************************************** */
#define SS1_PIN  	15
#define SCK1_PIN	2
#define MISO1_PIN	4
#define MOSI1_PIN	23



#define SPI1_Start() 	GPIO_WRITE_BIT1(0, SS1_PIN)
#define SPI1_Stop() 	GPIO_WRITE_BIT1(1, SS1_PIN)

#define Write_SCK1(x) 	GPIO_WRITE_BIT1(x, SCK1_PIN)

#define Read_MISO1() 	GPIO_READ_BIT1(MISO1_PIN)

#define Write_MOSI1(x) 	GPIO_WRITE_BIT1(x, MOSI1_PIN)


void SPI1_Init()
{
	pinMode(SS1_PIN, OUTPUT);
	pinMode(SCK1_PIN, OUTPUT);
	pinMode(MOSI1_PIN, OUTPUT);
	pinMode(MISO1_PIN, INPUT_PULLUP);

	SPI1_Stop();
	Write_SCK1(0);
}




#define SPI1_SwapByte(ByteSend) ({ \
    u8 ByteReceive = 0x00; \
    Write_MOSI1(ByteSend & 0x80); \
    ByteReceive = (ByteReceive << 1) | Read_MISO1(); \
    Write_SCK1(1); \
    Write_SCK1(0); \
    Write_MOSI1(ByteSend & 0x40); \
    ByteReceive = (ByteReceive << 1) | Read_MISO1(); \
    Write_SCK1(1); \
    Write_SCK1(0); \
    Write_MOSI1(ByteSend & 0x20); \
    ByteReceive = (ByteReceive << 1) | Read_MISO1(); \
    Write_SCK1(1); \
    Write_SCK1(0); \
    Write_MOSI1(ByteSend & 0x10); \
    ByteReceive = (ByteReceive << 1) | Read_MISO1(); \
    Write_SCK1(1); \
    Write_SCK1(0); \
    Write_MOSI1(ByteSend & 0x08); \
    ByteReceive = (ByteReceive << 1) | Read_MISO1(); \
    Write_SCK1(1); \
    Write_SCK1(0); \
    Write_MOSI1(ByteSend & 0x04); \
    ByteReceive = (ByteReceive << 1) | Read_MISO1(); \
    Write_SCK1(1); \
    Write_SCK1(0); \
    Write_MOSI1(ByteSend & 0x02); \
    ByteReceive = (ByteReceive << 1) | Read_MISO1(); \
    Write_SCK1(1); \
    Write_SCK1(0); \
    Write_MOSI1(ByteSend & 0x01); \
    ByteReceive = (ByteReceive << 1) | Read_MISO1(); \
    Write_SCK1(1); \
    Write_SCK1(0); \
    ByteReceive; \
}) 



// class SPI_SOFT
// {
//     private:
//         u8 _ss_pin;
//         u8 _sck_pin;
//         u8 _miso_pin;
//         u8 _mosi_pin;
//     private:
//         inline void Write_SCK(u8 x);
//         inline u8 Read_MISO();
//         inline void Write_MOSI(u8 x);
//     public:
//         SPI_SOFT(u8 ss_pin, u8 sck_pin, u8 miso_pin, u8 mosi_pin);
//         void Init();
//         inline void Start();
//         inline void Stop();

//         inline u8 SwapByte(u8 ByteSend);
// };

// SPI_SOFT::SPI_SOFT(u8 ss_pin, u8 sck_pin, u8 miso_pin, u8 mosi_pin):
//     _ss_pin(_ss_pin), _sck_pin(sck_pin), _miso_pin(miso_pin), _mosi_pin(mosi_pin)
// {

// }


// inline void SPI_SOFT::Start()
// {
//     GPIO_WRITE_BIT1(0, _ss_pin);
// }

// inline void SPI_SOFT::Stop()
// {
//     GPIO_WRITE_BIT1(1, _ss_pin);
// }

// inline void SPI_SOFT::Write_SCK(u8 x)
// {
//     GPIO_WRITE_BIT1(x, _sck_pin);
// }

// inline u8 SPI_SOFT::Read_MISO()
// {
//     return GPIO_READ_BIT1(_miso_pin);
// }

// inline void SPI_SOFT::Write_MOSI(u8 x)
// {
//     GPIO_WRITE_BIT1(x, _mosi_pin)
// }


// void SPI_SOFT::Init()
// {
//     pinMode(_ss_pin, OUTPUT);
//     pinMode(_sck_pin, OUTPUT);
//     pinMode(_miso_pin, INPUT_PULLUP);
//     pinMode(_mosi_pin, OUTPUT);

//     Stop();
//     Write_SCK(0);
// }


// inline u8 SPI_SOFT::SwapByte(u8 ByteSend)
// {
//     u8 ByteReceive = 0x00;
//     Write_MOSI(ByteSend & 0x80);
//     ByteReceive = (ByteReceive << 1) | Read_MISO();
//     Write_SCK(1);
//     Write_SCK(0);
//     Write_MOSI(ByteSend & 0x40);
//     ByteReceive = (ByteReceive << 1) | Read_MISO();
//     Write_SCK(1);
//     Write_SCK(0);
//     Write_MOSI(ByteSend & 0x20);
//     ByteReceive = (ByteReceive << 1) | Read_MISO();
//     Write_SCK(1);
//     Write_SCK(0);
//     Write_MOSI(ByteSend & 0x10);
//     ByteReceive = (ByteReceive << 1) | Read_MISO();
//     Write_SCK(1);
//     Write_SCK(0);
//     Write_MOSI(ByteSend & 0x08);
//     ByteReceive = (ByteReceive << 1) | Read_MISO();
//     Write_SCK(1);
//     Write_SCK(0);
//     Write_MOSI(ByteSend & 0x04);
//     ByteReceive = (ByteReceive << 1) | Read_MISO();
//     Write_SCK(1);
//     Write_SCK(0);
//     Write_MOSI(ByteSend & 0x02);
//     ByteReceive = (ByteReceive << 1) | Read_MISO();
//     Write_SCK(1);
//     Write_SCK(0);
//     Write_MOSI(ByteSend & 0x01);
//     ByteReceive = (ByteReceive << 1) | Read_MISO();
//     Write_SCK(1);
//     Write_SCK(0);
//     return ByteReceive;
// }

