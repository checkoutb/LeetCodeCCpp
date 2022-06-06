
#include "../header/myheader.h"

class LT1000
{
public:


    // D D

    // dp[i][j][m] means the cost needed to merge stone[i] ~ stones[j] into m piles.


        //stones[i] ~stones[j] will merge as much as possible.
        //Finally(j - i) % (K - 1) + 1 piles will be left.
        //It's less than K piles and no more merger happens.
        //dp[i][j] means the minimum cost needed to merge stones[i] ~stones[j].
    //for (int m = K; m <= n; ++m)
    //    for (int i = 0; i + m <= n; ++i) {
    //        int j = i + m - 1;
    //        dp[i][j] = INT_MAX;
    //        for (int mid = i; mid < j; mid += K - 1)
    //            dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j]);
    //        if ((j - i) % (K - 1) == 0)
    //            dp[i][j] += prefix[j + 1] - prefix[i];
    //    }


    //vector<vector<int>> dp(N, vector<int>(N));
    //// len is the current substring we are processing (sub-problem)
    //for (int len = K; len <= N; len++) {
    //    // i and j are the span of the previous sub-problems, we are scanning over
    //    for (int i = 0; i <= N - len; i++) {
    //        int j = i + len - 1;
    //        dp[i][j] = INT_MAX;
    //        // mid divides i-j into (1, rest), (K, rest), (2K-1, rest), etc....
    //        for (int mid = i; mid < j; mid += K - 1) {
    //            dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j]);
    //        }
    //        if ((j - i) % (K - 1) == 0)
    //            dp[i][j] += p[j + 1] - p[i];
    //    }
    //}






//Runtime: 3 ms, faster than 83.78 % of C++ online submissions for Minimum Cost to Merge Stones.
//Memory Usage : 8.3 MB, less than 60.27 % of C++ online submissions for Minimum Cost to Merge Stones.
    // dp[i][j] -> [i, j] 的最小花费和
    // 需要一个 prefix_sum 来快速计算 [i, j]的花费
    // size <= 30
    // ... -1 : k+(k-1) k+(k-1)+...+(k-1) .. 这种才能最终merge成一个，其它都不行。
    // 9 : 3-3-3 -> 3 -> 1
    //     3-2-2-2 -> 3-2-2 -> 32 -> 3 -> 1
    // 少一个直接k次。。  1-1-1-1-1 -> (((1,1),1)(1,1))
    int lt1000a(vector<int>& stones, int k)
    {
        int sz1 = stones.size();
        if ((sz1 - k) % (k - 1) != 0)
            return -1;
        vector<int> psum(sz1, 0);
        psum[0] = stones[0];
        for (int i = 1; i < sz1; ++i)
            psum[i] = psum[i - 1] + stones[i];

        vector<vector<int>> vvi(sz1, vector<int>(sz1, 0));
        int sum2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            sum2 += stones[i];
            if (i >= k - 1)
            {
                vvi[i - k + 1][i] = sum2;
                sum2 -= stones[i - k + 1];
            }
        }
#ifdef __test
        //for (myvi& vi : vvi)
        //    showVectorInt(vi);
#endif
        for (int len2 = k + (k - 1); len2 <= sz1; len2 += (k - 1))
        {
            int t2 = len2 - (k - 1);
            for (int i = 0; i + len2 - 1 < sz1; ++i)
            {

                int t4 = INT_MAX;
//                if (len2 % k == 0)            // len2 = 6, k = 2 ....
//                {
//                    int st = i;
//                    t4 = 0;
//                    while (st < (i + len2 - 1))
//                    {
////cout << st << endl;
//                        t4 += vvi[st][st + k - 1];
//                        st += k;
//                    }
//                }

                int j = i + len2 - 1;
                sum2 = psum[j] - (i == 0 ? 0 : psum[i - 1]);
                vvi[i][j] = t4;
                for (int st = i, en = i + t2 - 1; en <= j; ++en, ++st)
                {
                    vvi[i][j] = min(vvi[i][j], vvi[st][en]);
                }
                int t42 = dfsa1(vvi, i, j, 0, k, stones);
#ifdef __test
                cout << i << ", " << j<< ", " << vvi[i][j] << ", " << t4 << ", " << len2 << ", " << t42 << ", " << sum2 << endl;
#endif
                vvi[i][j] = min(vvi[i][j], t42);
                vvi[i][j] += sum2;
            }
        }
#ifdef __test
        //showVectorInt(psum);
        for (myvi& vi : vvi)
            showVectorInt(vi);
#endif

        return vvi[0][sz1 - 1];
    }

    int dfsa1(vector<vector<int>>& vvi, int st, int en, int sum2, int k, vector<int>& stones)
    {
        if (k == 1)
        {
            if (st > en)
                return INT_MAX;
            if (st == en)
                return sum2;
            return vvi[st][en] == 0 ? INT_MAX : vvi[st][en] + sum2;
            //int t2 = st == en ? stones[st] : vvi[st][en];
            //if (t2 == 0)
            //    return INT_MAX;
            //return sum2 + t2;
        }
        else
        {
            if (st >= en)
                return INT_MAX;
        }
        int mn2 = INT_MAX;
        int t3 = dfsa1(vvi, st + 1, en, sum2 
            // + stones[st]                         // 单个石头的代价是在外部的sum2中的。。。。。。
            , k - 1, stones);
        mn2 = std::min(mn2, t3);
        for (int i = st + 1; i <= en - k + 1; ++i)
        {
            if (vvi[st][i] != 0)
            {
                mn2 = min(mn2, dfsa1(vvi, i + 1, en, sum2 + vvi[st][i], k - 1, stones));
            }
            //for (int j = i + 1; j <= en - k + 1; ++j)
            //{
            //    if (vvi[i][j] != 0)
            //    {
            //        mn2 = min(mn2, dfsa1(vvi, ))
            //    }
            //}
        }
        return mn2;
    }

};

int main()
{

    LT1000 lt;

    //myvi v = { 3,2,4,1 };
    //int k = 2;

    //myvi v = { 3,2,4,1 };
    //int k = 3;

    //myvi v = { 3,5,1,2,6 };
    //int k = 3;

    myvi v = { 4,6,4,7,5 };     // 62       // 36+26 .. 4+6(10) 10+4(24(14+10)) 7+5(36(12+24)) 14+12(62(26+36))
    int k = 2;

    //myvi v = { 9, 8, 3, 2, 9, 4 };      // 88
    //int k = 2;

    //myvi v = { 7, 7, 8, 6, 5, 6, 6 };       // 83  {7,7,8}+{6,5,6}+6 = {22}+{17}+6 = 84
    //                                // 7+{7,8,6}+{5,6,6} = 7+{21}+{17} = 83...
    //int k = 3;

    cout << lt.lt1000a(v, k) << endl;

    return 0;
}
