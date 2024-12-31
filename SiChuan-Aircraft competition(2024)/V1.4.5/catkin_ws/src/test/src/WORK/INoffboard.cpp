#include "std_msgs/String.h"
#include <geometry_msgs/PoseStamped.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>

#include "test/set_position.h"
#include "test/avoidant_date.h"

/**********  0  ***************/
#include "ros/ros.h"
#include <functional>
#include <string>
#include <vector>

/**********  1  ***************/
#include "test/SYS/Some_define.hpp"
#include "test/APP/Debug.hpp"

/**********  2  ***************/
#include "test/SYS/MyROS.hpp"
#include "test/PTC/MyTopic.hpp"
#include "test/PTC/MyList.hpp"
#include "test/PTC/MyServer.hpp"

/**********  3  ***************/
#include "test/HW/MyPX4.hpp"
#include "test/APP/Position_Control.hpp"


/******************************************配置*******************************************************************/

//飞机飞行范围
struct 
{
    f32 x_min;
    f32 x_max;
    f32 y_min;
    f32 y_max;
    f32 z_min;
    f32 z_max;

}zyz_range;






using namespace std;

mavros_msgs::State now_state;
geometry_msgs::PoseStamped get_px4_state;   

test::set_position  setposition;
test::set_position  setposition_temp;

test::avoidant_date  avoidantdate;


geometry_msgs::PoseStamped pose;  


static u32 avoid_num = 0;

struct XY_
{
    f32 x;
    f32 y;
    f32 z;
};

XY_ xy_;

void Get_state(const mavros_msgs::State::ConstPtr& msg)
{
    now_state = *msg;
}

void Get_From_Px4(const geometry_msgs::PoseStamped::ConstPtr& msg)
{
    get_px4_state = *msg;
}

void Get_Set_Position(const test::set_position::ConstPtr& msg)
{
    setposition = *msg;

    if(setposition.z != 0)        setposition_temp.z = setposition.z ;
    if(setposition.x != 0)        setposition_temp.x = setposition.x + avoidantdate.x;
    if(setposition.y != 0)        setposition_temp.y = setposition.y + avoidantdate.y;

}


void Get_Avoid_Positin(const test::avoidant_date::ConstPtr& msg)
{
    avoidantdate = *msg;
    avoid_num = 0;
}




