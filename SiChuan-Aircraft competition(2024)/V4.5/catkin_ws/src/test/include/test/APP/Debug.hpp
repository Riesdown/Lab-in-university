#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class DEBUG
{
    private:
        struct LabelNumPair
        {
            string label;
            string str;
        };

        const static uint16_t maxPairs = 50;  // 最大数据量
        LabelNumPair pairs[maxPairs];
        string previousDisplay[maxPairs];
        uint16_t pairCount = 0;

    public:
        DEBUG();
        void List_string(const string& label, const string& str);
};


DEBUG::DEBUG()
{
    cout << "\033[2J\033[H"; // 清屏并将光标移动到顶端
}

void DEBUG::List_string(const string& label, const string& str)
{
    bool found = false;

    // 存在则更新对应的值
    for (uint16_t i = 0; i < pairCount; ++i)
    {
        if (pairs[i].label == label)
        {
            pairs[i].str = str;
            found = true;
            break;
        }
    }

    // 不存在且有空位，添加新的标签和字符串对
    if (!found && pairCount < maxPairs)
    {
        pairs[pairCount].label = label;
        pairs[pairCount].str = str;
        ++pairCount;
    }

    // 打印
    for (uint16_t i = 0; i < pairCount; ++i)
    {
        string currentDisplay = pairs[i].label + ": " + pairs[i].str + "   ";

        // 内容不同的时候才更新该行
        if (currentDisplay != previousDisplay[i])
        {
            cout << "\033[" << (i + 1) << ";1H" << currentDisplay << endl;
            previousDisplay[i] = currentDisplay; 
        }
    }

    // 光标到最后
    cout << "\033[" << (pairCount + 1) << ";1H" << endl;
}