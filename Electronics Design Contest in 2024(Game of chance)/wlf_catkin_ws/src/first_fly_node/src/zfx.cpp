#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include  <mavros_msgs/State.h>
#include <geometry_msgs/TwistStamped.h>
#include  <tf/tf.h>
#include <math.h>


mavros_msgs::State  drone_state;//创建无人机状态话题
geometry_msgs::PoseStamped  drone_pose_info;
geometry_msgs::PoseStamped   pose_temp;
geometry_msgs::PoseStamped   pose;

geometry_msgs::PoseStamped  drone_begin;//开机初始状态
geometry_msgs::PoseStamped   pose_set;//设置相对与地图坐标右前上
double ZB_change_angle = 0 ;//两个坐标系夹角
double  angle_begin ;//初始角度
double now_yaw;//当前航向
void ZB_change_init( geometry_msgs::PoseStamped    pose_ned  )
{
    double angle_temp;
    angle_temp =  tf::getYaw(pose_ned.pose.orientation);//得到的是-pi~pi
    if(angle_temp <=0 )
    {
        angle_temp =   - angle_temp;
    }
    else 
    {
        angle_temp = 2*M_PI  - angle_temp;
    }
    ZB_change_angle = angle_temp +M_PI/2;
    angle_begin = tf::getYaw(pose_ned.pose.orientation);
    drone_begin = pose_ned;
}
void  pose_to_NED(geometry_msgs::PoseStamped    pose    ,   geometry_msgs::PoseStamped  *pose_ned  )
{
double angleInRadians = ZB_change_angle;
(*pose_ned) .pose.position.x= cos(angleInRadians)*pose.pose.position.x    -sin(angleInRadians)*pose.pose.position.y     -  drone_begin.pose.position.x;
(*pose_ned) .pose.position.y= sin(angleInRadians)*pose.pose.position.x    +cos(angleInRadians)*pose.pose.position.y     -   drone_begin.pose.position.y;
(*pose_ned) .pose.position.z = pose.pose.position.z   - drone_begin.pose.position.z;

double angle = tf::getYaw(pose.pose.orientation);
double angle_ned =  angle + angle_begin  ;

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
    double x = msg.pose.position.x  - drone_begin.pose.position.x ;
    double y = msg.pose.position.y - drone_begin.pose.position.y  ; 
    double z =msg.pose.position.z                                                                   ;
    now_yaw = tf::getYaw(msg.pose.orientation)                                      ; 

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
    ros::Publisher pose_pub =nh.advertise<geometry_msgs :: PoseStamped>("/mavros/setpoint_position/local",1);//创建位置发布
    ros :: Rate loop_rate(30);//设置频率




    while(ros::ok() && !drone_state.connected  ){
        ros::spinOnce();
        ROS_INFO("wait connect");
        loop_rate.sleep();
    }

    int count = 40;
    while(count--)
    {
        ZB_change_init(drone_pose_info);
        ros::spinOnce();
        ROS_INFO("angle:%f",180*ZB_change_angle/M_PI);
    }

    ROS_INFO("begin:%f,%f,%f,%f",drone_pose_info.pose.position.x,drone_pose_info.pose.position.y,drone_pose_info.pose.position.z,180*ZB_change_angle/M_PI);
    ROS_INFO("begin:%f,%f,%f,%f",drone_pose_info.pose.position.x,drone_pose_info.pose.position.y,drone_pose_info.pose.position.z,180*ZB_change_angle/M_PI);
    ROS_INFO("begin:%f,%f,%f,%f",drone_pose_info.pose.position.x,drone_pose_info.pose.position.y,drone_pose_info.pose.position.z,180*ZB_change_angle/M_PI);
    double waypoint[100] = {
    0,0,1.2,
    0.8, 0 ,1.2,
    0.8,0.8,1.2,
    -0.8,0.8,1.2,
    -0.8,-0.8,1.2,
    0.8,-0.8,1.2,
    0.8,0,1.2,
    0,0,1.2,
    0,0,0.1,
    0,0,0.1,
    0,0,0.1,
    0,0,0.1,
    };
    int waypoint_num = 12;
   int  waypoint_count = 0;

    tf2::Quaternion quaternion;
    double roll = 0;
    double pitch = 0;
    double yaw =0;
    quaternion.setRPY(roll, pitch, yaw);
    pose_temp.pose.orientation.x = quaternion.x();
    pose_temp.pose.orientation.y = quaternion.y();
    pose_temp.pose.orientation.z = quaternion.z();
    pose_temp.pose.orientation.w = quaternion.w();
    ros::Time last_request = ros::Time::now() ;
    int show_count =0;
    while(ros::ok())
    {
        if( drone_state.mode == "OFFBOARD" &&  drone_state.armed == true &&ros::Time::now() - last_request > ros::Duration(5))
        {
            pose_temp.pose.position.x = waypoint[waypoint_count*3    ]   ;
             pose_temp.pose.position.y = waypoint[waypoint_count*3 + 1];
            pose_temp.pose.position.z = waypoint[waypoint_count*3+ 2];
            pose_to_NED(pose_temp , &pose);
            waypoint_count++;
            ROS_INFO("1%f,%f,%f",pose_temp.pose.position.x,pose_temp.pose.position.y,pose_temp.pose.position.z );
            ROS_INFO("2%f,%f,%f",pose.pose.position.x,pose.pose.position.y,pose.pose.position.z );
             last_request =ros::Time::now() ;
        }
        else{
            //ROS_INFO("wait");
            if( (show_count++)%20 == 0 )
            {
                 ROS_INFO("qian:%f,%f,%f , %f   ",pose_temp.pose.position.x,pose_temp.pose.position.y,pose_temp.pose.position.z , now_yaw);//转换后的位置
                 ROS_INFO("hou:%f,%f,%f , %f   ",pose.pose.position.x,pose.pose.position.y,pose.pose.position.z  , now_yaw);//转换后的位置
            }
        }
        pose_pub.publish(pose);
         loop_rate.sleep();
           ros::spinOnce();
    }

    return 0;
}
