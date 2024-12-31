#pragma once

#include <WiFi.h>


#include <array>
#include <stdexcept>  



#define Progress_Bar(x)     \
do {                        \
    int progress = 0;       \
    const char progressSymbols[] = {'|', '/', '-', '\\', '|', '/', '-', '\\', '|', '/', '-', '\\'}; \
    while (!(x)) {          \
        delay(100);         \
        Serial.print(progressSymbols[progress % 12]);       \
        Serial.print('\b'); \
        progress++;         \
    }                       \
} while (0)                 // 去掉多余的反斜杠


class WIFI
{
    private:
        const char * _ssid; 
        const char * _password;

    private:
        void Parse_Addr(const char* str, IPAddress& ip);


    public:
        WIFI(const char * ssid, const char * password);

        void Connect_WiFi(const char* local_ip = "192,168,137,137", 
        const char* gateway = "192, 168, 137, 1", const char* subnet = "255, 255, 255, 0");

        void Check_WiFi(void);


};

WIFI::WIFI(const char * ssid, const char * password):
    _ssid(ssid),
    _password(password)
{}


void WIFI::Connect_WiFi(const char* local_ip, const char* gateway, const char* subnet)
{
    IPAddress Local_IP, Gateway, Subnet;

    try 
    {
        Parse_Addr(local_ip, Local_IP);
        Parse_Addr(gateway, Gateway);
        Parse_Addr(subnet, Subnet);
    }
    catch(const std::exception& e) 
    {
        Serial.println("IP 地址解析失败: " + String(e.what()));
        return;
    }

    // 设置 WiFi 工作模式和 IP 地址
    WiFi.mode(WIFI_STA);
    WiFi.config(Local_IP, Gateway, Subnet);

    // 连接 WiFi
    WiFi.begin(_ssid, _password);

    Serial.print("\n\n正在连接 Wi-Fi  ");     Progress_Bar(WiFi.status() == WL_CONNECTED); // 等待连接成功
    Serial.println("\n连接成功");
    Serial.print("我的 IP 地址：");        Serial.println(WiFi.localIP());
}


// 解析 IP 地址字符串，支持格式 "xxx.xxx.xxx.xxx" 或 "xxx,xxx,xxx,xxx"
void WIFI::Parse_Addr(const char* str, IPAddress& ip)
{
    int parts[4] = {0};
    
 
    if (sscanf(str, "%d.%d.%d.%d", &parts[0], &parts[1], &parts[2], &parts[3]) == 4)     ip = IPAddress(parts[0], parts[1], parts[2], parts[3]);
    else if (sscanf(str, "%d,%d,%d,%d", &parts[0], &parts[1], &parts[2], &parts[3]) == 4)    ip = IPAddress(parts[0], parts[1], parts[2], parts[3]);
    else throw std::runtime_error("IP 地址格式错误");
}

void WIFI::Check_WiFi(void)
{
    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("\nWi-Fi 连接已断开\n");
        WiFi.begin(_ssid, _password);

        Serial.print("\n\n正在连接 Wi-Fi  ");
    }
    delay(1000);
}








