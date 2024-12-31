#include "/home/shili/wlf_catkin_ws/src/mission_node/include/mission_node/drone_cruise.h"
#include <ros/ros.h>
   void drone_cruise ::  crusise_Set_map( double C_x_0 ,  double C_y_0  ,     double C_x_dis ,  double C_y_dis,double C_push_dis_max)//设置起点，扫描范围
    {
         x_0 = C_x_0;
         y_0 =C_y_0;
         x_dis = C_x_dis;
         y_dis  =  C_y_dis;
         push_dis_max  = C_push_dis_max;//最大推进距离


    }
    void  drone_cruise :: crusise_Set_dir(    int C_mode  , int C_x_scan_dir,int C_y_scan_dir) //设置扫描方向
    {
        push_mode = C_mode  ;//模式,1为x推进型 ， 2为y推进型
        x_scan_dir =C_x_scan_dir ;//x扫描方向
        y_scan_dir  = C_y_scan_dir;//y扫描方向

    }
    void drone_cruise ::  crusise_Clear_flag_dis()//清除结束标志位和前进距离
    {
        Task_flag = false;
        Final_flag = false;
        push_dis = 0;
        fist_run_flag = true;
    }
    //跑航点
    bool drone_cruise :: crusise_run(drone_pose_2d_str   now_pose_2d, drone_pose_2d_str   exp_pose_2d, drone_pose_2d_str * Final_to_pose_2d ,  double threshold  )
    {
        static int count = 0;
        static double pose_x,pose_y;//暂存一下航点信息
        if(push_dis >= push_dis_max)
        {
            Final_flag = true;
             return true;
        }
        else
        {
            //ROS_INFO(" aaa%f    %f   ", abs(now_pose_2d.x - exp_pose_2d.x ) ,abs(now_pose_2d.y - exp_pose_2d.y ) );
            if(fist_run_flag == false && abs(now_pose_2d.x - exp_pose_2d.x  ) <threshold && abs(now_pose_2d.y - exp_pose_2d.y ) <threshold )//进行下一次计算
            {
                
                if( push_mode == PUSH_WITH_Y    )//沿着y推进
                {
                    if(count%2 == 0 ) //x轴移动
                    {
                        pose_x= pose_x  +  x_dis*x_scan_dir;
                        pose_y  = y_0  + push_dis ;
                          x_scan_dir = -x_scan_dir;
                    }
                    else if(count%2 == 1 ) //y轴移动
                    {
                        //ROS_INFO("count:%f",x_scan_dir);
                        push_dis +=y_dis;
                        pose_x = pose_x;
                        pose_y  = y_0  + push_dis;
                      
                    }
                  
                }
                else if( push_mode == PUSH_WITH_X    )//沿着y推进
                {
                    if(count%2 == 0 ) //y轴移动
                    {
                        pose_x = x_0  +  push_dis ;
                        pose_y  = y_0  + y_dis*y_scan_dir ;
                    
                    }
                    else if(count%2 == 1 ) //x轴移动
                    {
                        push_dis +=x_dis;
                        pose_x =x_0  +  push_dis ;
                        pose_y  = y_0  + y_dis*y_scan_dir;
                        y_scan_dir = -y_scan_dir;
                    }
                   
                }
                  count ++ ;
            }
             if( fist_run_flag == true)//只有刚刚初始化后才生效
            {
                count = 0 ;
                fist_run_flag = false ;
                Final_to_pose_2d->x = x_0;
                Final_to_pose_2d->y = y_0;
            }
            else
            {
                Final_to_pose_2d->x = pose_x;
                Final_to_pose_2d->y = pose_y;

            }
        }
        return false;
    }


//判断数字是否是新的，新数字返回true
bool isNumberReceived[4] = {false,false,false,false};
int receivedNumbers[4] = {0};

bool judge_is_New_Number(int number)
 {
    bool isNewNumber = true;
    for (int i = 0; i < 4; i++)
     {
        if (isNumberReceived[i] && receivedNumbers[i] == number) 
        {
            // 数字已经接收过一遍，
            printf("不响应：%d\n", number);
            isNewNumber = false;
            break;
        }
    }
    if (isNewNumber)
    {
        // 第一次接收到数字，
        printf("执行响应动作：%d\n", number);
        for (int i = 0; i < 4; i++)
         {
            if (!isNumberReceived[i]) 
            {
                isNumberReceived[i] = true;
                receivedNumbers[i] = number;
                break;
            }
        }
    }

    return  isNewNumber;
}



//**********************************************坐标系转换***************************************************//
//获取飞机上电前的位姿，解决原点问题
//传入上电前飞机位置姿态
double angle_of_coordinate ;//坐标系之间的夹角（东北天）与以上电时建立的（前右上）坐标系的夹角
double  drone_angle_begin;//上电时角度（东为0）（-pi~pi）
geometry_msgs::PoseStamped    drone_pose_begin     ;  //上电位置

void ZB_change_init( geometry_msgs::PoseStamped    pose_ned  )
{

    double angle_temp;
    //angle_temp =  tf::getYaw(pose_ned.pose.orientation);//得到的是-pi~pi ，正东为0，顺时针减小
    //改为0～2pi,
    if(angle_temp <=0 )
    {
        angle_temp =   - angle_temp;
    }
    else 
    {
        angle_temp = 2*M_PI  - angle_temp;
    }
    
    angle_of_coordinate = angle_temp +M_PI/2;
   // drone_angle_begin = tf::getYaw(pose_ned.pose.orientation);
    drone_pose_begin = pose_ned;
}
//将右前上转换为NED,并补偿原点
//pose 右前上坐标，角度沿逆时针增加，pose_ned 转换完的ned坐标，并补偿原点
//角度沿逆时针增加
void  pose_to_NED(geometry_msgs::PoseStamped    pose    ,   geometry_msgs::PoseStamped  *pose_ned  )
{
double angleInRadians = angle_of_coordinate;
(*pose_ned) .pose.position.x= cos(angleInRadians)*pose.pose.position.x    -sin(angleInRadians)*pose.pose.position.y    + drone_pose_begin.pose.position.x;
(*pose_ned) .pose.position.y= sin(angleInRadians)*pose.pose.position.x    +cos(angleInRadians)*pose.pose.position.y     +   drone_pose_begin.pose.position.y;
(*pose_ned) .pose.position.z = pose.pose.position.z   + drone_pose_begin.pose.position.z;

// double angle = tf::getYaw(pose.pose.orientation);
// double angle_ned =  angle + drone_angle_begin  ;

// tf::Quaternion quaternion;
// quaternion.setRPY(0, 0, angle_ned);
// quaternion.normalize();//归一化
// (*pose_ned).pose.orientation.x = quaternion.x();
// (*pose_ned).pose.orientation.y = quaternion.y();
// (*pose_ned).pose.orientation.z = quaternion.z();
// (*pose_ned).pose.orientation.w = quaternion.w();
}

