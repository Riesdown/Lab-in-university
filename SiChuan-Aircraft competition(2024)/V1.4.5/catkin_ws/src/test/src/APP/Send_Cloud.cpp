#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include "test/SYS/MyROS.hpp"
#include "test/PTC/MyTopic.hpp"
#include "test/PTC/MyList.hpp"
#include "test/HW/MyCloud.hpp"
#include <memory>


struct CLOUD_STATE
{
    f32 x_min;
    f32 x_max;
    f32 y_min;
    f32 y_max;

    f32 cloud_size;
    f32 cloud_min;
    f32 cloud_max;

    f32 ignore_range;
    u8 is_resize;
}cloud_state;




int main(int argc, char** argv) 
{
    MYROS myros(argc, argv, "send_cloud");
    MYLIST mylist;

    // change filter
    unique_ptr<STRATEGY::METHOD> filter_method = make_unique<STRATEGY::SIMPLEFILTER>();
    MYCLOUD<sensor_msgs::PointCloud> mycloud("/slam_cloud", "cloud_start","cloud_close", move(filter_method));  
    // MYCLOUD<sensor_msgs::LaserScan> mycloud("/2Dlidar_scan", "cloud_start","cloud_close", move(filter_method));  

    cloud_state.x_min = mylist.Get<f32>("yaml_x_min", 0);
    cloud_state.x_max = mylist.Get<f32>("yaml_x_max", 0);
    cloud_state.y_min = mylist.Get<f32>("yaml_y_min", 0);
    cloud_state.y_max = mylist.Get<f32>("yaml_y_max", 0);
    cloud_state.cloud_size = mylist.Get<f32>("yaml_cloud_size", 0);
    cloud_state.ignore_range = mylist.Get<f32>("yaml_ignore_range", 0);
    cloud_state.is_resize = mylist.Get<i32>("yaml_is_resize", 0);

    mycloud.Cloud_Config(cloud_state.x_min, cloud_state.x_max, 
                                                cloud_state.y_min, cloud_state.y_max,
                                                cloud_state.cloud_size,
                                                cloud_state.ignore_range,
                                                cloud_state.is_resize
                                                );


    while (ros::ok()) 
    {
        myros.Delay(30);
        ros::spinOnce();
    }
}
