import socket

# 配置
HOST = '192.168.137.1'  # ESP32的IP地址
PORT = 6666             # ESP32监听的UDP端口
FIRMWARE_FILE = "E:/esp32project/pro1/v2.1-1/fly/.pio/build/esp32s3box/firmware.bin"

def send_firmware():
    with open(FIRMWARE_FILE, "rb") as firmware:
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        sock.settimeout(2)
        print("准备发送固件...")

        # 发送start并等待响应
        sock.sendto(b"START", (HOST, PORT))
        print("发送START，等待接收响应...")
        try:
            data, addr = sock.recvfrom(1024)
            if data == b"START":
                print("接收到START响应，开始发送固件数据...")
            else:
                print("没有接收到正确的START响应！")
                return
        except socket.timeout:
            print("接收响应超时！")
            return

        # 发送固件数据
        while chunk := firmware.read(1024):  # 每次发送1024字节
            sock.sendto(chunk, (HOST, PORT))
            print(f"发送 {len(chunk)} 字节...")

        # 发送end并等待响应
        sock.sendto(b"END", (HOST, PORT))
        print("发送END，等待接收响应...")
        try:
            data, addr = sock.recvfrom(1024)
            if data == b"END":
                print("接收到END响应，固件发送完成！")
            else:
                print("没有接收到正确的END响应！")
        except socket.timeout:
            print("接收响应超时！")

if __name__ == "__main__":
    send_firmware()
