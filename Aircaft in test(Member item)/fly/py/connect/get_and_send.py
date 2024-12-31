import socket
import socketio
import threading
from flask import Flask
import json
import time
import select
'''..........配置...............................................................................................'''
sio_addr = "http://localhost:8081"


UDP_HOST = '192.168.137.1'
UDP_PORT = 6666

'''..........配置...............................................................................................'''



print1_num = 0
'''..........Flask, Socket.IO...............................................................................................'''

app = Flask(__name__)
sio = socketio.Server(cors_allowed_origins=sio_addr)
app.wsgi_app = socketio.WSGIApp(sio, app.wsgi_app)

@app.route('/')
def index():
    return "Socket.IO and UDP Server Running!"

@sio.event
def connect(sid, environ):
    print(f"WebSocket Client {sid} connected")

@sio.event
def disconnect(sid):
    print(f"WebSocket Client {sid} disconnected")
    
    
pid_data = ''
front_data_lock = threading.Lock()
    
# 接收前端发送的数据
@sio.event
def send_pid_data(sid, data):
    global pid_data
    try:
        # print(f"读取到前端数据: {data}")  
    
        # with front_data_lock:
        pid_data = json.loads(data)

    except json.JSONDecodeError as e:
        print(f"读取前端JSON错误: {e}")
    
    
def run_flask():
    app.run(host='0.0.0.0', port=8765, threaded=True)

'''..........Flask, Socket.IO...............................................................................................'''





'''..........UDP...............................................................................................'''

udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
udp_socket.bind((UDP_HOST, UDP_PORT))
print(f"UDP 监听 {UDP_HOST}:{UDP_PORT}...")

'''..........UDP...............................................................................................'''






# 数据处理
def Parse_Udp_Data(data):
    global print1_num
    try:
        # print1_num += 1
        # if print1_num %100 == 0: print(f"UDP 获取: {data}")  
        parsed_data = json.loads(data)

        return parsed_data
    except json.JSONDecodeError as e:
        print(f"JSON 解析错误: {e}")
        return {}

num = 0

# 读取ESP32数据
def Get_Data():
    global num, pid_data
    udp_socket.setblocking(False)  # 设置为非阻塞模式
    
    incomplete_data = ""  

    while True:
        # 使用 select 处理非阻塞数据接收
        rlist, _, _ = select.select([udp_socket], [], [], 0.1)
        if not rlist:
            continue  # 如果没有数据，继续等待

        data, addr = udp_socket.recvfrom(1024)
        received_string = data.decode('utf-8')

        incomplete_data += received_string

        try:
            data_dict = json.loads(incomplete_data)
            
            num += 1
            # if num % 100 == 0: print(f"数据接收: {data_dict}")
            
            if data_dict:
                sio.emit('data', data_dict) 
                
                
            if pid_data is not None:
                pid_data_json = json.dumps(pid_data).encode()
                udp_socket.sendto(pid_data_json, addr)
                # if num % 100 == 0: print(f"数据发送: {pid_data_json} \n")
                # print(f"数据发送: {pid_data_json} \n")
                
                
            incomplete_data = "" 

        except json.JSONDecodeError:
            pass 





# # 发送数据到前端
# def Send_Data():
#     global decoded_data
#     while True:
#         time.sleep(0.03) 
        
#         with data_lock:
#             data_dict = Parse_Udp_Data(decoded_data)
#             print(f"UDP 发送: {data_dict}")
#             if data_dict:
#                 sio.emit('data', data_dict)





if __name__ == '__main__':
    flask_thread = threading.Thread(target=run_flask, daemon=True)
    flask_thread.start()

    Get_Data() 
    
    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        raise SystemExit("退出")
    finally:
        udp_socket.close()