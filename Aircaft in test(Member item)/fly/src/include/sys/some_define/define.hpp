#pragma once


#include "stdint.h"
#include <Arduino.h>
#include <string.h>

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef double f64;

typedef int8_t  i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;


// 写 01
void GPIO_Write_Bit(u8 value, u8 pin) ;

// 读 01
u8 GPIO_Read_Bit(u8 pin) ;

// 数据映射
f64 MAP(f64 x, f64 in_min, f64 in_max, f64 out_min, f64 out_max) ;


