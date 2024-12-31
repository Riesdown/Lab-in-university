#pragma once

#include "test/PTC/MyTopic.hpp"
#include "test/PTC/MyList.hpp"
#include "test/all_position.h"


class ARM_SET
{
    private:
        MYLIST list;

        // 图像像素宽度
        static constexpr u16 w_date = 266;
        static constexpr u16 h_date = 266;

        //图像的实际长度
        static constexpr u16 x_date = 95;  //mm
        static constexpr u16 y_date = 95;

        //复位位置
        static constexpr u8 init_x = 0;
        static constexpr u8 init_y = 0;

        //相同棋子位置的距离
        static constexpr u8 piece_x = 42;

        //黑白棋子距离
        static constexpr u8 piece_y = 170;

        //位置偏移
        static constexpr u8 offset_x = 0;
        static constexpr u8 offset_y = 0;

        u8 state = 0;

        struct RATIO
        {
           f32 x;
           f32 y;
        };
        RATIO xy_ratio;

        struct XY_AIM
        {
            f32 chess_aim_x;
            f32 chess_aim_y;
        };
        XY_AIM xy_aim;



        void Pixel_Transformation(u16 w, u16 h, u32 x, u32 y);


        // 固定位置，待调整
        f32 piece_position[2][5][2] = 
        {
            // 黑棋
            {
                {offset_x, offset_y}, {offset_x, piece_x + offset_y}, {offset_x, piece_x*2 + offset_y}, 
                {offset_x, piece_x*3 + offset_y}, {offset_x, piece_x*4 + offset_y}
            },
            // 白棋
            {
                {piece_y + offset_x, offset_y}, {piece_y + offset_x, piece_x + offset_y}, 
                {piece_y + offset_x, piece_x*2 + offset_y}, 
                {piece_y + offset_x, piece_x*3 + offset_y}, {piece_y + offset_x, piece_x*4 + offset_y}
            }

        };



    public:
        ARM_SET();
        
        u8 Check_Up(u8 chess_change, u8 chess_num);
        u8 Check_Down(f32 x, f32 y);
        void Place(u8 chess_change, u8 chess_num, const test::key_send& arm_aim);
};



ARM_SET::ARM_SET()
{
    Pixel_Transformation(w_date, h_date, x_date, y_date);
}




// 将像素坐标与实际联系，得到一个比例.实际坐标的单位为mm
void ARM_SET::Pixel_Transformation(u16 w, u16 h, u32 x, u32 y)
{
    xy_ratio.x = static_cast<float>(x) / static_cast<float>(w);
    xy_ratio.y = static_cast<float>(y) / static_cast<float>(h);
}


/************************* */


// 1：磁铁吸起成功 0：未成功
u8 ARM_SET::Check_Up(u8 chess_change, u8 chess_num)
{
    //手动模式
    if(0 == list.Get<i32>("auto"))
    {
        if(state || 0 == list.Get<i32>("arm_start") ) return 0;
    }
    else
    {
        if(state) return 0;
    }



    xy_aim.chess_aim_x = piece_position[chess_change - 1][chess_num - 1][0];
    xy_aim.chess_aim_y = piece_position[chess_change - 1][chess_num - 1][1];

    ROS_INFO("UP:  x: %f, y: %f", xy_aim.chess_aim_x, xy_aim.chess_aim_y);

    if(1 == list.Get<i32>("aim_flag"))  // 0：xy未到达位置 1：xy到达位置
    {
    
        list.Send<i32>("arm_set", 1); // 0: 松 1： 吸
        if(1 == list.Get<i32>("arm_back")) 
        {
            state = 1;
            list.Send<i32>("aim_flag", 0);
            return 1; // 0: 松 1： 吸
        }
    }

    list.Send<f32>("chess_aim_x", xy_aim.chess_aim_x);
    list.Send<f32>("chess_aim_y", xy_aim.chess_aim_y);



    return 0;
}




u8 ARM_SET::Check_Down(f32 x, f32 y)
{

    //手动模式
    if(0 == list.Get<i32>("auto"))
    {
        if(!state || 0 == list.Get<i32>("arm_start") ) return 0;
    }
    else
    {
        if(!state) return 0;
    }


    // xy_aim.chess_aim_x = x * xy_ratio.x;
    // xy_aim.chess_aim_y = y * xy_ratio.y;

    xy_aim.chess_aim_x = x;
    xy_aim.chess_aim_y = y;

    // ROS_INFO("xy_ratio.x: %f, xy_ratio.y: %f", xy_ratio.x, xy_ratio.y);

    ROS_INFO("DOWN:  x: %f, y: %f", xy_aim.chess_aim_x, xy_aim.chess_aim_y);

    if(1 == list.Get<i32>("aim_flag"))  // 0：xy未到达位置 1：xy到达位置
    {
        ROS_INFO("到达位置");
        list.Send<i32>("arm_set", 0); // 0: 松 1： 吸
        if(0 == list.Get<i32>("arm_back")) 
        {
            state = 0;
            ROS_INFO("松");
            list.Send<i32>("aim_flag", 0);
            list.Send<i32>("arm_start", 0);


            list.Send<f32>("chess_aim_x", init_x);
            list.Send<f32>("chess_aim_y", init_y);

            return 1; // 0: 松 1： 吸
        }
    }

    list.Send<f32>("chess_aim_x", xy_aim.chess_aim_x);
    list.Send<f32>("chess_aim_y", xy_aim.chess_aim_y);

    return 0;
}


