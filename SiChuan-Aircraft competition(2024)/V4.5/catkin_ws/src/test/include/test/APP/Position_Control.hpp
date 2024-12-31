#pragma once

using namespace std;

#include <geometry_msgs/PoseStamped.h>
#include <tf2/LinearMath/Quaternion.h>

#include "test/PTC/MyTopic.hpp"
#include "test/set_position.h"
#include "test/avoidant_date.h"

#include <cmath>
#include <deque>
#include <geometry_msgs/PoseStamped.h>
#include "test/PTC/MyTopic.hpp"
#include "test/APP/Debug.hpp"
#include "test/SYS/Some_define.hpp"


class POSITION_CONTROL
{
    private:
        test::set_position position_;
        test::avoidant_date avoidant_;

        MYTOPIC topic_send_positon; 
        MYTOPIC topic_send_avoidant; 
        MYTOPIC topic_send_angle;

        f32 _xy_zone;
        f32 _z_zone;

        // geometry_msgs::PoseStamped xyz; 

        MYTOPIC topic_getpx4_position;
        
        DEBUG debug;

        struct XYZ
        {
            f32 x;
            f32 y;
            f32 z;
        };
        XYZ xyz_str;

    void CallBack(const  geometry_msgs::PoseStamped::ConstPtr& msg);


    public:
        POSITION_CONTROL(f32 xy_zone = 0.2, f32 z_zone = 0.2);
        inline void Set_Z(f32 zz);
        inline void Set_XY(f32 xx, f32 yy);

        u8 Check_Z(f32 zz);
        u8 Check_XY(f32 xx, f32 yy);

        inline void Get_Position(f32& x, f32& y, f32& z);

        inline void Set_Avoidant_XY(f32 xx, f32 yy); 

        void Obstacle_Avoidance();

        u8 Go_To_Angle(f32 angle, f32 distance);

        f32 Get_Angle(f32 x1, f32 y1, f32 x2, f32 y2);
};





POSITION_CONTROL::POSITION_CONTROL(f32 xy_zone, f32 z_zone) :
    topic_send_positon("set_position", 10),
    topic_send_avoidant("set_avoidant", 10),
    topic_getpx4_position("mavros/local_position/pose",  10),
    topic_send_angle("/mavros/vision_pose/pose",  10),
    _xy_zone(xy_zone),
    _z_zone(z_zone)
{
    topic_getpx4_position.Get<geometry_msgs::PoseStamped>([this](const geometry_msgs::PoseStamped::ConstPtr& ptr) 
    {
        this->CallBack(ptr);
    });
}


void POSITION_CONTROL::CallBack(const  geometry_msgs::PoseStamped::ConstPtr& msg)
{
    xyz_str.x = msg->pose.position.x;
    xyz_str.y = msg->pose.position.y;
    xyz_str.z = msg->pose.position.z;

    // ROS_INFO("Get x: %f, y: %f, z: %f", xyz_str.x, xyz_str.y,  xyz_str.z);
}


inline void POSITION_CONTROL::Get_Position(f32& x, f32& y, f32& z)
{
    x = xyz_str.x;
    y = xyz_str.y;
    z = xyz_str.z;
}



inline void POSITION_CONTROL::Set_Avoidant_XY(f32 xx, f32 yy)
{
    avoidant_.x = xx;
    avoidant_.y = yy;

    topic_send_avoidant.Send(avoidant_);
}




inline void POSITION_CONTROL::Set_Z(f32 zz)
{
    position_.z = zz;

    topic_send_positon.Send(position_);
}


inline void POSITION_CONTROL::Set_XY(f32 xx, f32 yy)
{
    position_.x = xx;
    position_.y = yy;
    topic_send_positon.Send(position_);
}


u8 POSITION_CONTROL::Check_Z(f32 zz)
{
    deque<f32> pos_z; 

    Set_Z(zz);

    pos_z.push_back(xyz_str.z);

    if (pos_z.size() > 5)  pos_z.pop_front();

    f32 sum = 0;
    for (f32 val : pos_z)   sum += val - position_.z;

    f32 average = sum / pos_z.size();

    if( abs(average) < _z_zone)
    {
        // ROS_INFO("OK!!!");
        return 1;
    }
    else 
    {
        // ROS_INFO("Waiting...");
        return 0;

    }


}


u8 POSITION_CONTROL::Check_XY(f32 xx, f32 yy)
{
    static deque<XYZ> pos_xy; 

    Set_XY(xx, yy);

    XYZ current_pos = { xyz_str.x, xyz_str.y, 0.0};

    pos_xy.push_back(current_pos);

    if (pos_xy.size() > 5)  pos_xy.pop_front();

    f32 sum_x = 0;
    f32 sum_y = 0;

    for (const auto& val : pos_xy)
    {
        sum_x += val.x - position_.x;
        sum_y += val.y - position_.y;
    }

    f32 average_x = sum_x / pos_xy.size();
    f32 average_y = sum_y / pos_xy.size();

    if (abs(average_x) < _xy_zone && abs(average_y) < _xy_zone)
    {
        // ROS_INFO("OK!!!");
        return 1;
    }
    else 
    {
        // ROS_INFO("Waiting...");
        return 0;

    }
}


void POSITION_CONTROL::Obstacle_Avoidance()
{
    


}

u8 POSITION_CONTROL::Go_To_Angle(f32 angle, f32 distance)
{
    f32 current_x, current_y, current_z;
    Get_Position(current_x, current_y, current_z); // 获取当前位置信息

    f32 theta = angle * M_PI / 180.0;

    // 计算目标位置
    f32 target_x = current_x + distance * cos(theta);
    f32 target_y = current_y + distance * sin(theta);

    // ROS_INFO("target_x%f, target_y%f", target_x, target_y);
    if(Check_XY(target_x, target_y)) return 1;
    else return 0;


}

f32 POSITION_CONTROL::Get_Angle(f32 x1, f32 y1, f32 x2, f32 y2)
{
    f32 delta_x = x2 - x1; 
    f32 delta_y = y2 - y1; 

    f32 angle_rad = atan2(delta_y, delta_x); 
    f32 angle_deg = angle_rad * 180.0 / M_PI; 

    if (angle_deg < 0)        angle_deg += 360.0; // 调整为正角度

    return angle_deg;
}
