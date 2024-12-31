#pragma once


#include "SYS/Some_Define/SomeDefine.hpp"
#include "SYS/LIB/Lib.hpp"
#include "OLED_Font.hpp"
#include "SYS/INTER/Interrupt.hpp"

#include <PTC/IIC/IIC_HARD.hpp>
/************************************************配置******************************************************************* */




#define SDA_PIN_OLED 5
#define SCL_PIN_OLED 4

#define OLED_ADDR 0x3c


IIC_HARD oled_iic(SDA_PIN_OLED, SCL_PIN_OLED, 1000000);

#define OLED_IIC_Init oled_iic.Init
#define IIC_SendByte oled_iic.Set_Reg


/************************************************函数******************************************************************* */
extern u16 fps; 
extern u16 fps1; 


void OLED_Init();

void OLED_GetFPS();
void OLED_GetFPS_Init();
	
void OLED_ShowBinNum(u8 Line, u8 Column, uint32_t Number, u8 Length);
void OLED_ShowHexNum(u8 Line, u8 Column, uint32_t Number, u8 Length);
void OLED_ShowSignedNum(u8 Line, u8 Column, int32_t Number, u8 Length);
void OLED_ShowNum(u8 Line, u8 Column, uint32_t Number, u8 Length);
void OLED_ShowString(u8 Line, u8 Column, char *String);

void OLED_ON();
void OLED_OFF();

/************************************************函数******************************************************************* */











extern void Tomer0_Hander();
extern hw_timer_t * timer0;
void OLED_GetFPS_Init()
{
	TIM_Update_Inter_Mode(timer0, 0, 1000000, &Tomer0_Hander);
}


void OLED_GetFPS()
{
	OLED_ShowNum(1, 9, fps, 5);
	OLED_ShowString(1, 14, "fps");
}


void OLED_WriteCommand(u8 Command)
{
	IIC_SendByte(OLED_ADDR, 0x00, Command);
}


void OLED_WriteData(u8 Data)
{
	IIC_SendByte(OLED_ADDR, 0x40, Data);
}


void OLED_SetCursor(u8 Y, u8 X)
{
    OLED_WriteCommand(0xB0 | Y);
    OLED_WriteCommand(0x10 | (X >> 4));
    OLED_WriteCommand(X & 0x0F);
}


void OLED_Clear()
{  
	u8 i, j;
	for (j = 0; j < 8; j++)
	{
		OLED_SetCursor(j, 0);
		for(i = 0; i < 128; i++)
		{
			OLED_WriteData(0x00);
		}
	}
}


//扫描方式：从左到右，从上到下
void OLED_ShowChar(u8 Line, u8 Column, char Char)
{      	
	u8 i;
	OLED_SetCursor((Line - 1) * 2, (Column - 1) * 8);		//设置光标位置在上半部分
	for (i = 0; i < 8; i++)
	{
		OLED_WriteData(OLED_F8x16[Char - ' '][i]);			//显示上半部分内容
	}
	OLED_SetCursor((Line - 1) * 2 + 1, (Column - 1) * 8);	//设置光标位置在下半部分
	for (i = 0; i < 8; i++)
	{
		OLED_WriteData(OLED_F8x16[Char - ' '][i + 8]);		//显示下半部分内容
	}
	fps1++;
}





void OLED_ShowString(u8 Line, u8 Column, const char *String)
{
	u8 i;
	for (i = 0; String[i] != '\0'; i++)
	{
		OLED_ShowChar(Line, Column + i, String[i]);
	}
	fps1++;
}


uint32_t OLED_Pow(uint32_t X, uint32_t Y)
{
	uint32_t Result = 1;
	while (Y--)
	{
		Result *= X;
	}
	return Result;
}



void OLED_ShowNum(u8 Line, u8 Column, uint32_t Number, u8 Length)
{
    char buffer[Length + 1]; 
    u8 index = Length - 1;

    for (u8 i = 0; i < Length; i++)
    {
        buffer[index--] = (Number % 10) + '0';
        Number /= 10;
    }

    buffer[Length] = '\0';

    u8 show = 0;
    for (u8 i = 0; i < Length; i++)
    {
        if (buffer[i] != '0' || show || i == Length - 1)
        {
            OLED_ShowChar(Line, Column + i, buffer[i]);
            show = 1; 
        }
        else
        {
            OLED_ShowChar(Line, Column + i, ' ');
        }
    }
    fps1++;
}




void OLED_ShowSignedNum(u8 Line, u8 Column, int32_t Number, u8 Length)
{
	u8 i;
	uint32_t Number1;
	if (Number >= 0)
	{
		OLED_ShowChar(Line, Column, '+');
		Number1 = Number;
	}
	else
	{
		OLED_ShowChar(Line, Column, '-');
		Number1 = -Number;
	}
	for (i = 0; i < Length; i++)							
	{
		OLED_ShowChar(Line, Column + i + 1, Number1 / OLED_Pow(10, Length - i - 1) % 10 + '0');
	}
	fps1++;
}


