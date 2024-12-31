#include "std_msgs/String.h"
#include "test/set_position.h"
#include "test/avoidant_date.h"
#include "test/cloud_date.h"

/**********  0  ***************/
#include "ros/ros.h"
#include <functional>
#include <string>
#include <deque>   // 使用 deque 容器来存储点云数据
#include <utility> // pair
#include <cmath>   // for sqrt
#include <limits>  // for std::numeric_limits

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

// 声明全局变量
test::set_position set_position;
test::avoidant_date avoidant_date;
test::cloud_date cloud_date;

// 当前飞机位置
struct 
{
    f32 x;
    f32 y;
    f32 z;
} now_position;

struct OFF_POSITION
{
    f32 x;
    f32 y;
};


// 安全半径， 宽度多一点
f32 safety_radius = 0.45;

//开启避障的距离, 轴距多一点
f32 run_len = 0.55;

// 转弯比 小于 all_radio
f32 radio = 0.8;
// 避障比 < 1
f32 all_radio =0.9;

// 避障速度
f32 radio_smooth = 3;

// 返回直线段上最近点
std::pair<f32, f32> Get_Close_Position_Line(f32 x_center, f32 y_center, f32 close_x, f32 close_y, f32 angle, f32 len1)
{
    f32 angle_rad = angle * M_PI / 180.0;

    f32 delta_x = len1 * std::cos(angle_rad);
    f32 delta_y = len1 * std::sin(angle_rad);

    std::pair<f32, f32> close_point1(x_center + delta_x, y_center + delta_y);
    std::pair<f32, f32> close_point2(x_center - delta_x, y_center - delta_y);

    f32 dis1_squared = std::pow(close_x - close_point1.first, 2) + std::pow(close_y - close_point1.second, 2);
    f32 dis2_squared = std::pow(close_x - close_point2.first, 2) + std::pow(close_y - close_point2.second, 2);

    return (dis1_squared < dis2_squared) ? close_point1 : close_point2;
}

static u8 dir_flag = 0;
static u8 dir = 0;

// 返回垂线上的点
std::pair<f32, f32> Get_Close_Position_Vertical(f32 x_center, f32 y_center, f32 close_x, f32 close_y, f32 angle, f32 len1)
{
    
    f32 angle_rad = angle * M_PI / 180.0;

    f32 delta_x = len1 * std::sin(angle_rad);
    f32 delta_y = -len1 * std::cos(angle_rad);

    std::pair<f32, f32> close_point1(x_center + delta_x, y_center + delta_y);
    std::pair<f32, f32> close_point2(x_center - delta_x, y_center - delta_y);

    f32 dis1_squared = std::pow(close_x - close_point1.first, 2) + std::pow(close_y - close_point1.second, 2);
    f32 dis2_squared = std::pow(close_x - close_point2.first, 2) + std::pow(close_y - close_point2.second, 2);


    if(dis1_squared < dis2_squared)    dir_flag = 1;
    else    dir_flag = 0;

    return (dir) ? close_point1 : close_point2;
}


// run_len > safety_radius
f32 CalculateValue(f32 input_data, f32 run_len, f32 safety_radius) 
{
    f32 normalized = (input_data - safety_radius) / (run_len - safety_radius);

    // 确保 normalized 在 [0, 1] 范围内
    if (normalized < 0) normalized = 0;
    if (normalized > 1) normalized = 1;

    // 使用平方增强非线性效果，使接近 safety_radius 和 run_len 时变化更快
    f32 returnValue = 1 / (1 + radio_smooth * std::pow(normalized, 2));

    return returnValue;
}

