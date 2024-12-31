#pragma once

#include <Arduino.h>
#include <sys/some_define/define.hpp>


class PID
{

    private:
        f64 _previous_error, _previous_delta_error;
        f64 _p, _i, _d;

        f64 _in_min, _in_max, _out_min, _out_max;
        f64 _integral;
    public:
        // PID参数 + 数据数据的范围 + 输出范围
        PID(f64 p, f64 i, f64 d, f64 in_min, f64 in_max, f64 out_min, f64 out_max);
        
        // PID参数
        PID(f64 p, f64 i, f64 d);

        // 默认
        PID() {};

        // 位置式PID + 积分项抗饱和 + 积分分离
        f64 Get_Output_Pos(f64 error, f64 integral_threshold);

        // 增量式PID
        f64 Get_Output_Inc(f64 error);

        // 重新设置PID参数
        void ReSet(f64 kp, f64 ki, f64 kd);

        // 清除PID计算
        void Clear();

        // 获取PID参数
        void Get_PID(f64 &kp, f64 &ki, f64 &kd);

        // 重新设置输出范围
        void Set_Out_Range(f64 out_min, f64 out_max);
};

