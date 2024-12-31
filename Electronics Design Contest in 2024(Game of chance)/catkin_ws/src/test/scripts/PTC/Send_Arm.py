#!/usr/bin/env python3
# coding=utf-8

import rospy
import serial
import time
from test.msg import arm_state
from std_msgs.msg import String

# 初始化串口
ser = serial.Serial(
    port='/dev/ttyS0',
    baudrate=115200,
    timeout=1
)

# 检查串口是否打开
if ser.is_open:
    print("串口已打开")
else:
    ser.open()
    print("打开串口")

rospy.init_node('arm_serial_comm', anonymous=True)

chess_aim_x = 0.0
chess_aim_y = 0.0
magnet_send = 0
buffer = ""

def parse_received_data(data):
    global buffer
    buffer += data
    lines = buffer.split("\n")
    buffer = lines[-1]  # 保留最后一个未完成的行
    return lines[:-1]  # 返回完整的行

try:
    while not rospy.is_shutdown():
        try:
            arm_set_value = rospy.get_param("arm_set", 0)
            chess_aim_x = rospy.get_param("chess_aim_x", 0.0)
            chess_aim_y = rospy.get_param("chess_aim_y", 0.0)
        except rospy.ROSException as e:
            print(f"获取参数失败: {e}")
            continue

        # 强制小数点后部分为两位零
        chess_aim_x_str = f"{int(chess_aim_x):.2f}"
        chess_aim_y_str = f"{int(chess_aim_y):.2f}"

        # 格式化数据为保留两位小数
        data_to_send = f"x={chess_aim_x_str},y={chess_aim_y_str}@{arm_set_value}!"
        ser.write(data_to_send.encode('utf-8'))
        print(f"发送数据: {data_to_send.strip()}")

        if ser.in_waiting > 0:
            raw_data = ser.read(ser.in_waiting).decode('utf-8', errors='ignore')
            received_lines = parse_received_data(raw_data)
            for received_data in received_lines:
                print(f"\n接收数据: {received_data}")

                if "electromagent_state" in received_data:
                    try:
                        magnet_state = received_data.split(":")[1].strip()
                        magnet_state_int = int(magnet_state)  # 转换为整数
                        rospy.set_param("arm_back", magnet_state_int)
                        print(f"更新arm_back状态: {magnet_state_int}\n")
                    except ValueError as e:
                        print(f"无法转换 magnet_state: {e}")

                if "position_state" in received_data:
                    try:
                        position_state = received_data.split(":")[1].strip()
                        position_state_int = int(position_state)  # 转换为整数
                        rospy.set_param("aim_flag", position_state_int)
                        print(f"更新aim_flag状态: {position_state_int}\n")
                    except ValueError as e:
                        print(f"无法转换 position_state: {e}")

        time.sleep(1)

except KeyboardInterrupt:
    print("程序被中断")

finally:
    ser.close()
    print("串口已关闭")
