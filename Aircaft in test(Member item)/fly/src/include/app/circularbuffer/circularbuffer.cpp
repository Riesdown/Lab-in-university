#include <sys/some_define/define.hpp>
#include "circularbuffer.hpp"


template class CIRCULAR_BUFFER<u8, 1024>;


template <typename T, size_t Capacity>
CIRCULAR_BUFFER<T, Capacity>::CIRCULAR_BUFFER()
    : head(0), tail(0), size(0)
{}


template <typename T, size_t Capacity>
void CIRCULAR_BUFFER<T, Capacity>::Write(const T* data, size_t dataLength)
{
    for (size_t i = 0; i < dataLength; ++i) {
        if (IsFull()) {
            // 缓冲区已满时不写入
            break;
        }
        buffer[head] = data[i];
        head = (head + 1) % Capacity;
        ++size;
    }
}


template <typename T, size_t Capacity>
size_t CIRCULAR_BUFFER<T, Capacity>::Read(T* dest, size_t length)
{
    size_t count = 0;
    while (count < length && !IsEmpty()) {
        dest[count] = buffer[tail];
        tail = (tail + 1) % Capacity;
        ++count;
        --size;
    }
    return count;
}


template <typename T, size_t Capacity>
bool CIRCULAR_BUFFER<T, Capacity>::IsEmpty() const
{
    return size == 0;
}


template <typename T, size_t Capacity>
bool CIRCULAR_BUFFER<T, Capacity>::IsFull() const
{
    return size == Capacity;
}


template <typename T, size_t Capacity>
size_t CIRCULAR_BUFFER<T, Capacity>::Get_Size() const
{
    return size;
}


template <typename T, size_t Capacity>
size_t CIRCULAR_BUFFER<T, Capacity>::Get_Capacity() const
{
    return Capacity;
}
