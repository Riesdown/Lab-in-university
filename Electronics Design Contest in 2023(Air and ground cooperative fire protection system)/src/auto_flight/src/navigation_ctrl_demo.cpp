#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include <user_messages/navigation_ctrl.h>
#include <serial/serial.h>
#include "floatbytedecode.h"
#include <std_msgs/UInt8.h>

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

//导航控制串口应答回调函数
void uart_ctrl_response_callback(const std_msgs::UInt8::ConstPtr& msg)
{
    uint8_t cmd_check=msg->data;
    if(cmd_check==0xf2)      std::cout<<"[ INFO] ["<<ros::Time::now()<<"]: SERIALPORT_RPLIDAR：飞控返回校验，位移控制指令写入成功"<<std::endl;
    else if(cmd_check==0xf6) std::cout<<"[ INFO] ["<<ros::Time::now()<<"]: SERIALPORT_RPLIDAR：飞控返回校验，导航控制指令写入成功"<<std::endl;
    else if(cmd_check==0xf7) std::cout<<"[ INFO] ["<<ros::Time::now()<<"]: SERIALPORT_RPLIDAR：飞控返回校验，导航控制完毕，已达到目标点"<<std::endl;
    else if(cmd_check==0xf8) std::cout<<"[ INFO] ["<<ros::Time::now()<<"]: SERIALPORT_RPLIDAR：飞控返回校验，SLAM复位重置"<<std::endl;
    else                     std::cout<<"[ INFO] ["<<ros::Time::now()<<"]: SERIALPORT_RPLIDAR：飞控返回校验，表征含义不明"<<std::endl;
}


int main(int argc,char **argv)
{
    ros::init(argc,argv,"navigation_ctrl_demo");//初始化节点名称
    ros::NodeHandle n;//初始化节点句柄  
    ros::Publisher nav_ctrl_cmd_pub=n.advertise<user_messages::navigation_ctrl>("nav_ctrl_comand",100);//定义导航控制话题发布者
    ros::Subscriber uart_ctrl_response_sub=n.subscribe("/uart_ctrl_response",100,uart_ctrl_response_callback);//定义导航控制应答话题订阅者
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
    cmd.execution_time=1000;//速度控制时的执行时间
    ros::Rate loop_rate(1);//1hz
    while(ros::ok())
    {
        size_t _cnt=com.available();
        if(_cnt!=0)
        {
            com.read(read_buf,_cnt);
            com.write(read_buf,_cnt);
        }
        static uint16_t cnt=0;
        if(cnt==0){
            //发布航点（0,0,100）
            cmd.num=0;
            cmd.x=0;
            cmd.y=0;
            cmd.z=100;
            cmd.frame_id=cmd.MAP_FRAME;
            cmd.nav_mode=cmd.GLOBAL_MODE;
            nav_ctrl_cmd_pub.publish(cmd);
            navigation_ctrl_send(&cmd);
        }
        else if(cnt==10){
            //发布航点（0,100,100）
            cmd.num=0;
            cmd.x=0;
            cmd.y=100;
            cmd.z=100;
            cmd.frame_id=cmd.MAP_FRAME;
            cmd.nav_mode=cmd.GLOBAL_MODE;
            nav_ctrl_cmd_pub.publish(cmd);
            navigation_ctrl_send(&cmd);    
        }
        else if(cnt==20){
            //发布航点（100,100,100）
            cmd.num=0;
            cmd.x=100;
            cmd.y=100;
            cmd.z=100;
            cmd.frame_id=cmd.MAP_FRAME;
            cmd.nav_mode=cmd.GLOBAL_MODE;
            nav_ctrl_cmd_pub.publish(cmd);
            navigation_ctrl_send(&cmd);
        }
        else if(cnt==30){
            //发布航点（100,0,100）
            cmd.num=0;
            cmd.x=100;
            cmd.y=0;
            cmd.z=100;
            cmd.frame_id=cmd.MAP_FRAME;
            cmd.nav_mode=cmd.GLOBAL_MODE;
            nav_ctrl_cmd_pub.publish(cmd);
            navigation_ctrl_send(&cmd);
        }
        else if(cnt==40){
            //发布航点（0,0,100）
            cmd.num=0;
            cmd.x=0;
            cmd.y=0;
            cmd.z=100;
            cmd.frame_id=cmd.MAP_FRAME;
            cmd.nav_mode=cmd.GLOBAL_MODE;
            nav_ctrl_cmd_pub.publish(cmd);
            navigation_ctrl_send(&cmd);
        }
        cnt++;
        ros::spinOnce();//监听反馈函数
        loop_rate.sleep();//执行循环     
    }
    return 0;
}