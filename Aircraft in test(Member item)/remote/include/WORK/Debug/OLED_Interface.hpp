#pragma once

#include <HW/OLED/OLED.hpp>

void All_Interface()
{
    
    OLED_Create_Interface("pot_data_start",
        OLED_ShowString(1, 1, "left_y: ");        OLED_ShowNum(1, 10, adData_filt.left_y, 4);
        OLED_ShowString(2, 1, "right_x:");        OLED_ShowNum(2, 10, adData_filt.right_x, 4);
        OLED_ShowString(3, 1, "right_y:");        OLED_ShowNum(3, 10, adData_filt.right_y, 4);
    
    );

    OLED_Create_Interface("pot_data_later",
        OLED_ShowString(1, 1, "power: ");        OLED_ShowNum(1, 11, adData_filt.left_y, 4);
        OLED_ShowString(2, 1, "roll:");        
        OLED_ShowString(3, 1, "pitch:");
        if (adData_filt.right_x_i16 < 0)
        {
            OLED_ShowString(2, 10, "-");
            OLED_ShowNum(2, 11, -adData_filt.right_x_i16, 4);
        }
        else 
        {
            OLED_ShowString(2, 10, "+");
            OLED_ShowNum(2, 11, adData_filt.right_x_i16, 4);
        }
        if (adData_filt.right_y_i16 < 0) 
        {
            OLED_ShowString(3, 10, "-");
            OLED_ShowNum(3, 11, -adData_filt.right_y_i16, 4);
        }
        else 
        {
            OLED_ShowString(3, 10, "+");
            OLED_ShowNum(3, 11, adData_filt.right_y_i16, 4);
        }
        OLED_ShowString(4, 1, "unlock");     OLED_ShowNum(4, 10, mode_data.unlock, 1);
    );

    OLED_Create_Interface("mode",

    );

    OLED_Create_Interface("send_data",

    );

    OLED_Interface_Replace(0);
}










