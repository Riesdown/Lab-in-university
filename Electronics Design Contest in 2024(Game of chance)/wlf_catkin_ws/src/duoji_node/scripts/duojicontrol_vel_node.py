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
time_of360  = 7;#一圈时间
go_speed = 157;#旋转速度
stop_speed = 150;#旋转速度

duoji_angle_now = 0;
turn_flag = False;#转动标志
turn_time = 0;#旋转时间
time_setpoint = 0
def set_duoji_speed(speed):
    pi.set_PWM_dutycycle(gpio_pin, speed);

def duojiCallback(msg):
   duoji_angle_control(msg.Duoji_angle );

def duoji_angle_control(angle_exp):
    global turn_flag
    angle_err = angle_exp - duoji_angle_now;
    if(angle_err  >0):
        turn_flag = True;
        turn_time = time_of360*angle_err/360.0;
        duoji_angle_now = angle_exp;
        time_setpoint  = rospy.Time.now();
    if( turn_flag ):
        if( rospy.Time.now() - time_setpoint < rospy.Duration(turn_time)):
             pi.set_PWM_dutycycle(gpio_pin, go_speed);
        else:
            pi.set_PWM_dutycycle(gpio_pin, stop_speed);
            turn_flag = False
    else:
        pi.set_PWM_dutycycle(gpio_pin, stop_speed);

        

def  pwm_init():
    #初始化gpio
    
    if not pi.connected:
        print("connect err")
        exit()
    
    pi.set_mode(gpio_pin, pigpio.OUTPUT)  # 设置 GPIO 13 为输出模式
    pi.set_PWM_range(gpio_pin, 1000*2)      # 设置 PWM 范围为 0-200
    pi.set_PWM_frequency(gpio_pin, 50)  # 设置 PWM 频率为 50 Hz
    pi.set_PWM_dutycycle(gpio_pin, 150)   # 设置 PWM 占空比为 7.5%
    

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
