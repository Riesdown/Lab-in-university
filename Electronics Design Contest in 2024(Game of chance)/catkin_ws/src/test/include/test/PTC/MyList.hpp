#pragma once

#include "ros/ros.h"
#include "test/SYS/Some_define.hpp"


using namespace std;


class MYLIST
{
    private:

    public:

        template <typename T>
        void Send(const string& name, const T& value);

        template <typename T>
        T Get(const string& name);



};



template <typename T>
void MYLIST::Send(const string& name, const T& value)
{
    for(u8 i = 0; i < 10; i++)        ros::param::set(name, value);
}


template<typename T>
T MYLIST::Get(const string& name)
{
    T value = T();
    if(ros::param::get(name, value))    return value;

}






