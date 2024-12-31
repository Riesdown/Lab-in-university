#include <sys/some_define/define.hpp>
#include "work/remote/fun.hpp"



u8 GET_DATA::Get_CheckData(u8 *data, u32 len)
{
    u8 checksum = 0;
    for (u32 i = 0; i < len; i++) checksum += data[i];
    return checksum & 0xFF;
}

GET_DATA::REMOTE_ALL GET_DATA::Get_Remote_Data(u8* data)
{
    REMOTE_ALL remote_data;

    remote_data.angle_temp.yaw = ((i8)data[11] << 8) | (i8)data[12];
    remote_data.angle_temp.pitch = (i8)data[10];
    remote_data.angle_temp.roll = (i8)data[9];
    remote_data.power = (data[7] << 8) | data[8];
    remote_data.mode = (data[13] << 8) | data[14];

    remote_data.unlock = (u8)(remote_data.mode && 0x01);

    return remote_data;
}