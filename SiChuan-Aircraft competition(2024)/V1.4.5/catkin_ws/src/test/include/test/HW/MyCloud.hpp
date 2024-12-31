#include "test/cloud_date.h"

#include "string"
#include <cmath>
#include <ros/ros.h>
#include "test/SYS/Some_define.hpp"
#include <vector>

#include <unordered_set>
#include "test/APP/Position_Control.hpp"
#include <sensor_msgs/PointCloud.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_ros/transforms.h>
#include <pcl/segmentation/extract_clusters.h>
#include <pcl/kdtree/kdtree.h>
#include <sensor_msgs/LaserScan.h>

using namespace std;

static  struct SEND_CLOUD
{
    u8 flag;
    f32 x_min;
    f32 x_max;
    f32 y_min;
    f32 y_max;
    f32 size;    
    f32 ignore_range;
    u8 is_resize;
} send_cloud_data;


struct FilterResult
{
    vector<test::cloud_date> filtered_points;  // 过滤后的点集
    test::cloud_date closest_point;            // 与飞机最近的点
    bool has_closest_point = false;            // 是否找到最近的点
};

namespace STRATEGY 
{
    class METHOD 
    {
        public:
            virtual ~METHOD() = default;

            virtual FilterResult Cloud_Filter(const vector<test::cloud_date>& points) = 0;
    };

    class SIMPLEFILTER : public METHOD 
    {
        private:
                POSITION_CONTROL position_control_;

        public:
            FilterResult Cloud_Filter(const vector<test::cloud_date>& points) override 
            {
                FilterResult result;
                unordered_set<size_t> visited;  // 使用 unordered_set 来存储访问的点索引

                float eps_squared = send_cloud_data.size * send_cloud_data.size;  
                float ignore_radius_squared = send_cloud_data.ignore_range * send_cloud_data.ignore_range; 

                // 计算距离的平方
                auto compute_distance_squared = [](const test::cloud_date& a, const test::cloud_date& b) 
                {
                    return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
                };

                auto compute_distance_to_body_squared = [&](const test::cloud_date& point, f32 x_local, f32 y_local) 
                {
                    return (point.x - x_local) * (point.x - x_local) + (point.y - y_local) * (point.y - y_local);
                };

                f32 x_local, y_local, z_local;
                position_control_.Get_Position(x_local, y_local, z_local);

                float closest_distance_squared = std::numeric_limits<float>::max();
                size_t closest_index = -1;

                for (size_t i = 0; i < points.size(); ++i)
                {
                    // 如果已经访问，跳过
                    if (visited.find(i) != visited.end()) continue;

                    // 计算点到机体的距离平方
                    float distance_to_body_squared = compute_distance_to_body_squared(points[i], x_local, y_local);
                    if (distance_to_body_squared < ignore_radius_squared) 
                        continue;

                    // 标记点为已访问
                    visited.insert(i);

                    // 查找邻居
                    vector<size_t> neighbors;
                    for (size_t j = 0; j < points.size(); ++j) 
                    {
                        if (compute_distance_squared(points[i], points[j]) < eps_squared) 
                        {
                            neighbors.push_back(j);
                        }
                    }

                    // 检查点是否在指定范围内
                    if (!neighbors.empty())
                    {
                        float x = points[i].x;
                        float y = points[i].y;
                        if (x >= send_cloud_data.x_min && x <= send_cloud_data.x_max &&
                            y >= send_cloud_data.y_min && y <= send_cloud_data.y_max)
                        {
                            result.filtered_points.push_back(points[i]); 
                        }
                    }

                    // 标记邻居为已访问
                    for (size_t j : neighbors)
                    {
                        visited.insert(j); 
                    }

                    // 更新最近点的信息
                    if (distance_to_body_squared < closest_distance_squared)
                    {
                        closest_distance_squared = distance_to_body_squared;
                        closest_index = i;
                    }
                }

                // 如果找到最近的点，存储该点
                if (closest_index != static_cast<size_t>(-1))
                {
                    result.closest_point = points[closest_index];
                    result.has_closest_point = true;
                }

                return result;
            }
    };
}

template <typename T>
class MYCLOUD 
{
    private:
        test::cloud_date cloud_data;
        MYTOPIC topic_get_cloud;
        MYTOPIC topic_send_cloud;
        MYTOPIC topic_send_closest_cloud;


        POSITION_CONTROL position_control_;

        unique_ptr<STRATEGY::METHOD> filter_method; 

        void CallBack_Normal(const typename T::ConstPtr& scan_msg);
        void CallBack_Other(const typename T::ConstPtr& scan_msg);

