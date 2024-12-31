#include <iostream>
#include <cstring>
#include "datatf.h"


using namespace std;

static uint8_t nclink_databuf[100];

_serialport_decode nclink_buf;

union
{
	unsigned char floatByte[4];
	float floatValue;
}FloatUnion;

static uint8_t NCLink_Head[2]={0xFC,0xFF};//数据帧头
static uint8_t NCLink_End[2] ={0xA1,0xA2};//数据帧尾


/***************************************************************************************
@函数名：void Float2Byte(float *FloatValue, unsigned char *Byte, unsigned char Subscript)
@入口参数：FloatValue:float值
			     Byte:数组
		       Subscript:指定从数组第几个元素开始写入
@出口参数：无
功能描述：将float数据转成4字节数据并存入指定地址
@作者：无名小哥
@日期：2020年01月17日
****************************************************************************************/
void Float2Byte(float *FloatValue, unsigned char *Byte, unsigned char Subscript)
{
	FloatUnion.floatValue = (float)2;
	if(FloatUnion.floatByte[0] == 0)//小端模式
	{
		FloatUnion.floatValue = *FloatValue;
		Byte[Subscript]     = FloatUnion.floatByte[0];
		Byte[Subscript + 1] = FloatUnion.floatByte[1];
		Byte[Subscript + 2] = FloatUnion.floatByte[2];
		Byte[Subscript + 3] = FloatUnion.floatByte[3];
	}
	else//大端模式
	{
		FloatUnion.floatValue = *FloatValue;
		Byte[Subscript]     = FloatUnion.floatByte[3];
		Byte[Subscript + 1] = FloatUnion.floatByte[2];
		Byte[Subscript + 2] = FloatUnion.floatByte[1];
		Byte[Subscript + 3] = FloatUnion.floatByte[0];
	}
}


/***************************************************************************************
@函数名：void Byte2Float(unsigned char *Byte, unsigned char Subscript, float *FloatValue)
@入口参数：Byte:数组
			     Subscript:指定从数组第几个元素开始写入
		       FloatValue:float值
@出口参数：无
功能描述：从指定地址将4字节数据转成float数据
@作者：无名小哥
@日期：2020年01月17日
****************************************************************************************/
void Byte2Float(unsigned char *Byte, unsigned char Subscript, float *FloatValue)
{
	FloatUnion.floatByte[0]=Byte[Subscript];
	FloatUnion.floatByte[1]=Byte[Subscript + 1];
	FloatUnion.floatByte[2]=Byte[Subscript + 2];
	FloatUnion.floatByte[3]=Byte[Subscript + 3];
	*FloatValue=FloatUnion.floatValue;
}

float constrain_float(float amt,float low,float high)
{
	return ((amt)<(low)?(low):((amt)>(high)?(high):(amt)));
}


//快速开方倒数函数
float invSqrt(float x)
{
  float halfx = 0.5f * x;
  float y = x;
  long i = *(long*)&y;  
  i = 0x5f3759df - (i>>1);
  y = *(float*)&i;
  y = y * (1.5f - (halfx * y * y));
  return y;
}



//ROS发送SLAM定位的位姿态数据给飞控
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
                                uint8_t msg_id)

