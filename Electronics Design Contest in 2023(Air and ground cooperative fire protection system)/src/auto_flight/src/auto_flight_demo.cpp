#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include <user_messages/position_ctrl.h>

void pos_cmd_translate(user_messages::position_ctrl *msg);
user_messages::position_ctrl cmd;


int main(int argc,char **argv)
{
    ros::init(argc,argv,"auto_flight_demo");//初始化节点名称
    ros::NodeHandle n;//初始化节点句柄 
    ros::Publisher pos_cmd_pub=n.advertise<user_messages::position_ctrl>("position_comand",100);//定义SDK控制话题发布者
    ros::Duration(1).sleep();//节点初始化后必要的延时

    //向前移动100CM
    cmd.move_flag=0;
    cmd.move_order=0;
    cmd.move_distance=100;
    pos_cmd_pub.publish(cmd);
    pos_cmd_translate(&cmd);

    //向右移动100CM
    ros::Duration(10).sleep();
    cmd.move_flag=3;
    cmd.move_order=0;
    cmd.move_distance=100;
    pos_cmd_pub.publish(cmd);
    pos_cmd_translate(&cmd);
    //向后移动100CM
    ros::Duration(10).sleep();
    cmd.move_flag=1;
    cmd.move_order=0;
    cmd.move_distance=100;
    pos_cmd_pub.publish(cmd);
    pos_cmd_translate(&cmd);
    //向左移动100CM
    ros::Duration(10).sleep();
    cmd.move_flag=2;
    cmd.move_order=0;
    cmd.move_distance=100;
    pos_cmd_pub.publish(cmd);
    pos_cmd_translate(&cmd);

    ros::Rate loop_rate(1);
    while(ros::ok())
    {
        ROS_INFO("auto_flight_demo cmd send complete");
        loop_rate.sleep();        
    }
    return 0;
}



void pos_cmd_translate(user_messages::position_ctrl *msg)
{
  switch(msg->move_flag)
  {
    case 0:
    {
      ROS_INFO("move front %d cm",msg->move_distance);
    }
    break;
    case 1:
    {
      ROS_INFO("move behind %d cm",msg->move_distance);
    }
    break;
    case 2:
    {
      ROS_INFO("move left %d cm",msg->move_distance);
    }
    break;
    case 3:
    {
      ROS_INFO("move right %d cm",msg->move_distance);
    }
    break;
    case 4:
    {
      ROS_INFO("move up %d cm",msg->move_distance);
    }
    break;
    case 5:
    {
      ROS_INFO("move down %d cm",msg->move_distance);
    }
    break;
    default:
    {
      ROS_INFO_STREAM("error cmd,stay put"); 
    }
  }
  //ROS_INFO("%d,%d,%d",msg->move_flag,msg->move_order,msg->move_distance); 
}


