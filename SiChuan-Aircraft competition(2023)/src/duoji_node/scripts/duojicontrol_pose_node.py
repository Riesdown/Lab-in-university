#!/usr/bin/env python
# -*- coding: utf-8 -*-
# 该例程将订阅/laneline_info话题，自定义消息类型laneline_publisher::laneline

import rospy
import pigpio
import time
from std_msgs.msg import String
from duoji_node.msg import duoji_msg

pi = pigpio.pi()
gpio_pin = 13#设置 pwm输出为GPIO 13
Duoji_angle_max = 270#舵机最大角度
def duojiCallback(msg):
    duty =  (10*msg.Duoji_angle  /  Duoji_angle_max  + 2.5)
    pi.set_PWM_dutycycle(gpio_pin, duty*2)#设置占空比
    print("angle: %d  duty  = %d", msg.Duoji_angle , duty )

def  pwm_init():
    #初始化gpio
    
    if not pi.connected:
        print("connect err")
        exit()
    
    pi.set_mode(gpio_pin, pigpio.OUTPUT)  # 设置 GPIO 13 为输出模式
    pi.set_PWM_range(gpio_pin, 100*2)      # 设置 PWM 范围为 0-200
    pi.set_PWM_frequency(gpio_pin, 50)  # 设置 PWM 频率为 50 Hz
    pi.set_PWM_dutycycle(gpio_pin, 50*2)   # 设置 PWM 占空比为 50%
    

def duoji_subscriber():
	# ROS节点初始化
    rospy.init_node('duoji_angle_subscriber', anonymous=True)

	# 创建一个Subscriber，订阅名为/laneline_info的topic，注册回调函数lanelineInfoCallback
    rospy.Subscriber("/duoji_angle", duoji_msg, duojiCallback)
    
	# 循环等待回调函数
    rospy.spin()

if __name__ == '__main__':
    print("hello")
    pwm_init()
    duoji_subscriber();
