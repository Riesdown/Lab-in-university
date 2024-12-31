#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include  <mavros_msgs/State.h>
#include <geometry_msgs/TwistStamped.h>
#include  <tf/tf.h>
#include <math.h>

ros :: Publisher   pose_pub;//创建位置发布话题
mavros_msgs::State  drone_state;//创建无人机状态话题
geometry_msgs::PoseStamped  drone_pose_info;



geometry_msgs::PoseStamped  drone_begin;//开机初始状态
geometry_msgs::PoseStamped   pose_set;//设置相对与地图坐标右前上
double ZB_change_angle = 0 ;//两个坐标系夹角
void ZB_change_init( geometry_msgs::PoseStamped    pose_ned  )
{
    ZB_change_angle = tf::getYaw(pose_ned.pose.orientation) +M_PI/2;
    drone_begin = pose_ned;
}
void  pose_to_NED(geometry_msgs::PoseStamped    pose    ,   geometry_msgs::PoseStamped  *pose_ned  )
{
double angleInRadians = ZB_change_angle;
(*pose_ned) .pose.position.x= cos(angleInRadians)*pose.pose.position.x    -sin(angleInRadians)*pose.pose.position.y     -  drone_begin.pose.position.x;
(*pose_ned) .pose.position.y= sin(angleInRadians)*pose.pose.position.x    +cos(angleInRadians)*pose.pose.position.y     -   drone_begin.pose.position.y;
(*pose_ned) .pose.position.z = pose.pose.position.z   - drone_begin.pose.position.z;

double angle = tf::getYaw(pose.pose.orientation);
double angle_ned =  angle + ZB_change_angle;

tf::Quaternion quaternion;
quaternion.setRPY(0, 0, angle_ned);

(*pose_ned).pose.orientation.x = quaternion.x();
(*pose_ned).pose.orientation.y = quaternion.y();
(*pose_ned).pose.orientation.z = quaternion.z();
(*pose_ned).pose.orientation.w = quaternion.w();

}

void pose_callback(const geometry_msgs::PoseStamped  msg)//位置消息
{
    static ros::Time last_time;
    drone_pose_info = msg;
    double x = msg.pose.position.x  - drone_begin.pose.position.x;
    double y = msg.pose.position.y - drone_begin.pose.position.y; 
    double z =msg.pose.position.z    ;
    double yaw = tf::getYaw(msg.pose.orientation)  ;
    if( (ros::Time::now() - last_time)  > ros::Duration(0.1))             //每秒打印10次信息
    {
       //ROS_INFO(drone_state.header.frame_id) ;
       //ROS_INFO("current x:%f  y:%f   z:%f  yaw :%f   state:%s    %s",x,y,z,yaw , drone_state.mode.c_str(), drone_state.armed ? "True" : "False");
       double angleInRadians = ZB_change_angle ;
       double x_map = x * cos(angleInRadians) + y * sin(angleInRadians);
       double y_map = -x * sin(angleInRadians) + y * cos(angleInRadians);
       double z_map = z - drone_begin.pose.position.z ;
       ROS_INFO(" x: %f   y:   %f  z:  %f     " , x_map,y_map,z_map );

 
       double x_map1 = x * cos(angleInRadians) -y * sin(angleInRadians);
       double y_map1= x * sin(angleInRadians) + y * cos(angleInRadians);
       double z_map1 = z - drone_begin.pose.position.z ;
       ROS_INFO(" x: %f   y:   %f  z:  %f     " , x_map1,y_map1,z_map1 );


        last_time = ros::Time::now();
    }
}
void  drone_state_callback(const mavros_msgs::State  &msg)//状态消息
{
    drone_state  =  msg;
}




int main(int argc, char  *argv[])
{
    /* code */  
    ros :: init(argc , argv ,"drone_fly_node");
    ros :: NodeHandle  nh;
    ros :: Subscriber state_sub = nh.subscribe("/mavros/local_position/pose" , 10 ,pose_callback);//创建位置订阅
    ros :: Subscriber pose_sub = nh.subscribe("/mavros/state/" , 1 ,drone_state_callback);//创建位置订阅
    ros :: Rate loop_rate(30);//设置频率




    while(ros::ok() && !drone_state.connected  ){
        ros::spinOnce();
        ROS_INFO("wait connect");
        loop_rate.sleep();
    }

    int count = 20;
    while(count--)
    {
        ZB_change_init(drone_pose_info);
        ros::spinOnce();
        ROS_INFO("angle:%f",180*ZB_change_angle/M_PI);
    }

    


    ros::Time last_request = ros::Time::now();

    while(ros::ok())
    {

         loop_rate.sleep();
           ros::spinOnce();       
    }

    return 0;
}
