#pragma once
#include <sys/some_define/define.hpp>
#include <WiFi.h>
#include <WiFiUdp.h>


class THEUDP
{
    public:
        // 目标IP + 端口
        THEUDP(const char* gateway, u16 port);

        // 发送数据
        void Send(String data);

        // 接收数据
        String Get();

        // 接收OTA数据

        // template <typename len>
        // String OTA_Get();

        // 连接
        u8 Connect();

        // 检查连接
        u8 Check() const;
    private:
        u16 _port;
        IPAddress _gateway; 
        WiFiUDP _udp;   
        u8 _connected;

        void Parse_Addr(const char* str, IPAddress& ip);
};
