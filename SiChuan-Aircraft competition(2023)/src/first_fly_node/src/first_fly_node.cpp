#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include  <mavros_msgs/State.h>
#include <geometry_msgs/TwistStamped.h>
#include  <tf/tf.h>

ros :: Publisher   pose_pub;//创建位置发布话题
mavros_msgs::State  drone_state;//创建无人机状态话题
geometry_msgs::PoseStamped  drone_pose_info;
geometry_msgs::PoseStamped    pose ;//要发布的位置信息
geometry_msgs::PoseStamped    pose_to_bub;//要发布的位置信息
geometry_msgs::PoseStamped     pose_temp ;//位置信息中间量






geometry_msgs::PoseStamped  drone_begin;//开机初始状态
geometry_msgs::PoseStamped   pose_set;//设置相对与地图坐标右前上
double ZB_change_angle = 0 ;//两个坐标系夹角
void ZB_change_init( geometry_msgs::PoseStamped    pose_ned  )
{
ZB_change_angle = tf::getYaw(pose_ned.pose.orientation);
drone_begin = pose_ned;
}
void  pose_to_NED(geometry_msgs::PoseStamped    pose    ,   geometry_msgs::PoseStamped  *pose_ned  )
{
double angleInRadians = ZB_change_angle * M_PI / 180.0;
(*pose_ned) .pose.position.x= cos(angleInRadians)*pose.pose.position.x    -sin(angleInRadians)*pose.pose.position.y     -  drone_begin.pose.position.x;
(*pose_ned) .pose.position.y= cos(angleInRadians)*pose.pose.position.x    -sin(angleInRadians)*pose.pose.position.y     -   drone_begin.pose.position.y;
(*pose_ned) .pose.position.z = pose.pose.position.z   - drone_begin.pose.position.z;

double angle = tf::getYaw(pose.pose.orientation);
double angle_ned =  angle + ZB_change_angle;
if(angle_ned >360 ) 
{
    angle_ned -= 360;
}
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
    double x = msg.pose.position.x   ;
    double y = msg.pose.position.y   ;
    double z =msg.pose.position.z    ;
    double yaw = tf::getYaw(msg.pose.orientation)  ;
    if( (ros::Time::now() - last_time)  > ros::Duration(0.1))             //每秒打印一次信息
    {
       //ROS_INFO(drone_state.header.frame_id) ;
       //ROS_INFO("current x:%f  y:%f   z:%f  yaw :%f   state:%s    %s",x,y,z,yaw , drone_state.mode.c_str(), drone_state.armed ? "True" : "False");
       double angleInRadians = ZB_change_angle * M_PI / 180.0;
       double x_map = x * cos(angleInRadians) + y * sin(angleInRadians);
       double y_map = -x * sin(angleInRadians) + y * cos(angleInRadians);
       double z_map = z - drone_begin.pose.position.z ;
       ROS_INFO(" x: %f   y:   %f  z:  %f     " , x_map,y_map,z_map);
        last_time = ros::Time::now();
    }
}
void  drone_state_callback(const mavros_msgs::State  &msg)//状态消息
{
    drone_state  =  msg;
}

//输入当前点位置，Now_pose：Last_Exp_pose：上一次目标点位置，New_Exp_pose：这一次目标位置     err： 距离上次点的误差   final_pose：最后发布的值  outtime:同一个点等待误差最大时间
//返回true表示已经完成一次更改

//！！！！！！重要!!!!!!!!第一次使用需要设置初始点，使用过程阻断后重新使用需设置初始点
bool fly_to_point(geometry_msgs :: PoseStamped   Now_pose  ,geometry_msgs :: PoseStamped   New_Exp_pose ,   geometry_msgs :: PoseStamped  *final_pose ,double err,  double outtime ,bool begin_flag)
{
    double err_x,err_y,err_z;
    static geometry_msgs :: PoseStamped   Last_Exp_pose;
   static ros::Time last_time;
   static int state = 1;
    if(    begin_flag == true   ) 
    {
        Last_Exp_pose = New_Exp_pose  ; 
        last_time = ros::Time::now()   ;
        state = 1;
    }

    err_x = abs(Now_pose.pose.position.x - Last_Exp_pose.pose.position.x);
    err_y = abs(Now_pose.pose.position.y - Last_Exp_pose.pose.position.y);
    err_z = abs(Now_pose.pose.position.z - Last_Exp_pose.pose.position.z);
   //ROS_INFO(" err:x   x%f     y %f    z%f     %d",err_x,err_y,err_z,state);
    switch (state)
    {
        case 1://xy未到期望
        {
                (*final_pose).pose.position.x =  Last_Exp_pose.pose.position.x;
                (*final_pose).pose.position.y =  Last_Exp_pose.pose.position.y; 
                (*final_pose).pose.position.z =  Now_pose.pose.position.z; //z位置不动
                if( err_x <err && err_y <err )//xy到达期望
                {
                      state = 2;
                      //  ROS_INFO(" err:x   x%f     y %f    z%f     %d",err_x,err_y,err_z,state);
                     //   ROS_INFO("111x:   %f y:  %f z:  %f",Now_pose.pose.position.x , Now_pose.pose.position.y , Now_pose.pose.position.z);
                      //  ROS_INFO("122x:   %f y:  %f z:  %f",Last_Exp_pose.pose.position.x , Last_Exp_pose.pose.position.y , Last_Exp_pose.pose.position.z);
                }     
                break;
        }
        case 2:
        {
            (*final_pose).pose.position.x =  Last_Exp_pose.pose.position.x;
            (*final_pose).pose.position.y =  Last_Exp_pose.pose.position.y; 
            (*final_pose).pose.position.z =  Last_Exp_pose.pose.position.z; //更新z位置

            if(err_x <err && err_y <err &&err_z < err )
            {
                state = 3;

            }
            break;
        }
        case 3://xyz都到达期望
        {
            state = 1;
            Last_Exp_pose = New_Exp_pose  ; //更新下一个点
            last_time = ros::Time::now()   ;
            return true;
            break;
        }
    }
    if(ros::Time::now() - last_time > ros::Duration(outtime))
    {
        ROS_INFO("flypoint Timeout    ");
    }

  //  ROS_INFO("x: %f   y: %f   Z: %f    %d",pose.pose.position.x   , pose.pose.position.y   ,pose.pose.position.z , state);
    // ROS_INFO(" err:x   x%f     y %f    z%f     %d",err_x,err_y,err_z,state);
    return false ;

}

