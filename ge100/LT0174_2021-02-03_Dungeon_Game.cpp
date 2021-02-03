
#include "../header/myheader.h"

class LT0174
{
public:

// D

// 从princess 到 knight

//        vector<vector<int> > dp(n + 1, vector<int>(m + 1, 1e9+5));
//        dp[n][m - 1] = 1;
//        dp[n - 1][m] = 1;
//                int need = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
//                // store this value
//                dp[i][j] = need <= 0 ? 1 : need;



// 看discuss的title，就是dp
// 难道 二分？
    int lt0174b(vector<vector<int>>& dungeon)
    {
        int sz1 = dungeon.size();
        int sz2 = dungeon[0].size();
        vector<vector<pair<int, int>>> vvp(sz1, vector<pair<int, int>>(sz2));
        vvp[0][0].first = dungeon[0][0];
        vvp[0][0].second = dungeon[0][0];
        for (int i = 1; i < sz1; ++i)
        {
            int val = dungeon[i][0] + vvp[i - 1][0].second;
            int mn = min(val, vvp[i - 1][0].first);
            vvp[i][0].first = mn;
            vvp[i][0].second = val;
        }
        for (int j = 1; j < sz2; ++j)
        {
            int val = dungeon[0][j] + vvp[0][j - 1].second;
            int mn = min(val, vvp[0][j - 1].first);
            vvp[0][j].first = mn;
            vvp[0][j].second = val;
        }
        for (int i = 1; i < sz1; ++i)
        {
            for (int j = 1; j < sz2; ++j)
            {
                int v1 = dungeon[i][j] + vvp[i - 1][j].second;      // from up
                int m1 = min(v1, vvp[i - 1][j].first);
                int v2 = dungeon[i][j] + vvp[i][j - 1].second;      // from left
                int m2 = min(v2, vvp[i][j - 1].first);
//                if (v1 < v2)
                if (m1 < m2)
                {
                    vvp[i][j].first = m2;
                    vvp[i][j].second = v2;
                }
//                else if (v1 > v2)
                else if (m1 > m2)
                {
                    vvp[i][j].first = m1;
                    vvp[i][j].second = v1;
                }
                else
                {
                    vvp[i][j].first = max(m1, m2);
                    vvp[i][j].second = max(v1, v2);
                }
            }
        }
        #ifdef __test
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                cout<<"{"<<vvp[i][j].first<<","<<vvp[i][j].second<<"}, ";
            }
            cout<<endl;
        }
        #endif // __test
        int mn4 = vvp[sz1 - 1][sz2 - 1].first;
        return mn4 > 0 ? 1 : 1 - mn4;
    }


// tle.
    int lt0174a(vector<vector<int>>& dungeon)
    {
//        int sz1 = dungeon.size();
//        int sz2 = dungeon[0].size();
        dfsa1(dungeon, 0, 0, INT_MAX, 0);
        return ans;
    }
    int ans = INT_MAX;
    void dfsa1(vector<vector<int>>& vvi, int i, int j, int mn, int val)
    {
        if (i == vvi.size() - 1 && j == vvi[0].size() - 1)
        {
            mn = min(mn, val + vvi[i][j]);
            if (mn >= 0)
                ans = min(1, ans);
            else
                ans = min(1 - mn, ans);
            return;
        }
        val += vvi[i][j];
        mn = min(val, mn);
        if (i < vvi.size() - 1)
        {
            dfsa1(vvi, i + 1, j, mn, val);
        }
        if (j < vvi[0].size() - 1)
        {
            dfsa1(vvi, i, j + 1, mn, val);
        }
    }


};

int main()
{
//    myvvi vv = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    myvvi vv = {{1,-3,3},
                {0,-2,0},
                {-3,-3,-3}};

    LT0174 lt;

    cout<<lt.lt0174b(vv);

    return 0;
}
