#include "std_msgs/String.h"
#include "test/all_position.h"
#include "test/key_send.h"
#include "test/next_piece.h"
/**********  0  ***************/
#include "ros/ros.h"
#include <cmath>
#include <map>
/**********  1  ***************/
#include "test/SYS/Some_define.hpp"
#include "test/PTC/MyTopic.hpp"
#include "test/PTC/MyList.hpp"
/**********  2  ***************/
#include "test/SYS/MyROS.hpp"
#include "test/HW/Arm_Set.hpp"

test::all_position position_date;
test::key_send arm_aim;
std::map<u16, test::all_position> position_map;

MYLIST mylist;

test::next_piece next_piece_date;

using namespace std_msgs;

void Arm_Run(const test::key_send::ConstPtr& msg)
{
    arm_aim = *msg;
}

void Get_Position(const test::all_position::ConstPtr& msg) 
{
    position_date = *msg;
    position_map[position_date.id] = position_date;

    for (auto& date : position_map)
    {
        // ROS_INFO("ID: %d, 坐标为：[%f, %f]  [%f, %f]", date.first, date.second.x1, date.second.y1, date.second.x2, date.second.y2);
    }

    // ROS_INFO("棋盘的坐标为：[%f, %f]  [%f, %f]", position_date.x1, position_date.y1, position_date.x2, position_date.y2);
}

void Get_Arm_State(const std_msgs::String::ConstPtr& msg, ARM_SET& arm_set)
{
    ROS_INFO("现在的模式：%d", mylist.Get<i32>("auto"));
    // if (arm_aim.chess_change == 1)        ROS_INFO("拿起黑棋");
    // else        ROS_INFO("拿起白棋");


    // ROS_INFO("拿起棋子的ID为: %d", arm_aim.chess_num);
    // ROS_INFO("棋子放到的位置是: %d", arm_aim.position);

    //手动
    if(0 == mylist.Get<i32>("auto"))
    {
        // 捡棋子
        if (arm_set.Check_Up(arm_aim.chess_change, arm_aim.chess_num))
        {
            ROS_INFO("捡起成功");
        }

        // 放棋子
        auto it = position_map.find(arm_aim.position);
        const test::all_position& pos = it->second;


        // ROS_INFO("x1:%f, y1: %f, x2: %f, y2: %f", pos.x1, pos.y1, pos.x2, pos.y2);

        // ROS_INFO("放置棋子的位置为：[%f, %f]", (pos.x1 + pos.x2) / 2, (pos.y1 + pos.y2) / 2);
        if (arm_set.Check_Down((pos.x1 + pos.x2) / 2, (pos.y1 + pos.y2) / 2))
        {
            ROS_INFO("放置成功");
        }
    }
    else //自动
    {
        ROS_INFO("自动模式");
        if(1 == mylist.Get<i32>("aistop"))
        {
            static u8 chess_piece = 0;
            static u8 chess_num = 1;

            ROS_INFO("下一个棋子的位置正在放置：%d", next_piece_date.next);

            chess_piece = mylist.Get<i32>("black");  //0：人白棋，机器黑棋   1：人黑棋，机器白棋

            // 捡棋子，arm_aim.chess_change：：1，机器下黑棋，2：机器下白棋
            //arm_aim.chess_num :: 1-5 棋子的编号


            // ROS_INFO("拿起棋子的ID为: %d", chess_piece + 1);
            // ROS_INFO("棋子放到的位置是: %d", next_piece_date.next);

            if (arm_set.Check_Up(chess_piece + 1, chess_num))
            {
                chess_num++;
                ROS_INFO("捡起成功");
            }

            ROS_INFO("九宫格的位置为：%d", next_piece_date.next);

            // 放棋子arm_aim.position ::1-9,棋子的位置
            auto it = position_map.find(next_piece_date.next);
            const test::all_position& pos = it->second;


            // ROS_INFO("x1:%f, y1: %f, x2: %f, y2: %f", pos.x1, pos.y1, pos.x2, pos.y2);

            ROS_INFO("放置棋子的位置为：[%f, %f]", (pos.x1 + pos.x2) / 2, (pos.y1 + pos.y2) / 2);
            if (arm_set.Check_Down((pos.x1 + pos.x2) / 2, (pos.y1 + pos.y2) / 2))
            {
                ROS_INFO("放置成功");
                // for(u8 i = 0; i < 10; i++)  
                // {
                //     ros::WallDuration(0.1).sleep();
                    mylist.Send<i32>("aistop", 0);

            }
        }
 

    }

}


void Get_Next_Piece(const test::next_piece::ConstPtr& msg)
{
    next_piece_date = *msg;

    ROS_INFO("下一个棋子的位置是：%d", next_piece_date.next);
}




int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");

    MYROS myros(argc, argv, "Arm_Contorl");

    MYTOPIC get_position("send_all_posioin", 10);
    MYTOPIC get_start("arm_date", 10);
    MYTOPIC task("Task_500ms", 10);

    MYTOPIC get_nextpiece("next_piece", 10);
    get_nextpiece.Get<test::next_piece>(Get_Next_Piece);

    ARM_SET arm_set;

    get_position.Get<test::all_position>(Get_Position);

    auto callback = boost::bind(Arm_Run, _1);
    get_start.Get<test::key_send>(callback);

    auto callback2 = boost::bind(Get_Arm_State, _1, boost::ref(arm_set));
    task.Get<std_msgs::String>(callback2);


    while(ros::ok())
    {
        myros.Delay(50);
        ros::spinOnce();
    }

    return 0;
}
