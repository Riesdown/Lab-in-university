#include <sys/some_define/define.hpp>
#include <hw/attitude/gy910s/gy910s.hpp>

/*******添加模版******* */
template class GY901S<ATTITUDE_DATA::NINE_AXIS_DATA>;


template <typename nine_axis_data>
GY901S<nine_axis_data>::GY901S(u32 baudrate, u8 rx_pin, u8 tx_pin, HardwareSerial &serial):
    _baudrate(baudrate), _rx_pin(rx_pin), _tx_pin(tx_pin), _serial(serial)
{
    
}

template <typename nine_axis_data>
f32 GY901S<nine_axis_data>::Get_Aver(const vector<f32>& data) 
{
    f32 sum = accumulate(data.begin(), data.end(), 0.0f);
    return sum / data.size();
}

template <typename nine_axis_data>
void GY901S<nine_axis_data>::Init()
{
    _serial.begin(_baudrate, SERIAL_8N1, _rx_pin, _tx_pin);
    _serial.setTimeout(1);
}

template <typename nine_axis_data>
void GY901S<nine_axis_data>::GetData(nine_axis_data& data) 
{



}


template <typename nine_axis_data>
void GY901S<nine_axis_data>::Data_Clear()
{
    pitch_history.clear();
    roll_history.clear();
    yaw_history.clear();
}

template <typename nine_axis_data>
void GY901S<nine_axis_data>::Angle_Calibrate()
{
    _serial.write(unlock, 5);
    delay(200);
    u8 data[5] = {0xFF, 0xAA, 0x01, 0x01, 0x00};
    _serial.write(data, 5);
    delay(5000);
    _serial.write(save, 5);
    Data_Clear();
}
template <typename nine_axis_data>
void GY901S<nine_axis_data>::Z_To_Zero()
{
    _serial.write(unlock, 5);
    delay(200);
    u8 data[5] = {0xFF, 0xAA, 0x01, 0x04, 0x00};
    _serial.write(data, 5);
    delay(3000);
    _serial.write(save, 5);
    Data_Clear();
}
template <typename nine_axis_data>
void GY901S<nine_axis_data>::XY_To_Zero()
{
    _serial.write(unlock, 5);
    delay(200);
    u8 data[5] = {0xFF, 0xAA, 0x01, 0x08, 0x00};
    _serial.write(data, 5);
    delay(3000);
    _serial.write(save, 5);
    Data_Clear();
}

template <typename nine_axis_data>
void GY901S<nine_axis_data>::GetData(ANGLE& angle, nine_axis_data& data)
{
    if (_angle_true.roll) angle = _angle_true;
    data = _nine_axis_data_true;
}

template <typename nine_axis_data>
void GY901S<nine_axis_data>::Data_process(u8* data) 
{
    _nine_axis_data_true.ax = (f32)((((i16)(data[3] << 8) | data[3]) / 32768.0) * 16.0);
    _nine_axis_data_true.ay = (f32)((((i16)(data[5] << 8) | data[4]) / 32768.0) * 16.0);
    _nine_axis_data_true.az = (f32)((((i16)(data[7] << 8) | data[6]) / 32768.0) * 16.0);

    _nine_axis_data_true.gx = (f32)((((i16)(data[14] << 8) | data[13]) / 32768.0) * 2000.0);
    _nine_axis_data_true.gy = (f32)((((i16)(data[16] << 8) | data[15]) / 32768.0) * 2000.0);
    _nine_axis_data_true.gz = (f32)((((i16)(data[18] << 8) | data[17]) / 32768.0) * 2000.0);

    _angle_true.roll = (f32)((((i16)(data[25] << 8) | data[24]) / 32768.0) * 180.0);
    _angle_true.pitch = (f32)((((i16)(data[27] << 8) | data[26]) / 32768.0) * 180.0);
    _angle_true.yaw = (f32)((((i16)(data[29] << 8) | data[28]) / 32768.0) * 180.0);

    // Serial0.printf("roll: %f, pitch: %f, yaw: %f\n", _angle_true.roll, _angle_true.pitch, _angle_true.yaw);
}

