#!/usr/bin/env python3

import rospy
from std_msgs.msg import Int32
import pigpio

# GPIO引脚设置
PIN = 21  # 选择GPIO引脚（例如，GPIO 17）
pi = pigpio.pi()  # 初始化pigpio库
pi.set_mode(PIN, pigpio.OUTPUT)  # 设置引脚为输出模式

pi.write(PIN, 1)


def gpio_callback(msg):
    # 根据接收到的消息设置GPIO引脚状态
    if msg.data == 1:
        pi.write(PIN, 1)
        rospy.loginfo("GPIO pin {} set to HIGH".format(PIN))
    elif msg.data == 0:
        pi.write(PIN, 0)
        rospy.loginfo("GPIO pin {} set to LOW".format(PIN))
    else:
        rospy.logwarn("Received invalid GPIO value: {}".format(msg.data))

def gpio_control_node():
    rospy.init_node('gpio_control_node', anonymous=True)
    rospy.Subscriber('gpio_control', Int32, gpio_callback)
    rospy.loginfo("GPIO Control Node started, listening to 'gpio_control' topic")
    rospy.spin()

if __name__ == '__main__':
    try:
        gpio_control_node()
    except rospy.ROSInterruptException:
        pass
    finally:
        pi.stop()  # 确保在退出时停止pigpio
