#include "test/piece.h"
#include "test/all_position.h"

/**********  0  ***************/
#include "ros/ros.h"
#include <cmath>
#include <map>
/**********  1  ***************/
#include "test/SYS/Some_define.hpp"
#include "test/PTC/MyTopic.hpp"
/**********  2  ***************/
#include "test/SYS/MyROS.hpp"

struct Point 
{
    f64 x;
    f64 y;
};

struct Cell 
{
    Point top_left;
    Point bottom_right;
};

// 正方形大小
const u16 cell_size = 30;

static constexpr u16 zone = 5;


std::map<u16, Cell> Get_InitPosition() 
{
    std::map<u16, Cell> coordinates;
    f64 half_size = cell_size / 2.0;
    for (u16 i = 0; i < 3; ++i) 
    {
        for (u16 j = 0; j < 3; ++j) 
        {
            u16 cell_number = i * 3 + j + 1;
            f64 x_center = (j - 1) * cell_size;
            f64 y_center = (1 - i) * cell_size;
            f64 x_left = x_center - half_size;
            f64 y_top = y_center + half_size;
            f64 x_right = x_center + half_size;
            f64 y_bottom = y_center - half_size;
            coordinates[cell_number] = { {x_left, y_top}, {x_right, y_bottom} };
        }
    }
    return coordinates;
}

Point Rotate_Point(f64 x, f64 y, f64 angle) 
{
    f64 rad = angle * M_PI / 180.0;
    f64 cos_a = std::cos(rad);
    f64 sin_a = std::sin(rad);
    f64 x_new = cos_a * x - sin_a * y;
    f64 y_new = sin_a * x + cos_a * y;
    return { x_new, y_new };
}

test::piece piece_date;
test::all_position position_date;

void Send_Position(MYTOPIC& send_all_position, f64 angle) 
{
    for (const auto& [cell, coord] : Get_InitPosition()) 
    {
        Point top_left_rot = Rotate_Point(coord.top_left.x, coord.top_left.y, angle);
        Point bottom_right_rot = Rotate_Point(coord.bottom_right.x, coord.bottom_right.y, angle);

        position_date.id = cell;
        position_date.x1 = top_left_rot.x + 85;
        position_date.y1 = 85 - top_left_rot.y;
        position_date.x2 = bottom_right_rot.x + 85;
        position_date.y2 = 85 - bottom_right_rot.y;
        position_date.angle = angle;

        ROS_INFO("Cell: %d, x1: %.2f, y1: %.2f, x2: %.2f, y2: %.2f", 
                 cell, top_left_rot.x, top_left_rot.y, bottom_right_rot.x, bottom_right_rot.y);

        send_all_position.Send<test::all_position>(position_date);
    }
}

void Get_Piece(const test::piece& msg, MYTOPIC& send_all_position)
{
    piece_date = msg;

    ROS_INFO("Now Angle :%.2f", piece_date.angle);

    // if (std::abs(piece_date.angle) < zone)
    // {
    //     Send_Position(send_all_position, 0.0);
    // }
    // else
    // {
        Send_Position(send_all_position, piece_date.angle);
    // }
}

int main(int argc, char **argv) 
{
    MYROS myros(argc, argv, "send_position");

    MYTOPIC get_piece("get_piece", 10);

    MYTOPIC send_all_position("send_all_posioin", 10);

    auto callback = [&send_all_position](const test::piece::ConstPtr& msg) {Get_Piece(*msg, send_all_position);};

    get_piece.Get<test::piece>(callback);

    while(ros::ok())
    {
        myros.Delay(10);
        ros::spinOnce();
    }

    return 0;
}
