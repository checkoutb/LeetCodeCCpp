
#include "../header/myheader.h"

class LT2088
{
public:

    // D D

    // grid[i][j] = min(grid[i - 1][j - 1], grid[i - 1][j + 1]) + 1;
    // 只需要2个，因为 grid[i-1][j] 被 [j-1],[j+1] 完全覆盖了的。
    // 。不，如果grid[i-1][j]是0呢。。


    //int m = g.size(), n = g[0].size(), res = 0;
    //for (int i = 1; i < m; ++i) {
    //    for (int j = 0, cnt = 0; j < n; ++j) {
    //        cnt = g[i][j] + (g[i][j] ? cnt : 0);
    //        for (int h = 1; cnt > h * 2 && g[i - 1][j - h] >= h; ++h, ++res)
    //            g[i][j - h] = h + 1;
    //    }
    //}
    // 。。 不理解


//Runtime: 170 ms, faster than 76.99 % of C++ online submissions for Count Fertile Pyramids in a Land.
//Memory Usage : 39.8 MB, less than 38.49 % of C++ online submissions for Count Fertile Pyramids in a Land.
    int lt2088a(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();

        vector<vector<int>> vvi(begin(grid), end(grid));
        int ans = 0;
        for (int i = sz1 - 2; i >= 0; --i)
        {
            for (int j = 1; j < sz2 - 1; ++j)
            {
                if (vvi[i][j] == 1)
                {
                    int t2 = min({ vvi[i + 1][j - 1],vvi[i + 1][j],vvi[i + 1][j + 1] });
                    ans += t2;
                    vvi[i][j] = t2 + 1;
                }
            }
        }

#ifdef __test
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                cout << vvi[i][j] << ", ";
            }
            cout << endl;
        }
#endif

        vector<vector<int>> vv2(begin(grid), end(grid));
        for (int i = 1; i < sz1; ++i)
        {
            for (int j = 1; j < sz2 - 1; ++j)
            {
                if (vv2[i][j] == 1)
                {
                    int t2 = min({ vv2[i - 1][j - 1],vv2[i - 1][j],vv2[i - 1][j + 1] });
                    ans += t2;
                    vv2[i][j] = t2 + 1;
                }
            }
        }

#ifdef __test
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                cout << vv2[i][j] << ", ";
            }
            cout << endl;
        }
#endif

        return ans;
    }

};

int main()
{

    LT2088 lt;

    //myvvi vv = { {0,1,1,0},{1,1,1,1} };
    myvvi vv = { {1,1,1},{1,1,1} };
    //myvvi vv = { {1,1,1,1,0},{1,1,1,1,1},{1,1,1,1,1},{0,1,0,0,1} };

    cout << lt.lt2088a(vv) << endl;

    return 0;
}
