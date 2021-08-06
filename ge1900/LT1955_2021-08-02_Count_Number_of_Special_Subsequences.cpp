
#include "../header/myheader.h"

class LT1955
{
public:

// D D

//    struct DT {
//        unsigned v[3];
//        DT() { v[0] = v[1] = v[2] = 0; }
//    };
//    int countSpecialSubsequences(vector<int>& nums) {
//        int N = nums.size();
//        vector<DT> dp(N+1);
//        for (int i=0;i<N;++i) {
//            dp[i+1] = dp[i];
//            switch(nums[i]) {
//                case 0:
//                    dp[i+1].v[0] = MOD(2*dp[i+1].v[0] + 1);
//                    break;
//                case 1:
//                    dp[i+1].v[1] = MOD(2*dp[i+1].v[1] + dp[i].v[0]);
//                    break;
//                case 2:
//                    dp[i+1].v[2] = MOD(2*dp[i+1].v[2] + dp[i].v[1]);
//                    break;
//            }
//        }
//        return dp.back().v[2];


//        while(i < n){
//            vector<long> dp2 = dp;
//            int val = nums[i];
//            dp2[val] = (dp2[val] + (val > 0 ? dp[val-1] : 1)+ dp[val]) % MOD;
//            dp = dp2;
//            i++;
//        }
//        return dp[2];


//        MOD = 10**9 + 7
//        dp = [1, 0, 0, 0]
//        for num in nums:
//            idx = num + 1
//            dp[idx] += (dp[idx] + dp[idx-1])
//            dp[idx] = dp[idx] % MOD
//        return dp[-1]


//        vector<int> dp = {0, 0, 0};
//        int mod = 1e9 + 7;
//        for (int& a: A)
//            dp[a] = ((dp[a] + dp[a]) % mod + (a > 0 ? dp[a-1] : 1)) % mod;
//        return dp[2];



//int dp[100001][4] = {}, mod = 1000000007;
//int dfs(vector<int>& nums, int i, int last) {
//    if (i >= nums.size())
//        return last == 2;
//    if (dp[i][last + 1] == 0) {
//        dp[i][last + 1] = 1 + dfs(nums, i + 1, last);
//        if (nums[i] == last || nums[i] == last + 1)
//            dp[i][last + 1] = (dp[i][last + 1] + dfs(nums, i + 1, nums[i])) % mod;
//    }
//    return dp[i][last + 1] - 1;
//}
//int countSpecialSubsequences(vector<int>& nums) {
//    return dfs(nums, 0, -1);
//}


//    long long c[4] = { 1 }, mod = 1000000007;
//    for (auto n : nums)
//		c[n + 1] = (c[n + 1] * 2 + c[n]) % mod;
//    return c[3];




// vi 似乎没有任何用。。 应该也是 样本不足，所以100%了。
//Runtime: 200 ms, faster than 100.00% of C++ online submissions for Count Number of Special Subsequences.
//Memory Usage: 180.1 MB, less than 100.00% of C++ online submissions for Count Number of Special Subsequences.
    int lt1955a(vector<int>& nums)
    {
        int sz1 = nums.size();
        vector<int> vi(sz1, 0);
        int arr[3] = {0};
        const int MOD = 1E9 + 7;
        if (nums[0] == 0)
        {
            arr[0] = 1;
            vi[0] = 1;
        }
        int ans = 0;
        for (int i = 1; i < sz1; ++i)
        {
            switch(nums[i])
            {
            case 0:
                vi[i] = (arr[0] + 1) % MOD;
                arr[0] = (arr[0] + vi[i]) % MOD;
                break;
            case 1:
                vi[i] = (arr[0] + arr[1]) % MOD;
                arr[1] = (arr[1] + vi[i]) % MOD;
                break;
            case 2:
                vi[i] = (arr[1] + arr[2]) % MOD;
                arr[2] = (arr[2] + vi[i]) % MOD;
                ans = (ans + vi[i]) % MOD;
                break;
            }
        }
        return ans;
    }

};

int main()
{
//    myvi v = {0,1,2,2};
//    myvi v = {2,2,0,0};
    myvi v = {0,1,2,0,1,2};

    LT1955 lt;

    cout<<lt.lt1955a(v)<<endl;

    return 0;
}
