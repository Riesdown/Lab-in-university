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


pair<f32, f32> XY_Convert(f32 cam_x, f32 cam_y) 
{
    f32 flight_x = (cam_x / 320) * 320;
    f32 flight_y = (cam_y / 240) * 240;
    return make_pair(flight_x, flight_y);
}


int main(int argc, char **argv)
{
    MYROS myros(argc, argv, "Fixed_Path");

    
    // std::setlocale(LC_ALL, "zh_CN.UTF-8");




    MYTOPIC get_fly("fly_position", 10);
    MYTOPIC get_circle("circle_cen", 1);

    /***************路径************* */
    vector<pair<f32, f32>> all_path;

    POS_CLOSE pos_close(320, 240, 1.6, 1.2);
    MYLIST mylist;

    /*************************初始化*************************************** */

    f32 h2 = mylist.Get<f32>("fix2/h2", 0);
    f32 h3 = mylist.Get<f32>("fix2/h3", 0);
    f32 h_land = mylist.Get<f32>("fix2/h_land", 0);
    i32 stab = mylist.Get<i32>("fix2/stab", 0);
    f32 xy_zone = mylist.Get<f32>("fix2/xy_zone", 0);
    f32 x_over = mylist.Get<f32>("fix2/x_over", 0);
    f32 land_zone = mylist.Get<f32>("fix2/land_zone", 0);

    POSITION_CONTROL position_control(xy_zone);

    ca_land_positon.ca_x = mylist.Get<f32>("fix2/ca_x", 0);
    ca_land_positon.ca_y = mylist.Get<f32>("fix2/ca_y", 0);
    ca_land_positon.land_x = mylist.Get<f32>("fix2/land_x", 0);
    ca_land_positon.land_y = mylist.Get<f32>("fix2/land_y", 0);



    f32 aim_xy;

    std::cout << "......" << std::endl;
    std::cout << "......" << std::endl;
    std::cout << "......" << std::endl;
    std::cout << "......" << std::endl;
    std::cout << "......" << std::endl;
    std::cout << "......" << std::endl;


    auto Positon_Call = [&](const test::fly_position::ConstPtr &msg)
    {
        position_data = *msg;
    };
    auto Circle_Call = [&](const test::circle::ConstPtr &msg)
    {
        circle_data = *msg;
    };

    get_fly.Get<test::fly_position>(Positon_Call);
    get_circle.Get<test::circle>(Circle_Call);

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

        all_path.push_back(make_pair(position_data.x1, position_data.y1)); //起点1
        all_path.push_back(make_pair(position_data.x2, position_data.y2)); //起点2

        all_path.push_back(make_pair(position_data.x2, (position_data.y3 + position_data.y4) / 2) ); // 调整第一个y轴
        all_path.push_back(make_pair( (position_data.x3 + position_data.x4) / 2 + x_over , (position_data.y3 + position_data.y4) / 2) ); // 调整x穿第一个框
        all_path.push_back(make_pair( (position_data.x3 + position_data.x4) / 2 + x_over,  (position_data.y5 + position_data.y6) / 2) ); // 调整第二个y轴
        all_path.push_back(make_pair( (position_data.x5 + position_data.x6) / 2 + x_over,  (position_data.y5 + position_data.y6) / 2) ); // 调整x穿第二个框
        all_path.push_back(make_pair(ca_land_positon.ca_x, ca_land_positon.ca_y));
        all_path.push_back(make_pair(ca_land_positon.land_x, ca_land_positon.land_y));


        aim_xy = (position_data.x3 + position_data.x4) / 2 + x_over + (position_data.y5 + position_data.y6) / 2;

        break;
    }

    ROS_WARN("data finish");

    for(auto &point : all_path)
    {
        std::cout << point.first << " " << point.second << std::endl;
    }

    mylist.Send<i32>("unlock_flag", 1);

    auto current_point = all_path.begin();

    /*************************初始化*************************************** */


    /*************************巡航方案*************************************** */

    /******************巡航一次，降落一次***************/
    static u8 flag = 0;
    f32 now_xy;

    u8 id;

    auto Run_Position = [&]() 
    {
        xy_set.x = current_point->first;
        xy_set.y = current_point->second;

        now_xy = xy_set.x + xy_set.y;

        if(xy_set.x == ca_land_positon.land_x) position_control.Check_Z(h_land);

        if(aim_xy == now_xy)
        {
            // cout << "到达中间点" << endl;
            position_control.Check_Z(h2);
        }

        if(xy_set.x == ca_land_positon.ca_x)
        {
            id = mylist.Get<i32>("aruco", 0);
            position_control.Check_Z(h3);
            if(id) 
            {
                current_point++;
                for(u8 i = 0; i < 10; i++) ROS_INFO("%d", id);
                mylist.Send<i32>("start_camera_land", 1);
            }
        }

        if(position_control.Check_XY(xy_set.x, xy_set.y) && !flag)
        {
            if(xy_set.x == ca_land_positon.ca_x)
            {

                while(!id)
                {
                    if(id)  break;
                    static u16 num = 0;
                    cout << "等待aruco..." << num++ << endl;

                    id = mylist.Get<i32>("aruco", 0);
                }

                for(u8 i = 0; i < 10; i++) ROS_INFO("%d", id);
                mylist.Send<i32>("start_camera_land", 1);
            }



            current_point++;
            if(current_point == all_path.end()) flag = 1;
        }
    };



    f32 x_now = 0, y_now = 0, z_now = 0;

    f32 target_range_ = land_zone; 

    auto Close_Land = [&]()
    {
        // mylist.Send<i32>("start_camera_land", 1);
        while(1)
        {
            for(u16 i = 0; i < 5000; i++)
            {
                myros.Delay(1);
                if(circle_data.x) break;
                ros::spinOnce();
            }
            break;
        }
        while(1)
        {
            if(!circle_data.x) 
            {
                ROS_INFO("no Circel");
                break;
            }
            else
            {
                RUN_ONCE(4, ROS_INFO("get Circel");)

                position_control.Get_Position(x_now, y_now, z_now);
                auto [aim_x, aim_y] = pos_close.XY_Convert(circle_data.x, circle_data.y, x_now, y_now, 1);

                if (fabs(aim_x) <= target_range_ && fabs(aim_y) <= target_range_)    break; 
                else    position_control.Set_XY(aim_x, aim_y);

                
            }

            ros::spinOnce();
        }

    };


    //直接 降落
    auto Direct_Land = [&]() 
    {
        if(flag == 1 && position_control.Check_XY( (all_path.end() - 1)->first, (all_path.end() - 1)->second))
        {
            if(stab)   Close_Land();

            position_control.Check_Z(-2);
            myros.Delay(2000);

            mylist.Send<string>("state", "land");
            position_control.Get_Position(x_now, y_now, z_now);

            ROS_INFO("land:x %f, y %f", x_now, y_now);
            return 1; 
        }
        return 0; 
    };





    while (ros::ok())
    {
        Run_Position();

        //结束直接降落
        if(Direct_Land()) break;

        myros.Delay(5);

        ros::spinOnce();
    }

    return 0;
}









