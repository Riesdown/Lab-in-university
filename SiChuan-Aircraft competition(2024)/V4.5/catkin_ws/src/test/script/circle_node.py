#!/usr/bin/env python
# coding:utf8

import rospy
import cv2
import numpy as np
from cv_bridge import CvBridge, CvBridgeError
from test.msg import circle
import time

def circle_detection_node():
    rospy.init_node('circle_detection', anonymous=True)
    pub = rospy.Publisher('circle_cen', circle, queue_size=10)


    while(rospy.get_param('start_camera_land', 0) == 0):
        time.sleep(0.1)
        
    cir_msg = circle()
    bridge = CvBridge()
    cap = cv2.VideoCapture(0)

    while not rospy.is_shutdown():
        success, img = cap.read()
        if not success:
            break
        
        img = cv2.resize(img, (320, 240))
        imghsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
        mask = cv2.inRange(imghsv, np.array([100, 70, 100]), np.array([140, 255, 255]))

        kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (5, 5))
        mask1 = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernel)
        mask2 = cv2.morphologyEx(mask1, cv2.MORPH_CLOSE, kernel)

        blur_buleimg = cv2.bilateralFilter(mask2, 5, 75, 75)

        edges = cv2.Canny(mask2, 100, 200, apertureSize=5, L2gradient=True)

        contours = cv2.findContours(mask2, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[1]

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

        if cv2.waitKey(1) & 0xFF == 27:
            break

    cap.release()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    try:
        print("[INFO] CIRCLE")
        
        circle_detection_node()
    except rospy.ROSInterruptException:
        pass
