#!/usr/bin/env python3
# coding=utf-8

import cv2
import numpy as np
import rospy
from test.msg import piece
from test.msg import all_position

# 初始化ROS节点
rospy.init_node("sanziqi_node")
rospy.logwarn("The initialization is successful")

# 打开摄像头
cap = cv2.VideoCapture(0)

# 定义ROI参数
roi_x = 250
roi_y = 135
roi_w = 205
roi_h = 205

# 定义网格参数
rows = 3
cols = 3

# 初始化ID
ID = 0

# 创建消息和发布者
msg = piece()
pub = rospy.Publisher("get_piece", piece, queue_size=10)

# 圆检测参数
dp = 1.2
minDist = 30
param1 = 50
param2 = 30
minRadius = 10
maxRadius = 30

num = 0

while not rospy.is_shutdown():
    # 读取一帧图像
    ret, frame = cap.read()
    if not ret:
        rospy.logerr("Failed to capture image from camera")
        break

    # 获取ROI
    roi = frame[roi_y:roi_y + roi_h, roi_x:roi_x + roi_w]

    # 计算网格的宽度和高度
    grid_width = roi_w // cols
    grid_height = roi_h // rows

    # 遍历网格
    for i in range(rows):
        for j in range(cols):
            ID = i * cols + j + 1  # 根据行列索引计算ID

            # 计算当前网格的左上角和右下角坐标
            l_x = roi_x + j * grid_width
            l_y = roi_y + i * grid_height
            r_x = l_x + grid_width
            r_y = l_y + grid_height

            # 获取当前网格的图像
            grid_roi = roi[l_y - roi_y:r_y - roi_y, l_x - roi_x:r_x - roi_x]

            # 转换为灰度图像
            gray = cv2.cvtColor(grid_roi, cv2.COLOR_BGR2GRAY)

            # 检测圆形轮廓
            circles = cv2.HoughCircles(gray, cv2.HOUGH_GRADIENT, dp, minDist,
                                       param1=param1, param2=param2,
                                       minRadius=minRadius, maxRadius=maxRadius)

            status = 0  # 假设0表示空

            if circles is not None:
                circles = np.uint16(np.around(circles))
                for circle in circles[0, :]:
                    center = (circle[0], circle[1])  # 圆心
                    radius = circle[2]  # 半径

                    # 在图像上绘制圆形
                    cv2.circle(grid_roi, center, radius, (0, 255, 0), 2)

                    # 提取圆形区域内的像素
                    mask = np.zeros_like(gray)
                    cv2.circle(mask, center, radius, 255, -1)
                    mean_val = cv2.mean(grid_roi, mask=mask)[:3]  # 获取圆形区域内的平均颜色

                    # 判断黑白色
                    if mean_val[2] < 60:  # 调整阈值
                        status = 2  # 黑棋
                    elif mean_val[2] > 100:  # 调整阈值
                        status = 1  # 白棋

            # 在图像上绘制矩形
            cv2.rectangle(frame, (l_x, l_y), (r_x, r_y), (0, 255, 0), 2)

            print("state: {}, ID: {}".format(status, ID))
            # 创建并发布消息
            msg = piece()
            msg.id = ID
            msg.status = status
            pub.publish(msg)

    # 显示图像
    cv2.imshow("Frame", frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()

