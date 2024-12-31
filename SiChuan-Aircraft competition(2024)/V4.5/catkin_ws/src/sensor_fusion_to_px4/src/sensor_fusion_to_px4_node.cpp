#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <nlink_parser/TofsenseFrame0.h>
#include <sensor_msgs/LaserScan.h>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>

// 全局变量
ros::Publisher pose_pub;  // 发布位姿的发布者
geometry_msgs::PoseStamped pose_from_lidar;  // 雷达解算的位置，从SLAM接受的位姿消息
geometry_msgs::PoseStamped pose_to_px4;  // 发给px4的位置
tf2_ros::TransformBroadcaster* tf_broadcaster;

// 雷达数据回调
void slam_pose_callback(const geometry_msgs::PoseStamped::ConstPtr& msg)
{
  pose_from_lidar = *msg;

  // 更新pose_to_px4的xy位置
  pose_to_px4.pose.position.x = pose_from_lidar.pose.position.x;
  pose_to_px4.pose.position.y = pose_from_lidar.pose.position.y;

  // 发布Transform
  geometry_msgs::TransformStamped transformStamped;
  transformStamped.header.stamp = ros::Time::now();
  transformStamped.header.frame_id = "base_footprint";  // 设置父坐标系
  transformStamped.child_frame_id = "lidar";            // 设置子坐标系

  transformStamped.transform.translation.x = pose_from_lidar.pose.position.x;
  transformStamped.transform.translation.y = pose_from_lidar.pose.position.y;
  transformStamped.transform.translation.z = pose_from_lidar.pose.position.z;
  transformStamped.transform.rotation = pose_from_lidar.pose.orientation;

  tf_broadcaster->sendTransform(transformStamped);
}

// 激光测距数据回调
void tofsense_callback(const nlink_parser::TofsenseFrame0::ConstPtr& msg)
{
  pose_to_px4.pose.position.z = msg->dis;
  pose_to_px4.header.stamp = ros::Time::now();

  // 发布融合后的数据
  pose_pub.publish(pose_to_px4);
}

int main(int argc, char *argv[])
{
  ros::init(argc, argv, "sensor_fusion_to_px4_node");
  ros::NodeHandle nh;

  // 初始化TF广播
  tf2_ros::TransformBroadcaster broadcaster;
  tf_broadcaster = &broadcaster;

  // 订阅雷达和激光测距数据
  ros::Subscriber slam_pos_sub = nh.subscribe("slam_out_pose", 10, slam_pose_callback);
  ros::Subscriber tofsense_sub = nh.subscribe("/nlink_tofsense_frame0", 10, tofsense_callback);

  // 创建发布者
  pose_pub = nh.advertise<geometry_msgs::PoseStamped>("/mavros/vision_pose/pose", 10);

  ros::spin();

  return 0;
}


