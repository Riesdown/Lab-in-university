#include <ros/ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/PoseStamped.h>
#include  <tf/tf.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include  <nlink_parser/TofsenseFrame0.h>
ros :: Publisher  pose_pub;
nlink_parser :: TofsenseFrame0  tofsenser_dis;//激光得到的高度

geometry_msgs::PoseStamped  pose_to_px4;//发给px4的位置
geometry_msgs::PoseStamped  pose_from_px4;//从px4得到的位置
double send_dis ,  dis_last , dis_now,  dis_inc;//最终发布高度,这一次高度上一次的高度，高度增量
#define  mutation_threshold    1    //突变阈值
void tofsenser_callback(nlink_parser :: TofsenseFrame0 msg)
{
  tofsenser_dis = msg;
  dis_last =  dis_now ;
  dis_now =  tofsenser_dis.dis;//
   if((dis_last - dis_now)   >  mutation_threshold)//检测到柱子
   {
        dis_inc = dis_last - dis_now;
   }
   else if((dis_last - dis_now)   < -  mutation_threshold)//离开柱子
   {
        dis_inc = 0;
   }
   send_dis = dis_now +dis_inc;
  //ROS_INFO("dis %f",msg.dis);
}

void px4_local_pose_callback(  geometry_msgs::PoseStamped  msg   )
{
    pose_from_px4 = msg;
     // 将四元数转换为欧拉角
     geometry_msgs::Quaternion quaternion;
    quaternion = msg.pose.orientation;
    tf2::Quaternion tf_quaternion(quaternion.x, quaternion.y, quaternion.z, quaternion.w);
    // 使用Matrix3x3类从四元数获取旋转矩阵
    tf2::Matrix3x3 rotation_matrix(tf_quaternion);
    // 使用getRPY方法从旋转矩阵获取欧拉角
    double roll, pitch, yaw;
    rotation_matrix.getRPY(roll, pitch, yaw);
    //ROS_INFO("X:   %f       Y:     %f     Z:    %f      YAW%f ",  msg.pose.position.x , msg.pose.position.y ,msg.pose.position.z , 180*yaw/M_PI) ; //将字符转换为字符数组打印,显示打印时间戳
}
//四元素转欧拉角
void  Quatenion_to_Eular( geometry_msgs::Quaternion  quaternion  ,  double *roll, double *pitch, double *yaw)
{
     tf2::Quaternion tf_quaternion(quaternion.x, quaternion.y, quaternion.z, quaternion.w);
    // 使用Matrix3x3类从四元数获取旋转矩阵
    tf2::Matrix3x3 rotation_matrix(tf_quaternion);
    // 使用getRPY方法从旋转矩阵获取欧拉角
    rotation_matrix.getRPY(*roll, *pitch, *yaw);

}
int main(int argc, char  *argv[])
{
    /* code */
    ros ::init(argc , argv ,"send_pos_to_px4_node");
    ros ::NodeHandle nh ;
    ros :: Subscriber px4_local_pos_sub = nh.subscribe("/mavros/local_position/pose" , 10 ,  px4_local_pose_callback);
    ros :: Subscriber tofsenser_sub = nh.subscribe("/nlink_tofsense_frame0" , 10 ,  tofsenser_callback);//激光数据
    pose_pub =nh.advertise<geometry_msgs :: PoseStamped>("/mavros/vision_pose/pose",10);//创建位置发布

    ros::Time last_request = ros::Time::now();

   int loop_rate = 40;//设置发布频率
   int  show_rate = 10;//显示频率
   int count =0;

   
    while(ros :: ok())
    {
         if( (ros::Time::now() - last_request > ros::Duration(1.0/loop_rate)))
         {
           

            pose_to_px4.pose.position.x = 0;//根据雷达信息更新雷达数据
            pose_to_px4.pose.position.y = 0;
            pose_to_px4.pose.position.z =  send_dis   ;       
            pose_pub.publish(pose_to_px4);
            last_request = ros::Time::now();


            count ++;
            if(count %(loop_rate/show_rate)  == 0)
            {
                double pitch ,roll ,yaw;
                Quatenion_to_Eular(pose_from_px4.pose.orientation , &pitch ,&roll ,&yaw);
                ROS_INFO("X:   %f       Y:     %f     Z:    %f    \n  YAW:%f   \n Dis : %f ",  pose_from_px4.pose.position.x , pose_from_px4.pose.position.y ,pose_from_px4.pose.position.z , 180*yaw/M_PI , tofsenser_dis.dis) ; //将字符转换为字符数组打印,显示打印时间戳
            }
         }
      ros::spinOnce();
    }
    
    return 0;



}