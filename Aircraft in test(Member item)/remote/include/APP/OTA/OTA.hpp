#pragma once

#include <AsyncElegantOTA.h>
#include <memory>

using namespace std;



class OTA
{
    private:
        AsyncWebServer server;

    public:
        OTA();
        ~OTA(); 
        void Connect_OTA_HTTP();
        void LogStatus(const String &message);
};

OTA::OTA():
    server(80)
{}

OTA::~OTA()
{
    LogStatus("OTA Server destroyed.");
}

void OTA::LogStatus(const String &message)
{
    Serial.println("[OTA] " + message);
}


void OTA::Connect_OTA_HTTP()
{
    AsyncElegantOTA.begin(&server); 
    // 启动服务器
    server.begin();
    Serial.println("\n服务器开启成功");
}








