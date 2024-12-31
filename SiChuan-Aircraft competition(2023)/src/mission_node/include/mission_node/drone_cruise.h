#ifndef MYCLASS_H
#define MYCLASS_H

#include <geometry_msgs/PoseStamped.h>
#include  <mavros_msgs/State.h>
#include <geometry_msgs/TwistStamped.h>
#include  <tf/tf.h>
//无人机巡航
enum push_mode_enum{
    PUSH_WITH_X = 1,
    PUSH_WITH_Y = 2,
};
typedef struct {

    double x ;
    double y;
}drone_pose_2d_str;

class drone_cruise {
public:
    
    //初始化
    //
    void crusise_Set_map( double C_x_0 ,  double C_y_0  ,     double C_x_dis ,  double C_y_dis,double C_push_dis_max);//设置起点，扫描范围
    void crusise_Set_dir(    int C_push_mode  , int C_x_scan_dir,int C_y_scan_dir) ; //设置扫描方向
    void crusise_Clear_flag_dis();//清除结束标志位和前进距离

    //巡航
    bool crusise_run(drone_pose_2d_str   now_pose_2d, drone_pose_2d_str   exp_pose_2d, drone_pose_2d_str * Final_to_pose_2d ,  double threshold  );
    bool  Task_flag;  // 任务标志
    bool  Final_flag; // 巡航结束标志
private:
//初始化需设置变量
    double x_0;//起点x
    double y_0;//起点y
    double x_dis ; //x方向距离
    double y_dis ;//y方向距离 
    double push_dis_max;//最大推进距离
    int push_mode  ;//模式,1为x推进型 ， 2为y推进型
    int x_scan_dir;//x扫描方向
    int y_scan_dir;//y扫描方向

    //中间变量
    double push_dis;//已经推进距离
    bool       change_mode;
    bool       fist_run_flag;
};



//*********************************openmv***************************//
bool judge_is_New_Number(int number);



//******************************坐标系转换******************************************/

//获取飞机上电前的位姿，解决原点问题
//传入上电前飞机位置姿态
void  pose_to_NED(geometry_msgs::PoseStamped    pose    ,   geometry_msgs::PoseStamped  *pose_ned  );
//将右前上转换为NED
//pose 右前上，角度沿逆时针增加，pose_ned 转换完的ned坐标
//角度沿逆时针增加
void ZB_change_init( geometry_msgs::PoseStamped    pose_ned  );


#endif // MYCLASS_H