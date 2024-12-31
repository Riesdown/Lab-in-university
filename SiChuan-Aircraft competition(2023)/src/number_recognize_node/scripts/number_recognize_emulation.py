#!/usr/bin/env python
# -*- coding: utf-8 -*-
import rospy
import time
import re
from std_msgs.msg import String
from number_recognize_node.msg import numeber_info_msgs
BAUD = 9600
gpio_tx_pin = 7#设置 pwm输出为GPIO 13
gpio_rx_pin = 24#设置 pwm输出为GPIO 13
pi = pigpio.pi()
msg = bytes()

pub = rospy.Publisher('/num_info', numeber_info_msgs, queue_size=10)

def pub_init():
    # 初始化一个节点
    rospy.init_node('talker', anonymous=True)
   


# 计数器和上一次识别的数字
consecutive_count = 0
last_number = None

def msg_JX(msg_dates):
    global consecutive_count, last_number
    if(len(msg_dates) != 13):
        return
    num_info = numeber_info_msgs()
    msg_date = re.findall(r'\d+', msg_dates)
    current_number = int(msg_date[1])
    if current_number == last_number:
        consecutive_count += 1
    else:
        consecutive_count = 1
        last_number = current_number
    if consecutive_count >= 10:
        num_info.flag = bool(int(msg_date[0]))
    else:
        num_info.flag = false
    num_info.num = current_number
    num_info.center_x = int(msg_date[2])
    num_info.center_y = int(msg_date[3])
    pub.publish(num_info)  # 发布消息到话题




            

if __name__ == '__main__':
    print("hello")
    pub_init()
    usart_read();
    print("hello11")
    






