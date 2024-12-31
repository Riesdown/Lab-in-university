#include "std_msgs/String.h"
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include <geometry_msgs/PoseStamped.h>

#include "test/set_position.h"
#include "test/fly_position.h"
#include "test/circle.h"


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
#include "test/APP/Pos_Close.hpp"
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


struct
{
    f32 ca_x, ca_y, land_x, land_y;
}ca_land_positon;


test::fly_position position_data;
test::circle circle_data;


int main(int argc, char **argv)
{
    MYROS myros(argc, argv, "test1");


    POS_CLOSE pos_close(320, 240, 1.6, 1.2);
    POSITION_CONTROL position_control;

    MYLIST mylist;
    MYTOPIC get_circle("circle_cen", 10);

    auto Circle_Call = [&](const test::circle::ConstPtr &msg)
    {
        circle_data = *msg;
    };

    get_circle.Get<test::circle>(Circle_Call);

    f32 mode = mylist.Get<f32>("test1/mode", 0);

    f32 x, y, z = 0;

    mylist.Send<i32>("start_camera_land", 1);

    while (ros::ok())
    {
        position_control.Get_Position(x, y, z);
        auto [aim_x, aim_y] = pos_close.XY_Convert(circle_data.x, circle_data.y, x, y, mode);

        position_control.Set_XY(aim_x, aim_y);


        ROS_INFO("circle_data.x:%f, circle_data.y:%f, aim_x:%f, aim_y:%f, x:%f, y:%f, dis_x: %f, dis_y: %f", 
            circle_data.x, circle_data.y,
            aim_x ,aim_y,
            x, y,
            x - aim_x, y - aim_y
        );



        ros::spinOnce();
    }

    return 0;
}









