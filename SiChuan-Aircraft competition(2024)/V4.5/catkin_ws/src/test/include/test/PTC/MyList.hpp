#pragma once


using namespace std;


class MYLIST
{
    private:

    public:

        template <typename T>
        void Send(const string& name, const T& value);

        template <typename T>
       T Get(const std::string& name, const T& default_value) ;



};



template <typename T>
void MYLIST::Send(const string& name, const T& value)
{
    u8 i;
    for(i = 0; i < 10; i++)        
    {
        ros::param::set(name, value);
        ros::WallDuration(0.01).sleep();
    }
}


template<typename T>
T MYLIST::Get(const std::string& name, const T& default_value) 
{
    T value = default_value; 
    if(ros::param::get(name, value))        return value;  

    return default_value;  
}






