#pragma once

#include <Arduino.h>
#include <cmath> 
#include <sys/some_define/define.hpp>


template <typename angle>
class QUATERNION
{
    public:
        // 数据读取时间间隔
        QUATERNION(f64 dt);

        // 获取角度
        angle Get_Angle(f64 gx, f64 gy, f64 gz);

        // 重置
        void Reset();

    private:
        f64 quaternion[4]; 
        f64 _dt;
};