// 判断障碍物是否在飞机的前进方向
bool IsObstacleOnPath(f32 obs_x, f32 obs_y, f32 plane_x, f32 plane_y, f32 target_x, f32 target_y)
{
    f32 plane_dir_x = target_x - plane_x;
    f32 plane_dir_y = target_y - plane_y;
    f32 obs_dir_x = obs_x - plane_x;
    f32 obs_dir_y = obs_y - plane_y;

    f32 dot_product = (plane_dir_x * obs_dir_x + plane_dir_y * obs_dir_y);
    f32 plane_length_squared = std::pow(plane_dir_x, 2) + std::pow(plane_dir_y, 2);

    // 直接使用安全半径判断
    return (dot_product > 0) && (dot_product * dot_product / plane_length_squared < safety_radius * safety_radius);
}


int main(int argc, char** argv) 
{
    MYROS myros(argc, argv, "test1");

    MYTOPIC topic_get_position("set_position", 10);
    MYTOPIC topic_avoid_position("set_avoidant", 10);
    MYTOPIC topic_get_close("cloud_close", 10);


    POSITION_CONTROL position_control;
    std::pair<f32,f32> pos_line;
    std::pair<f32,f32> pos_ver;

    auto Get_Position = [&](const test::set_position::ConstPtr& msg)
    {
        set_position = *msg;
    };

    auto Get_Cloud_Close = [&](const test::cloud_date::ConstPtr& msg)
    {
        cloud_date = *msg;
        position_control.Get_Position(now_position.x, now_position.y, now_position.z);

        f32 obs_angle = position_control.Get_Angle(now_position.x, now_position.y, cloud_date.x, cloud_date.y);
        f32 aim_angle = position_control.Get_Angle(now_position.x, now_position.y, set_position.x, set_position.y);

        pos_line = Get_Close_Position_Line(cloud_date.x, cloud_date.y, now_position.x, now_position.y, obs_angle, safety_radius);
        pos_ver = Get_Close_Position_Vertical(pos_line.first, pos_line.second, set_position.x, set_position.y, obs_angle, run_len);

        // 飞机离障碍物的距离
        f32 dist1 = std::sqrt(std::pow(now_position.x - cloud_date.x, 2) + std::pow(now_position.y - cloud_date.y, 2));
        // 离目标点的距离
        f32 dist2 = std::sqrt(std::pow(now_position.x - set_position.x, 2) + std::pow(now_position.y - set_position.y, 2));

        // if(dist2 < safety_radius) RESET(0);
        // 开启避障
        if(IsObstacleOnPath(cloud_date.x, cloud_date.y, now_position.x, now_position.y, set_position.x, set_position.y) && dist1 < run_len)
        {
            RUN_ONCE(0,
                if(dir_flag) dir = 1;
                else dir = 0;
            );

            if(dist2 < safety_radius) RESET(0);
     
            avoidant_date.x = ((pos_line.first - set_position.x) * (all_radio - radio) +
                            (pos_ver.first - set_position.x)) * CalculateValue(dist1, run_len, safety_radius);

            avoidant_date.y = ((pos_line.second - set_position.y) * (all_radio - radio) +
                            (pos_ver.second - set_position.y) * radio) * CalculateValue(dist1, run_len, safety_radius);

            ROS_INFO("CalculateValue:%f", CalculateValue(dist1, run_len, safety_radius));
            // ROS_INFO("d = %f", run_len - dist1 + safety_radius);
            // ROS_INFO("dist1:%f, dist2:%f", dist1, dist2);
            // ROS_INFO("pos_ver.first:%f, pos_ver.second:%f", pos_ver.first, pos_ver.second);

            ROS_INFO("set_position.x:%f, set_position.y:%f", set_position.x, set_position.y);
            ROS_INFO("avoidant_date.x:%f, avoidant_date.y:%f", avoidant_date.x, avoidant_date.y);

            topic_avoid_position.Send<test::avoidant_date>(avoidant_date);
        }
    };

    topic_get_position.Get<test::set_position>(Get_Position);
    topic_get_close.Get<test::cloud_date>(Get_Cloud_Close);

    while(ros::ok())
    {
        myros.Delay(100);
        ros::spinOnce();
    }
}

