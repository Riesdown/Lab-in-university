#include "std_msgs/String.h"

/**********  0  ***************/
#include "ros/ros.h"
/**********  1  ***************/
#include "test/SYS/Some_define.hpp"
#include "test/PTC/MyTopic.hpp"
/**********  2  ***************/
#include "test/SYS/MyROS.hpp"


using namespace std_msgs;
using namespace std;


int main(int argc, char **argv)
{
    MYROS myros(argc, argv, "task_schedul");

    MYTOPIC Task_1ms("Task_1ms", 1);
    MYTOPIC Task_5ms("Task_5ms", 1);
    MYTOPIC Task_10ms("Task_10ms", 1);
    MYTOPIC Task_20ms("Task_20ms", 1);
    MYTOPIC Task_50ms("Task_50ms", 1);
    MYTOPIC Task_100ms("Task_100ms", 1);
    MYTOPIC Task_200ms("Task_200ms", 1);
    MYTOPIC Task_500ms("Task_500ms", 1);
    MYTOPIC Task_1s("Task_1s", 1);

    String date;
    date.data = "RUN";

    u16 num = 0;


    while(ros::ok())
    {
        myros.Delay(1);

        num++;

        if(num % 1 == 0) Task_1ms.Send(date);
        if(num % 5 == 0) Task_5ms.Send(date);
        if(num % 6 == 0) Task_10ms.Send(date);
        if(num % 30 == 0) Task_50ms.Send(date);
        if(num % 60 == 0) Task_100ms.Send(date);
        if(num % 120 == 0) Task_200ms.Send(date);
        if(num % 300 == 0) Task_500ms.Send(date);
        if(num % 12 == 0) Task_20ms.Send(date);
        if(num % 600 == 0) 
        {
            Task_1s.Send(date);

            num = 0;
        }
    }

}



