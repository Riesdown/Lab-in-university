#pragma once

#include "hw/attitude/data/data.hpp"

using namespace ATTITUDE_DATA;


namespace GET_ATTITUD 
{
    template <typename nine_axis_data>
    class METHOD 
    {
        public:
            virtual ~METHOD() = default;
            virtual void Init() = 0;
            virtual void GetData(nine_axis_data& data) = 0;
    };
}
