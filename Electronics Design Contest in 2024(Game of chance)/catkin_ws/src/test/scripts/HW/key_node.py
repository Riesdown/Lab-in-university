#!/usr/bin/env python3
# coding=utf-8
import pigpio
import time
import os
import rospy

if __name__ == '__main__':
        
    if not rospy.has_param('pig_flag'):
        rospy.set_param('pig_flag', 0)
        
        open_io="sudo pigpiod"
        os.system(open_io)
        time.sleep(1)

    rospy.init_node('key_node', anonymous=True)
    rospy.loginfo("按键节点运行")

    # 参数初始化
    rospy.set_param('key', 0)

    # 初始化 pigpio
    pi = pigpio.pi()

    # 定义行和列的引脚
    ROWS = [17, 27, 22, 23]  # 行 R1-R4
    COLS = [24, 25, 5, 6]    # 列 C1-C4

    # 初始化行引脚为输入上拉模式
    for row in ROWS:
        pi.set_mode(row, pigpio.INPUT)
        pi.set_pull_up_down(row, pigpio.PUD_UP)

    # 初始化列引脚为输出并设为高电平
    for col in COLS:
        pi.set_mode(col, pigpio.OUTPUT)
        pi.write(col, 1)

    def scan_keypad():
        key_value = -1  # 未按下任何键时的默认值

        # 扫描列
        for col in range(len(COLS)):
            pi.write(COLS[col], 0)  # 将当前列设为低电平
            for row in range(len(ROWS)):
                if pi.read(ROWS[row]) == 0:  # 检测到低电平，即有按键按下
                    key_value = row * 4 + col + 1  # 根据行列计算按键值
                    time.sleep(0.2)  # 消抖
                    while pi.read(ROWS[row]) == 0:
                        time.sleep(0.01)  # 等待按键松开
            pi.write(COLS[col], 1)  # 恢复当前列为高电平

        return key_value

    try:
        while True:
            key = scan_keypad()
            if key != -1:
                print(f"Key {key} pressed")
                rospy.set_param('key', key)
            time.sleep(0.1)
    except KeyboardInterrupt:
        pass
    finally:
        pi.stop()  # 停止pigpio
