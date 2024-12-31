#include <ros/ros.h>
#include <signal.h>
#include <serial/serial.h>
#include <std_msgs/String.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Empty.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <sensor_msgs/Imu.h>

#include <nav_msgs/Odometry.h>
#include <tf2/LinearMath/Quaternion.h>
#include <librealsense2/rs.hpp>
#include "datatf.h"
#include <wiringPi.h>



#define WORK_FREQUENCY 100//100hz

//#define T265_STATE_CAPTURE_ENABLE  1

uint8_t read_buf[2048];
static uint8_t NCLink_Head[2]={0xFC,0xFF};//数据帧头
static uint8_t NCLink_End[2] ={0xA1,0xA2};//数据帧尾
_serialport_decode _nclink_buf;
serial::Serial com;
geometry_msgs::Pose current_position;
geometry_msgs::Pose target_position;
geometry_msgs::Vector3 currrent_velocity;
std_msgs::Bool current_position_update_flag;
std_msgs::Bool target_position_update_flag;
geometry_msgs::PoseWithCovarianceStamped _current_position;
sensor_msgs::Imu imu_data;
nav_msgs::Odometry feedback_position;


#if T265_STATE_CAPTURE_ENABLE 
void t265_callback_internal(const geometry_msgs::PoseStamped::ConstPtr& msg)
{
    //ROS_INFO_STREAM("t265_callback_internal");
    NCLink_Send_Currrent_State(msg->pose.position.x,
                               msg->pose.position.y,
                               msg->pose.position.z,
                               currrent_velocity.x,
                               currrent_velocity.y,
                               currrent_velocity.z,
                               msg->pose.orientation.x,
                               msg->pose.orientation.y,
                               msg->pose.orientation.z,
                               msg->pose.orientation.w,
                               100.0f,0x01,
                               0,1,2,3,4,5,6,7,
                               0x0D);

}
#endif


void t265_callback_external(const nav_msgs::Odometry::ConstPtr& msg)
{
    _nclink_buf=NCLink_Send_Currrent_State(-msg->pose.pose.position.y,
                                                  msg->pose.pose.position.x,
                                                  msg->pose.pose.position.z,
                                                  -msg->twist.twist.linear.y,
                                                  msg->twist.twist.linear.x,
                                                  msg->twist.twist.linear.z,
                                                  -msg->pose.pose.orientation.y,
                                                  msg->pose.pose.orientation.z,
                                                  -msg->pose.pose.orientation.x,
                                                  msg->pose.pose.orientation.w,
                                                  100.0f,0x01,
                                                  0,1,2,3,4,5,6,7,
                                                  0x0D);
    com.write(_nclink_buf.buf,_nclink_buf.cnt);
    /*
    ROS_INFO("px py pz:%0.4f,%0.4f,%0.4f",
              -msg->pose.pose.position.y,
              msg->pose.pose.position.x,
              msg->pose.pose.position.z,"m");
    */
}


