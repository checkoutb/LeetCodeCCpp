
#include "../header/myheader.h"

class LT2218
{
public:

// D D


//dp[i,k] means picking k elements from pile[i] to pile[n-1].

//        int n = A.size();
//        vector<vector<int>> memo(n + 1, vector<int>(K + 1, 0));
//        function<int(int, int)> dp = [&](int i, int k) {
//            if (memo[i][k] > 0) return memo[i][k];
//            if (i == n || k == 0) return 0;
//            int res = dp(i + 1, k), cur = 0;
//            for (int j = 0; j < A[i].size() && j < k; ++j) {
//                cur += A[i][j];
//                res = max(res, dp(i + 1, k - j - 1) + cur);
//            }
//            memo[i][k] = res;
//            return res;
//        };
//        return dp(0, K);


//int dp[1001][2001] = {};
//int maxValueOfCoins(vector<vector<int>>& piles, int k, int i = 0) {
//    if (i == piles.size() || k == 0)
//        return 0;
//    if (dp[i][k] == 0)
//        for (int j = 0, sum = 0; j <= piles[i].size() && k - j >= 0; ++j) {
//            dp[i][k] = max(dp[i][k], sum + maxValueOfCoins(piles, k - j, i + 1));
//            if (j < piles[i].size())
//                sum += piles[i][j];
//        }
//    return dp[i][k];
//}



//Runtime: 480 ms, faster than 50.00% of C++ online submissions for Maximum Value of K Coins From Piles.
//Memory Usage: 18.1 MB, less than 66.67% of C++ online submissions for Maximum Value of K Coins From Piles.
    int lt2218b(vector<vector<int>>& piles, int k)
    {
        int sz1 = piles.size();
        vector<vector<int>> vvi (sz1, vector<int>(k + 1, 0));
        for (int i = 1; i <= k; ++i)        // 取 i 个
        {
            vvi[0][k - i] = (i <= piles[0].size() ? piles[0][i - 1] : 0) + vvi[0][k - i + 1];
        }
        for (int i = 1; i < sz1; ++i)
        {
            int sum2 = 0;
            for (int j = 0; j <= piles[i].size(); ++j)      // qu j ge                      // 改了这个。 但是 m 的上界是否可以改？
            {
                for (int m = j; m <= k; ++m)
                {
                    vvi[i][m - j] = max(vvi[i][m - j], sum2 + vvi[i - 1][m]);
                }
                if (j < piles[i].size())
                    sum2 += piles[i][j];
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
        return vvi[sz1 - 1][0];
    }

// tle。
// sum(piles[i].length) <= 2000  . 可以dfs啊。？
// dp ，还剩多少次的 ，到目前下标为止， 最大值。
    int lt2218a(vector<vector<int>>& piles, int k)
    {
        int sz1 = piles.size();
        vector<vector<int>> vvi (sz1, vector<int>(k + 1, 0));
        for (int i = 1; i <= k; ++i)        // 取 i 个
        {
            vvi[0][k - i] = (i <= piles[0].size() ? piles[0][i - 1] : 0) + vvi[0][k - i + 1];
        }
        for (int i = 1; i < sz1; ++i)
        {
            int sum2 = 0;
            for (int j = 0; j <= k; ++j)      // qu j ge
            {
//                int t2 = k - j;         // shengyu cishu
//                for (int m = 0; m <= (k - j); ++m)        // 上一轮 还剩 多少次
                for (int m = j; m <= k; ++m)
                {
                    vvi[i][m - j] = max(vvi[i][m - j], sum2 + vvi[i - 1][m]);
                }
                if (j < piles[i].size())
                    sum2 += piles[i][j];
            }
//            for (int j = 0; j <= k; ++j)            // 本列 取后 剩 j 次
//            {
//                int sum2 = 0;
//                for (int m = 0; m <= piles[i].size(); ++m)      // 取 m 个
//                {
//                    int t2 = j + m;             // 上一次 剩几次
//                    vvi[i][j] = max(vvi[i][j], t2 <= k ? vvi[i - 1][t2] : 0);
//                    if (m < piles[i].size())
//                        sum2 += piles[i][m];
//                }
//            }
//            for (int j = k - 1; j >= 0; --j)
//                vvi[i][j] = max(vvi[i][j], vvi[i][j + 1]);
        }
        #ifdef __test
        for (myvi& vi : vvi)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test
        return vvi[sz1 - 1][0];
    }

};

int main()
{

    LT2218 lt;

//    myvvi vv = {{1,100,3},{7,8,9}};
//    int k = 2;

    myvvi vv = {{111},{111},{111},{1,1,1,1,777}};
    int k = 6;

    cout<<lt.lt2218b(vv, k)<<endl;

    return 0;
}
