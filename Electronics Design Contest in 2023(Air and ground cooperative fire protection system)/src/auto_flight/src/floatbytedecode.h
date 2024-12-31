#ifndef FLOATBYTEDECODE_H
#define FLOATBYTEDECODE_H

#define BYTE0(dwTemp)       ( *( (char *)(&dwTemp)      ) )
#define BYTE1(dwTemp)       ( *( (char *)(&dwTemp) + 1) )
#define BYTE2(dwTemp)       ( *( (char *)(&dwTemp) + 2) )
#define BYTE3(dwTemp)       ( *( (char *)(&dwTemp) + 3) )


typedef struct 
{
    uint8_t buf[100];
    uint16_t cnt;
}_serialport_decode;

float invSqrt(float x);
float constrain_float(float amt,float low,float high);
void FloatToByte(float *FloatValue, unsigned char *Byte, unsigned char Subscript);
void ByteToFloat(unsigned char *Byte, unsigned char Subscript, float *FloatValue);


_serialport_decode NCLink_Send_Currrent_State(float userdata1  ,float userdata2,
                                float userdata3  ,float userdata4,
                                float userdata5  ,float userdata6,
                                float userdata7  ,float userdata8,
                                float userdata9  ,float userdata10,
                                float quality    ,
                                uint8_t byte0,
                                uint8_t byte1,
                                uint8_t byte2,
                                uint8_t byte3,
                                uint8_t byte4,
                                uint8_t byte5,
                                uint8_t byte6,
                                uint8_t byte7,
                                uint8_t update_flag,
                                uint8_t msg_id);

_serialport_decode Send_Navigation_Ctrl(uint16_t number,float x,float y,float z,uint8_t navmode,uint8_t frameid,uint32_t execution_time);
_serialport_decode Send_DIS_CMD(uint8_t move_flag,uint8_t move_order,uint16_t move_distance);


#endif




