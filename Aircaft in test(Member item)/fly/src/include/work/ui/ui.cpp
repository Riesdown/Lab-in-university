#include <sys/some_define/define.hpp>
#include "ui.hpp"
#include <sys/init/all_init.hpp>
#include <ArduinoJson.h>
#include <functional> 
/*
MPU:
    1，发送角度


格式：
    1, name:roll/pitch等
    2, name + _p + _i + _d  

*/





void Parse_Json_PID(const String& jsonString)
{
    DynamicJsonDocument doc(2048);

    DeserializationError error = deserializeJson(doc, jsonString);

    if (error)  return;

    if (!doc.is<JsonArray>()) return;


    for (JsonObject obj : doc.as<JsonArray>()) 
    {
        if (!obj.containsKey("name")) continue;

        const char* name = obj["name"];

        if (String(name) == "roll")     pid_roll.ReSet(obj["roll_p"], obj["roll_i"], obj["roll_d"]);
        if (String(name) == "pitch")    pid_pitch.ReSet(obj["pitch_p"], obj["pitch_i"], obj["pitch_d"]);
        if (String(name) == "yaw")      pid_yaw.ReSet(obj["yaw_p"], obj["yaw_i"], obj["yaw_d"]);
        if (String(name) == "gx")       pid_gx.ReSet(obj["gx_p"], obj["gx_i"], obj["gx_d"]);
        if (String(name) == "gy")       pid_gy.ReSet(obj["gy_p"], obj["gy_i"], obj["gy_d"]);
        if (String(name) == "gz")       pid_gz.ReSet(obj["gz_p"], obj["gz_i"], obj["gz_d"]);
    }

    pid_roll.Get_PID(pid_data.roll_p, pid_data.roll_i, pid_data.roll_d);
    // pid_pitch.Get_PID(pid_data.pitch_p, pid_data.pitch_i, pid_data.pitch_d);
    // pid_yaw.Get_PID(pid_data.yaw_p, pid_data.yaw_i, pid_data.yaw_d);
    // pid_gx.Get_PID(pid_data.gx_p, pid_data.gx_i, pid_data.gx_d);
    // pid_gy.Get_PID(pid_data.gy_p, pid_data.gy_i, pid_data.gy_d);
    // pid_gz.Get_PID(pid_data.gz_p, pid_data.gz_i, pid_data.gz_d);

    Serial0.printf("roll_p: %f, roll_i: %f, roll_d: %f\n", pid_data.roll_p, pid_data.roll_i, pid_data.roll_d);
    // Serial0.printf("pitch_p: %f, pitch_i: %f, pitch_d: %f\n", pid_data.pitch_p, pid_data.pitch_i, pid_data.pitch_d);
    // Serial0.printf("yaw_p: %f, yaw_i: %f, yaw_d: %f\n", pid_data.yaw_p, pid_data.yaw_i, pid_data.yaw_d);
    // Serial0.printf("gx_p: %f, gx_i: %f, gx_d: %f\n", pid_data.gx_p, pid_data.gx_i, pid_data.gx_d);
    // Serial0.printf("gy_p: %f, gy_i: %f, gy_d: %f\n", pid_data.gy_p, pid_data.gy_i, pid_data.gy_d);
    // Serial0.printf("gz_p: %f, gz_i: %f, gz_d: %f\n", pid_data.gz_p, pid_data.gz_i, pid_data.gz_d);
}


#include <functional> 

void IU_Connect_Get(void* p)
{
    size_t previous_hash = 0;

    while (1)
    {
        delay(100);

        String get_data = udp.Get();
        if (get_data != "")
        {
            size_t current_hash = std::hash<std::string>{}(get_data.c_str());
            if (current_hash != previous_hash)
            {
                Parse_Json_PID(get_data);
                previous_hash = current_hash;
            }
        }
    }
}



void IU_Connect_Send(void* p)
{
    String json_start = "{";
    String json_end = "}";

    String interval = ",";

    while(1)
    {
        delay(20);

        if (!udp.Check()) continue;
        
        String str;

        str += json_start;
        /*******有效数据**************************** */
        str += "\"roll\": " + String(gy901s_angle.roll);
        str += interval;
        str += "\"pitch\": " + String(gy901s_angle.pitch);
        str += interval;
        str += "\"yaw\": " + String(gy901s_angle.yaw);



        /*******有效数据**************************** */
        str += json_end;


        udp.Send(str);


    }
}
