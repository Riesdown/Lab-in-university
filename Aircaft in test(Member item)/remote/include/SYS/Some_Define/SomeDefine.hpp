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



#define GPIO_WRITE_BIT1(value, pin) \
    *(volatile unsigned int*)(value ? GPIO_OUT_W1TS_REG : GPIO_OUT_W1TC_REG) = (1 << pin);

#define GPIO_READ_BIT1(pin) \
    ((*(volatile unsigned int*)GPIO_IN_REG & (1 << pin)) != 0)



#define MAP(x, in_min, in_max, out_min, out_max) \
    ((x) <= (in_min) ? (out_min) : ((x) >= (in_max) ? (out_max) : ((out_min) + ((x) - (in_min)) * (float)((out_max) - (out_min)) / (float)((in_max) - (in_min)))))


#define MAP_(value, min, mid, max, range_min, range_max) \
    ({ \
        f32 _value = (value); \
        double _min = (min); \
        double _mid = (mid); \
        double _max = (max); \
        double _range_min = (range_min); \
        double _range_max = (range_max); \
        double _result = 0; \
        \
        if (_value < _min) _value = _min; \
        if (_value > _max) _value = _max; \
        \
        if (_value < _mid) \
            _result = (_value - _mid) * (_range_min / (_mid - _min)); \
        else \
            _result = (_value - _mid) * (_range_max / (_max - _mid)); \
        \
        _result; \
    })



/************哈希初始化*********************************************************/
#define MAX_KEYS 128
#define MAX_KEY_LEN 32

typedef struct 
{
    char key[MAX_KEY_LEN];
    u32 id;
} KeyMap;

/************RUNONCE***********************************************************/
static KeyMap keyMap_RUNONCE[MAX_KEYS];
static u32 keyCount_RUNONCE = 0;
static u32 hasRun_RUNONCE[MAX_KEYS];


u32 Get_Key_RUNONCE(const char* key) 
{
    for (u32 i = 0; i < keyCount_RUNONCE; i++)     if (strcmp(keyMap_RUNONCE[i].key, key) == 0)     return keyMap_RUNONCE[i].id;

    if (keyCount_RUNONCE < MAX_KEYS) 
    {
        strncpy(keyMap_RUNONCE[keyCount_RUNONCE].key, key, MAX_KEY_LEN - 1);
        keyMap_RUNONCE[keyCount_RUNONCE].key[MAX_KEY_LEN - 1] = '\0';
        keyMap_RUNONCE[keyCount_RUNONCE].id = keyCount_RUNONCE;
        return keyCount_RUNONCE++;
    }

    return -1; 
}

#define RUN_ONCE_STR(key, statement) \
    do { \
        int id = Get_Key_RUNONCE(key); \
        if (id >= 0 && !hasRun_RUNONCE[id]) { \
            statement; \
            hasRun_RUNONCE[id] = 1; \
        } \
    } while (0)

#define RESET_STR(key) \
    do { \
        int id = Get_Key_RUNONCE(key); \
        if (id >= 0) { \
            hasRun_RUNONCE[id] = 0; \
        } \
    } while (0)

/************环形缓冲区*********************************************************/
#define MAX_BUFFER_SIZE 512


typedef struct {
    char key[MAX_KEY_LEN];
    u32 id;
    u8 buffer[MAX_BUFFER_SIZE];
    u32 size;
    volatile u32 writeIndex;
    volatile u32 readIndex;
} RingBuffer;

static RingBuffer keyMap_RINGBUFFER[MAX_KEYS];
static u32 keyCount_RINGBUFFER = 0;

#define INCREMENT_INDEX(index, max_size) \
    do { \
        (index) = ((index) + 1) % (max_size); \
    } while (0)

i32 GET_KEY_RINGBUFFER(const char *key) 
{
    i32 result = -1;

    for (u32 i = 0; i < keyCount_RINGBUFFER; i++) 
    {
        if (strcmp(keyMap_RINGBUFFER[i].key, key) == 0) 
        {
            result = i; 
            break;
        }
    }

    if (result == -1 && keyCount_RINGBUFFER < MAX_KEYS) 
    {
        strncpy(keyMap_RINGBUFFER[keyCount_RINGBUFFER].key, key, MAX_KEY_LEN - 1);
        keyMap_RINGBUFFER[keyCount_RINGBUFFER].key[MAX_KEY_LEN - 1] = '\0';  
        keyMap_RINGBUFFER[keyCount_RINGBUFFER].id = keyCount_RINGBUFFER;  
        keyMap_RINGBUFFER[keyCount_RINGBUFFER].size = 0;  
        keyMap_RINGBUFFER[keyCount_RINGBUFFER].writeIndex = 0; 
        keyMap_RINGBUFFER[keyCount_RINGBUFFER].readIndex = 0; 
        result = keyCount_RINGBUFFER++;  
    }

    return result;
}

#define SET_RINGBUFFER(key, size1) \
    do { \
        u32 keyId = GET_KEY_RINGBUFFER(key); \
        if (keyId != -1 && size1 <= MAX_BUFFER_SIZE) { \
            keyMap_RINGBUFFER[keyId].size = size1; \
            keyMap_RINGBUFFER[keyId].writeIndex = 0; \
            keyMap_RINGBUFFER[keyId].readIndex = 0; \
        } \
    } while (0)

#define CLEAR_RINGBUFFER(key) \
    do { \
        u32 keyId = GET_KEY_RINGBUFFER(key); \
        if (keyId != -1) { \
            keyMap_RINGBUFFER[keyId].writeIndex = 0; \
            keyMap_RINGBUFFER[keyId].readIndex = 0; \
        } \
    } while (0)

#define PUSH_RINGBUFFER(key, data, size1) \
    do { \
        u32 keyId = GET_KEY_RINGBUFFER(key); \
        if (keyId == -1 || keyMap_RINGBUFFER[keyId].size == 0) break; \
        RingBuffer* ringBuffer = &keyMap_RINGBUFFER[keyId]; \
        for (u32 i = 0; i < size1; i++) { \
            ringBuffer->buffer[ringBuffer->writeIndex] = (data)[i]; \
            INCREMENT_INDEX(ringBuffer->writeIndex, ringBuffer->size); \
            if (ringBuffer->writeIndex == ringBuffer->readIndex) { \
                INCREMENT_INDEX(ringBuffer->readIndex, ringBuffer->size); \
            } \
        } \
    } while (0)

#define POP_RINGBUFFER(key, data, size1) \
    do { \
        u32 keyId = GET_KEY_RINGBUFFER(key); \
        if (keyId == -1 || keyMap_RINGBUFFER[keyId].size == 0) break; \
        RingBuffer* ringBuffer = &keyMap_RINGBUFFER[keyId]; \
        for (u32 i = 0; i < size1; i++) { \
            if (ringBuffer->readIndex == ringBuffer->writeIndex) break; \
            (data)[i] = ringBuffer->buffer[ringBuffer->readIndex]; \
            INCREMENT_INDEX(ringBuffer->readIndex, ringBuffer->size); \
        } \
    } while (0)
