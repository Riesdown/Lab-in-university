#pragma once

#include <sys/some_define/define.hpp>
#include <vector>


using namespace std;


class UKF
{
    private:
        f64 _x;         // 状态值
        f64 _p;         // 状态协方差
        f64 _r;         // 测量噪声协方差
        f64 _q;         // 过程噪声协方差
        f64 _lambda;    // 超参数
        vector<f64> _Xsig;   // Sigma 点
        vector<f64> _weights; // 权重

    private:
        f64 State_Transition_Function(f64 x);
        f64 Measurement_Function(f64 x);
        void Get_Sigma();
        void Predict();
        void Update(f64 z);
    public:
        // Sigma点超参数 + PRQ参数
        UKF(f64 lambda, f64 init_P, f64 init_R, f64 init_Q);

        // 重置PRQ参数
        void Reset(f64 x, f64 p, f64 r, f64 q);

        // 初始化
        void Init();

        // 滤波
        f64 Filter(f64 z); 

};

