
#include "../header/myheader.h"

class LT1712
{
public:

// D D

//    int res = 0, sz = nums.size();
//    partial_sum(begin(nums), end(nums), begin(nums));
//    for (int i = 0, j = 0, k = 0; i < sz - 2; ++i) {
//        while (j <= i || (j < sz - 1 && nums[j] < nums[i] * 2))
//            ++j;
//        while (k < j || ( k < sz - 1 && nums[k] - nums[i] <= nums[sz - 1] - nums[k]))
//            ++k;
//        res = (res + k - j) % 1000000007;
//    }
//    return res;
// 3指针。
//For each point i, we find the minimum (j) and maximum (k) boundaries of the second subarray:
//    nums[j] >= 2 * nums[i]
//    nums[sz - 1] - nums[k] >= nums[k] - nums[i]
// 。第一个数组 确定的情况下， 第二，第三个 可以 有多少种可能。 j,k 都是 第二个数组的结束。  最早结束j，最晚结束k
// partial_sum


// binary search.


// tle...
    int lt1712a(vector<int>& nums)
    {
        for (int i = 1; i < nums.size(); ++i)
        {
            nums[i] += nums[i - 1];
        }
        int sz1 = nums.size();
//        int mxs = nums[sz1 - 1] / 3;
        int mxs1 = nums[sz1 - 1] / 3;
        int mxs2 = mxs1 * 2 + 1;
        int ans = 0;
        int sum2 = nums[sz1 - 1];
        const int mod = 1E9 + 7;
        for (int i = 0; i < sz1; ++i)
        {
            int v1 = nums[i];
            if (v1 > mxs1)
                break;

            for (int j = i + 1; j < sz1; ++j)
            {
                int v2 = nums[j] - nums[i];
                if (v2 < v1)
                    continue;
                if (v2 > mxs2)
                    break;
                int v3 = sum2 - v1 - v2;
                if (v3 < v2)
                    break;
                ans++;
                if (ans >= mod)             // ans = (ans + 1) % mod;      which is faster?
                    ans = 0;
            }
        }
        return ans;
    }

};

int main()
{
//    myvi v = {1,1,1};
//    myvi v = {1,2,2,2,5,0};
//    myvi v = {3,2,1};
    myvi v = {0,3,3};

    LT1712 lt;

    cout<<lt.lt1712a(v)<<endl;

    return 0;
}
