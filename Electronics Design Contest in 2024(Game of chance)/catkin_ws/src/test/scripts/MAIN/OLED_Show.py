#!/usr/bin/env python3
# coding=utf-8
from luma.core.interface.serial import i2c
from luma.core.render import canvas
from luma.oled.device import ssd1306
from time import sleep
from PIL import ImageFont
import rospy
from test.msg import key_send
from test.msg import piece


"""
    连线:(使用BCM编码)
    SDA-BCM2, SCL-BCM3
"""

# 初始化ROS节点
rospy.init_node('oled_display', anonymous=True)

# 初始化端口
serial = i2c(port=1, address=0x3C)
device = ssd1306(serial)

# 加载字体
font_path = "/usr/share/fonts/opentype/noto/NotoSansCJK-Regular.ttc"
font_small = ImageFont.truetype(font_path, 12)
font_middle = ImageFont.truetype(font_path, 16)
font_large = ImageFont.truetype(font_path, 24)

# 创建发布者
pub = rospy.Publisher('arm_date', key_send, queue_size=10)
pub_piece = rospy.Publisher('get_piece', piece, queue_size=10)


rospy.set_param("arm_start", 0)


# 初始化变量
key_value = 0       # 按键值
chess_change = 1    # 棋子改变
chess_num = 1       # 棋子编号
position = 1        # 位置
flag_note = 0       # 指示按键
num_time = 0        # 计时
flag_true = 0       # 确认键

angle_0 = 0         # 角度的个位
angle_10 = 0        # 角度的十位
angle = 0           # 角度
PN_ = 1             # 正负


mode = 1            # 手动或自动模式

black = 1           # 1: 人下黑棋    2: 人下白棋

ai_start = 1        # AI开始下棋



def Fixed_Font(draw):
    draw.text((0, 0), "时间:", font=font_small, fill="white")
    draw.text((0, 45), "位置:", font=font_small, fill="white")
    draw.text((0, 20), "黑白棋选择:", font=font_small, fill="white")
    draw.text((60, 45), "角度:", font=font_small, fill="white")

def Change_Mode():
    global position, chess_change, chess_num, flag_note, num_time, flag_true, angle_10, angle_0, mode, black, ai_start, PN_

    if key_value == 1:                              # 位置
        position = position % 9 + 1
    elif key_value == 2:                           # 棋子改变
        chess_change = chess_change % 2 + 1
    elif key_value == 3:                           # 棋子编号
        chess_num = chess_num % 5 + 1


    elif key_value == 5:                           # 棋子的10位
        angle_10 = (angle_10 + 1) % 5
    elif key_value == 6:                           # 棋子的个位
        angle_0 = (angle_0 + 1) % 6
    elif key_value == 7:                           # 度数正负，左转为负
        PN_ = -1
    elif key_value == 8:                           # 度数正负，右转为正
        PN_ = 1


    elif key_value == 9:                           # 模式切换
        mode = mode % 2 + 1
    elif key_value == 10:                           # 黑白
        black = black % 2 + 1
    elif key_value == 11:                           # 自动模式开始确认键
        ai_start = ai_start % 2 + 1


    elif key_value == 16:                           # 指示按键
        flag_note = 1 if flag_note == 0 else 0
        rospy.set_param("aistop", 1)                # 开启机器动
        rospy.set_param("getpc", 1)  

    elif key_value == 15:                           # 清空                         
        reset_values()
    elif key_value == 14:                           # 手动操控确认键                        
        flag_true = 1
        # 发送信息, 考虑一下接收是否能接收到
        for i in range(100):
            msg = key_send()
            msg.chess_change = chess_change
            msg.chess_num = chess_num
            msg.position = position
            pub.publish(msg)
            rospy.sleep(0.01)



    if key_value != 0:
        rospy.set_param("key", 0)

def reset_values():
    global chess_change, chess_num, position, flag_note, num_time, flag_true, angle_0, angle_10
    chess_change = 1
    chess_num = 0
    position = 0
    flag_note = 0
    num_time = 0
    flag_true = 0
    angle_0 = 0
    angle_10 = 0
    rospy.set_param("ai_start", 0)


def OLED_Mode(draw):
    global angle, flag_true
    draw.text((70, 20), "黑棋" if chess_change == 1 else "白棋", font=font_small, fill="white")
    draw.text((40, 45), str(position), font=font_small, fill="white")
    draw.text((100, 20), str(chess_num), font=font_small, fill="white")
    draw.text((30, 0), str(num_time), font=font_small, fill="white")
    if flag_true == 1:
        # draw.text((90, 0), "已发送", font=font_small, fill="white")
        rospy.set_param("arm_start", 1)
        flag_true = 0
        rospy.sleep(3)
        draw.text((90, 0), "        ", font=font_small, fill="white")


    angle = (angle_10 * 10 + angle_0) * PN_
    draw.text((100, 45), str(-angle), font=font_small, fill="white")

    if mode == 1:
        rospy.set_param("auto", 0)
        draw.text((50, 0), "手动", font=font_small, fill="white")
    else:
        rospy.set_param("auto", 1)
        draw.text((50, 0), "自动", font=font_small, fill="white")

    if black == 1:
        rospy.set_param("black", 1)
        draw.text((80, 0), "黑", font=font_small, fill="white")
    else:
        rospy.set_param("black", 0)
        draw.text((80, 0), "白", font=font_small, fill="white")

    if ai_start == 2:
        rospy.set_param("ai_start", 1)
        draw.text((100, 0), "YES", font=font_small, fill="white")
    else:
        rospy.set_param("ai_start", 0)
        draw.text((100, 0), "NO ", font=font_small, fill="white")



rospy.loginfo("OLED已启动...")


def main():
    global key_value, num_time, aistop_set
    rospy.set_param("key", 0)
    try:
        while not rospy.is_shutdown():
            with canvas(device) as draw:
                Fixed_Font(draw)    # 固定显示
                OLED_Mode(draw)     # 模式显示
                Change_Mode()       # 改模式

                if flag_note == 1:
                    num_time += 1
                else:
                    num_time = 0

                    
            msg2 = piece()
            msg2.angle = angle
            pub_piece.publish(msg2)

            key_value = rospy.get_param("key")
            # rospy.loginfo("key_value: %d", key_value)
            # rospy.loginfo("chess_selection: %d", chess_change)

            rospy.sleep(0.05)
    except KeyboardInterrupt:
        print("显示程序已终止")

if __name__ == "__main__":
    main()
