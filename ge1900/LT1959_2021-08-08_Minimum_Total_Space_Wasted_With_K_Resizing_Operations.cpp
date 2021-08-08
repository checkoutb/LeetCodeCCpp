
#include "../header/myheader.h"

class LT1959
{
public:

// D D

// We do not have enough accepted submissions to show

//    if (dp[i][k] == -1) {
//        dp[i][k] = dfs(nums, i + 1, k - 1);
//        int mx = nums[i], sum = nums[i];
//        for (int j = i + 1; j < nums.size(); ++j) {
//            mx = max(mx, nums[j]);
//            sum += nums[j];
//            int diff = mx * (j - i + 1) - sum;
//            dp[i][k] = min(dp[i][k], diff + dfs(nums, j + 1, k - 1));
//        }
//    }





//Runtime: 468 ms, faster than 100.00% of C++ online submissions for Minimum Total Space Wasted With K Resizing Operations.
//Memory Usage: 9.8 MB, less than 100.00% of C++ online submissions for Minimum Total Space Wasted With K Resizing Operations.
// k = 0, size == max_ele(nums)
// k = 1, 前半部分max 后半部分后半的max  or 前半部分前半的max 后半部分max
// 划分成 k+1 个部分， 每个部分是
// hint 2: Can we build our solution using dynamic programming using the current index and the number of resizing operations performed as the states?
//   已经执行了几次resize ？
    int lt1959a(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
        vector<vector<int>> vvi(k + 1, vector<int>(sz1));
        // 在 i 之前 i-1 之后， resize.
        // wasted
//        int was = 0;        // waste
        int mx = nums[sz1 - 1];
        int sum2 = mx;
        vvi[0][sz1 - 1] = 0;
        for (int i = sz1 - 2; i >= 0; --i)
        {
            mx = max(mx, nums[i]);
            sum2 += nums[i];
            vvi[0][i] = (mx * (sz1 - i)) - sum2;
        }
        for (int i = 1; i <= k; ++i)
        {
            for (int j = 0; j < sz1 - 1; ++j)
            {
                mx = nums[j];
                sum2 = nums[j];
                vvi[i][j] = (mx * 1 - sum2) + vvi[i - 1][j + 1];
                for (int k = j + 1; k < sz1 - 1; ++k)
                {
                    mx = max(mx, nums[k]);
                    sum2 += nums[k];
                    vvi[i][j] = min(vvi[i][j], (mx * (k - j + 1) - sum2) + vvi[i - 1][k + 1]);
                }
            }
        }
        #ifdef __test
        for (myvi& vi : vvi)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test
        return vvi[k][0];
    }

};

int main()
{
//    myvi v = {10,20};
//    int k{0};

//    myvi v = {10,20,30};
//    int k{1};

    myvi v = {10,20,15,30,20};
    int k(2);

    LT1959 lt;

    cout<<lt.lt1959a(v, k)<<endl;

    return 0;
}
