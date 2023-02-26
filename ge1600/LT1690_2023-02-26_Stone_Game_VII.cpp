
#include "../header/myheader.h"

class LT1690
{
public:

    // D D

    //vector<int> dp(n, 0), dp2(n, 0);
    //for (l = n - 2; l >= 0; --l) {
    //    for (r = l + 1; r < n; ++r) {
    //        dp2[r] = prefix[r - 1] - (l > 0 ? prefix[l - 1] : 0) - dp2[r - 1];
    //        dp2[r] = max(dp2[r], prefix[r] - prefix[l] - dp[r]);
    //    }
    //    swap(dp, dp2);
    //}


    //int dp[1001][1001] = {};
    //int dfs(vector<int>& s, int i, int j, int sum) {
    //    if (i == j)
    //        return 0;
    //    return dp[i][j] ? dp[i][j] : dp[i][j] = max(sum - s[i] - dfs(s, i + 1, j, sum - s[i]),
    //        sum - s[j] - dfs(s, i, j - 1, sum - s[j]));
    //}
    //int stoneGameVII(vector<int>& s) {
    //    return dfs(s, 0, s.size() - 1, accumulate(begin(s), end(s), 0));
    //}



    // dp, 就是感觉，感觉对了，就对了，感觉错了，就错了。 虚无缥缈。  这也是我的感觉。

    //Runtime370 ms
    //    Beats
    //    40.63 %
    //    Memory84.5 MB
    //    Beats
    //    32.3 %
    // 看到bob一直输，我想起来，有道题目是， alice 能决定 她始终选择 奇数 或 偶数，所以 必胜。
    int lt1690a(vector<int>& stones)
    {
        int sz1 = stones.size();
        vector<vector<int>> vvi(sz1, vector<int>(sz1, INT_MAX));     // alice - bob

        for (int i = 1; i < sz1; ++i)
            stones[i] += stones[i - 1];

        return dfsa1(vvi, stones, 0, sz1 - 1);
    }

    // alice
    int dfsa1(vector<vector<int>>& vvi, vector<int>& vi, int st, int en)
    {
        if (st >= en)
            return 0;
        if (vvi[st][en] != INT_MAX)
            return vvi[st][en];

        int ans = 0;

        // choose left
        ans = vi[en] - vi[st] + dfsa2(vvi, vi, st + 1, en);

        // choose right
        ans = max(ans, vi[en - 1] - (st == 0 ? 0 : vi[st - 1]) + dfsa2(vvi, vi, st, en - 1));

        vvi[st][en] = ans;
        return ans;
    }

    // bob
    int dfsa2(vector<vector<int>>& vvi, vector<int>& vi, int st, int en)
    {
        if (st >= en)
            return 0;
        if (vvi[st][en] != INT_MAX)
            return vvi[st][en];

        int ans = 0;
        ans = -(vi[en] - vi[st]) + dfsa1(vvi, vi, st + 1, en);
        ans = min(ans, -(vi[en - 1] - (st == 0 ? 0 : vi[st - 1])) + dfsa1(vvi, vi, st, en - 1));
        vvi[st][en] = ans;
        return ans;
    }

};

int main()
{

    LT1690 lt;

    //myvi v = { 5,3,1,4,2 };
    myvi v = { 7,90,5,1,100,10,10,2 };

    cout << lt.lt1690a(v) << endl;

    return 0;
}
