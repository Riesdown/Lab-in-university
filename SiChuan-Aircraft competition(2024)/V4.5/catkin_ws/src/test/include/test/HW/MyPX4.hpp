#pragma once


#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include <geometry_msgs/PoseStamped.h>


class MYPX4
{
    private:
        MYTOPIC topic_state;
        MYSERVER server_Set_mode;
        mavros_msgs::State now_state;

        void CallBack(const mavros_msgs::State::ConstPtr& msg);
    public:
        MYPX4(int argc);
        void Set_Mode(const std::string   mode);
};


MYPX4::MYPX4(int argc) :
    topic_state("mavros/state", 10),
    server_Set_mode("mavros/set_mode")
{
    topic_state.Get<mavros_msgs::State>([this](const mavros_msgs::State::ConstPtr& ptr) 
    {
        this->CallBack(ptr);
    });

}

void MYPX4::CallBack(const mavros_msgs::State::ConstPtr& msg)
{
    now_state = *msg;

    // ROS_INFO
}


/*
"OFFBOARD"
"AUTO.LAND"   //自动降落

now_state.mode.c_str()  //当前状态
*/

void MYPX4::Set_Mode(const std::string   mode)
{
    mavros_msgs::SetMode set_mode;
    set_mode.request.custom_mode = mode;

    server_Set_mode.Send<mavros_msgs::SetMode>(set_mode);
    if (set_mode.response.mode_sent)     ROS_INFO("mypx4 Send  OK!!!");
}








