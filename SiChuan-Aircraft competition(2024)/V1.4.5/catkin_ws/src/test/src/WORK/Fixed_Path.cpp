#include "std_msgs/String.h"
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include <geometry_msgs/PoseStamped.h>

#include "test/set_position.h"
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

/******************************************配置*******************************************************************/




/******************************************配置*******************************************************************/



using namespace std;




struct XY_SET
{
    f32 x;
    f32 y;
    f32 z;
};
XY_SET xy_set;


/*******************路径**************************************** */

void All_Path_2023(vector<pair<f32, f32>>& path)
{
    path = 
    {
        {0.01,  0.02},
        {2.5, 0.01},
        {0.01, 0.01}
    };
}


int main(int argc, char **argv)
{
    MYROS myros(argc, argv, "Fixed_Path");
    POSITION_CONTROL position_control;

    /***************路径************* */
    vector<pair<f32, f32>> all_path;
    All_Path_2023(all_path);   


    auto current_point = all_path.begin();

    MYLIST mylist;


    /*************************初始化*************************************** */

    /*************************初始化*************************************** */


    /*************************巡航方案*************************************** */

    /******************巡航一次，降落一次***************/
    static u8 flag = 0;

    auto Run_Position = [&]() 
    {
        xy_set.x = current_point->first;
        xy_set.y = current_point->second;

        if(position_control.Check_XY(xy_set.x, xy_set.y))
        {
            current_point++;
            if(current_point == all_path.end()) flag = 1;
        }
    };

    //直接 降落
    auto Direct_Land = [&]() 
    {
        if(flag == 1 && position_control.Check_XY( (all_path.end() - 1)->first, (all_path.end() - 1)->second))
        {
            mylist.Send<string>("state", "land");
            return 1; 
        }
        return 0; 
    };





    while (ros::ok())
    {
        Run_Position();

        //结束直接降落
        if(Direct_Land()) break;

        myros.Delay(30);

        ros::spinOnce();
    }

    return 0;
}









