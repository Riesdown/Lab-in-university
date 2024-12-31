#include <sys/some_define/define.hpp>
#include <app/quaternion/quaternion.hpp>

template <typename angle>
QUATERNION<angle>::QUATERNION(f64 dt) : _dt(dt)
{
    quaternion[0] = 1.0; // w
    quaternion[1] = 0.0; // x
    quaternion[2] = 0.0; // y
    quaternion[3] = 0.0; // z
}


template <typename angle>
angle QUATERNION<angle>::Get_Angle(f64 gx, f64 gy, f64 gz)
{
    f64 norm = sqrt(gx * gx + gy * gy + gz * gz);
    static angle old_angle; 

    if (norm < 1e-8) return old_angle;  

    f64 theta = norm * _dt / 2.0; 
    f64 sinTheta = sin(theta);
    f64 dq[4] = 
    {
        cos(theta),               // dq_w
        sinTheta * (gx / norm),   // dq_x
        sinTheta * (gy / norm),   // dq_y
        sinTheta * (gz / norm)    // dq_z
    };


    f64 w = quaternion[0] * dq[0] - quaternion[1] * dq[1] - quaternion[2] * dq[2] - quaternion[3] * dq[3];
    f64 x = quaternion[0] * dq[1] + quaternion[1] * dq[0] + quaternion[2] * dq[3] - quaternion[3] * dq[2];
    f64 y = quaternion[0] * dq[2] - quaternion[1] * dq[3] + quaternion[2] * dq[0] + quaternion[3] * dq[1];
    f64 z = quaternion[0] * dq[3] + quaternion[1] * dq[2] - quaternion[2] * dq[1] + quaternion[3] * dq[0];

    f64 q_norm = sqrt(w * w + x * x + y * y + z * z);
    if (q_norm < 1e-8) 
    {
        quaternion[0] = 1.0; quaternion[1] = quaternion[2] = quaternion[3] = 0.0;
    }
    else
    {
        quaternion[0] = w / q_norm;
        quaternion[1] = x / q_norm;
        quaternion[2] = y / q_norm;
        quaternion[3] = z / q_norm;
    }


    angle angle1;
    angle1.roll = atan2(2.0 * (quaternion[0] * quaternion[1] + quaternion[2] * quaternion[3]),
                       1.0 - 2.0 * (quaternion[1] * quaternion[1] + quaternion[2] * quaternion[2]));
    f64 sin_pitch = 2.0 * (quaternion[0] * quaternion[2] - quaternion[3] * quaternion[1]);
    if (sin_pitch > 1.0) sin_pitch = 1.0;
    if (sin_pitch < -1.0) sin_pitch = -1.0;
    angle1.pitch = asin(sin_pitch);
    angle1.yaw = atan2(2.0 * (quaternion[0] * quaternion[3] + quaternion[1] * quaternion[2]),
                      1.0 - 2.0 * (quaternion[2] * quaternion[2] + quaternion[3] * quaternion[3]));

    if (angle1.pitch > M_PI / 2.0) angle1.pitch = M_PI / 2.0;
    if (angle1.pitch < -M_PI / 2.0) angle1.pitch = -M_PI / 2.0;

    angle1.roll *= 180.0 / M_PI;
    angle1.pitch *= 180.0 / M_PI;
    angle1.yaw *= 180.0 / M_PI;

    old_angle = angle1;
    return angle1;
}

template <typename angle>
void QUATERNION<angle>::Reset()
{
    quaternion[0] = 1.0; 
    quaternion[1] = 0.0; 
    quaternion[2] = 0.0; 
    quaternion[3] = 0.0; 
}