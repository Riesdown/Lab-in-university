#include "std_msgs/String.h"
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include <geometry_msgs/PoseStamped.h>

#include "test/set_position.h"
#include "test/fly_position.h"

/**********  0  ***************/
#include "ros/ros.h"
#include <functional>
#include <string>
#include <vector>
#include <deque>
#include <utility> //pair
#include <map>
/**********  1  ***************/
#include "test/SYS/Some_define.hpp"
#include "test/APP/Debug.hpp"

/**********  2  ***************/
#include "test/SYS/MyROS.hpp"
#include "test/PTC/MyTopic.hpp"
#include "test/PTC/MyList.hpp"
#include "test/PTC/MyServer.hpp"

/**********  3  ***************/
#include "test/APP/Position_Control.hpp"

using namespace std;

struct XY_SET
{
    f32 x;
    f32 y;
    f32 z;
};
XY_SET xy_set;


struct
{
    f32 ca_x, ca_y, land_x, land_y;
}ca_land_positon;

test::fly_position position_data;

int main(int argc, char **argv)
{
    MYROS myros(argc, argv, "VARY_PATH");

    POSITION_CONTROL position_control;

    /***************路径************* */
    vector<pair<f32, f32>> all_path;

    MYLIST mylist;

    f32 h2 = mylist.Get<f32>("vary/h2", 0);

    std::cout << "......" << std::endl;
    std::cout << "......" << std::endl;
    std::cout << "......" << std::endl;
    std::cout << "......" << std::endl;
    std::cout << "......" << std::endl;
    std::cout << "......" << std::endl;

    MYTOPIC get_fly("fly_position", 10);

    ca_land_positon.ca_x = 6.5;
    ca_land_positon.ca_y = 1;
    ca_land_positon.land_x = 7;
    ca_land_positon.land_y = 1;

    auto Positon_Call = [&](const test::fly_position::ConstPtr &msg)
    {
        position_data = *msg;
    };


    get_fly.Get<test::fly_position>(Positon_Call);

    // 等待空格确认
    while (!mylist.Get<int>("black_ready", 0) )
    {
        myros.Delay(100);
        ros::spinOnce(); 
    }

    while(ros::ok() )
    {
        ros::spinOnce();

        if(!position_data.x1)
        {
            cout << "..." << endl;
            continue;
        }

        all_path.push_back(make_pair(position_data.x1, position_data.y1) );
        all_path.push_back(make_pair(position_data.x1, position_data.y2) );

        break;
    }


    ROS_WARN("data finish");

    for(auto &point : all_path)
    {
        std::cout << point.first << " " << point.second << std::endl;
    }
    mylist.Send<i32>("unlock_flag", 1);

    auto current_point = all_path.begin();

    static u8 flag = 0;
    auto Run_Position = [&]() 
    {
        xy_set.x = current_point->first;
        xy_set.y = current_point->second;

        if(!xy_set.x) return;


        if(position_control.Check_XY(xy_set.x, xy_set.y))
        {
            current_point++;
            if(current_point == all_path.end()) flag = 1;
        }
    };


    auto Get_Path = [&]()
    {


    };



    while (ros::ok())
    {
        Run_Position();

        Get_Path();

        myros.Delay(30);

        ros::spinOnce();
    }

    return 0;

}
