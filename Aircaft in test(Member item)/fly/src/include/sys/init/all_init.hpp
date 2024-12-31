#pragma once

#include <hw/attitude/data/data.hpp>
#include "app/pid/pid.hpp"

using namespace ATTITUDE_DATA;
/*********初始化***************************************************************************************************************************************************************** */

/*****串口调试********/
#include <app/debug/serial/debug.hpp>
extern SERIAL_DEBUG serial_bebug;


/*****GY901S陀螺仪********/
#include <hw/attitude/gy910s/gy910s.hpp>


extern GY901S<NINE_AXIS_DATA> gy901s;

/*****串口********/
#include <ptc/serial/serial.hpp>

extern SERIAL_WORK serial_work;
/*****HEX********/
#include <app/hex/hex.hpp>

extern HEX_CONTROL hex_control;

/*****遥控数据读取方式********/
#include <ptc/serial/serial.hpp>

extern SERIAL_WORK remote_work;

#define GET_REMOTE_DATA(buff, len)  remote_work.GetBinaryData(buff, len)

/*****PID********/
extern PID pid_roll;
extern PID pid_pitch;
extern PID pid_yaw;


extern PID pid_gx;
extern PID pid_gy;
extern PID pid_gz;

/*****UDP********/
#include <app/udp/udp.hpp>
#include <app/wifi/wifi.hpp>


extern THEUDP udp;
extern THEWIFI wifi;

/*********变量***************************************************************************************************************************************************************** */

/*****pid********/
struct PID_DATA
{
    f64 roll_p, roll_i, roll_d;
    f64 pitch_p, pitch_i, pitch_d;
    f64 yaw_p, yaw_i, yaw_d;    

    f64 gx_p, gx_i, gx_d;
    f64 gy_p, gy_i, gy_d;
    f64 gz_p, gz_i, gz_d;
};
extern PID_DATA pid_data;

/*****实时的角度值********/
extern ANGLE gy901s_angle;

/*****实时的9轴数据********/
extern NINE_AXIS_DATA gy901s_nine_axis_data;

// /*****实时的预测位置********/
// extern POSITION position_now;

/*****实时获取到的遥控数据********/
#include "work/remote/fun.hpp"

extern GET_DATA::REMOTE_ALL remote_all;


/*****电机********/
#include "hw/motor/brushless/motor.hpp"
#include "hw/motor/create.hpp"

extern array<BL_MOTOR, 4> motor_all;

/*****pid控制 -v1********/
#include "work/motor/fun.hpp"

using namespace CONTROL;

extern PID_CONTROL_V1<ANGLE, NINE_AXIS_DATA, PID> motor_pid_v1;


/*****MPU数据缓冲区********/
#include "app/circularbuffer/circularbuffer.hpp"
extern CIRCULAR_BUFFER<u8, 1024>  mpu_data_buffer;

/*****遥控器数据缓冲区********/
extern CIRCULAR_BUFFER<u8, 1024>  remote_data_buffer;

/*********外部调用***************************************************************************************************************************************************************** */

void All_Init();



