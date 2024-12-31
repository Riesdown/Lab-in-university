#pragma once



using namespace std;

class MYSERVER
{
private:
    ros::NodeHandle n;
    ros::ServiceClient client_;
    ros::ServiceServer service_;
    string _name;
    int arg_;
    u8 num_;

public:

    MYSERVER(int arg, u8 num, const string& name);

    template <typename T>
    u8 Send(T& date);

    template <typename Req, typename Res>
    void Get(bool (*callback)(Req&, Res&));

};


MYSERVER::MYSERVER(int arg, u8 num, const string& name) :
    arg_(arg), num_(num), _name(name)
{

}


template <typename T>
u8 MYSERVER::Send(T& date)
{
    client_ = n.serviceClient<T>(_name);
    ROS_INFO("Waiting server...");
    client_.waitForExistence();
    ROS_INFO("Server OK");

    // if(arg_ != num_)
    // {
    //     ROS_INFO("Parameters num bad");
    //     return;
    // }

    bool flag = client_.call(date);
    if(flag)    
    {
        ROS_INFO("Send Good");
        return 1;
    }
    else        
    {
        ROS_INFO("Send Bad");
        return 0;
    }

}


template <typename Req, typename Res>
void MYSERVER::Get(bool (*callback)(Req&, Res&))
{
    service_ = n.advertiseService(_name, callback);
}












