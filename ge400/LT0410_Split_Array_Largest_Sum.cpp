
#include "../header/myheader.h"

class LT0410
{


// sum / m... 递归 +-1。
// tle


// discuss
//public:
//    using ll = long long;
//
//    bool canSplit(vector<int>& nums, int m, ll sum) {
//        int c = 1;
//        ll s = 0;         // ll == long long

// 二分搜索，初始区间[max in nums, sum of nums].. 值代表每个分组的最大值。
// 二分搜索条件： 对于每个值(left + (right-left) / 2)，是否可能满足划分要求，即每个划分<=值，并且一共m个划分。
//   满足就 right=mid - 1; 不满足就 left = mid + 1;




public:


    // 25/27 tle
    int lt0410a(vector<int>& nums, int m)
    {
//        int64_t sum = accumulate(nums.begin(), nums.end(), 0);

        int64_t sum = 0;
        for (int n : nums)
            sum += n;

        int avg = sum / m;
        int ans = recursiona1(nums, 0, avg, m);
        return ans;
    }

    int recursiona1(vector<int>& nums, int s, int avg, int m)
    {
        #ifdef __test
        cout<<s<<", "<<avg<<", "<<m<<endl;
        #endif // __test

        if (s >= nums.size())
            return INT_MAX;

        if (m == 1)
            return accumulate(nums.begin() + s, nums.end(), 0);

        int i = s;
        int64_t sum = 0;
        while (sum < avg && i < nums.size())            // ....i<...
        {
            sum += nums[i];
            i++;
        }

        int64_t ans = 0;
        if (avg == sum)
        {
            ans = recursiona1(nums, i, avg, m - 1);
            ans = max(ans, sum);

            int64_t t1 = INT_MAX;
            if (i < nums.size() - 1)
            {
                sum += nums[i];
                i++;
                int64_t t1 = recursiona1(nums, i, avg, m - 1);
                t1 = max(t1, sum);
            }

            ans = min (t1, ans);
        }
        else
        {
            ans = recursiona1(nums, i, avg, m - 1);
            ans = max(ans, sum);

            int64_t t1 = INT_MAX;
            if (i > s + 1 && sum > avg)                  // heap over flow..........................
            {
                i--;
                sum -= nums[i];
                t1 = recursiona1(nums, i, avg, m - 1);
                t1 = max(t1, sum);
            }

            ans = min(t1, ans);
        }
        return (int) ans;
    }
};

int main()
{
//    vector<int> n = {7,2,5,10,8};
//    int m = 2;

//    vector<int> n = {1,2147483647};
//    int m = 2;

    vector<int> n = {2,3,1,2,4,3};
    int m = 5;

    LT0410 lt;
    cout<<lt.lt0410a(n, m)<<endl;

    return 0;
}
