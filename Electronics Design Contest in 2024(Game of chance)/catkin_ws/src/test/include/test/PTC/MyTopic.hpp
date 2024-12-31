#pragma once


using namespace std;

class MYTOPIC
{
    private:
        string _topic_name;
        uint32_t _topic_size;
        ros::Publisher _pub;
        ros::Subscriber _sub;

        ros::NodeHandle myros_node;


    public:
        MYTOPIC(const string& topic_name, uint32_t topic_size);
        ~MYTOPIC();

        template <typename T>
        void Send(const T& msg);

        template <typename T>
        void Get(std::function<void(const typename T::ConstPtr&)> callback);
};


MYTOPIC::MYTOPIC(const string& topic_name, uint32_t topic_size) :
    _topic_name(topic_name),
    _topic_size(topic_size)
{}


MYTOPIC::~MYTOPIC() {}


template <typename T>
void MYTOPIC::Send(const T& msg) 
{
    _pub = myros_node.advertise<T>(_topic_name, _topic_size);

    _pub.publish(msg);
}

template <typename T>
void MYTOPIC::Get(std::function<void(const typename T::ConstPtr&)> callback) 
{
    _sub = myros_node.subscribe<T>(_topic_name, _topic_size, callback);
}
