#include "app/udp/udp.hpp"


THEUDP::THEUDP(const char* gateway, u16 port): 
    _port(port)
{
    Parse_Addr(gateway, _gateway);

}

u8 THEUDP::Connect()
{
    while (!_udp.begin(_port));
    _connected = _udp.begin(_port);

    return _connected; 
}



void THEUDP::Parse_Addr(const char* str, IPAddress& ip)
{
    u32 parts[4] = {0};
    
 
    if (sscanf(str, "%d.%d.%d.%d", &parts[0], &parts[1], &parts[2], &parts[3]) == 4)     ip = IPAddress(parts[0], parts[1], parts[2], parts[3]);
    else if (sscanf(str, "%d,%d,%d,%d", &parts[0], &parts[1], &parts[2], &parts[3]) == 4)    ip = IPAddress(parts[0], parts[1], parts[2], parts[3]);
    else throw std::runtime_error("IP 地址格式错误");
}

void THEUDP::Send(String data)
{
    _udp.beginPacket(_gateway, _port); 
    _udp.write(reinterpret_cast<const uint8_t*>(data.c_str()), data.length());
    _udp.endPacket();   
}



String THEUDP::Get()
{
    Send(" ");
    u32 packetSize = _udp.parsePacket();
    if (packetSize > 0)
    {
        char buffer[512]; 
        u32 len = _udp.read(buffer, sizeof(buffer) - 1);
        if (len > 0) buffer[len] = '\0'; 
        return String(buffer);
    }
    return String(""); 
}


// template <typename len>
// String THEUDP::OTA_Get()
// {
//     char buff[len];
//     u32 packetSize = _udp.parsePacket();
//     if (packetSize)
//     {
//         u32 len = _udp.read(buff, sizeof(buff) - 1);
//     }

// }




u8 THEUDP::Check() const
{
    return _connected;
}