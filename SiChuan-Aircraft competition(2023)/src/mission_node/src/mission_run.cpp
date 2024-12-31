#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include  <mavros_msgs/State.h>
#include <geometry_msgs/TwistStamped.h>
#include  <tf/tf.h>
#include <duoji_node/duoji_msg.h>
#include <number_recognize_node/numeber_info_msgs.h>
#include "/home/shili/wlf_catkin_ws/src/mission_node/include/mission_node/drone_cruise.h"

mavros_msgs::State  drone_state;//无人机订阅的状态
geometry_msgs::PoseStamped  drone_pose_info;//无人机订阅的ned位置
geometry_msgs::PoseStamped    pose_ned ;//要发布的ned位置信息
geometry_msgs::PoseStamped    pose_yqs ;//基于上电位置的右前上坐标系位置
drone_pose_2d_str  now_pose,flypoint_pose,exp_pose;//当前无人机位置,航点位置，

geometry_msgs::TwistStamped  drone_vel;//无人机速度

duoji_node::duoji_msg  duoji_angle;//舵机角度

number_recognize_node::numeber_info_msgs  number_info;//openmv回传数据

void pose_callback(const geometry_msgs::PoseStamped & msg)//位置消息
{
    static ros::Time last_time;
    drone_pose_info = msg;

    now_pose.x = msg.pose.position.x;
    now_pose.y = msg.pose.position.y;
    // if( (ros::Time::now() - last_time)  > ros::Duration(1))//每秒打印一次信息
    // {
            // double x = msg.pose.position.x;
            // double y = msg.pose.position.y;
            // double z =msg.pose.position.z;
            // double yaw = tf::getYaw(msg.pose.orientation);
    //     //ROS_INFO("current x:%f  y:%f   z:%f  yaw :%f   state:%s    %s",x,y,z,yaw , drone_state.mode.c_str(), drone_state.armed ? "True" : "False");
    //     last_time = ros::Time::now();
    // }
}
void num_info_callback(number_recognize_node::numeber_info_msgs msg)
{
    number_info = msg;

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
    ros :: Publisher   pose_pub =nh.advertise<geometry_msgs :: PoseStamped>("/mavros/setpoint_position/local",1);//创建位置发布
    ros::Publisher local_vel_pub = nh.advertise<geometry_msgs::TwistStamped>("mavros/setpoint_velocity/cmd_vel", 10);//创建速度发布
    ros::Publisher duoji_angle_pub = nh.advertise<duoji_node::duoji_msg>("/duoji_angle", 10);//创建舵机角度发布
    ros :: Subscriber state_sub = nh.subscribe("/mavros/local_position/pose" , 10 ,pose_callback);//创建位置订阅
    ros :: Subscriber pose_sub = nh.subscribe("/mavros/state/" , 1 ,drone_state_callback);//创建状态订阅
    ros :: Subscriber number_sub = nh.subscribe("/num_info" , 1 ,num_info_callback);//创建openmv数字订阅
    ros :: Rate loop_rate(30);//设置频率

    //巡航类
    drone_cruise   fly_cruise;

//状态
    enum  RUN_STATE
    {
        state_area_b = 1,
        state_area_a = 2,
    };
    enum  AREA_B_RUN_STATE
    {
        area_b_run_cruiseing = 1,//巡航状态
        area_b_run_move_to_middle = 2,//对准
        area_b_run_drop = 3,//抛投
        area_b_final_landing,//降落
    };
    int run_state = state_area_b;
    int area_b_run_state = area_b_run_cruiseing;
   


    //等待连接
    while(ros::ok() && !drone_state.connected){
        ros::spinOnce();
        ROS_INFO("wait connect");
        loop_rate.sleep();
    }
    //原点坐标系转换初始化
    int  ZB_count =20;
        while(ZB_count--)
    {
        ZB_change_init(drone_pose_info);
        ros::spinOnce();
        loop_rate.sleep();
    }
        ROS_INFO("begin:%f , %f,%f,",drone_pose_info.pose.position.x,drone_pose_info.pose.position.y,drone_pose_info.pose.position.z);
        ROS_INFO("begin:%f , %f,%f,",drone_pose_info.pose.position.x,drone_pose_info.pose.position.y,drone_pose_info.pose.position.z);
        ROS_INFO("begin:%f , %f,%f,",drone_pose_info.pose.position.x,drone_pose_info.pose.position.y,drone_pose_info.pose.position.z);
        ROS_INFO("begin:%f , %f,%f,",drone_pose_info.pose.position.x,drone_pose_info.pose.position.y,drone_pose_info.pose.position.z);

    ros::Time last_request = ros::Time::now();

    //舵机初始化
    duoji_angle.Duoji_angle = 0    ;
    duoji_angle_pub.publish(   duoji_angle   )    ;
    //航点初始化
    fly_cruise.crusise_Set_map(0,0,2,0.5,8);//设置巡航范围起点
    fly_cruise.crusise_Set_dir(PUSH_WITH_Y,1,1);//设置巡航方向
    fly_cruise.crusise_Clear_flag_dis();//清除标志位
    double cruise_hight = 2;//巡航高度
    //机体姿态初始化
       tf2::Quaternion quaternion;
    double roll = 0;
    double pitch = 0;
    double yaw =0;
    quaternion.setRPY(roll, pitch, yaw);
    pose_yqs.pose.orientation.x = quaternion.x();
    pose_yqs.pose.orientation.y = quaternion.y();
    pose_yqs.pose.orientation.z = quaternion.z();
    pose_yqs.pose.orientation.w = quaternion.w();
    //openmv初始化
    number_info.flag = false; 
   
    while(ros::ok())
    {
         if( drone_state.mode == "OFFBOARD" &&  drone_state.armed == true &&
         (ros::Time::now() - last_request > ros::Duration(0.05)))
         {
            
            switch(run_state)
            {
                case state_area_b:
                {
                    static int area_b_run_state = area_b_run_cruiseing;
                    static int See_number = 4;
                    switch(area_b_run_state)
                    {
                        case  area_b_run_cruiseing://跑航点
                            {
                                //巡航
                                if(fly_cruise.crusise_run(now_pose,exp_pose,&flypoint_pose,0.2))
                                {

                                    area_b_run_state = area_b_final_landing;//返航
                                }
                                //ROS_INFO("x:%f     ,  y:    %f    ",flypoint_pose.x ,flypoint_pose.y); 
                                pose_yqs.pose.position.x = flypoint_pose.x;
                                pose_yqs.pose.position.y = flypoint_pose.y;
                                pose_yqs.pose.position.z =      cruise_hight ;
                                
                                //检测到数字
                                if(number_info.flag  ==  true  )
                                {
                                    See_number = number_info.num;
                                    if( judge_is_New_Number(See_number) )//数字未被使用
                                    {
                                        area_b_run_state = area_b_run_move_to_middle;
                                    }
                                }
                                //ROS_INFO(" cruise"  );
                                break;
                            }
                            case  area_b_run_move_to_middle://对准
                            {
                                static int stabilize_count = 0;
                                static double move_speed = 0.01;
                                double  circle_err_x  = 240/2   -  number_info.center_x;
                                double  circle_err_y  = 240/2   -  number_info.center_y;
                                drone_vel.twist.linear.x = move_speed*(circle_err_x) ;
                                drone_vel.twist.linear.y = move_speed*(circle_err_y)   ;
                                drone_vel.twist.linear.z = 0  ;
                                if(circle_err_x < 10 && circle_err_y < 10)
                                {
                                    stabilize_count ++;
                                    if(stabilize_count > 20)
                                    {
                                        //定点
                                      pose_yqs.pose.position.x = now_pose.x;
                                      pose_yqs.pose.position.y = now_pose.y;

                                      stabilize_count = 0;
                                      area_b_run_state = area_b_run_drop;//抛投

                                    }
                                }
                                //ROS_INFO(" middle"  );
                                break;
                              }
                              case area_b_run_drop://抛投
                              {

                                    duoji_angle.Duoji_angle  +=   See_number*90;
                                    area_b_run_state  = area_b_run_cruiseing;//继续巡航
                                    //ROS_INFO(" throw"  );
                                    break;

                              }
                               case area_b_final_landing://降落
                              {

                                    pose_yqs.pose.position.x = 0;
                                   pose_yqs.pose.position.y = 0;
                                   pose_yqs.pose.position.z =      0 ;
                                    ROS_INFO(" throw"  );
                                    break;

                              }

                    }
                   //停止巡航，进行任务
                    break;
                }
            }
            

         }
         else if(drone_state.mode != "OFFBOARD" ||  drone_state.armed != true)
         {
                
                 if(drone_state.mode != "OFFBOARD")
                 {
                    //ROS_INFO("not offboard");
                 }
                
                 if(drone_state.armed != true)
                 {
                    //ROS_INFO("not armed");
                  }
         }
        pose_ned.header.stamp = ros ::Time::now()    ;
        pose_to_NED(pose_yqs    ,  & pose_ned  );
        exp_pose.x =  pose_ned.pose.position.x;//更新航点期望
        exp_pose.y =  pose_ned.pose.position.y;

        static int show_count=0;
        if((show_count++)%20 == 0)
        {
                ROS_INFO("state :%d",area_b_run_state);
                ROS_INFO("publish:%f , %f,%f,",pose_ned.pose.position.x,pose_ned.pose.position.y,pose_ned.pose.position.z);

        }
  

        pose_pub.publish(pose_ned)    ;
        duoji_angle_pub.publish(   duoji_angle   )    ;
        loop_rate.sleep();
        ros::spinOnce(); 
        
       
        
    }
    return 0;
}







