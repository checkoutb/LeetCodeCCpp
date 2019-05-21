
#include "../header/myheader.h"


// 不知不觉。


class LT0377
{
//    int* dp;
    vector<int> dp;
public:


// 看了discuss的。dp。。。
    int lt0377b(vector<int>& nums, int target)
    {
        int result = 0;
        dp.resize(target + 1, -1);
        dp[0] = 1;

        result = recursionb1(nums, target);

        return result;
    }

    int recursionb1(vector<int>& nums, int target)
    {
        if (dp[target] != -1)
            return dp[target];
        int result = 0;
        for (int n : nums)
        {
            if (n <= target)
            {
                result += recursionb1(nums, target - n);
            }
        }
        dp[target] = result;
        return result;
    }


//    10 / 17 tle.... [1,2,3] + 32...
    int lt0377a(vector<int>& nums, int target)
    {
        int result = 0;
        result = recursiona1(nums, target, 0);          // target 用 target - nums[i]
        return result;
    }

    int recursiona1(vector<int>& nums, int target, int now)
    {
        if (now > target)
            return 0;
        if (now == target)
            return 1;
        int result = 0;
        for (int i = 0, sz1 = nums.size(); i < sz1; i++)
        {
            result += recursiona1(nums, target, now + nums[i]);
        }
        return result;
    }

};

int main()
{
    vector<int> v = {1,2,3};
    int target = 3;

    LT0377 lt;
    cout<<endl<<lt.lt0377b(v, target)<<endl;
    return 0;
}