    public:
        MYCLOUD(string get_name, string send_name,  string send_name2, unique_ptr<STRATEGY::METHOD> method);  
        void Cloud_Config(f64 x_min, f64 x_max, f64 y_min, f64 y_max, f32 size, f32 ignore_range, u8 is_resize);
};

template <typename T>
MYCLOUD<T>::MYCLOUD(string get_name, string send_name, string send_name2, unique_ptr<STRATEGY::METHOD> method) : 
    topic_get_cloud(get_name, 100),
    topic_send_cloud(send_name, 1000), 
    topic_send_closest_cloud(send_name2, 1000), 
    filter_method(move(method)) 
{
    topic_get_cloud.Get<T>([this](const typename T::ConstPtr& ptr) 
    {   
        if constexpr (std::is_same<T, sensor_msgs::LaserScan>::value)             this->CallBack_Normal(ptr);
        else if constexpr (std::is_same<T, sensor_msgs::PointCloud>::value)       this->CallBack_Other(ptr);
    });
}

template <typename T>
void MYCLOUD<T>::CallBack_Other(const typename T::ConstPtr& cloud_msg) 
{
    if (!send_cloud_data.flag) return; 
    FilterResult result;

    f32 x_local, y_local, z_local;
    position_control_.Get_Position(x_local, y_local, z_local);

    vector<test::cloud_date> points; 

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>());
    
    // 转换 sensor_msgs::PointCloud 到 pcl::PointCloud<pcl::PointXYZ>
    for (const auto& point : cloud_msg->points) 
    {
        pcl::PointXYZ pcl_point(point.x, point.y, point.z);
        cloud->points.push_back(pcl_point);
    }
    cloud->width = cloud->points.size();
    cloud->height = 1; 



    for (const auto& point : cloud->points) 
    {
        cloud_data.x = x_local - point.x;
        cloud_data.y = y_local - point.y;

        if(cloud_data.x <= send_cloud_data.x_max && cloud_data.x >= send_cloud_data.x_min && 
        cloud_data.y <= send_cloud_data.y_max && cloud_data.y >= send_cloud_data.y_min)
        {
            points.push_back(cloud_data);
        }

        // std::cout << "Global Position: (" << cloud_data.x << ", " << cloud_data.y << ")" << std::endl;
    } 

    if(send_cloud_data.is_resize)
    {
        // 滤波并发送
        result = filter_method->Cloud_Filter(points);
        if(!result.closest_point.x) return;
        
        for (const auto& point : result.filtered_points)         
        {
            // std::cout << "Position: (" << point.x << ", " << point.y << ")" << std::endl;
            topic_send_cloud.Send<test::cloud_date>(point);

        }
        topic_send_closest_cloud.Send<test::cloud_date>(result.closest_point);
    }
    else
    {
        for (const auto& point : points)         
        {
            topic_send_cloud.Send<test::cloud_date>(point);
        }
    }




}

template <typename T>
void MYCLOUD<T>::CallBack_Normal(const typename T::ConstPtr& scan_msg) 
{
    // std::cout << "CallBack_Normal" << std::endl;

    if (!send_cloud_data.flag) return; 

    FilterResult result;

    vector<test::cloud_date> points; 

    for (size_t i = 0; i < scan_msg->ranges.size(); ++i) 
    {
        f64 range = scan_msg->ranges[i];

        if (std::isinf(range) || std::isnan(range)) continue;

        f64 angle = scan_msg->angle_min + i * scan_msg->angle_increment;
        f64 x = range * cos(angle);
        f64 y = range * sin(angle);

        f32 x_local, y_local, z_local;
        position_control_.Get_Position(x_local, y_local, z_local);
        cloud_data.x = x + x_local;
        cloud_data.y = y + y_local;

        points.push_back(cloud_data);
    }
    // 滤波并发送
    result = filter_method->Cloud_Filter(points);
    if(!result.closest_point.x) return;
    
    for (const auto& point : result.filtered_points)         topic_send_cloud.Send<test::cloud_date>(point);
    topic_send_closest_cloud.Send<test::cloud_date>(result.closest_point);
}


template <typename T>
void MYCLOUD<T>::Cloud_Config(f64 x_min, f64 x_max, f64 y_min, f64 y_max, f32 size, f32 ignore_range, u8 is_resize)
{
    send_cloud_data.flag = 1;
    send_cloud_data.x_min = x_min;
    send_cloud_data.x_max = x_max;
    send_cloud_data.y_min = y_min;
    send_cloud_data.y_max = y_max;
    send_cloud_data.size = size;     
    send_cloud_data.ignore_range = ignore_range;
    send_cloud_data.is_resize = is_resize;
}