float _q[4],_g[3],_a[3],pos[3],vel[3];
bool NCLink_Data_Prase_Process_Lite(uint8_t *data_buf,uint8_t num)//飞控数据解析进程
{
  uint8_t sum = 0;
  for(uint8_t i=0;i<(num-3);i++)  sum ^= *(data_buf+i);
  if(!(sum==*(data_buf+num-3)))    																					return false;//判断sum	
  if(!(*(data_buf)==NCLink_Head[1]&&*(data_buf+1)==NCLink_Head[0]))         return false;//判断帧头
	if(!(*(data_buf+num-2)==NCLink_End[0]&&*(data_buf+num-1)==NCLink_End[1])) return false;//帧尾校验  
  uint8_t frame_id=*(data_buf+2);
  if(frame_id==0XE0)//imu数据与位置、速度数据解析
	{
    Byte2Float(data_buf,4,&_q[0]);		
    Byte2Float(data_buf,8,&_q[1]);		
    Byte2Float(data_buf,12,&_q[2]);		
    Byte2Float(data_buf,16,&_q[3]);

    Byte2Float(data_buf,20,&_g[0]);		
    Byte2Float(data_buf,24,&_g[1]);		
    Byte2Float(data_buf,28,&_g[2]);
    Byte2Float(data_buf,32,&_a[0]);		
    Byte2Float(data_buf,36,&_a[1]);		
    Byte2Float(data_buf,40,&_a[2]);

    Byte2Float(data_buf,44,&pos[0]);		
    Byte2Float(data_buf,48,&pos[1]);		
    Byte2Float(data_buf,52,&pos[2]);
    Byte2Float(data_buf,56,&vel[0]);		
    Byte2Float(data_buf,60,&vel[1]);		
    Byte2Float(data_buf,64,&vel[2]);

    //归一化处理
    float norm=invSqrt(_q[0]*_q[0]+_q[1]*_q[1]+_q[2]*_q[2]+_q[3]*_q[3]);
    _q[0]*=norm;
    _q[1]*=norm;
    _q[2]*=norm;
    _q[3]*=norm;
    
    imu_data.header.stamp=ros::Time::now();
    imu_data.header.frame_id="base_link";

    imu_data.orientation.x=_q[0];
    imu_data.orientation.y=_q[1];
    imu_data.orientation.z=_q[2];
    imu_data.orientation.w=_q[3];

    imu_data.angular_velocity.x=_g[0];
    imu_data.angular_velocity.y=_g[1];
    imu_data.angular_velocity.z=_g[2];
    imu_data.linear_acceleration.x=_a[0];
    imu_data.linear_acceleration.y=_a[1];
    imu_data.linear_acceleration.z=_a[2];
/*
    ROS_INFO("x y z w:%0.4f,%0.4f,%0.4f,%0.4f",
              _q[0],_q[1],_q[2],_q[3]);
    ROS_INFO("gx gy gz:%0.4f,%0.4f,%0.4f",
              imu_data.angular_velocity.x,
              imu_data.angular_velocity.y,
              imu_data.angular_velocity.z);
    ROS_INFO("ax ay az:%0.4f,%0.4f,%0.4f",
              imu_data.linear_acceleration.x,
              imu_data.linear_acceleration.y,
              imu_data.linear_acceleration.z);
*/
    feedback_position.header.stamp=ros::Time::now();
    feedback_position.header.frame_id="odom";
    feedback_position.child_frame_id="base_footprint";
    feedback_position.pose.pose.orientation.x=imu_data.orientation.x;
    feedback_position.pose.pose.orientation.y=imu_data.orientation.y;
    feedback_position.pose.pose.orientation.z=imu_data.orientation.z;
    feedback_position.pose.pose.orientation.w=imu_data.orientation.w;

    feedback_position.pose.pose.position.x=pos[0];
    feedback_position.pose.pose.position.y=pos[1];
    feedback_position.pose.pose.position.z=pos[2];
  
    feedback_position.twist.twist.linear.x=vel[0];
    feedback_position.twist.twist.linear.y=vel[1];
    feedback_position.twist.twist.linear.z=vel[2];

    feedback_position.twist.twist.angular.x=_g[0];
    feedback_position.twist.twist.angular.y=_g[1];
    feedback_position.twist.twist.angular.z=_g[2];
    /*
    ROS_INFO("px py pz vx vy vz:%0.4f,%0.4f,%0.4f,%0.4f,%0.4f,%0.4f",
              feedback_position.pose.pose.position.x,
              feedback_position.pose.pose.position.y,
              feedback_position.pose.pose.position.z,
              feedback_position.twist.twist.linear.x,
              feedback_position.twist.twist.linear.y,
              feedback_position.twist.twist.linear.z);
    */

    return true;
  }
  else if(frame_id==0XE1)//单独imu数据解析
	{
    Byte2Float(data_buf,4,&_q[0]);		
    Byte2Float(data_buf,8,&_q[1]);		
    Byte2Float(data_buf,12,&_q[2]);		
    Byte2Float(data_buf,16,&_q[3]);

    Byte2Float(data_buf,20,&_g[0]);		
    Byte2Float(data_buf,24,&_g[1]);		
    Byte2Float(data_buf,28,&_g[2]);
    Byte2Float(data_buf,32,&_a[0]);		
    Byte2Float(data_buf,36,&_a[1]);		
    Byte2Float(data_buf,40,&_a[2]);

    imu_data.header.stamp=ros::Time::now();
    imu_data.header.frame_id="base_link";

    imu_data.orientation.x=_q[0];
    imu_data.orientation.y=_q[1];
    imu_data.orientation.z=_q[2];
    imu_data.orientation.w=_q[3];

    imu_data.angular_velocity.x=_g[0];
    imu_data.angular_velocity.y=_g[1];
    imu_data.angular_velocity.z=_g[2];
    imu_data.linear_acceleration.x=_a[0];
    imu_data.linear_acceleration.y=_a[1];
    imu_data.linear_acceleration.z=_a[2];

    return true;
  }
  else if(frame_id==0xF0)//应答解析
  {
    uint8_t cmd_check=*(data_buf+4);
    if(cmd_check==0xf2)      std::cout<<"[ INFO] ["<<ros::Time::now()<<"]: SERIALPORT_T265：飞控返回校验，位移控制指令写入成功"<<std::endl;
    else if(cmd_check==0xf6) std::cout<<"[ INFO] ["<<ros::Time::now()<<"]: SERIALPORT_T265：飞控返回校验，导航控制指令写入成功"<<std::endl;
    else if(cmd_check==0xf7) std::cout<<"[ INFO] ["<<ros::Time::now()<<"]: SERIALPORT_T265：飞控返回校验，导航控制完毕，已达到目标点"<<std::endl;
    else                     std::cout<<"[ INFO] ["<<ros::Time::now()<<"]: SERIALPORT_T265：飞控返回校验，表征含义不明"<<std::endl;
    return false;
  }	
  return false;
}


