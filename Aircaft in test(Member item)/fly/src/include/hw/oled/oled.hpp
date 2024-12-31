#pragma once

#include <sys/some_define/define.hpp>


extern u16 fps; 
extern u16 fps1; 

/********外部调用************************************************************** */
// 初始化
void OLED_Init();

// 显示帧率
void OLED_GetFPS();

// 显示帧率初始化
void OLED_GetFPS_Init();
	
// show BIN
void OLED_ShowBinNum(u8 Line, u8 Column, uint32_t Number, u8 Length);

// show HEX
void OLED_ShowHexNum(u8 Line, u8 Column, uint32_t Number, u8 Length);

// show SignedNum
void OLED_ShowSignedNum(u8 Line, u8 Column, int32_t Number, u8 Length);

// show unsignedNum
void OLED_ShowNum(u8 Line, u8 Column, uint32_t Number, u8 Length);

// 显示字符
void OLED_ShowString(u8 Line, u8 Column, char *String);

// open OLED
void OLED_ON();

// close OLED
void OLED_OFF();

// get key
u32 Get_Key_OLED(const char* key) ;


// create interface
#define OLED_Create_Interface(key, interface)                   \
    {                                                           \
        u8 id = Get_Key_OLED(key);                             \
        if (id < OLED_MAX_INTERFACES)                           \
        {                                                       \
            OLED_Interfaces[id] = []() { interface; };          \
        }                                                       \
    }

// replace interface
void OLED_Interface_Switch(u8 id);