#!/usr/bin/env python3
# coding:utf8

import rospy
import numpy as np
import cv2
import cv2.aruco as aruco
from std_msgs.msg import Int32  # 导入Int32消息类型
import sys


cap = cv2.VideoCapture(0)

def aruco_detection(img, pub, aruco_ids):
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    
    # 设置预定义的字典为 original
    aruco_dict = aruco.Dictionary_get(aruco.DICT_ARUCO_ORIGINAL)
    parameters = aruco.DetectorParameters_create()
    
    # 使用aruco.detectMarkers()函数检测marker
    corners, ids, rejectedImgPoints = aruco.detectMarkers(gray, aruco_dict, parameters=parameters)
    
    if ids is not None:
        for id in ids.flatten():  # 将id展平为一维数组
            if id not in aruco_ids:
                aruco_ids.add(id)
                aruco.drawDetectedMarkers(img, corners, ids)
                
                # 显示检测到的ID
                print("Detected ID: %d" % id)

                if id :
                    rospy.set_param('aruco', int(id))
                    sys.exit()




                # # 发布ID到ROS主题
                # pub.publish(id)

                # 保存到文件
                try:
                    with open("one_aruco_data.txt", "a+") as f:
                        f.write("aruco_data:%d\n" % id)
                except IOError as e:
                    print("File write error: ", e)

            # # 在图像上显示ID
            # for corner in corners:
            #     cv2.putText(img, str(id), (int(corner[0][0][0]), int(corner[0][0][1])),
            #                 cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)
    # print("666")
    # cv2.imshow("frame", img)

def main():
    rospy.init_node('aruco', anonymous=True)  # 初始化ROS节点

    pub = rospy.Publisher('aruco_ids', Int32, queue_size=10)  # 创建发布者

    aruco_ids = set()  

    if not cap.isOpened():
        print("Error: Could not open camera.")
        return
    
    while not rospy.is_shutdown():
        ret, frame = cap.read()
        if not ret:
            break
        
        aruco_detection(frame, pub, aruco_ids)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows()

if __name__ == "__main__":
    try:
        print("[INFO] ARUCO")
        
        main()
    except rospy.ROSInterruptException:
        pass
