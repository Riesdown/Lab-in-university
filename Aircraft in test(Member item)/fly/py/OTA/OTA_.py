import socket
import time

HOST = '192.168.137.1'
PORT = 6666

server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_socket.bind((HOST, PORT))

print(f"Listening for incoming UDP data on {HOST}:{PORT}...")


def Start():
    while True:
        data, addr = server_socket.recvfrom(1024)
        server_socket.sendto(b"start", addr) 

        # if data == b"start":  
        #     break

        time.sleep(0.01)


def End():
    while True:
        data, addr = server_socket.recvfrom(1024)
        server_socket.sendto(b"end", addr)  

        # if data == b"end": 
        #     break

        time.sleep(0.01)

data2 = "666666".encode() 

try:
    while True:
        # Start()

        # data, addr = server_socket.recvfrom(1024)
        # server_socket.sendto(data2, addr) 

        End()

except KeyboardInterrupt:
    print("exit.......")

finally:
    server_socket.close()
