#pragma once
#include <Arduino.h>

#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <utility>
#include <sys/some_define/define.hpp>



class TERMINAL_DEBUG
{
    private:
        struct LabelNumPair 
        {
            String label;
            String str; 
        };

        
        const static u32 maxPairs = 50;        //最大数据量
        LabelNumPair pairs[maxPairs];
        String previousDisplay[maxPairs];
        u32 pairCount = 0;

        HardwareSerial& _serial;

    public:
        // 选择硬件串口
        TERMINAL_DEBUG(HardwareSerial &serial);

        // 打印数据
        void List_String(const String& label, const String& str);

        // 初始化
        void Init();

};


