
#include "../header/myheader.h"

class LT1877
{
public:

// D D

//assuming amin <= ai <= amax, amin <= aj <= amax,
//the combination of (amin + amax, ai + aj),
//is always no worse than
//the combination of (amin + ai, aj + amax).
//
//So we can always pair amin with amax,
//and we can reach the optimized result.


//The smallest number should be matched with the largest number (easy to prove otherwise).
//
//So we sort the array, match the smallest with largest, next smallest with next largest, and so on.

// 反证



// shide..怎么证明？
//Runtime: 364 ms, faster than 38.81% of C++ online submissions for Minimize Maximum Pair Sum in Array.
//Memory Usage: 96.3 MB, less than 18.42% of C++ online submissions for Minimize Maximum Pair Sum in Array.
// 是sort后， (i, sz1 - i - 1) ?
    int lt1877a(vector<int>& nums)
    {
        std::sort(begin(nums), end(nums));
        int ans = 0;
        for (int i = 0; i < nums.size() / 2; ++i)
            ans = max(ans, nums[i] + nums[nums.size() - 1 - i]);
        return ans;
    }

};

int main()
{

    LT1877 lt;


    return 0;
}
