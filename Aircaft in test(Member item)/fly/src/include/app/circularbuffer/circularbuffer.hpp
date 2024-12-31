#pragma once


#include <stdexcept>
#include <vector>

using namespace std;


template <typename T, size_t Capacity>
class CIRCULAR_BUFFER
{
    private:
        T buffer[Capacity];
        size_t head;  
        size_t tail;  
        size_t size;  

    public:
        explicit CIRCULAR_BUFFER();

        // 写入数据
        void Write(const T* data, size_t dataLength);

        // 读取数据
        size_t Read(T* dest, size_t length);

        // 判断缓冲区是否为空
        bool IsEmpty() const;

        // 判断缓冲区是否已满
        bool IsFull() const;

        // 获取当前数据大小
        size_t Get_Size() const;

        // 获取缓冲区容量
        size_t Get_Capacity() const;
};

