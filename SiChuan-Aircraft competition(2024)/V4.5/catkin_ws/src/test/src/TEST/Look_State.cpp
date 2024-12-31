#include "ros/ros.h"
#include "std_msgs/String.h"
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include <geometry_msgs/PoseStamped.h>
#include <mavros_msgs/RCOut.h>
#include "test/set_position.h"
#include "test/SYS/Some_define.hpp"
#include "test/APP/Debug.hpp"
#include "test/SYS/MyROS.hpp"
#include "test/PTC/MyTopic.hpp"
#include "test/PTC/MyList.hpp"

#ifdef __INTELLISENSE__
#define NULL nullptr
#endif

using namespace std_msgs;
using namespace std;

DEBUG debug;

mavros_msgs::State now_state;
geometry_msgs::PoseStamped get_px4_state;
mavros_msgs::RCOut motor_output;
test::set_position setposition;

geometry_msgs::PoseStamped set_to_px4;   
geometry_msgs::PoseStamped px4_get;   

MYLIST mylist;

struct FLY_STATE 
{
    string fly_fb;
    string fly_up_down;
    string fly_rl;

    string corr_up;
    string corr_fb;
    string corr_rl;
};

FLY_STATE now_fly = {"none"};
FLY_STATE set_fly = {"none"};

void Get_Set_Position(const test::set_position::ConstPtr& msg) 
{
    setposition = *msg;
}

void Get_state(const mavros_msgs::State::ConstPtr& msg) 
{
    now_state = *msg;
}

void Get_From_Px4(const geometry_msgs::PoseStamped::ConstPtr& msg) 
{
    get_px4_state = *msg;
}

// void Get_Motor_Output(const mavros_msgs::RCOut::ConstPtr& msg)
//  {
//     motor_output = *msg;
// }

void Set_To_PX4(const geometry_msgs::PoseStamped::ConstPtr& msg)
{
    set_to_px4 = *msg;
}

void UpdateInfo(const ros::TimerEvent&)
{
    ROS_INFO("\n...........PX4 Set POSITION..........\n");
    ROS_INFO("x: %f", set_to_px4.pose.position.x);
    ROS_INFO("y: %f", set_to_px4.pose.position.y);
    ROS_INFO("z: %f", set_to_px4.pose.position.z);

    ROS_INFO("\n...........PX4 Local POSITION...........\n");
    ROS_INFO("x: %f", get_px4_state.pose.position.x);
    ROS_INFO("y: %f", get_px4_state.pose.position.y);
    ROS_INFO("z: %f", get_px4_state.pose.position.z);

    ROS_INFO("\n.........NOW STATE........\n");
    ROS_INFO("PX4 Mode: %s", now_state.mode.c_str());
    ROS_INFO("Lock state: %s", now_state.armed ? "have unlock" : "no unlock");
}

int main(int argc, char **argv)
{
    MYROS myros(argc, argv, "look_state");

    MYTOPIC topic_state("mavros/state", 10);
    topic_state.Get<mavros_msgs::State>(Get_state);

    MYTOPIC topic_getpx4_position("mavros/local_position/pose", 10);
    topic_getpx4_position.Get<geometry_msgs::PoseStamped>(Get_From_Px4);

    // MYTOPIC topic_motor_output("mavros/rc/out", 10);
    // topic_motor_output.Get<mavros_msgs::RCOut>(Get_Motor_Output);

    MYTOPIC topic_positin_send("mavros/setpoint_position/local", 10);
    topic_positin_send.Get<geometry_msgs::PoseStamped>(Set_To_PX4);

    // MYTOPIC topic_px4_get_positin("mavros/vision_pose/pose", 10);
    // topic_px4_get_positin.Get<geometry_msgs::PoseStamped>(Px4_Get);

    MYTOPIC topic_send_positon("set_position", 10);
    topic_send_positon.Get<test::set_position>(Get_Set_Position);

    ros::Timer time;
    time = myros.CreateTimer(ros::Duration(1), UpdateInfo); 

    while(ros::ok() )
    {
        myros.Delay(500);

        ros::spinOnce();
    }


    return 0;
}