{
    uint8_t sum=0,cnt=0,i=0;
    nclink_databuf[cnt++]=NCLink_Head[0];
    nclink_databuf[cnt++]=NCLink_Head[1];
    nclink_databuf[cnt++]=msg_id;
    nclink_databuf[cnt++]=0;
    Float2Byte(&userdata1,nclink_databuf,cnt);//position.x
    cnt+=4;
    Float2Byte(&userdata2,nclink_databuf,cnt);//position.y
    cnt+=4;
    Float2Byte(&userdata3,nclink_databuf,cnt);//position.z
    cnt+=4;
    Float2Byte(&userdata4,nclink_databuf,cnt);//velocity.x
    cnt+=4;
    Float2Byte(&userdata5,nclink_databuf,cnt);//velocity.y
    cnt+=4;
    Float2Byte(&userdata6,nclink_databuf,cnt);//velocity.z
    cnt+=4;
    Float2Byte(&userdata7,nclink_databuf,cnt);//quaternion.x
    cnt+=4;
    Float2Byte(&userdata8,nclink_databuf,cnt);//quaternion.y
    cnt+=4;
    Float2Byte(&userdata9,nclink_databuf,cnt);//quaternion.z
    cnt+=4;//28
    Float2Byte(&userdata10,nclink_databuf,cnt);//quaternion.w
    cnt+=4;//32
    Float2Byte(&quality,nclink_databuf,cnt);//quality
    cnt+=4;//32
    nclink_databuf[cnt++]=byte0;//预留的8个字节数据
    nclink_databuf[cnt++]=byte1;
    nclink_databuf[cnt++]=byte2;
    nclink_databuf[cnt++]=byte3;
    nclink_databuf[cnt++]=byte4;
    nclink_databuf[cnt++]=byte5;
    nclink_databuf[cnt++]=byte6;
    nclink_databuf[cnt++]=byte7;
    nclink_databuf[cnt++]=update_flag;//更新标志位
    nclink_databuf[3] = cnt-4;
    for(i=0;i<cnt;i++) sum ^= nclink_databuf[i]; 
    nclink_databuf[cnt++]=sum;
    nclink_databuf[cnt++]=NCLink_End[0];
    nclink_databuf[cnt++]=NCLink_End[1];

	memcpy(nclink_buf.buf,nclink_databuf,cnt*sizeof(uint8_t));
	nclink_buf.cnt=cnt;
	return nclink_buf;
}


_serialport_decode Send_Navigation_Ctrl(uint16_t number,float x,float y,float z,uint8_t navmode,uint8_t frameid,uint32_t execution_time)//地面站指令发送移动距离数据
{
  uint8_t sum = 0,i=0,cnt=0;
  uint16_t _temp;
  nclink_databuf[cnt++]=NCLink_Head[0];
  nclink_databuf[cnt++]=NCLink_Head[1];
  nclink_databuf[cnt++]=0x0F;
  nclink_databuf[cnt++]=0;

  _temp = number;
  nclink_databuf[cnt++]=BYTE1(_temp);
  nclink_databuf[cnt++]=BYTE0(_temp);

  Float2Byte(&x,nclink_databuf,cnt);
  cnt+=4;
  Float2Byte(&y,nclink_databuf,cnt);
  cnt+=4;
  Float2Byte(&z,nclink_databuf,cnt);
  cnt+=4;

  nclink_databuf[cnt++]=navmode;
  nclink_databuf[cnt++]=frameid;

  uint32_t tmp = execution_time;
  nclink_databuf[cnt++]=BYTE3(tmp);
  nclink_databuf[cnt++]=BYTE2(tmp);
  nclink_databuf[cnt++]=BYTE1(tmp);
  nclink_databuf[cnt++]=BYTE0(tmp);
  
  nclink_databuf[3] = cnt-4;
  for(i=0;i<cnt;i++) sum ^= nclink_databuf[i];
  nclink_databuf[cnt++]=sum;
  nclink_databuf[cnt++]=NCLink_End[0];;
  nclink_databuf[cnt++]=NCLink_End[1];;
  memcpy(nclink_buf.buf,nclink_databuf,cnt*sizeof(uint8_t));
  nclink_buf.cnt=cnt;
  return nclink_buf;
}


_serialport_decode Send_DIS_CMD(uint8_t move_flag,uint8_t move_order,uint16_t move_distance)//地面站指令发送移动距离数据
{
  uint8_t sum = 0,i=0,cnt=0;
  uint16_t _temp;
  nclink_databuf[cnt++]=NCLink_Head[0];
  nclink_databuf[cnt++]=NCLink_Head[1];
  nclink_databuf[cnt++]=0x0A;
  nclink_databuf[cnt++]=0;

  nclink_databuf[cnt++]=BYTE0(move_flag);
  nclink_databuf[cnt++]=BYTE0(move_order);

  _temp = move_distance;
  nclink_databuf[cnt++]=BYTE1(_temp);
  nclink_databuf[cnt++]=BYTE0(_temp);

  nclink_databuf[3] = cnt-4;
  for(i=0;i<cnt;i++) sum ^= nclink_databuf[i];
  nclink_databuf[cnt++]=sum;
  nclink_databuf[cnt++]=NCLink_End[0];;
  nclink_databuf[cnt++]=NCLink_End[1];;
  memcpy(nclink_buf.buf,nclink_databuf,cnt*sizeof(uint8_t));
  nclink_buf.cnt=cnt;
  return nclink_buf;
}