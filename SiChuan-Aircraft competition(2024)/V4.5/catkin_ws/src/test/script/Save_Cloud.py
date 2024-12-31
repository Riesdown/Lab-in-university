#!/usr/bin/env python
# -*- coding: utf-8 -*-

from all_pkg.other_pkg.CSV.Csv import CSV
import rospy
from test.msg import cloud_date

'''.......................................................................'''
node_name = 'save_cloud'
get_cloud_name = 'cloud_start'
'''.......................................................................'''
rospy.init_node(node_name, anonymous=True)

# 输入点云坐标
csv = CSV("/home/shili/catkin_ws/src/test/CSV_DATA/cloud_test.csv")

lab = ["cloud_x", "cloud_y", "aim_xy"]
csv.Save_Label(lab)

aim_xy_data_json = [
    (2.1,0),
    (2.1,0.5),
    (3.5,0.5),
    (3.5,-0.5),
    (5,-0.5)
]

aim_xy_data = csv.Trans_JsonData(aim_xy_data_json)

num = 0

def Cloud_CallBack(data):
    global num
    cloud_xy = [round(data.x, 4), round(data.y, 4), aim_xy_data]
    csv.Save_Data(cloud_xy)
    num += 1
    if num == 5000:
        rospy.signal_shutdown("[INFO] Save_Cloud Finish")

rospy.Subscriber(get_cloud_name, cloud_date, Cloud_CallBack)

print("[INFO] Save_Cloud Good")
rospy.spin()
