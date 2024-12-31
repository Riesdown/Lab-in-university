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

    public:
        UKF(f64 lambda, f64 init_P, f64 init_R, f64 init_Q);

        void Init();
        f64 State_Transition_Function(f64 x);
        f64 Measurement_Function(f64 x);
        void Get_Sigma();
        void Predict();
        void Update(f64 z);
        f64 Filter(f64 z); 
        void Reset(f64 x, f64 p, f64 r, f64 q);
};

UKF::UKF(f64 lambda, f64 init_P, f64 init_R, f64 init_Q) 
    : _lambda(lambda), _p(init_P), _r(init_R), _q(init_Q), _x(0.0)
{
    _Xsig.resize(3, 0.0); 
    _weights.resize(3, 0.0); 
    Init();
}

// 0.001≤α≤1。
void UKF::Reset(f64 x, f64 p, f64 r, f64 q)
{
    _x = x;
    _p = p;
    _r = r;
    _q = q;
}

void UKF::Init()
{
    f64 weight_0 = _lambda / (1 + _lambda);
    _weights[0] = weight_0;
    f64 weight = 1.0 / (2 * (1 + _lambda));
    _weights[1] = weight;
    _weights[2] = weight;
}

// 状态转移函数，例如：直接返回状态值
f64 UKF::State_Transition_Function(f64 x)
{
    return x;
}

// 测量函数，例如：直接返回状态值
f64 UKF::Measurement_Function(f64 x)
{
    return x;
}

void UKF::Get_Sigma()
{
    f64 sqrt_p = sqrt(1 + _lambda) * sqrt(_p);
    _Xsig[0] = _x;
    _Xsig[1] = _x + sqrt_p;
    _Xsig[2] = _x - sqrt_p;
}

void UKF::Predict()
{
    for (size_t i = 0; i < 3; i++)    _Xsig[i] = State_Transition_Function(_Xsig[i]);
    _x = 0.0;
    for (size_t i = 0; i < 3; i++)    _x += _weights[i] * _Xsig[i];

    _p = _q; 
    for (size_t i = 0; i < 3; i++)    _p += _weights[i] * pow((_Xsig[i] - _x), 2);
}

void UKF::Update(f64 z)
{
    vector<f64> Zsig(3, 0.0); 
    for (size_t i = 0; i < 3; i++)    Zsig[i] = Measurement_Function(_Xsig[i]);

    f64 z_pred = 0.0;
    for (size_t i = 0; i < 3; i++)    z_pred += _weights[i] * Zsig[i];

    f64 S = _r; 
    for (size_t i = 0; i < 3; i++)    S += _weights[i] * pow((Zsig[i] - z_pred), 2);

    f64 T = 0.0;
    for (size_t i = 0; i < 3; i++)    T += _weights[i] * (_Xsig[i] - _x) * (Zsig[i] - z_pred);

    f64 K = T / S;
    _x += K * (z - z_pred);
    _p -= K * S * K;
}

f64 UKF::Filter(f64 z)
{
    Get_Sigma(); 
    Predict();   
    Update(z); 
    return _x;  
}
