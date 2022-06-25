
#include "../header/myheader.h"

class LT1473
{
public:

    // D D

    // 只需要当前house，所以可以 二维数组 [color][neighbour/block]






//Runtime: 695 ms, faster than 5.28 % of C++ online submissions for Paint House III.
//Memory Usage : 17.3 MB, less than 28.57 % of C++ online submissions for Paint House III.
    // 100 house, 20 colour.
    // [house][color]  [0, house] 这些房子，并且 [house] 这个房子 是 color 颜色。
    // [house][color][neighbour]
    int lt1473a(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target)
    {
        vector<vector<vector<int>>> vvvi(m, vector<vector<int>>(n + 1, vector<int>(target + 1, INT_MAX >> 2)));

        for (int i = 0; i < m; ++i)
        {
#ifdef __test
            cout << " - " << i << endl;
#endif
            if (houses[i] != 0)
            {
                if (i > 0)
                {
                    for (int k = 1; k <= n; k++)     // prev house's color
                    {
                        for (int a = 1; a <= target; ++a)
                        {
                            if (k == houses[i])
                            {
                                vvvi[i][k][a] = min(vvvi[i][k][a], vvvi[i - 1][k][a]);
                            }
                            else
                            {
                                if (a < target)
                                {
                                    vvvi[i][houses[i]][a + 1] = min(vvvi[i][houses[i]][a + 1], vvvi[i - 1][k][a]);
                                }
                            }
                        }
                    }
                }
                else
                {
                    vvvi[i][houses[i]][1] = 0;
                }
                continue;
            }
            for (int j = 1; j <= n; j++)     // this house choose color [1, n]
            {
                if (i == 0)
                {
                    vvvi[i][j][1] = cost[i][j - 1];
                }
                else
                {
                    for (int k = 1; k <= n; ++k)     // prev house choose color
                    {
                        for (int a = 1; a <= target; ++a)       // prev house ... neighbour
                        {
                            if (j == k)
                            {
                                vvvi[i][j][a] = min(vvvi[i][j][a], vvvi[i - 1][k][a] + cost[i][j - 1]);
                            }
                            else
                            {
                                if (a < target)
                                {
                                    vvvi[i][j][a + 1] = min(vvvi[i][j][a + 1], vvvi[i - 1][k][a] + cost[i][j - 1]);
                                }
                            }
                        }
                    }
                }
            }
        }
        int ans = INT_MAX;

        for (int j = 1; j <= n; ++j)
        {
            ans = min(ans, vvvi[m - 1][j][target]);
        }

        return ans == (INT_MAX >> 2) ? -1 : ans;
    }

};

int main()
{

    LT1473 lt;

    //myvi v = { 0,0,0,0,0 };
    //myvvi vv = { {1,10},{10,1},{10,1},{1,10},{5,1} };
    //int tar = 3;

    //myvi v = { 3,1,2,3 };
    //myvvi vv = { {1,1,1},{1,1,1},{1,1,1},{1,1,1} };
    //int tar = 3;

    myvi v = { 0,2,1,2,0 };
    myvvi vv = { {1,10},{10,1},{10,1},{1,10},{5,1} };
    int tar = 3;

    cout << lt.lt1473a(v, vv, v.size(), vv[0].size(), tar) << endl;

    return 0;
}
