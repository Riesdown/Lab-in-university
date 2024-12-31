#pragma once

#include <sys/some_define/define.hpp>
#include <WiFiClient.h>



class TCP
{
    public:
        // 目标IP + 端口 + 模式
        TCP(const char* gateway, u16 port, String mode = "client");

        // 连接
        u8 Connect();

        // 发送数据
        void Send(String data);

        // 检查连接
        u8 Check();

        // 获取数据
        String Get();

    private:
        u16 _port;
        String _mode;
        IPAddress _gateway;
        WiFiClient _client;

    private:
        void Parse_Addr(const char* str, IPAddress& ip);

};


