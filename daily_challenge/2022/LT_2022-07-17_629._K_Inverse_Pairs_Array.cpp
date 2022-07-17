
#include "../../header/myheader.h"

class LT
{
public:

    // D

    // 不是 prefix sum ， 而是 sliding window...
    // 上+左 还是 prefix sum


    //dp[n][k + 1] = dp[n][k] + dp[n - 1][k + 1] - dp[n - 1][k + 1 - n]


    //int dp[1001][1001] = { 1 };
    //class Solution {
    //public:
    //    int kInversePairs(int n, int k) {
    //        if (dp[n][k])
    //            return dp[n][k];
    //        for (int N = 1; N <= n; ++N)
    //            for (int K = 0; K <= k; ++K) {
    //                dp[N][K] = (dp[N - 1][K] + (K > 0 ? dp[N][K - 1] : 0)) % 1000000007;
    //                if (K >= N)
    //                    dp[N][K] = (1000000007 + dp[N][K] - dp[N - 1][K - N]) % 1000000007;
    //            }
    //        return dp[n][k];
    //    }
    //};




    // GG   。。。



    // prefixsum ？  但是 lta 的输出中，有不满足的。。
    // 又像是 上+左。。。
    int ltb(int n, int k)
    {
        vector<vector<int>> vvi(n + 1, vector<int>(k + 1, -1));

        for (int i = 0; i <= n; ++i)
        {
            vvi[i][0] = 1;
        }

        for (int i = 1; i <= k; ++i)
        {

        }

        return vvi[n][k];
    }



    // tle
    int lta2(int n, int k)
    {
        vector<vector<int>> vvi(n + 1, vector<int>(k + 1, -1));
        int ans = dfsa12(vvi, n, k);

        return ans;
    }

    int dfsa12(vector<vector<int>>& vvi, int n, int k)
    {
        if (vvi[n][k] != -1)
            return vvi[n][k];
        if (k == 0)
        {
            vvi[n][k] = 1;
            return 1;
        }
        if (n == 1)
        {
            vvi[n][k] = k == 0;
            return k == 0 ? 1 : 0;
        }
        if (k > (n * (n - 1) / 2))
        {
            vvi[n][k] = 0;
            return 0;
        }
        if (k == (n * (n - 1) / 2))
        {
            vvi[n][k] = 1;
            return 1;
        }

        int ans = 0;
        const int MOD = 1e9 + 7;

        //for (int i = 0; i <= min(k, n - 1); ++i)
        for (int i = min(k, n - 1); i >= 0; --i)
        {
            int t2 = dfsa12(vvi, n - 1, k - i);
            ans = (ans + t2) % MOD;
            if (t2 == 0)
                break;
        }
        vvi[n][k] = ans;
        return ans;
    }

    // tle      1000 1000
    // 下标小 但是值大。
    // 这2个应该是 相连的， 否则的话，中间的其它数值 必然会导致 inverse pair 的增加。
    // 1 2 3 4 5
    // 21345 13245 12435 12354
    // 21345 -> 23145 21435 21354 
    // 13245 -> 13425 13254     31245
    // 12435 -> 12453           14235
    // 12354 -> {}              12534
    // 
    // 31245    2ge
    // {1,2,3} {1,22,55} 组成的 inverse pair 个数并没有区别。 
    // 缩小的时候，要直接减去 。 需要知道 个数。 不太需要。
    // 感觉有数学的解法， n==1 || k==0 || n==(k*(k-1)/2)(可能) 都是 返回1.  k==1返回 n-1,  k==2返回？ 感觉排列组合。
    //              k==0 是直接升序， n==(k k-1 2)是降序。
    int lta(int n, int k)
    {
        vector<vector<int>> vvi(n + 1, vector<int>(k + 1, -1));
        int ans = dfsa1(vvi, n, k);
#ifdef __test
        for (myvi& vi : vvi)
        {
            for (int i : vi)
                cout << i << ", ";
            cout << endl;
        }
#endif
        return ans;
    }

    int dfsa1(vector<vector<int>>& vvi, int n, int k)
    {
#ifdef __test
        cout << n << " -- " << k << endl;
#endif
        //if (n == 1 || k == 0)
        //    return 1;

        if (k == 0)
        {
#ifdef __test
            vvi[n][k] = 1;
#endif
            return 1;
        }
        if (n == 1)
        {
#ifdef __test
            vvi[n][k] = k == 0;
#endif
            return k == 0 ? 1 : 0;
        }
        if (k > (n * (n - 1) / 2))
        {
#ifdef __test
            vvi[n][k] = 0;
#endif
            return 0;
        }
        //if (k == (n * (n - 1) / 2))
        //    return 1;

        if (vvi[n][k] != -1)
            return vvi[n][k];

        int ans = 0;
        const int MOD = 1e9 + 7;

        //for (int i = 0; i <= k; ++i)        // 0取最小， 1取次小， 2取次次小
        for (int i = 0; i <= min(k, n - 1); ++i)
        {
            ans = (ans + dfsa1(vvi, n - 1, k - i)) % MOD;
#ifdef __test
            if (n == 6 && k == 3)
            {
                cout << "              " << i << " - " << ans << endl;
            }
#endif
        }
        vvi[n][k] = ans;
        return ans;
    }

};

int main()
{

    LT lt;

    //int n{ 3 }, k{ 1 };
    //int n{ 6 }, k{ 3 };     // 29
    //int n{ 4 }, k{ 2 };     // 5
    // 3 2 2
    // 4 1 3

    //int n{ 3 }, k{ 2 };     // 2 // 312 231

    //int n{ 6 }, k{ 3 };

    int n{ 10 }, k{ 4 };         // 440

    //int n{ 1000 }, k{ 1000 };

    cout << lt.lta(n, k) << endl;

    return 0;
}
