#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include <user_messages/navigation_ctrl.h>
#include <serial/serial.h>
#include "floatbytedecode.h"



user_messages::navigation_ctrl cmd;
serial::Serial com;
uint8_t read_buf[2048];
_serialport_decode _nclink_buf;
static uint8_t NCLink_Head[2]={0xFC,0xFF};//数据帧头
static uint8_t NCLink_End[2] ={0xA1,0xA2};//数据帧尾



//导航控制串口数据帧发送
void navigation_ctrl_send(user_messages::navigation_ctrl *_cmd)
{
    _nclink_buf=Send_Navigation_Ctrl(_cmd->num,_cmd->x,_cmd->y,_cmd->z,_cmd->nav_mode,_cmd->frame_id,_cmd->execution_time);
    com.write(_nclink_buf.buf,_nclink_buf.cnt);   
}

//键盘控制回调函数
void cmd_vel_callback(const geometry_msgs::Twist::ConstPtr& msg)
{
    static float x,y,z;
    static float scale=2;
    if(msg->linear.x==0&&msg->linear.y==0&&msg->linear.z==0)
    {
        x=0;
        y=0;
        z=0;
    }
    else if(msg->linear.x!=0)
    {
        x+=msg->linear.x*scale;
        y=0;
        z=0;
    }
     else if(msg->linear.y!=0)
    {
        x=0;
        y+=msg->linear.y*scale;
        z=0;
    }
    else if(msg->linear.z!=0)
    {
        x=0;
        y=0;
        z+=msg->linear.z*scale;
    }
    else
    {
        x=0;
        y=0;
        z=0;      
    }   
    cmd.x=constrain_float(x,-50,50);
    cmd.y=constrain_float(y,-50,50);
    cmd.z=constrain_float(z,-50,50);  

    cmd.update_flag=1;
    cmd.num=0;
    cmd.frame_id=cmd.BODY_FRAME;    //表征是ROS发出的速度控制指令，用于转换单位
    cmd.nav_mode=cmd.RELATIVE_MODE; //相对模式
    cmd.execution_time=1000;//执行时间1000ms
    ROS_INFO("cmd pos-x y z nav_mode frame_id time: %.2f %.2f %.2f %d %d %d",cmd.x,cmd.y,cmd.z,cmd.nav_mode,cmd.frame_id,cmd.execution_time);
}




int main(int argc,char **argv)
{
    ros::init(argc,argv,"cmd_pos_ctrl_comand");//初始化节点名称
    ros::NodeHandle n;//初始化节点句柄    
    ros::Publisher nav_ctrl_cmd_pub=n.advertise<user_messages::navigation_ctrl>("nav_ctrl_comand",100);//定义导航控制话题发布者
    ros::Subscriber cmd_pos_sub=n.subscribe("/cmd_vel",100,cmd_vel_callback);//定义导航控制键盘话题订阅者
    ros::Duration(1).sleep();//节点初始化后必要的延时
    //参数重载
    std::string serial_port;    
    int serial_baudrate = 460800; 
    ros::NodeHandle nh_private("~");
    nh_private.param<std::string>("serial_port", serial_port, "/dev/ttyAMA0"); 
    nh_private.param<int>("serial_baudrate", serial_baudrate, 460800);
    try
    {
        com.setPort(serial_port);
        com.setBaudrate(serial_baudrate);
        serial::Timeout to=serial::Timeout::simpleTimeout(1000);
        com.setTimeout(to);
        com.open();
    }
    catch (serial::IOException& e)
    {
        ROS_ERROR_STREAM("NAMELESSTECH unable to open port");
        return -1;
    }
    if(com.isOpen())
    {
        ROS_INFO_STREAM("NAMELESSTECH serial port is initialized");
    }
    else return -1;

    ros::Rate loop_rate(100);//设置循环频率Hz
    while(ros::ok())
    {
        size_t _cnt=com.available();
        if(_cnt!=0)
        {
            com.read(read_buf,_cnt);
            com.write(read_buf,_cnt);
        }
        //判断键盘控制是否更新
        if(cmd.update_flag==1)
        {
            nav_ctrl_cmd_pub.publish(cmd);//发布导航控制话题
            navigation_ctrl_send(&cmd);//发送导航控制串口数据帧
            cmd.update_flag=0;
        }
        ros::spinOnce();//监听反馈函数
        loop_rate.sleep();//执行循环   
    }
    return 0;
}