static uint8_t nclink_buf[100];
bool NCLink_Data_Prase_Prepare_Lite(uint8_t data)//数据解析
{
  static uint8_t data_len = 0,data_cnt = 0;
  static uint8_t state = 0;
  if(state==0&&data==NCLink_Head[1])
  {
    state=1;
    nclink_buf[0]=data;
  }
  else if(state==1&&data==NCLink_Head[0])
  {
    state=2;
    nclink_buf[1]=data;
  }
  else if(state==2&&data<0XF1)
  {
    state=3;
    nclink_buf[2]=data;
  }
  else if(state==3&&data<100)
  {
    state = 4;
    nclink_buf[3]=data;
    data_len = data;
    data_cnt = 0;
  }
  else if(state==4&&data_len>0)
  {
    data_len--;
    nclink_buf[4+data_cnt++]=data;
    if(data_len==0)  state = 5;
  }
  else if(state==5)//异或校验
  {
    state = 6;
    nclink_buf[4+data_cnt++]=data;
  }
	else if(state==6&&data==NCLink_End[0])
	{
			state = 7;
			nclink_buf[4+data_cnt++]=data;
	}
	else if(state==7&&data==NCLink_End[1])
	{
			state = 0;
			nclink_buf[4+data_cnt]=data;
		  return NCLink_Data_Prase_Process_Lite(nclink_buf,data_cnt+5);
	}
  else state = 0;
  return false;
}


void Notify_Init(void)
{
    wiringPiSetup();//采用wiringpi库驱动gpio
    pinMode(4,OUTPUT);
}
//状态显示函数，低点平表示点亮
void Notify(void)
{
  static uint32_t _cnt=0; //
  _cnt++;
  if(_cnt<1000/WORK_FREQUENCY)
  {
        digitalWrite(4,LOW); 
  }
  else if(_cnt<2000/WORK_FREQUENCY)
  {
    digitalWrite(4,HIGH);
  }
  else _cnt=0;
}

void mysiginthandler(int sig)//重写结束中断函数
{
  ROS_INFO("serialport_t265_node is shutting down");
  ros::shutdown();
}

