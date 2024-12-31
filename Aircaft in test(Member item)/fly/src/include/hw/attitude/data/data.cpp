#include <sys/some_define/define.hpp>
#include "hw/attitude/data/data.hpp"

using namespace ATTITUDE_DATA;


void Get_Line_Speed(const NINE_AXIS_DATA& data, SPEED& speed, u64& last_time) 
{
    u64 current_time = millis();
    f32 dt = (current_time - last_time) / 1000.0f;

    if (dt > 0) 
    {
        speed.vx += data.ax * dt;
        speed.vy += data.ay * dt;
        speed.vz += data.az * dt;

        last_time = current_time;
    }
}