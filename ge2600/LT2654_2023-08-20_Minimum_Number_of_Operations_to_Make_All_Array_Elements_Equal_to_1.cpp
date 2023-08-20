
#include "../header/myheader.h"

class LT2654
{
public:




// g

// hint: Try finding the shortest subarray with a gcd equal to 1.

    int minOperations(vector<int>& nums)
    {
        int cnt1 = 0;
        for (int i : nums)
            cnt1 += i == 1;
        if (cnt1 > 0)
        {
            return sz1 - cnt1;
        }
        queue<vector<int>> que1;
        que1.push(nums);
        int cnt = 0;

        while (!que1.empty())
        {

        }
    }

    // 看来只能 bfs暴力了？

    // 10,5,10,30,70,4,2,6,8,4 ： 13

    // 计算当前下标 做为第一个 1 需要多少步？
    // sz1 or sz1+1 or -1 ?
    int minOperations___EE(vector<int>& nums)
    {
        int cnt1 = 0;
        for (int i : nums)
            cnt1 += i == 1;
        if (cnt1 > 0)
        {
            return sz1 - cnt1;
        }

        int sz1 = nums.size();
        int mn = -1;
        if  (gcda1(nums[0], nums[1]) == 1 || (gcda1(nums[sz1 - 1], nums[sz1 - 2]) == 1))
        {
            return sz1;
        }
        int t2 = 0;
        int ans = -1;
        for (int i = 1; i < sz1 - 1; ++i)
        {
            t2 = gcda1(nums[i], nums[i + 1]);
            if (t2 == 1)
            {
                return sz1;
            }
            t2 = gcda1(t2, nums[i - 1]);
            if (t2 == 1)
            {
                ans = sz1 + 1;
            }
        }
        return ans;
    }

    // 6 10 15  : 4
    // 6 2 15
    // 6 2 1

    // -1 or sz1 ?
    int minOperations__EEE(vector<int>& nums)
    {
        int sz1 = nums.size();

        for (int i = 0; i < sz1 - 1; ++i)
        {
            if (gcda1(max(nums[i], nums[i + 1]), min(nums[i], nums[i + 1])) == 1)
            {
                return sz1;
            }
        }
        return -1;
    }


    // 直接算?
    // .... 是替换1个。。。。？？？？
    int minOperations__ERROR(vector<int>& nums)
    {
        // int st = 0;
        bool has1 = false;
        int sz1 = nums.size();
        int ans = 0;
        int done = 0;
        for (int i = 0; i < sz1 - 1; ++i)
        {
            int t2 = gcda1(nums[i], nums[i + 1])
            if (t2 == 1)
            {
                ans += 1;
                ++i;
                done += 2;
            }
        }
        if (done == 0)
            return -1;
        return sz1 - done + ans;
    }

    int gcda1(int a, int b)
    {
        if (a < b)
            swap(a, b);
        return b == 0 ? a : gcda1(b, a % b);
    }

};

int main()
{

    LT2654 lt;

    myvi v = {}

    return 0;
}
