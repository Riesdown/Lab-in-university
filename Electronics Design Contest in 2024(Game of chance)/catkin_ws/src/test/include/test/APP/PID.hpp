#pragma once

class PID 
{
    private:
        double Kp;
        double Ki;
        double Kd;
        double integral;
        double prevError;
        double setpoint;
        double feedback;

    public:
        PID(double kp, double ki, double kd);                                   //设置PID参数
        double ComputePID(double setpoint, double measuredValue, double dt);    //计算PID输出
        double ComputePI(double setpoint, double measuredValue, double dt);     //计算PI输出
        double ComputePD(double setpoint, double measuredValue, double dt);     //计算PD输出
        void Set_PID(double kp, double ki, double kd);                          //重新设置PID参数
        void Clear();                                                           //清除积分项和误差项
};







PID::PID(double kp, double ki, double kd)
    : Kp(kp), Ki(ki), Kd(kd), integral(0), prevError(0) {}

double PID::ComputePID(double setpoint, double measuredValue, double dt) 
{
    double error = setpoint - measuredValue;
    integral += error * dt;
    double derivative = (error - prevError) / dt;
    prevError = error;
    return Kp * error + Ki * integral + Kd * derivative;
}

double PID::ComputePI(double setpoint, double measuredValue, double dt)
{
    double error = setpoint - measuredValue;
    integral += error * dt;
    prevError = error;
    return Kp * error + Ki * integral;
}

double PID::ComputePD(double setpoint, double measuredValue, double dt)
{
    double error = setpoint - measuredValue;
    double derivative = (error - prevError) / dt;
    prevError = error;
    return Kp * error + Kd * derivative;
}

void PID::Set_PID(double kp, double ki, double kd)
{
    Kp = kp;
    Ki = ki;
    Kd = kd;
}

void PID::Clear()
{
    integral = 0;
    prevError = 0;
}
