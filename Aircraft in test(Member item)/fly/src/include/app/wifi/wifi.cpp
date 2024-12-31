#include <app/wifi/wifi.hpp>
#include <sys/some_define/define.hpp>


THEWIFI::THEWIFI(const char * ssid, const char * password, const char* gateway, const char* local_ip, const char* subnet):
    _ssid(ssid), _password(password)
{
    Parse_Addr(gateway, _gateway);
    Parse_Addr(local_ip, _local_ip);
    Parse_Addr(subnet, _subnet);
}


u8 THEWIFI::Connect_WiFi()
{
    // IPAddress Local_IP, Gateway, Subnet;

    // try 
    // {
    //     Parse_Addr(local_ip, Local_IP);
    //     Parse_Addr(gateway, Gateway);
    //     Parse_Addr(subnet, Subnet);
    // }
    // catch(const std::exception& e) 
    // {
    //     return 3;
    // }

    WiFi.mode(WIFI_STA);
    WiFi.config(_local_ip, _gateway, _subnet);

    WiFi.begin(_ssid, _password);


    while (WiFi.status() != WL_CONNECTED) ;

    return (WiFi.status() == WL_CONNECTED);
}


// 解析 IP 地址字符串，支持格式 "xxx.xxx.xxx.xxx" 或 "xxx,xxx,xxx,xxx"
void THEWIFI::Parse_Addr(const char* str, IPAddress& ip)
{
    int parts[4] = {0};
    
 
    if (sscanf(str, "%d.%d.%d.%d", &parts[0], &parts[1], &parts[2], &parts[3]) == 4)     ip = IPAddress(parts[0], parts[1], parts[2], parts[3]);
    else if (sscanf(str, "%d,%d,%d,%d", &parts[0], &parts[1], &parts[2], &parts[3]) == 4)    ip = IPAddress(parts[0], parts[1], parts[2], parts[3]);
    else throw std::runtime_error("IP 地址格式错误");
}

u8 THEWIFI::Check_WiFi(void)
{
    if (WiFi.status() != WL_CONNECTED) return 0;
    else return 1;
}



