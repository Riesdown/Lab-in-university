#include <sys/some_define/define.hpp>
#include "app/hex/hex.hpp"

bool HEX_CONTROL::Is_ValidRange(const std::vector<u8>& data, u32 start, u32 length)
{
    return start < data.size() && (start + length) <= data.size();
}

bool HEX_CONTROL::Contrast(const std::vector<u8>& data1, const std::vector<u8>& data2,
                   u32 start1, u32 len1, u32 start2, u32 len2)
{
    if (!Is_ValidRange(data1, start1, len1) || !Is_ValidRange(data2, start2, len2))    return false;

    if (len1 != len2)     return false;

    return equal(data1.begin() + start1, data1.begin() + start1 + len1,
                      data2.begin() + start2);
}

// 从data_all找到len_find长度的data_find，找到后，将data_find+后面的get_len - data_find的数据给get_data
void HEX_CONTROL::Find_And_Get(const u8* data_all, u32 all_len, const u8* data_find, u32 len_find, u8* get_data, u32 get_len) 
{
    if (data_all == nullptr || data_find == nullptr || get_data == nullptr) return; 

    for (u32 i = 0; i < all_len; i++) 
    {
        bool found = true;
        for (u32 j = 0; j < len_find; j++) 
        {
            if (data_all[i + j] != data_find[j]) 
            {
                found = false;
                break;
            }
        }

        if (found) 
        {
            u32 data_start_index = i;
            for (u32 k = 0; k < get_len; k++) 
            {
                if (data_start_index + k < all_len) get_data[k] = data_all[data_start_index + k];
                else get_data[k] = 0; 
            }
            return; 
        }
    }
}



