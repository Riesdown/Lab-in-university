#include "std_msgs/String.h"
#include "test/set_position.h"
#include "test/avoidant_date.h"
#include "test/cloud_date.h"

/**********  0  ***************/
#include "ros/ros.h"
#include <functional>
#include <string>
#include <deque>
#include <utility>
#include <cmath>
#include <limits>
#include <cstdlib>

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

// 安全半径
f32 safety_radius = 0.49; 
// 动态调整避障启动距离
f32 dynamic_run_len = 0.69;
// 避障系数与平滑度
f32 radio_smooth = 10; 

// 安全边界补偿
f32 safety_margin = 0.6;  
// 增加缓冲区
f32 buffer_zone = safety_radius;  // 当飞机靠近障碍物时的缓冲区

// 判断障碍物是否在飞机的前进方向
bool IsObstacleOnPath(f32 obs_x, f32 obs_y, f32 plane_x, f32 plane_y, f32 target_x, f32 target_y)
{
    f32 plane_dir_x = target_x - plane_x;
    f32 plane_dir_y = target_y - plane_y;
    f32 obs_dir_x = obs_x - plane_x;
    f32 obs_dir_y = obs_y - plane_y;

    // 计算障碍物与飞机之间的距离
    f32 distance_to_obstacle = std::sqrt(std::pow(obs_dir_x, 2) + std::pow(obs_dir_y, 2));

    f32 dot_product = (plane_dir_x * obs_dir_x + plane_dir_y * obs_dir_y);
    f32 plane_length_squared = std::pow(plane_dir_x, 2) + std::pow(plane_dir_y, 2);

    // 直接判断距离与安全半径之和
    return (dot_product > 0) && (distance_to_obstacle < (safety_radius + buffer_zone));
}

// 计算避障权重
f32 CalculateValue(f32 input_data, f32 run_len, f32 safety_radius) 
{
    f32 normalized = (input_data - safety_radius) / (run_len - safety_radius);

    if (normalized < 0) normalized = 0;
    if (normalized > 1) normalized = 1;

    // 使用增强的指数函数计算
    f32 returnValue = std::exp(-radio_smooth * normalized);
    return returnValue;
}

// 动态调整的安全半径
f32 AdjustedSafetyRadius(f32 dist1) 
{
    return safety_radius + safety_margin * (1 - CalculateValue(dist1, dynamic_run_len, safety_radius));
}

// 动态偏移更新
f32 AdjustOffsetWithSafety(f32 weight, f32 max_offset, f32 dist1)
{
    f32 adjusted_safety = AdjustedSafetyRadius(dist1);
    return max_offset * (1 - weight) * adjusted_safety;
}

int main(int argc, char** argv) 
{
    MYROS myros(argc, argv, "test1");

    MYTOPIC topic_get_position("set_position", 10);
    MYTOPIC topic_avoid_position("set_avoidant", 10);
    MYTOPIC topic_get_close("cloud_close", 10);

    POSITION_CONTROL position_control;

    auto Get_Position = [&](const test::set_position::ConstPtr& msg)
    {
        set_position = *msg;
    };

    auto Get_Cloud_Close = [&](const test::cloud_date::ConstPtr& msg)
    {
        cloud_date = *msg;
        position_control.Get_Position(now_position.x, now_position.y, now_position.z);

        f32 dist1 = std::sqrt(std::pow(now_position.x - cloud_date.x, 2) + std::pow(now_position.y - cloud_date.y, 2));
        f32 dist2 = std::sqrt(std::pow(now_position.x - set_position.x, 2) + std::pow(now_position.y - set_position.y, 2));

        // 默认偏移量
        f32 avoid_offset_x = 0;
        f32 avoid_offset_y = 0;

        if (IsObstacleOnPath(cloud_date.x, cloud_date.y, now_position.x, now_position.y, set_position.x, set_position.y) && 
            dist1 < dynamic_run_len && dist2 > (dist1 - safety_radius))
        {
            f32 avoid_angle = position_control.Get_Angle(now_position.x, now_position.y, cloud_date.x, cloud_date.y) + 90;

            f32 angle_temp = avoid_angle * M_PI / 180;

            // 增加对动态偏移的调整
            f32 weight = CalculateValue(dist1, dynamic_run_len, safety_radius);
            f32 offset = AdjustOffsetWithSafety(weight, 0.1, dist1);

            avoid_offset_x = std::cos(angle_temp) * AdjustedSafetyRadius(dist1) * (1 - weight);
            avoid_offset_y = std::sin(angle_temp) * AdjustedSafetyRadius(dist1) * (1 - weight);

            // 额外的速度调整
            if (dist1 < safety_radius)
            {
                // 当距离小于安全半径时，降低速度
                avoid_offset_x *= 0.5;
                avoid_offset_y *= 0.5;
            }
        }

        avoidant_date.x = set_position.x + avoid_offset_x;
        avoidant_date.y = set_position.y + avoid_offset_y;

        topic_avoid_position.Send<test::avoidant_date>(avoidant_date);
    };

    topic_get_position.Get<test::set_position>(Get_Position);
    topic_get_close.Get<test::cloud_date>(Get_Cloud_Close);

    while(ros::ok())
    {
        myros.Delay(100);
        ros::spinOnce();
    }
}
