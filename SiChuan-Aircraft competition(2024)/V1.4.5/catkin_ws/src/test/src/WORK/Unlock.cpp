#include "std_msgs/String.h"
#include <geometry_msgs/PoseStamped.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>



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


using namespace std;


mavros_msgs::State now_state;


void Get_state(const mavros_msgs::State::ConstPtr& msg)
{
    now_state = *msg;
}



int main(int argc, char** argv)
{
    MYROS myros(argc, argv, "Unlock");

    MYTOPIC topic_state("mavros/state", 10);
    topic_state.Get<mavros_msgs::State>(Get_state);

    MYSERVER server_lock_state("mavros/cmd/arming");

    mavros_msgs::CommandBool arm_cmd;
    arm_cmd.request.value = true;

    MYLIST mylist;

    /****************************额外任务****************************************** */


    
    /****************************解锁方案****************************************** */

    /**********直接************ */
    auto Unlock = [&]()
    {
        if( !now_state.armed)
        {
            server_lock_state.Send<mavros_msgs::CommandBool>(arm_cmd);
            if(arm_cmd.response.success)
            {
                if(now_state.armed)
                {
                    ROS_INFO("Unlock Good!!!");
                }
                else    ROS_INFO("Waiting.....");
            }
        }
    };


    


    while(ros::ok() )
    {

        //解锁
        Unlock();



        myros.Delay(1000);
        ros::spinOnce();
    }
}





