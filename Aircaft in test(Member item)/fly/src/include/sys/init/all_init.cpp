#include <Arduino.h>
#include <sys/some_define/define.hpp>
#include <sys/init/all_init.hpp>


#include <hw/attitude/data/data.hpp>

using namespace ATTITUDE_DATA;
using namespace std;
/*********初始化***************************************************************************************************************************************************************** */
/*****串口调试********/
#include <app/debug/serial/debug.hpp>

static constexpr u8 DEBUG_RX_PIN = 17;
static constexpr u8 DEBUG_TX_PIN = 18;
static constexpr HardwareSerial& DEBUG_SERIAL = Serial0;

SERIAL_DEBUG serial_bebug(115200, DEBUG_RX_PIN, DEBUG_TX_PIN, DEBUG_SERIAL);


/*****GY901S陀螺仪********/
#include <hw/attitude/gy910s/gy910s.hpp>

static constexpr u8 GY_RX_PIN = 15;
static constexpr u8 GY_TX_PIN = 16;
static constexpr HardwareSerial& GY_SERIAL = Serial1;

GY901S<NINE_AXIS_DATA> gy901s(115200, GY_RX_PIN, GY_TX_PIN, GY_SERIAL);

/*****串口********/
#include <ptc/serial/serial.hpp>

SERIAL_WORK serial_work(115200, GY_RX_PIN, GY_TX_PIN, GY_SERIAL);

/*****HEX********/
#include <app/hex/hex.hpp>

HEX_CONTROL hex_control;

/*****遥控数据读取方式********/
#include <ptc/serial/serial.hpp>

static constexpr u8 BLUE_RX_PIN = 12;
static constexpr u8 BLUE_TX_PIN = 11;
static constexpr HardwareSerial& BLUE_SERIAL = Serial2;

SERIAL_WORK remote_work(115200, BLUE_RX_PIN, BLUE_TX_PIN, BLUE_SERIAL);

/*****PID********/
PID pid_roll(0.1915, 0, 0.0497, -15, 15, -100, 100);
PID pid_pitch(0.1906, 0, 0.0497, -15, 15, -100, 100);
PID pid_yaw(0.0146, 0, 0, -180, 180, -100, 100);


PID pid_gx(0.0694, 0, 0, -100, 100, -1000, 1000);
PID pid_gy(0.0704, 0, 0, -100, 100, -1000, 1000);
PID pid_gz(0.0008, 0, 0, -100, 100, -1000, 1000);

/*****UDP********/
#include <app/udp/udp.hpp>
#include <app/wifi/wifi.hpp>

const char* ip = "192, 168, 137, 1";
u16 port = 6666;

THEUDP udp(ip, port);

THEWIFI wifi("666666", "12345678", ip);


/*********变量***************************************************************************************************************************************************************** */

/*****pid********/
PID_DATA pid_data;


/*****实时的角度值********/
ANGLE gy901s_angle;

/*****实时的9轴数据********/
NINE_AXIS_DATA gy901s_nine_axis_data;

// /*****实时的预测位置********/
// POSITION position_now;


/*****实时获取到的遥控数据********/
#include "work/remote/fun.hpp"
GET_DATA::REMOTE_ALL remote_all;


/*****电机********/
#include "hw/motor/brushless/motor.hpp"
#include "hw/motor/create.hpp"
BL_MOTOR front_left(0, 4);
BL_MOTOR front_right(1, 5);
BL_MOTOR back_right(2, 6);
BL_MOTOR back_left(3, 7);
array<BL_MOTOR, 4> motor_all = {front_left, front_right, back_right, back_left};

/*****pid控制 -v1********/
#include "work/motor/fun.hpp"
#include "app/pid/pid.hpp"
using namespace CONTROL;

PID_CONTROL_V1<ANGLE, NINE_AXIS_DATA, PID> motor_pid_v1;

/*****MPU数据缓冲区********/
#include "app/circularbuffer/circularbuffer.hpp"
CIRCULAR_BUFFER<u8, 1024>  mpu_data_buffer;

/*****遥控器数据缓冲区********/
CIRCULAR_BUFFER<u8, 1024>  remote_data_buffer;

void All_Init()
{
    // serial_bebug.Init();
    Serial0.begin(115200);




    gy901s.Init();
    remote_work.Init();


    Serial0.printf("WiFi 连接中  ");
    wifi.Connect_WiFi();
    Serial0.printf("\nWiFi 连接成功\n");

    Serial0.printf("UDP 连接中  ");
    udp.Connect();
    Serial0.printf("\nUDP 连接成功\n");
}