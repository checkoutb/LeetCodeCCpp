
// #include "../header/myheader.h"

#include <vector>
// #include <map>
#include <unordered_map>
#include <algorithm>
#include <iostream>

class LT2958
{
public:




//     Runtime201 ms
// Beats
// 93.9%
// Memory144.6 MB
// Beats
// 88.30%

    int maxSubarrayLength(std::vector<int>& nums, int k)
    {
        std::size_t sz1 = nums.size();
        int ans = 0;
        std::size_t st = 0;     // [st, en]
        std::unordered_map<int, int> map2;      // <num, count>
        for (std::size_t en = 0; en < sz1; ++en)
        {
            ++map2[nums[en]];
            while (map2[nums[en]] > k)
            {
                --map2[nums[st]];
                ++st;
            }
            ans = std::max(ans, static_cast<int>(en - st + 1));
        }
        return ans;
    }

};

int main()
{

    LT2958 lt;

    std::vector<int> vi = {1,2,1,2,1,2};
    int k = 1;

    std::cout<<lt.maxSubarrayLength(vi, k)<<std::endl;

    return 0;
}
