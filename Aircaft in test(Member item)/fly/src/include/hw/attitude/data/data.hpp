#pragma once


#include <sys/some_define/define.hpp>

#include <iostream>
#include <chrono>


namespace ATTITUDE_DATA
{
    struct NINE_AXIS_DATA
    {
        f32 gx, gy, gz;
        f32 ax, ay, az;
        f32 mx, my, mz;
    };


    struct Quaternion
    {
        f32 w, x, y, z;
    };

    struct SPEED
    {
        f32 vx, vy, vz;
    };


    struct ANGLE
    {
        f32 roll, pitch, yaw;
    };

    struct POSITION
    {
        f32 x, y, z;
    };


}
using namespace ATTITUDE_DATA;

// 获取线速度
void Get_Line_Speed(const NINE_AXIS_DATA& data, SPEED& speed, u64& last_time) ;