int main(int argc, char **argv)
{
    MYROS myros(argc, argv, "INoffboard");
    setlocale(LC_CTYPE, "zh_CN.utf8");


    MYTOPIC topic_state("mavros/state", 10);
    topic_state.Get<mavros_msgs::State>(Get_state);

    MYTOPIC topic_set_position("mavros/setpoint_position/local",  10);
    MYTOPIC topic_getpx4_position("mavros/local_position/pose",  10);
    topic_getpx4_position.Get< geometry_msgs::PoseStamped>(Get_From_Px4); 

    MYSERVER server_Set_mode("mavros/set_mode");

    MYTOPIC topic_send_positon("set_position", 10);
    topic_send_positon.Get<test::set_position>(Get_Set_Position);

    MYTOPIC topic_send_avoid("set_avoidant", 10);
    topic_send_avoid.Get<test::avoidant_date>(Get_Avoid_Positin);


    MYLIST mylist;

    POSITION_CONTROL position_control;

    MYPX4 mypx4(argc);


    /****************************************************************************************/
    zyz_range.x_min = mylist.Get<f32>("yaml_x_min", 0);
    zyz_range.x_max = mylist.Get<f32>("yaml_x_max", 0);
    zyz_range.y_min = mylist.Get<f32>("yaml_y_min", 0);
    zyz_range.y_max = mylist.Get<f32>("yaml_y_max", 0);
    zyz_range.z_min = mylist.Get<f32>("yaml_z_min", 0);
    zyz_range.z_max = mylist.Get<f32>("yaml_z_max", 0);

    f32 start_z = mylist.Get<f32>("yaml_start_z", 0);

    f32 speed_xy = mylist.Get<f32>("yaml_speed_xy", 0);
    f32 speed_z = mylist.Get<f32>("yaml_speed_z", 0);


    // 转化为米/s
    const f32 delay_ms = 50;
    speed_xy = speed_xy / (1000 / delay_ms);
    speed_z = speed_z / (1000 / delay_ms);

    //避障位置删除时间,ms
    const f32 delete_time = 1000;
    u32 time_num =   delete_time  / delay_ms;


// ROS_INFO("zyz_range.x_min: %f, zyz_range.x_max: %f, zyz_range.y_min: %f, zyz_range.y_max: %f, zyz_range.z_min: %f, zyz_range.z_max: %f, start_z: %f, speed: %f",
//     zyz_range.x_min, zyz_range.x_max, zyz_range.y_min, zyz_range.y_max, zyz_range.z_min, zyz_range.z_max, start_z, speed);

    /****************************************************************************************/  


    while(ros::ok() && !now_state.connected)
    {
        ROS_INFO("Waiting for connection...");
        myros.Delay(100);
        ros::spinOnce();
    }


    setposition_temp.x = 0;
    setposition_temp.y = 0;
    setposition_temp.z = start_z;





    for(int i = 100; ros::ok() && i > 0; --i)
    {
        topic_set_position.Send(pose);
        myros.Delay(10);
        ros::spinOnce();
    }

    mavros_msgs::SetMode set_mode;
    set_mode.request.custom_mode = "OFFBOARD";

    ros::Time last_request = ros::Time::now();

    static u8 flag[2] = {0};

    static u8 num = 0;

    /*************************额外任务********************************************* */


    /****************************降落方案****************************************** */

    f32 h = -20;

    /******直接降落***** */
    auto Direct_Land = [&]()
    {
        if("land" == mylist.Get<string>("state" , "nothing")  )
        {
            position_control.Set_Z(h);
            myros.Delay(1000);

            mypx4.Set_Mode("AUTO.LAND");
            return 1;
        }
        else return 0;

    };
    /****************************offboard方案****************************************** */

    /**********使用offboard******** */
    auto Offboard_Direct = [&]()
    {
  
        if (now_state.mode != "OFFBOARD" 
            &&  (ros::Time::now() - last_request > ros::Duration(5.0))
            )
        {
                server_Set_mode.Send<mavros_msgs::SetMode>(set_mode);

                if (set_mode.response.mode_sent)     
                {
                    ROS_INFO("offboard send  OK!!!");
                    flag[0] = 1;
                }

                last_request = ros::Time::now();

        }

    };


    auto Send_Position = [&]()
    {
        f32 dx = setposition_temp.x - pose.pose.position.x;
        f32 dy = setposition_temp.y - pose.pose.position.y;
        f32 dz = setposition_temp.z - pose.pose.position.z;

        
        dx = dx > speed_xy ? speed_xy : dx < -speed_xy ? -speed_xy : dx;
        dy = dy > speed_xy ? speed_xy : dy  < -speed_xy ? -speed_xy : dy;
        dz = dz > speed_z ? speed_z : dz  < -speed_z ? -speed_z : dz;

        pose.pose.position.x += dx;
        pose.pose.position.y += dy;
        pose.pose.position.z += dz;

        pose.pose.position.z = (pose.pose.position.z < zyz_range.z_min) ? zyz_range.z_min 
        : (pose.pose.position.z > zyz_range.z_max) ? zyz_range.z_max : pose.pose.position.z;

        pose.pose.position.x = (pose.pose.position.x < zyz_range.x_min) ? zyz_range.x_min
        : (pose.pose.position.x > zyz_range.x_max) ? zyz_range.x_max : pose.pose.position.x;

        pose.pose.position.y = (pose.pose.position.y < zyz_range.y_min) ? zyz_range.y_min
        : (pose.pose.position.y > zyz_range.y_max) ? zyz_range.y_max : pose.pose.position.y;


        topic_set_position.Send(pose);


        avoid_num++;
        if(avoid_num > time_num)
        {
            avoid_num = 0;
            avoidantdate.x = 0;
            avoidantdate.y = 0;
        }

        myros.Delay(delay_ms);
    };





    while (ros::ok())
    {
        //使用offboard
        //Offboard_Direct();

        //直接降落
        if(Direct_Land() )  break;

        Send_Position();
        
        ros::spinOnce();
    }

    return 0;
}
