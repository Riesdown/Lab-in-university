#pragma once




using namespace std;

class MYROS
{
    private:
        int _argc;
        char** _argv;
        string _name;

    public:
        MYROS(int argc, char** argv, const string& name);

        void Delay(u64 ms);

};



MYROS::MYROS(int argc, char** argv, const string& name):
    _argc(argc),
    _argv(argv),
    _name(name)
{
    ros::init(_argc, _argv, name);
}


void MYROS::Delay(u64 ms)
{
    ros::WallDuration(ms/1000.0).sleep();
}
