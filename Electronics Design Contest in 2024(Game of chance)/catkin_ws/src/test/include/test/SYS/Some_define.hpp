#pragma once

#include "stdint.h"


typedef int8_t  i8;
typedef uint8_t u8;

typedef int16_t  i16;
typedef uint16_t u16;

typedef int32_t  i32;
typedef uint32_t u32;

typedef int64_t  i64;
typedef uint64_t u64;

typedef float   f32;
typedef double  f64;



static u8 hasRun[8]; // 最大使用

#define RUN_ONCE(num, statement) if(!hasRun[num]) { statement; hasRun[num] = 1; };


#define RESET(num) {hasRun[num] = 0;};



