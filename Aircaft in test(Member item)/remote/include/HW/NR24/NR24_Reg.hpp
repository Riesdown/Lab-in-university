#pragma once




/*
数据长度
*/
#define TX_ADR_WIDTH    5     //5字节地址宽度
#define RX_ADR_WIDTH    5     //5字节地址宽度
#define TX_PLOAD_WIDTH  32    //32字节有效数据宽度
#define RX_PLOAD_WIDTH  32    //32字节有效数据宽度

/*
寄存器操作命令  
*/
#define NRF_READ_REG        0x00 //读的寄存器，低5位为寄存器地址

#define NRF_WRITE_REG       0x20 //写的寄存器，低5位为寄存器地址

#define RD_RX_PLOAD     0x61 //读的有效数据寄存器，1-32字节
#define WR_TX_PLOAD     0xA0 //写的有效数据寄存器，1-32字节
#define FLUSH_TX        0xE1 //清除写的FIFO寄存器，发射模式下用
#define FLUSH_RX        0xE2 //清除读的FIFO寄存器，发射模式下用
#define REUSE_TX_PL     0xE3 //重新使用上一包数据，CE为高时，不断发送
#define NOP_             0xFF //空状态。可以用来读状态寄存器

/*
寄存器地址（常用）   
*/
#define CONFIG          0x00 //配置寄存器地址                       
#define EN_AA           0x01 //使能自动应答功能  
#define EN_RXADDR       0x02 //接收地址允许  
#define SETUP_AW        0x03 //设置地址宽度（所有数据通道）  
#define SETUP_RETR      0x04 //建立自动重发  
#define RF_CH           0x05 //频率范围通道  
#define RF_SETUP        0x06 //频率范围寄存器
#define STATUS          0x07 //状态寄存器
#define OBSERVE_TX      0x08 //发送检测寄存器  
#define CD              0x09 //载波检测寄存器  
#define RX_ADDR_P0      0x0A //数据接收通道0地址  
#define RX_ADDR_P1      0x0B //数据接收通道1地址    
#define RX_ADDR_P2      0x0C //数据接收通道2地址    
#define RX_ADDR_P3      0x0D //数据接收通道3地址    
#define RX_ADDR_P4      0x0E //数据接收通道4地址    
#define RX_ADDR_P5      0x0F //数据接收通道5地址   
#define TX_ADDR         0x10 //发送地址寄存器
#define RX_PW_P0        0x11 //有效数据接收通道0地址
#define RX_PW_P1        0x12 //有效数据接收通道1地址   
#define RX_PW_P2        0x13 //有效数据接收通道2地址   
#define RX_PW_P3        0x14 //有效数据接收通道3地址   
#define RX_PW_P4        0x15 //有效数据接收通道4地址  
#define RX_PW_P5        0x16 //有效数据接收通道5地址 
#define FIFO_STATUS     0x17 //FIFO状态寄存器

//STATUS寄存器指令
#define Write_Max  	0x10 //达到最大发送次数
#define Write_OK   	0x20 //数据写入完成 	 
#define Read_OK   	0x40 //数据读取完成 