#!/usr/bin/env python3
# coding:utf8

import rospy
import cv2
import numpy as np
import cv2.aruco as aruco
import sys
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
from test.msg import circle
import time




rospy.init_node('circle_detection', anonymous=True)

def circle_detection():
    cap = cv2.VideoCapture(0)

    # # 尝试打开摄像头
    # while not rospy.is_shutdown():
    #     if not cap.isOpened():
    #         # print("Cannot open camera.")
    #         continue
    #     else:
    #         # print("Camera successfully")
    #         break

    pub = rospy.Publisher('circle_cen', circle, queue_size=2)
    cir_msg = circle()

    aruco_ids = set()  # 用来保存检测到的二维码id

    flag1 = 0
    flag2 = 0

    while not rospy.is_shutdown():
        start_camera_land = rospy.get_param('start_camera_land', 0)
        start_camera_car = rospy.get_param('start_camera_car', 1)  # 获取控制二维码识别的参数
        
        success, img = cap.read()

        if img is None:
            # print("Failed to capture image from camera!")
            rospy.sleep(1)  # 等待1秒后重试
            continue  # 跳过当前循环，尝试重新捕获图像

        # imgcopy2 = img.copy()

        if start_camera_car == 1:
            if flag1 == 0:
                print("Waiting ArUco ")
                flag1 = 1
            
 
            
            aruco_detection(img, aruco_ids)

        if start_camera_land == 1 and start_camera_car == 2:
            
            if flag2 == 0:
                print("Waiting Land")
                flag2 = 1
                
            img = cv2.resize(img, (320, 240))
            imghsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
            mask = cv2.inRange(imghsv, np.array([100, 70, 100]), np.array([140, 255, 255]))

            kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (5, 5))
            mask1 = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernel)
            mask2 = cv2.morphologyEx(mask1, cv2.MORPH_CLOSE, kernel)

            blur_buleimg = cv2.bilateralFilter(mask2, 5, 75, 75)

            edges = cv2.Canny(mask2, 100, 200, apertureSize=5, L2gradient=True)

            contours = cv2.findContours(mask2, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[0]
            
            max_area = 0
            max_contour = None

            for contour in contours:
                area = cv2.contourArea(contour)
                if area > 500:  
                    if area > max_area:
                        max_area = area
                        max_contour = contour

            if max_contour is not None:
                (x, y), radius = cv2.minEnclosingCircle(max_contour)
                center = (int(x), int(y))
                radius = int(radius)
                cv2.circle(img, center, radius, (0, 0, 255), 3)

                M = cv2.moments(max_contour)
                if M["m00"] != 0:
                    cir_msg.x = -int(M["m10"] / M["m00"]) + 160
                    cir_msg.y = -int(M["m01"] / M["m00"]) + 120
                    # circle_center = (int(M["m10"] / M["m00"]), int(M["m01"] / M["m00"]))
                    # print("Circle center:", circle_center)
                    
                    pub.publish(cir_msg)
                    

            # try:
            #     img_msg = bridge.cv2_to_imgmsg(img, "bgr8")
            #     pub.publish(img_msg)
            # except CvBridgeError as e:
            #     print(e)

            # cv2.imshow('Processed Image', img)

            # if cv2.waitKey(1) & 0xFF == 27:
            #     break
        
    # 在程序结束时释放资源
    cap.release()
    cv2.destroyAllWindows()


def aruco_detection(imgcopy1, aruco_ids):
    gray = cv2.cvtColor(imgcopy1, cv2.COLOR_BGR2GRAY)

    # 设置预定义的字典为 original
    aruco_dict = aruco.Dictionary_get(aruco.DICT_ARUCO_ORIGINAL)
    parameters = aruco.DetectorParameters_create()

    corners, ids, _ = aruco.detectMarkers(gray, aruco_dict, parameters=parameters)

    if ids is not None:
        for id in ids.flatten():  # 将id展平为一维数组
            if id not in aruco_ids:
                aruco_ids.add(id)
                aruco.drawDetectedMarkers(imgcopy1, corners, ids)

                if id:
                    rospy.set_param('aruco', int(id))
                    rospy.set_param('start_camera_car', int(2))
                    # print("Detected ID: %d" % id)
                    


if __name__ == "__main__":
    try:
        print("ALL..")
        circle_detection()
    except rospy.ROSInterruptException:
        pass