
#include "hw/motor/brushless/motor.hpp"
#include "app/pid/pid.hpp"
#include <memory>
#include "fun.hpp"


using namespace CONTROL;
using namespace std;



template class PID_CONTROL<BL_MOTOR, PID_CONTROL_V1<ANGLE, NINE_AXIS_DATA, PID>>;



template <typename motor_type, typename pid_control_type>
PID_CONTROL<motor_type, pid_control_type>::PID_CONTROL(const array<motor_type, 4>& motor):
    _f_l(motor[0]), _f_r(motor[1]), _b_l(motor[2]), _b_r(motor[3])
{}



template <typename motor_type, typename pid_control_type>
void PID_CONTROL<motor_type, pid_control_type>::Raise_Debug()
{

}

template <typename motor_type, typename pid_control_type>
void PID_CONTROL<motor_type, pid_control_type>::Control_Plane(pid_control_type& control_data)
{
    // 角速度
    auto aim_gyro = control_data.aim_gyro;    auto now_gyro = control_data.now_gyro;
    // 姿态角
    auto aim_angle = control_data.aim_angle;  auto now_angle = control_data.now_angle;
    
    // PID 控制
    gx_aim = control_data.pid_roll.Get_Output_Pos(aim_angle.roll - now_angle.roll, 0.5);
    roll_pwm = control_data.pid_gx.Get_Output_Pos(-gx_aim + now_gyro.gx, 0.01);
    // roll_pwm = control_data.pid_gx.Get_Output_Inc(-gx_aim + now_gyro.gx) + gx_aim;

    gy_aim = control_data.pid_pitch.Get_Output_Pos(aim_angle.pitch - now_angle.pitch, 0.5);
    pitch_pwm = control_data.pid_gy.Get_Output_Pos(-gy_aim + now_gyro.gy, 0.01);
    // pitch_pwm = control_data.pid_gy.Get_Output_Inc(-gy_aim + now_gyro.gy) + gy_aim;

    gz_aim = control_data.pid_yaw.Get_Output_Pos(aim_angle.yaw - now_angle.yaw, 0.5);
    yaw_pwm = control_data.pid_gz.Get_Output_Pos(-gz_aim + now_gyro.gz, 0.01);
    // yaw_pwm = control_data.pid_gz.Get_Output_Inc(-gz_aim + now_gyro.gz) + gz_aim;

    // 油门控制
    front_l_power = control_data.power / 4 - roll_pwm - pitch_pwm + yaw_pwm; 
    front_r_power = control_data.power / 4 + roll_pwm - pitch_pwm - yaw_pwm;
    back_l_power = control_data.power / 4 - roll_pwm + pitch_pwm - yaw_pwm; 
    back_r_power = control_data.power / 4 + roll_pwm + pitch_pwm + yaw_pwm;


    // 限幅
    front_l_power = constrain(front_l_power, 0, power / 2);
    back_l_power = constrain(back_l_power, 0, power / 2);
    front_r_power = constrain(front_r_power, 0, power / 2);
    back_r_power = constrain(back_r_power, 0, power / 2);

    _f_l.Set_Power(front_l_power);  
    _f_r.Set_Power(back_l_power);  
    _b_l.Set_Power(front_r_power);
    _b_r.Set_Power(back_r_power);  

    // 调试
    Raise_Debug();
}


