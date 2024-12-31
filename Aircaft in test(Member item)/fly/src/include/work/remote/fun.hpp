#pragma once



#include <Arduino.h>
#include <sys/some_define/define.hpp>
#include <hw/attitude/data/data.hpp>

using namespace ATTITUDE_DATA;

using namespace std;


struct GET_DATA
{
    private:

        u32 _num;

    public:
        // 遥控数据接口
        struct REMOTE_ALL
        {
            ANGLE angle_temp;
            u16 power;
            u16 mode;

            u8 unlock : 1;
        };

        // 获取数据
        REMOTE_ALL Get_Remote_Data(u8* data);

        // 校验数据
        u8 Get_CheckData(u8 *data, u32 len);
};



