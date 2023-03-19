
#include "../header/myheader.h"

class LT0375
{
public:

    // D D

    //int[][] dp = new int[n + 1][n + 1];
    //for (int jminusi = 1; jminusi < n; jminusi++) {
    //    for (int i = 0; i + jminusi <= n; i++) {
    //        int j = i + jminusi;
    //        dp[i][j] = Integer.MAX_VALUE;
    //        for (int k = i; k <= j; k++) {
    //            dp[i][j] = Math.min(dp[i][j],
    //                k + Math.max(k - 1 >= i ? dp[i][k - 1] : 0,
    //                    j >= k + 1 ? dp[k + 1][j] : 0));
    //        }
    //    }
    //}




    
    //Runtime236 ms
    //    Beats
    //    48.99 %
    //    Memory8.2 MB
    //    Beats
    //    53.1 %
    int lt0375a(int n)
    {
        if (n == 1)
            return 0;

        vector<vector<int>> vvi(n + 1, vector<int>(n + 1, INT_MAX));

        dfsa1(vvi, 1, n);

        return vvi[1][n];
    }

    int dfsa1(vector<vector<int>>& vvi, int st, int en)
    {
        if (st >= en)
            return 0;

        if (vvi[st][en] != INT_MAX)
            return vvi[st][en];

        int t2 = INT_MAX;
        for (int i = st; i <= en; ++i)
        {
            t2 = min(t2, i + max(dfsa1(vvi, st, i - 1), dfsa1(vvi, i + 1, en)));
        }
        vvi[st][en] = t2;

#ifdef __test
        //cout << st << " - " << en << " : " << t2 << endl;
#endif

        return t2;
    }

};

int main()
{

    LT0375 lt;

    int n = 10;

    cout << lt.lt0375a(n) << endl;

    return 0;
}
