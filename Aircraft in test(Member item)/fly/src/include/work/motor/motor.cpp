#include "motor.hpp"
#include "fun.hpp"
#include "hw/motor/brushless/motor.hpp"
#include "app/pid/pid.hpp"
#include <sys/init/all_init.hpp>
#include "work/flag/flag.hpp"   
#include "vector"   


using namespace CONTROL;
using namespace std;





void Motor_Control(void *p) 
{

    PID_CONTROL<BL_MOTOR, PID_CONTROL_V1<ANGLE, NINE_AXIS_DATA, PID> > control(motor_all);

    vector<u8> stop_av;
    f64 stop_av_sum = 0;

    while (1) 
    {
        delay(10);

        stop_av.push_back(some_flag.stop_motor);
        if (stop_av.size() > 10) stop_av.erase(stop_av.begin());
        for (auto i : stop_av) stop_av_sum += i;
        stop_av_sum /= stop_av.size();

        if (stop_av_sum > 0.1)
        {
            motor_all[0].Set_Power(0);
            motor_all[1].Set_Power(0);
            motor_all[2].Set_Power(0);
            motor_all[3].Set_Power(0);
            continue;
        }


        /***************V1****************************************************************** */
        // 目标角度
        motor_pid_v1.aim_angle.pitch = 0;
        motor_pid_v1.aim_angle.roll = 0;
        motor_pid_v1.aim_angle.yaw = 0;

        // 目标角速度
        motor_pid_v1.aim_gyro.gx = 0;
        motor_pid_v1.aim_gyro.gy = 0;
        motor_pid_v1.aim_gyro.gz = 0;

        // 当前角度
        motor_pid_v1.now_angle.pitch = gy901s_angle.pitch;
        motor_pid_v1.now_angle.roll = gy901s_angle.roll;
        motor_pid_v1.now_angle.yaw = gy901s_angle.yaw;

        // 当前角速度
        motor_pid_v1.now_gyro.gx = gy901s_nine_axis_data.gx;
        motor_pid_v1.now_gyro.gy = gy901s_nine_axis_data.gy;
        motor_pid_v1.now_gyro.gz = gy901s_nine_axis_data.gz;

        // 当前油门
        motor_pid_v1.power = remote_all.power;

        // pid
        motor_pid_v1.pid_gx = pid_gx;
        motor_pid_v1.pid_gy = pid_gy;
        motor_pid_v1.pid_gz = pid_gz;

        motor_pid_v1.pid_pitch = pid_pitch;
        motor_pid_v1.pid_roll = pid_roll;
        motor_pid_v1.pid_yaw = pid_yaw;

        control.Control_Plane(motor_pid_v1);


    }
}
