#pragma once

#include <sys/some_define/define.hpp>

struct SOME_FLAG
{
    u8 stop_motor : 1;
    u8 is_get_remote_data_ture : 1;
    // u8 is_get_remote_data : 1;
    // u8 is_get_remote_data_hard : 1;

};



union TEMP_DATA
{
    u8 data[4];
};

extern SOME_FLAG some_flag;
