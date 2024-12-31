#pragma once

#include "test/PTC/MyList.hpp"
#include "test/PTC/MyTopic.hpp"
#include "ros/ros.h"
#include "std_msgs/String.h"

using namespace std;
using namespace std_msgs;


class GET_KEY 
{
    private:
        MYLIST mylist;
        MYTOPIC mytopic;
        u8 key_num;

        void CallBack(const String::ConstPtr& msg);

    public:
        GET_KEY();
        u8 Get_Key(); 
        void Clear_Key();
    };

GET_KEY::GET_KEY() :
    mytopic("Task_50ms", 1)
{
    mytopic.Get<std_msgs::String>
    ([this](const std_msgs::String::ConstPtr& ptr) 
    {
        this->CallBack(ptr);
    });
}


//具体话题是什么，需要改
void GET_KEY::CallBack(const String::ConstPtr& msg)
{
    key_num = mylist.Get<u8>("key");
}



inline u8 GET_KEY::Get_Key()
{
    return key_num;
}



inline void GET_KEY::Clear_Key()
{
    // for(u8 i = 0; i < 10; i++) mylist.Get<>();
}
