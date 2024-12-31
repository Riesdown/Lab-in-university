#pragma once

#include <WiFi.h>
#include <WiFiUdp.h>
#include <array>
#include <stdexcept>  
#include <sys/some_define/define.hpp>



class THEWIFI
{
    private:
        const char * _ssid; 
        const char * _password;
        IPAddress _gateway;
        IPAddress _local_ip;
        IPAddress _subnet;

    private:
        void Parse_Addr(const char* str, IPAddress& ip);


    public:
        THEWIFI(const char * ssid, const char * password, const char* gateway = "192, 168, 137, 1", const char* local_ip = "192,168,137,137", const char* subnet = "255, 255, 255, 0");

        u8 Connect_WiFi();

        u8 Check_WiFi(void);


};






