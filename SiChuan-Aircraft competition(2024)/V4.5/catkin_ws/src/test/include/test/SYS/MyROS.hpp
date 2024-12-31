#pragma once

#include "ros/ros.h"  // 包含 ROS 头文件
#include "test/SYS/Some_define.hpp"
#include <functional>

using namespace std;

class MYROS {
private:
    int _argc;
    char** _argv;
    string _name;

public:
    MYROS(int argc, char** argv, const string& name);

    void Delay(u64 ms);

    ros::Timer CreateTimer(const ros::Duration& duration, std::function<void(const ros::TimerEvent&)> callback);

};

MYROS::MYROS(int argc, char** argv, const string& name) :
    _argc(argc),
    _argv(argv),
    _name(name)
{
    ros::init(_argc, _argv, name);
}

void MYROS::Delay(u64 ms) 
{
    ros::WallDuration(ms / 1000.0).sleep();
}


ros::Timer MYROS::CreateTimer(const ros::Duration& duration, std::function<void(const ros::TimerEvent&)> callback) 
{
    return ros::NodeHandle().createTimer(duration, callback);
}