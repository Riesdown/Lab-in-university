// #include "ota.hpp"
// #include <sys/some_define/define.hpp>



// OTA::OTA(THEUDP& udp) : THEUDP(udp) 
// {
//     _firmwareSize = 0;
//     _updating = false;
// }

// void OTA::Wait_OTA(std::function<void()> stop_allwork) 
// {
//     while (true) {
//         // 检查UDP连接是否正常
//         if (!Check()) {
//             delay(1000); // 等待连接恢复
//             continue;
//         }

//         // 获取来自客户端的数据包
//         String data = Get();
//         if (data.length() > 0) {
//             // 如果未开始OTA，初始化更新
//             if (!_updating) {
//                 stop_allwork(); // 停止其他工作
//                 Serial.println("Starting OTA update...");
//                 if (!Update.begin(UPDATE_SIZE_UNKNOWN)) {
//                     Serial.println("Failed to start OTA update");
//                     return;
//                 }
//                 _updating = true;
//             }

//             // 写入固件数据
//             size_t written = Update.write((uint8_t*)data.c_str(), data.length());
//             if (written != data.length()) {
//                 Serial.println("Error writing firmware data");
//                 Update.abort();
//                 return;
//             }

//             _firmwareSize += written;
//             Serial.printf("Received %d bytes (Total: %d)\n", data.length(), _firmwareSize);
//         }

//         // 假设协议定义某种方式标识数据结束，例如特定数据包标志结束
//         if (_updating && data.endsWith("END")) {
//             if (Update.end(true)) {
//                 Serial.println("OTA Update completed successfully!");
//                 ESP.restart(); // 重启设备应用新固件
//             } else {
//                 Serial.println("OTA Update failed!");
//                 Update.abort();
//             }
//             _updating = false;
//         }
//     }
// }






