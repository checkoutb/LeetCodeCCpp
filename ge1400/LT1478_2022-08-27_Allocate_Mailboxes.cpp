
#include "../header/myheader.h"

class LT1478
{
public:

    // D

    // 预先计算下 [i][j] 间 只有一个 邮箱 的 总距离
    //
    // dp[k][i]  从 i 开始 到 最后的房子，总共 k 个邮箱 的消耗。
    //for (int j = i; j < n; j++)
    //    ans = min(ans, costs[i][j] + dp(houses, n, k - 1, j + 1));


    // g



    // tle。。。
    // 
    // 邮箱应该在 某些house 门口。 门不门口 都一样，只不过 门口好算。
    // 是 剔除邮箱，还是 增加邮箱。
    // 可以分块的，dfs+memo 
    // 就是，取信的时候，不可能出现  2个面对面的人 走着走着 会 变成 背对背。
    // 多个房子 属于 同一块的时候，且只有一个邮箱， 那么这个邮箱 放 中位数 上最合适。   (x+1)/2
    // [house st][house en][mailbox]
    int lt1478a(vector<int>& houses, int k)
    {
        int sz1 = houses.size();

        if (sz1 == k)
            return 0;

        sort(begin(houses), end(houses));

        vector<vector<vector<int>>> vvvi(sz1, vector<vector<int>>(sz1, vector<int>(k + 1, -1)));

        dfsa1(houses, k, 0, sz1 - 1, vvvi);

        return vvvi[0][sz1 - 1][k];
    }

    int dfsa1(vector<int>& hs, int k, int st, int en, vector<vector<vector<int>>>& vvvi)
    {
        if ((en - st + 1) <= k)
            return 0;

        if (vvvi[st][en][k] != -1)
            return vvvi[st][en][k];

        if (k == 1)
        {
            int t2 = (st + (en - st + 1) / 2);
            t2 = hs[t2];
            int ans = 0;

            for (int i = st; i <= en; ++i)
            {
                ans += abs(hs[i] - t2);
            }
            vvvi[st][en][k] = ans;
            return ans;
        }

        int ans = INT_MAX;

        for (int i = st; i < en; ++i)
        {
            for (int j = 1; j < k; ++j)
            {
                int t2 = dfsa1(hs, j, st, i, vvvi) + dfsa1(hs, k - j, i + 1, en, vvvi);
                ans = min(ans, t2);
            }
        }
        vvvi[st][en][k] = ans;
        return ans;
    }

};

int main()
{

    LT1478 lt;

    //myvi v = { 1,4,8,10,20 };
    //int k = 3;

    myvi v = { 2,3,5,12,18 };
    int k = 5;

    cout << lt.lt1478a(v, k) << endl;

    return 0;
}
