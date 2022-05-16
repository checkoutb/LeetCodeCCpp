
#include "../header/myheader.h"

class LT2270
{
public:

// D D

//    long long right = accumulate(begin(n), end(n), 0LL), left = 0, res = 0;
//    for (int i = 0; i < n.size() - 1; ++i) {
//        left += n[i];
//        right -= n[i];
//        res += left >= right;
//    }





//Runtime: 184 ms, faster than 100.00% of C++ online submissions for Number of Ways to Split Array.
//Memory Usage: 85.5 MB, less than 66.67% of C++ online submissions for Number of Ways to Split Array.
// sum([<=idx]) >= sum([>idx])
    int lt2270a(vector<int>& nums)
    {
        long sum2 = std::accumulate(begin(nums), end(nums), 0L);
        long left = 0L;
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            left += nums[i];
            sum2 -= nums[i];
            if (left >= sum2)
                ans++;
        }
        return ans;
    }

};

int main()
{

    LT2270 lt;


    return 0;
}
