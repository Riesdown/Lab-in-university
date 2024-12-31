#!/usr/bin/env python
# -*- coding: utf-8 -*-

import rospy
from test.msg import cloud_date
import matplotlib.pyplot as plt
from geometry_msgs.msg import PoseStamped
from test.msg import fly_position
import sys


# Node and parameters setup
node_name = 'cloud_map'
get_cloud_name = 'cloud_start'
get_cloud_close_name = 'cloud_close'

x_min = rospy.get_param('yaml_x_min', 0.003)
x_max = rospy.get_param('yaml_x_max', 0)
y_min = rospy.get_param('yaml_y_min', 0)
y_max = rospy.get_param('yaml_y_max', 0)

while x_min == 0.003:
    print("[INFO] Wait Data...")
    rospy.sleep(1)

rospy.init_node(node_name, anonymous=True)

positions = []
positions_close = []
local_position = []
aim_position = []

plt.xlabel('X')
plt.ylabel('Y')
plt.title('Point Cloud Visualization')

clicked_position = None  
num = 0


msg = fly_position()
pub = rospy.Publisher('fly_position', fly_position, queue_size=10)



def Cloud_CallBack(data):
    global positions
    positions.append((data.x, data.y))
    
    if num > 0:
        pub.publish(msg)
    
    

def Cloud_Close_CallBack(data):
    global positions_close
    positions_close.append((data.x, data.y))

def Local_CallBack(data):
    global local_position
    local_position.append((data.pose.position.x, data.pose.position.y))

def Aim_CallBack(data):
    global aim_position
    aim_position.append((data.pose.position.x, data.pose.position.y))

def Click_CallBack(event):
    global clicked_position
    if event.inaxes and event.button == 1:  # 左键选择
        clicked_position = (event.xdata, event.ydata)
        print("click: ({:.2f}, {:.2f})".format(clicked_position[0], clicked_position[1]))

def True_CallBack(event):
    global clicked_position, num, msg
    if event.button == 3 and clicked_position:  # 右键确认
        num += 1
        print("get{:d}: ({:.2f}, {:.2f})\n".format(num, clicked_position[0], clicked_position[1]))
        
        if num == 1:
            msg.x1 = float(clicked_position[0])
            msg.y1 = float(clicked_position[1])
        if num == 2:
            msg.x2 = float(clicked_position[0])
            msg.y2 = float(clicked_position[1])
        if num == 3:
            msg.x3 = float(clicked_position[0])
            msg.y3 = float(clicked_position[1])
        if num == 4:
            msg.x4 = float(clicked_position[0])
            msg.y4 = float(clicked_position[1])
        if num == 5:
            msg.x5 = float(clicked_position[0])
            msg.y5 = float(clicked_position[1])
        if num == 6:
            msg.x6 = float(clicked_position[0])
            msg.y6 = float(clicked_position[1])

        clicked_position = None


def Clear_CallBack(event):
    global num
    if event.key == 'enter':  # 按下 Enter 键清除
        num = 0
        msg.x1 = 0
        msg.y1 = 0
        msg.x2 = 0
        msg.y2 = 0
        msg.x3 = 0
        msg.y3 = 0
        msg.x4 = 0
        msg.y4 = 0
        msg.x5 = 0
        msg.y5 = 0
        msg.x6 = 0
        msg.y6 = 0
        
        
        
        print("clear\n")

def Ready_CallBack(event):
    if event.key == ' ': # 按下空格键准备
        
        rospy.set_param('black_ready', int(1) )
        
        print("ready\n")



def Update_Plot():
    plt.clf()

    plt.xlim(x_min, x_max)
    plt.ylim(y_min, y_max)
    plt.grid(True)

    if positions and local_position and aim_position and positions_close:  
        x, y = zip(*positions)  
        x1, y1 = zip(*local_position)
        x2, y2 = zip(*aim_position)
        x3, y3 = zip(*positions_close)
        plt.plot(x, y, color='green', marker='o', linestyle='None', markersize=1)  
        plt.plot(x1, y1, color='b', marker='o')  
        plt.plot(x3, y3, color='red', marker='o')  
        plt.plot(x2, y2, color='b', marker='+')  
        plt.pause(0.2)  

rospy.Subscriber(get_cloud_name, cloud_date, Cloud_CallBack)
rospy.Subscriber(get_cloud_close_name, cloud_date, Cloud_Close_CallBack)
rospy.Subscriber("mavros/local_position/pose", PoseStamped, Local_CallBack)
rospy.Subscriber("mavros/setpoint_position/local", PoseStamped, Aim_CallBack)



plt.ion()
plt.show()

# 鼠标按键中断
cid_click1 = plt.gcf().canvas.mpl_connect('button_press_event', Click_CallBack)
cid_click2 = plt.gcf().canvas.mpl_connect('button_press_event', True_CallBack)
cid_key1 = plt.gcf().canvas.mpl_connect('key_press_event', Clear_CallBack)
cid_key2 = plt.gcf().canvas.mpl_connect('key_press_event', Ready_CallBack)


print("......")
print("......")
print("......")
print("......")
print("......")
print("......")

while not rospy.is_shutdown():
    Update_Plot() 
    positions = []
    local_position = []
    aim_position = []
    positions_close = []
    
    
    
