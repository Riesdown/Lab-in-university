#pragma once

#include <PTC/SPI/SPI_HARD.hpp>
#include <Arduino.h>
#include <SYS/Some_Define/SomeDefine.hpp>
#include <HW/NR24/NR24_Reg.hpp>


using namespace std;


class NR24
{
    private:
        u8 _ce_pin;
        u8 _irq_pin;
        SPI_HARD spi;
        string _send_addr;
        string _get_addr;

        u8 _TX_ADDRESS[TX_ADR_WIDTH]; 
        u8 _RX_ADDRESS[RX_ADR_WIDTH]; 

    private:
        void Enable_Reg();
        void Disable_Reg();
        u8 Check();
        void Convert_String_To_Address(const string &addr_str, u8 *address, u8 max_len);
        u8 Get_IRQ();
    public:
        NR24(u8 _SS_PIN, u8 _SCK_PIN, u8 _MISO_PIN, u8 _MOSI_PIN, u8 _CE_PIN, u8 _IRQ_PIN, string send_addr = "66666", string get_addr = "66666");
        void Init();
        void Get_Data(u8 *data);
        void Send_Data(u8 *data);
};



NR24::NR24(u8 _SS_PIN, u8 _SCK_PIN, u8 _MISO_PIN, u8 _MOSI_PIN, u8 _CE_PIN, u8 _IRQ_PIN, string send_addr, string get_addr):
    spi(_SS_PIN, _SCK_PIN, _MISO_PIN, _MOSI_PIN, 10000000),
    _ce_pin(_CE_PIN), _send_addr(send_addr), _get_addr(get_addr), _irq_pin(_IRQ_PIN)
{}


void NR24::Init()
{
    pinMode(_ce_pin, OUTPUT);
    pinMode(_irq_pin, INPUT);
    spi.Init();

    while(Check())	Serial.printf("NRF24 Check Fail \r\n");
	Serial.printf("NRF24 Check Good \r\n");

    // Convert_String_To_Address(_send_addr, _TX_ADDRESS, TX_ADR_WIDTH);
    // Convert_String_To_Address(_get_addr, _RX_ADDRESS, RX_ADR_WIDTH);
    const uint8_t _TX_ADDRESS[TX_ADR_WIDTH] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF}; 
    const uint8_t _RX_ADDRESS[RX_ADR_WIDTH] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF}; 

    Enable_Reg();
    spi.Set_Reg(NRF_WRITE_REG + RX_PW_P0, RX_PLOAD_WIDTH);  							// 设置接收通道有效数据宽度
    spi.Set_Reg_Buffer(NRF_WRITE_REG + TX_ADDR, (u8*)_TX_ADDRESS, TX_ADR_WIDTH); 		// 设置发送地址
    spi.Set_Reg_Buffer(NRF_WRITE_REG + RX_ADDR_P0, (u8*)_RX_ADDRESS, RX_ADR_WIDTH); 	// 设置接收地址

    spi.Set_Reg(NRF_WRITE_REG + EN_AA, 0x01); 										// 启用自动应答
    spi.Set_Reg(NRF_WRITE_REG + EN_RXADDR, 0x01); 									// 启用接收地址通道0

    spi.Set_Reg(NRF_WRITE_REG + SETUP_RETR, 0x5F); 									// 1500 μs 间隔，重发 15 次
    spi.Set_Reg(NRF_WRITE_REG + RF_CH, 0); 											// 设置无线频率通道
    spi.Set_Reg(NRF_WRITE_REG + RF_SETUP, 0x0F); 										// 设置数据速率与发射功率
    spi.Set_Reg(NRF_WRITE_REG + CONFIG, 0x0F); 										// 配置工作模式
	
    Disable_Reg();
	delayMicroseconds(100);

}

void NR24::Convert_String_To_Address(const string &addr_str, u8 *address, u8 max_len)
{
    memset(address, 0, max_len);

    size_t len = addr_str.size() > max_len ? max_len : addr_str.size();
    memcpy(address, addr_str.c_str(), len);
}

void NR24::Enable_Reg()
{
    digitalWrite(_ce_pin, LOW);
}


void NR24::Disable_Reg()
{
    digitalWrite(_ce_pin, HIGH);
}

u8 NR24::Check()
{
    u8 check_in_buf[5] = {0x11, 0x22, 0x33, 0x44, 0x55};
    u8 check_out_buf[5] = {0};

    Enable_Reg();

    spi.Set_Reg_Buffer(NRF_WRITE_REG + TX_ADDR, check_in_buf, 5);
    spi.Get_Reg_Buffer(NRF_READ_REG + TX_ADDR, check_out_buf, 5);

    return memcmp(check_in_buf, check_out_buf, 5) == 0 ? 0 : 1;
}


void NR24::Get_Data(u8* data)
{
    Enable_Reg();
    spi.Set_Reg(NRF_WRITE_REG + CONFIG, 0x0F); 
    Disable_Reg();
	
    u8 State = spi.SwapByte(0xff);
    spi.Get_Reg_Buffer(RD_RX_PLOAD, data, RX_PLOAD_WIDTH); 
}

u8 NR24::Get_IRQ()
{
    return digitalRead(_irq_pin);
}



void NR24::Send_Data(u8* data)
{
    spi.Set_Reg(FLUSH_TX, 0xff); 
    spi.Set_Reg(FLUSH_RX, 0xff);
	
    RUN_ONCE_STR("NR24_Send",
        Enable_Reg();
        spi.Set_Reg(NRF_WRITE_REG + CONFIG, 0x0E); 
        Disable_Reg();
    )


    Enable_Reg();
    spi.Set_Reg_Buffer(WR_TX_PLOAD, data, TX_PLOAD_WIDTH);
    Disable_Reg();
}






