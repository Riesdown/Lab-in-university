
#include "test/SYS/Some_define.hpp"

#include "std_msgs/String.h"

/**********  0  ***************/
#include "ros/ros.h"
#include <cmath>
#include <map>

/**********  1  ***************/
#include "test/SYS/Some_define.hpp"
#include "test/PTC/MyTopic.hpp"
/**********  2  ***************/
#include "test/SYS/MyROS.hpp"




class GET_POSITION
{
    private:
        struct Point 
        {
            double x;
            double y;
        };

        struct Cell 
        {
            Point top_left;
            Point bottom_right;
        };

        std::map<int, Cell> Get_InitPosition(); 
        Point Rotate_Point(double x, double y, double angle);
    public:



};



void GET_POSITION::Get_Diagonal(vector<u8> &Left, vector<u8> &right)
{


}



std::map<int, Cell> GET_POSITION::Get_InitPosition() 
{
    std::map<int, Cell> coordinates;
    double half_size = cell_size / 2.0;
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            int cell_number = i * 3 + j + 1;
            double x_center = (j - 1) * cell_size;
            double y_center = (1 - i) * cell_size;
            double x_left = x_center - half_size;
            double y_top = y_center + half_size;
            double x_right = x_center + half_size;
            double y_bottom = y_center - half_size;
            coordinates[cell_number] = { {x_left, y_top}, {x_right, y_bottom} };
        }
    }
    return coordinates;
}



Point GET_POSITION::Rotate_Point(double x, double y, double angle) 
{
    double rad = angle * M_PI / 180.0;
    double cos_a = std::cos(rad);
    double sin_a = std::sin(rad);
    double x_new = cos_a * x - sin_a * y;
    double y_new = sin_a * x + cos_a * y;
    return { x_new, y_new };
}


// 打印旋转后的坐标
void Get_Rotate_Position(const std::map<int, Cell>& coordinates, double angle) 
{
    ROS_INFO("Rotated coordinates by %.2f degrees:", angle);
    for (const auto& [cell, coord] : coordinates) 
    {
        Point top_left_rot = rotate_point(coord.top_left.x, coord.top_left.y, angle);
        Point bottom_right_rot = rotate_point(coord.bottom_right.x, coord.bottom_right.y, angle);


        ROS_INFO("Cell %d: top_left (%.2f, %.2f), bottom_right (%.2f, %.2f)", 
                 cell, top_left_rot.x, top_left_rot.y, 
                 bottom_right_rot.x, bottom_right_rot.y);
    }
}






