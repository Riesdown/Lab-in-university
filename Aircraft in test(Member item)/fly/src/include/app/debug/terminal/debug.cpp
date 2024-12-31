#include <sys/some_define/define.hpp>
#include "app/debug/terminal/debug.hpp"





TERMINAL_DEBUG::TERMINAL_DEBUG(HardwareSerial &serial):
    _serial(serial)
{

}

void TERMINAL_DEBUG::Init()
{
    _serial.print("\033[2J"); 
    _serial.print("\033[H");
}

void TERMINAL_DEBUG::List_String(const String& label, const String& str)
{
    bool found = false;

    for (u32 i = 0; i < pairCount; ++i) 
    {
        if (pairs[i].label.equals(label)) 
        {
            pairs[i].str = str;
            found = true;
            break;
        }
    }

    if (!found && pairCount < maxPairs) 
    {
        pairs[pairCount].label = label;
        pairs[pairCount].str = str;
        ++pairCount;
    }

    for (u32 i = 0; i < pairCount; ++i) 
    {
        String currentDisplay = pairs[i].label + pairs[i].str + "   ";
        
        if (currentDisplay != previousDisplay[i]) 
        {
            _serial.print("\033[");
            _serial.print(i + 1); 
            _serial.print(";1H"); 
            _serial.print(currentDisplay);
            previousDisplay[i] = currentDisplay; 
        }
    }

    _serial.print("\033[");
    _serial.print(pairCount + 1); 
    _serial.print(";1H"); 

    _serial.flush();
}
