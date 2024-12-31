#include <sys/some_define/define.hpp>
#include <sys/init/all_init.hpp>




void Default_Debug(void* p)
{
    while(1)
    {
        String get_data_debug;
        serial_bebug.ListData();
        get_data_debug = serial_bebug.GetData();

        if (get_data_debug == "restart")          ESP.restart();
        if (get_data_debug == "xy_zero")          gy901s.XY_To_Zero();
        if (get_data_debug == "z_zero")           gy901s.Z_To_Zero();
        if (get_data_debug == "xy_cal")           gy901s.Angle_Calibrate();
        delay(500);
    }
}























