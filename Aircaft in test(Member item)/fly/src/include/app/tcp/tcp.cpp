#include "app/tcp/tcp.hpp"



TCP::TCP(const char* gateway, u16 port, String mode):
    _port(port), _mode(mode)
{
    Parse_Addr(gateway, _gateway);
}



u8 TCP::Connect()
{
    return _client.connect(_gateway, _port);
}

void TCP::Send(String data)
{
    if (_client.connected() && _mode == "client")  _client.print(data);
}

void TCP::Parse_Addr(const char* str, IPAddress& ip)
{
    int parts[4] = {0};
    
 
    if (sscanf(str, "%d.%d.%d.%d", &parts[0], &parts[1], &parts[2], &parts[3]) == 4)     ip = IPAddress(parts[0], parts[1], parts[2], parts[3]);
    else if (sscanf(str, "%d,%d,%d,%d", &parts[0], &parts[1], &parts[2], &parts[3]) == 4)    ip = IPAddress(parts[0], parts[1], parts[2], parts[3]);
    else throw std::runtime_error("IP 地址格式错误");
}


u8 TCP::Check()
{
    return _client.connected();
}


String TCP::Get()
{
    if (_client.connected()) return _client.readString(); 
    else return "";
}