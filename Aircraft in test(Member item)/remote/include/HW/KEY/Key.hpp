#pragma omce

#include <Arduino.h>
#include <SYS/Some_Define/SomeDefine.hpp>


using namespace std;

class KEY
{
    private:
        u8 _key;
        u8 _pin;
        string _mode1;
        string _mode2;
        u32 _over_time;
    public:
        KEY(u8 pin, string mode2 = "up", string mode1 = "single", u32 over_time = 300);
        u8 Get_Key();
        void Init();
};

KEY::KEY(u8 pin, string mode2, string mode1, u32 over_time):
    _pin(pin), _mode1(mode1), _mode2(mode2), _over_time(over_time)
{

}

void KEY::Init()
{
    if(_mode2 == "up")  pinMode(_pin, INPUT_PULLDOWN);
    else  pinMode(_pin, INPUT_PULLUP);
}


u8 KEY::Get_Key()
{
    u8 data = digitalRead(_pin);
    u8 key = 0;


    if (_mode1 == "single")
    {
        u8 trigger = (_mode2 == "up") ? 1 : 0;
        u8 release = (_mode2 == "up") ? 0 : 1;

        if (data == trigger) delay(_over_time), key = 1;
    }

    return key;
}



