#include "app/pid/pid.hpp"
#include <sys/some_define/define.hpp>


PID::PID(f64 p, f64 i, f64 d, f64 in_min, f64 in_max, f64 out_min, f64 out_max):
    _p(p), _i(i), _d(d), _in_min(in_min), _in_max(in_max), _out_min(out_min), _out_max(out_max)

{}



PID::PID(f64 p, f64 i, f64 d):
    _p(p), _i(i), _d(d)
{}


void PID::Set_Out_Range(f64 out_min, f64 out_max)
{
    _out_min = out_min;
    _out_max = out_max;
}


f64 PID::Get_Output_Pos(f64 error, f64 integral_threshold)
{
    f64 error_later;
    if (_in_max) error_later = MAP(error, _in_min, _in_max, _out_min, _out_max);
    else error_later = error;

    if (fabs(error_later) > integral_threshold) _integral += error_later;
    else _integral *= 0.9;

    _integral = constrain(_integral, _out_min, _out_max);

    f64 derivative = error_later - _previous_error;

    f64 output = _p * error_later + _d * derivative + _i * _integral;

    _previous_error = error_later;

    return output;
}


f64 PID::Get_Output_Inc(f64 error)
{
    f64 error_later;
    if (_in_max) 
        error_later = MAP(error, _in_min, _in_max, _out_min, _out_max);

    f64 delta_error = error_later - _previous_error;
    f64 delta_u = _p * delta_error + 
                  _i * error_later + 
                  _d * (delta_error - _previous_delta_error);

    _previous_delta_error = delta_error;
    _previous_error = error_later;

    return delta_u;
}


void PID::ReSet(f64 kp, f64 ki, f64 kd)
{
    _p = kp;
    _i = ki;
    _d = kd;

    Clear();
}


void PID::Clear()
{
    _previous_error = 0;
    _previous_delta_error = 0;
    _integral = 0;
}


void PID::Get_PID(f64 &kp, f64 &ki, f64 &kd)
{
    kp = _p;
    ki = _i;
    kd = _d;
}