int main(int argc,char** argv)
{
    Notify_Init();//状态显示初始化
    ros::init(argc,argv,"serialport_t265");//初始化节点名称
    ros::NodeHandle n;//初始化节点句柄     
    ros::Publisher imu_pub=n.advertise<sensor_msgs::Imu>("imu_fc",1000);//定义IMU数据话题发布者，用于提供姿态数据给SLAM算法，补偿姿态倾斜
    ros::Publisher flight_state_pub=n.advertise<nav_msgs::Odometry>("flight_state",100);//定义里程计数据话题发布者
    ros::Subscriber t265_sub_external=n.subscribe("/camera/odom/sample",1000,t265_callback_external);//定义slam定位数据更新话题订阅者，用于发送定位数据给无人机
#if T265_STATE_CAPTURE_ENABLE   
    ros::Subscriber t265_sub_innernal=n.subscribe("/t265/odom/sample",1000,t265_callback_internal);//定义t265数据解析成功订阅者
    ros::Publisher t265_pub=n.advertise<geometry_msgs::PoseStamped>("/t265/odom/sample",1000);//定义t265数据解析成功发布者 
    rs2::pipeline pipe;//定义realsense pipe类
    rs2::config cfg;   //定义realsense config类
    cfg.enable_stream(RS2_STREAM_POSE,RS2_FORMAT_6DOF);//使能位置数据和6轴imu数据输出
    pipe.start(cfg);//使配置生效
#endif
    ROS_INFO("NAMELESSTECH software permissions have been opened,www.nameless.tech");
    //参数重载
    std::string serial_port;    
    int serial_baudrate = 460800; 
    ros::NodeHandle nh_private("~");
    nh_private.param<std::string>("serial_port", serial_port, "/dev/ttyAMA1"); 
    nh_private.param<int>("serial_baudrate", serial_baudrate, 460800);

    try
    {
        com.setPort(serial_port);
        com.setBaudrate(serial_baudrate);
        serial::Timeout to=serial::Timeout::simpleTimeout(1000);
        com.setTimeout(to);
        com.open();
    }
    catch (serial::IOException& e)
    {
        ROS_ERROR_STREAM("unable to open port");
        return -1;
    }
    if(com.isOpen())
    {
        ROS_INFO_STREAM("serial port is initialized");
    }
    else return -1;
    ros::Rate loop_rate(WORK_FREQUENCY);//设置循环频率Hz
    signal(SIGINT,mysiginthandler);     //链接结束中断
    while(ros::ok())
    {        
        //串口数据解析：IMU数据、应答返回数据等
        size_t _cnt=com.available();
        if(_cnt!=0)
        {
            com.read(read_buf,_cnt);
            for(int16_t i=0;i<_cnt;i++)
            {
              if(NCLink_Data_Prase_Prepare_Lite(read_buf[i]))
              {
                imu_pub.publish(imu_data);
                flight_state_pub.publish(feedback_position);//发布来自飞控端的位姿数据
                //ROS_INFO_STREAM("serialport prase success\n");
              }
            }
        }
#if     T265_STATE_CAPTURE_ENABLE  
        auto frames=pipe.wait_for_frames();
        auto f=frames.first_or_default(RS2_STREAM_POSE);
        auto pose_data=f.as<rs2::pose_frame>().get_pose_data();
        //rs2_pose pose_data;
        geometry_msgs::PoseStamped pmsg;
        pmsg.pose.position.x=current_position.position.x=-pose_data.translation.x;
        pmsg.pose.position.y=current_position.position.y=-pose_data.translation.z;
        pmsg.pose.position.z=current_position.position.z=pose_data.translation.y;
        currrent_velocity.x=-pose_data.velocity.x;
        currrent_velocity.y=-pose_data.velocity.z;
        currrent_velocity.z=pose_data.velocity.y;
        pmsg.pose.orientation.x=pose_data.rotation.x;
        pmsg.pose.orientation.y=pose_data.rotation.y;
        pmsg.pose.orientation.z=pose_data.rotation.z;
        pmsg.pose.orientation.w=pose_data.rotation.w;
        t265_pub.publish(pmsg);
        ROS_INFO("translation:%f %f %f",
        pose_data.translation.x,
        pose_data.translation.y,
        pose_data.translation.z);
        ROS_INFO("velocity:%f %f %f",
        pose_data.velocity.x,
        pose_data.velocity.y,
        pose_data.velocity.z);
        ROS_INFO("quad:%f %f %f %f",
        pose_data.rotation.x,
        pose_data.rotation.y,
        pose_data.rotation.z,
        pose_data.rotation.w);
#endif  
      ros::spinOnce();//监听反馈函数
      loop_rate.sleep();//执行循环     
      Notify();      
    }
    printf("Node exit");
    digitalWrite(22,LOW); //失能RPLIDAR PWM控制
    digitalWrite(4,LOW);  //关闭RGB状态指示灯
    return 0;
}

















//com.setPort("/dev/serial0");//("/dev/ttyUSB0");("/dev/ttyAMA0");


