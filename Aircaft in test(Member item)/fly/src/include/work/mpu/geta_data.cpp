#include <sys/some_define/define.hpp>
#include <sys/init/all_init.hpp>
#include <app/hex/hex.hpp>




void MPU_Get_Data(void* p)
{
    u8 data_out[66];
    u8 get_data[33];
    u8 data_find[2] = {0x55, 0x51};

    // u64 last_time = millis();
    while(1)
    {
        mpu_data_buffer.Read(data_out, 66);

        hex_control.Find_And_Get(data_out, 66, data_find, 2, get_data, 33);
        gy901s.Data_process(get_data);

        gy901s.GetData(gy901s_angle, gy901s_nine_axis_data);

        // Get_Line_Speed(gy901s_nine_axis_data, gy901s_speed, last_time);

        // Serial0.printf("roll: %f, pitch: %f, yaw: %f\n", gy901s_angle.roll, gy901s_angle.pitch, gy901s_angle.yaw);

        delay(10);
    }
}

// 
void MPU_Get_Data_Pany(void* p)
{
    u8 data_mpu[33];

    while(1)
    {
        memset(data_mpu, 0, 33);
        serial_work.GetBinaryData(data_mpu, 33);

        mpu_data_buffer.Write(data_mpu, 33);

        delay(5);
    }
}
