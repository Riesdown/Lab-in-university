#pragma once

#include <sys/some_define/define.hpp>


namespace MOTOR_PWM
{
    class METHOD 
    {
        public:
            virtual ~METHOD() = default;
            virtual void Set_Power(u32 power) = 0;
    };
}

// virtual的函数继承必须使用
namespace MOTOR_DIR
{
    class METHOD 
    {
        public:
            virtual ~METHOD() = default;
            virtual void Set_Direction(u8 direction) = 0;
    };
}