void OLED_ShowHexNum(u8 Line, u8 Column, uint32_t Number, u8 Length)
{
	u8 i, SingleNumber;
	for (i = 0; i < Length; i++)							
	{
		SingleNumber = Number / OLED_Pow(16, Length - i - 1) % 16;
		if (SingleNumber < 10)
		{
			OLED_ShowChar(Line, Column + i, SingleNumber + '0');
		}
		else
		{
			OLED_ShowChar(Line, Column + i, SingleNumber - 10 + 'A');
		}
	}
	fps1++;
}


void OLED_ShowBinNum(u8 Line, u8 Column, uint32_t Number, u8 Length)
{
	u8 i;
	for (i = 0; i < Length; i++)							
	{
		OLED_ShowChar(Line, Column + i, Number / OLED_Pow(2, Length - i - 1) % 2 + '0');
	}
	fps1++;
}



/************多界面***********************************************************/
#include <functional>

using namespace std;

static constexpr u8 OLED_MAX_KEY_LEN = 20;
static constexpr u8 OLED_MAX_KEYS = 128;


static KeyMap keyMap_OLED[OLED_MAX_KEYS];
static u32 keyCount_OLED = 0;
static u32 hasRun_OLED[OLED_MAX_KEYS];


static constexpr u8 OLED_MAX_INTERFACES = 10;

static function<void()> OLED_Interfaces[OLED_MAX_INTERFACES] = {};
static u8 OLED_Current_Interface = 0; 


u32 Get_Key_OLED(const char* key) 
{
    for (u32 i = 0; i < keyCount_OLED; i++)  if (strcmp(keyMap_OLED[i].key, key) == 0)  return keyMap_OLED[i].id;

    if (keyCount_OLED < OLED_MAX_KEYS) 
	{
        strncpy(keyMap_OLED[keyCount_OLED].key, key, OLED_MAX_KEY_LEN - 1);
        keyMap_OLED[keyCount_OLED].key[OLED_MAX_KEY_LEN - 1] = '\0';
        keyMap_OLED[keyCount_OLED].id = keyCount_OLED;
        return keyCount_OLED++;
    }

    return -1; 
}



#define OLED_Create_Interface(key, interface)                   \
    {                                                           \
        u8 id = Get_Key_OLED(key);                             \
        if (id < OLED_MAX_INTERFACES)                           \
        {                                                       \
            OLED_Interfaces[id] = []() { interface; };          \
        }                                                       \
    }

void OLED_Interface_Replace(u8 id)
{
	static u8 last_id = 0;

    if (id != last_id && id < OLED_MAX_INTERFACES && OLED_Interfaces[id])
    {	
        OLED_Clear();
        OLED_Current_Interface = id;
    }
    OLED_Interfaces[OLED_Current_Interface]();
	last_id = id;
}





















void OLED_ON()
{
	OLED_WriteCommand(0X8D);  //设置电荷泵
	OLED_WriteCommand(0X14);  //开启电荷泵
	OLED_WriteCommand(0XAF);  //OLED唤醒
}

void OLED_OFF()
{
	OLED_WriteCommand(0X8D);  //设置电荷泵
	OLED_WriteCommand(0X10);  //关闭电荷泵
	OLED_WriteCommand(0XAE);  //OLED休眠
}





void OLED_Init()
{
	OLED_IIC_Init();			//端口初始化
	
	OLED_WriteCommand(0xAE);	//关闭显示
	
	OLED_WriteCommand(0xD5);	//设置显示时钟分频比/振荡器频率
	OLED_WriteCommand(0x80);
	
	OLED_WriteCommand(0xA8);	//设置多路复用率
	OLED_WriteCommand(0x3F);
	
	OLED_WriteCommand(0xD3);	//设置显示偏移
	OLED_WriteCommand(0x00);
	
	OLED_WriteCommand(0x40);	//设置显示开始行
	
	OLED_WriteCommand(0xA1);	//设置左右方向，0xA1正常 0xA0左右反置
	
	OLED_WriteCommand(0xC8);	//设置上下方向，0xC8正常 0xC0上下反置

	OLED_WriteCommand(0xDA);	//设置COM引脚硬件配置
	OLED_WriteCommand(0x12);
	
	OLED_WriteCommand(0x81);	//设置对比度控制
	OLED_WriteCommand(0xCF);

	OLED_WriteCommand(0xD9);	//设置预充电周期
	OLED_WriteCommand(0xF1);

	OLED_WriteCommand(0xDB);	//设置VCOMH取消选择级别
	OLED_WriteCommand(0x30);

	OLED_WriteCommand(0xA4);	//设置整个显示打开/关闭

	OLED_WriteCommand(0xA6);	//设置正常/倒转显示

	OLED_WriteCommand(0x8D);	//设置充电泵
	OLED_WriteCommand(0x14);

	OLED_WriteCommand(0xAF);	//开启显示
		
	OLED_Clear();				//OLED清屏
}
 