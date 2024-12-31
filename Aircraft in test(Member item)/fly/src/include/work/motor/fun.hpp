#pragma once

#include <Arduino.h>
#include <array> 
#include <sys/some_define/define.hpp>
#include "hw/attitude/data/data.hpp"
#include "hw/motor/method/method.hpp"


using namespace std;
using namespace ATTITUDE_DATA;


namespace CONTROL 
{
    template <typename angle_type, typename g_type, typename pid_type>
    struct PID_CONTROL_V1
    {
        angle_type aim_angle;
        angle_type now_angle;

        g_type aim_gyro;
        g_type now_gyro;


        pid_type pid_roll, pid_pitch, pid_yaw;
        pid_type pid_gx, pid_gy, pid_gz;    

        u32 power;
    };

/*******************************************************************************************/

    template <typename motor_type, typename pid_control_type>
    class PID_CONTROL
    {
        private:
            motor_type _f_l, _f_r, _b_l, _b_r;

            // 调试用
            pid_control_type control_data;
            u32 power;
            f64 gx_aim, gy_aim, gz_aim;                 f64 gx_now, gy_now, gz_now;
            f64 roll_aim, pitch_aim, yaw_aim;           f64 roll_now, pitch_now, yaw_now;
            f64 roll_pwm, pitch_pwm, yaw_pwm; f64 front_l_power, front_r_power, back_l_power, back_r_power;


        private:
            // 上传调试信息
            void Raise_Debug();

        public:
            // 4个电机 
            PID_CONTROL(const array<motor_type, 4>& motor);

            // 飞机控制 - V1
            void Control_Plane(pid_control_type& control_data);
    };
}