int main(int argc, char  *argv[])
{
    /* code */  
    ros :: init(argc , argv ,"drone_fly_node");
    ros :: NodeHandle  nh;
    pose_pub =nh.advertise<geometry_msgs :: PoseStamped>("/mavros/setpoint_position/local",1);//创建位置发布
    ros::Publisher local_vel_pub = nh.advertise<geometry_msgs::TwistStamped>("mavros/setpoint_velocity/cmd_vel", 10);//创建速度发布
    ros :: Subscriber state_sub = nh.subscribe("/mavros/local_position/pose" , 10 ,pose_callback);//创建位置订阅
    ros :: Subscriber pose_sub = nh.subscribe("/mavros/state/" , 1 ,drone_state_callback);//创建位置订阅
    ros :: Rate loop_rate(30);//设置频率




    while(ros::ok() && !drone_state.connected  ){
        ros::spinOnce();
        ROS_INFO("wait connect");
        loop_rate.sleep();
    }



    sleep(0.1);
    ZB_change_init(drone_pose_info);
    ROS_INFO("angle:%f",ZB_change_angle);
    //设置姿态角
    tf2::Quaternion quaternion;
    double roll = 0;
    double pitch = 0;
    double yaw =0;
    quaternion.setRPY(roll, pitch, yaw);
    pose.pose.orientation.x = quaternion.x();
    pose.pose.orientation.y = quaternion.y();
    pose.pose.orientation.z = quaternion.z();
    pose.pose.orientation.w = quaternion.w();
    

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
    ros::Time last_request = ros::Time::now();

    
    while(ros::Time::now() - last_request < ros::Duration(10))
    {
         pose.pose.position.x = 5   ;
        pose.pose.position.y = 7;
        pose.pose.position.z = 8;
        pose_pub.publish(pose);
        ros::spinOnce();
    }


    pose_temp.pose.position.x = waypoint[waypoint_count*3    ]   ;
    pose_temp.pose.position.y = waypoint[waypoint_count*3 + 1];
    pose_temp.pose.position.z = waypoint[waypoint_count*3+ 2];
    waypoint_count ++ ;
    fly_to_point(drone_pose_info,pose_temp,&pose,0.1,20,true);//设置初始点
    while(ros::ok())
    {

         if( true)
         {
                if( fly_to_point(drone_pose_info,pose_temp,&pose,0.1,20,false)) 
                {
                    pose_temp.pose.position.x = waypoint[waypoint_count*3    ]    ;
                    pose_temp.pose.position.y = waypoint[waypoint_count*3 + 1] ;
                    pose_temp.pose.position.z = waypoint[waypoint_count*3+ 2]  ;
                    waypoint_count ++ ;
                    if(  waypoint_count   ==   waypoint_num   )
                    {
                            waypoint_count = 0;
                            ROS_INFO("count :%d",waypoint_count);

                    }
                }
                
         }
         else if(drone_state.mode != "OFFBOARD" ||  drone_state.armed != true)
         {
                 pose.pose.position.x = 0 ;
                 pose.pose.position.y = 0;
                 pose.pose.position.z = 0;
                 if(drone_state.mode != "OFFBOARD")
                 {
                     ROS_INFO("not offboard");
                 }
                
                 if(drone_state.armed != true)
                 {
                    ROS_INFO("not armed");
                  }
         }

        pose.header.stamp = ros ::Time::now();
        pose_to_NED(pose,&pose_to_bub);
        pose_pub.publish(pose_to_bub);
        
        loop_rate.sleep();
        ros::spinOnce();
    }

    return 0;
}
