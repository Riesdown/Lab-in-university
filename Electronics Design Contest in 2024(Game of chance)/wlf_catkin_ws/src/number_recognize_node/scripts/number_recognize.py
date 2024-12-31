#!/usr/bin/env python
# -*- coding: utf-8 -*-
import rospy
import pigpio
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
def  usart_init():
    #初始化gpios
    if not pi.connected:
        print("connect err")
        exit()
    pi.set_mode(gpio_rx_pin, pigpio.INPUT)
    pi.set_mode(gpio_tx_pin, pigpio.OUTPUT)
    pigpio.exceptions = False
    pi.bb_serial_read_close(gpio_rx_pin)
    pigpio.exceptions = True
    pi.bb_serial_read_open(gpio_rx_pin, BAUD, 8)

def pub_init():
    # 初始化一个节点
    rospy.init_node('talker', anonymous=True)
   


def  msg_JX(msg_dates):
    if(len(msg_dates ) !=13     ):
        return
    print(len(msg_dates))
    num_info = numeber_info_msgs()
    msg_date = re.findall(r'\d+' , msg_dates)
    num_info.flag = bool(int(msg_date[0]))
    num_info.num = int(msg_date[1]) 
    num_info.center_x =  int(msg_date[2]) 
    num_info.center_y =  int(msg_date[3]) 
    pub.publish(num_info)    # 发布消息到话题



def usart_read():
    msg = bytes()
    while 1:
        count, data = pi.bb_serial_read(gpio_rx_pin)
        if count:
           if data == 's': #帧头
                msg = bytes()
           msg += data
           if data == 'l': #帧尾
            msg_JX(msg)
            print( msg) 
        #stime.sleep(0.015)



            

if __name__ == '__main__':
    print("hello")
    usart_init()
    pub_init()
    usart_read();
    print("hello11")
    