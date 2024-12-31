#include <sys/some_define/define.hpp>
#include "remote.hpp"
#include "fun.hpp"
#include <sys/init/all_init.hpp>
#include <work/flag/flag.hpp>
#include <Arduino.h>

const u8 STATIC_DATA[7] = {0x66, 0x66, 0x66, 0x66, 0x12, 0x34, 0x56};

GET_DATA get_data;


void Remote_Get_Data(void* p)
{
    u8 data_out[32];
    u8 remote_data[16];

    while (1)
    {
        delay(20);

        remote_data_buffer.Read(data_out, 32);

        hex_control.Find_And_Get(data_out, 32, STATIC_DATA, 7, remote_data, 16);

        // 校验
        if(!some_flag.is_get_remote_data_ture)  some_flag.stop_motor = 1;

        if (remote_data[15] != get_data.Get_CheckData(remote_data, 15))
        {
            some_flag.is_get_remote_data_ture = 0;
            continue;
        }

        // 读取数据
        remote_all = get_data.Get_Remote_Data(remote_data);

        // 解锁条件
        if(remote_all.unlock) some_flag.stop_motor = 1;
        else some_flag.stop_motor = 0;

        some_flag.is_get_remote_data_ture = 1;
    }
}


void Remote_Get_Data_Pany(void* p)
{
    u8 data_remote[16]; // 两倍宽度
    while (1)
    {
        delay(10);

        memset(data_remote, 0, 16);
        data_remote[0] = 0xFF;
        GET_REMOTE_DATA(data_remote, 16);

        remote_data_buffer.Write(data_remote, 16);
        
        // 校验
        if (data_remote[0] == 0xFF) some_flag.stop_motor = 1;
    }
}



