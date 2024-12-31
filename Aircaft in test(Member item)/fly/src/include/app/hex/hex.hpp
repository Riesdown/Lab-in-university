#pragma once


using namespace std;


#include <vector>
#include <algorithm> 
#include <sys/some_define/define.hpp>



class HEX_CONTROL
{
    public:
        // 验证两段hex数据是否一致
        bool Contrast(const std::vector<u8>& data1, const std::vector<u8>& data2,
                    u32 start1, u32 len1, u32 start2, u32 len2);

        // 在data_all中查找data_find，并将找到的数据 + 其它数据存入get_data中
        void Find_And_Get(const u8* data_all, u32 all_len, const u8* data_find, u32 len_find, u8* get_data, u32 get_len);

    private:
        bool Is_ValidRange(const std::vector<u8>& data, u32 start, u32 length);
};

