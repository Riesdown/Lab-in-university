#include "test/SYS/Some_define.hpp"
#include <cmath>
#include <deque>
#include "ros/ros.h"





class POS_CLOSE
{
    private:
        u16 _w, _h;
        f32 _w_ture, _h_ture;



    public:
        POS_CLOSE(u16 w, u16 h, f32 w_ture, f32 h_ture);
        std::pair<f32, f32> XY_Convert(f32 ca_x, f32 ca_y, f32 current_x, f32 current_y, u8 mode);
};


POS_CLOSE::POS_CLOSE(u16 w, u16 h, f32 w_ture, f32 h_ture):
    _w(w), _h(h), _w_ture(w_ture), _h_ture(h_ture)
{

}





// w_ture(m)  speed(m / s) 
std::pair<f32, f32> POS_CLOSE::XY_Convert(f32 ca_x, f32 ca_y, f32 current_x, f32 current_y, u8 mode) 
{
    ros::WallDuration(0.1).sleep(); 

    f32 flight_x = (ca_x / _w) * _w_ture;
    f32 flight_y = (ca_y / _h) * _h_ture;

    static f32 radio = 1;
    f32 target_x, target_y;
    if(mode == 1)
    {
        target_x = current_x - flight_y * radio;
        target_y = current_y - flight_x * radio;
    }

    return std::make_pair(target_x, target_y);
}

