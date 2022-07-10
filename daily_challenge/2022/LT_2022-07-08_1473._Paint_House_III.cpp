
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    // .. 我写 dfs+memo 的时候，他们写 bottom-up,  我写bottom-up 的时候，他们写 top-down...

    // 感觉是 稀疏矩阵，或者 稠密矩阵的区别。 这道题目，它应该很稀疏，毕竟 如果 houses已经刷漆，那么可以砍掉很多分支，还有neighour的数量也可以剔除很多分支。 所以是稀疏的。
    //      不像 其它的dp， for for 全部走一遍，需要遍历全部分支。


    //int dp[101][101][21] = {};
    //int dfs(vector<int>& houses, vector<vector<int>>& cost, int i, int target, int last_clr) {
    //    if (i >= houses.size() || target < 0)
    //        return target == 0 ? target : 1000001;
    //    if (houses[i] != 0) // painted last year.
    //        return dfs(houses, cost, i + 1, target - (last_clr != houses[i]), houses[i]);
    //    if (dp[i][target][last_clr])
    //        return dp[i][target][last_clr];
    //    auto res = 1000001;
    //    for (auto clr = 1; clr <= cost[i].size(); ++clr) {
    //        res = min(res, cost[i][clr - 1]
    //            + dfs(houses, cost, i + 1, target - (last_clr != clr), clr));
    //    }
    //    return dp[i][target][last_clr] = res;
    //}
    //int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
    //    auto res = dfs(houses, cost, 0, target, 0);
    //    return res > 1000000 ? -1 : res;
    //}






//Runtime: 502 ms, faster than 5.05 % of C++ online submissions for Paint House III.
//Memory Usage : 17.1 MB, less than 38.03 % of C++ online submissions for Paint House III.
    int lta(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target)
    {
        vector<vector<vector<int>>> vvvi(m, vector<vector<int>>(n + 1, vector<int>(target + 1, INT_MAX >> 2)));
        if (houses[0] == 0)
        {
            for (int i = 0; i < n; ++i)
            {
                vvvi[0][i + 1][1] = cost[0][i];
            }
        }
        else
        {
            vvvi[0][houses[0]][1] = 0;
        }

        for (int i = 1; i < m; ++i)
        {
            if (houses[i] == 0)
            {
                for (int col = 1; col <= n; ++col)      // my color
                {
                    for (int col2 = 1; col2 <= n; ++col2)   // previous color
                    {
                        for (int j = 1; j <= target; ++j)       // previous neighbour
                        {
                            int t2 = j + (col == col2 ? 0 : 1);
                            if (t2 > target)
                                continue;

                            vvvi[i][col][t2] = min(vvvi[i][col][t2], vvvi[i - 1][col2][j] + cost[i][col - 1]);

                        }
                    }
                }
            }
            else
            {
                for (int col2 = 1; col2 <= n; ++col2)
                {
                    for (int j = 1; j <= target; ++j)
                    {
                        int t2 = j + (houses[i] == col2 ? 0 : 1);
                        if (t2 > target)
                            continue;

                        vvvi[i][houses[i]][t2] = min(vvvi[i][houses[i]][t2], vvvi[i - 1][col2][j]);
                    }
                }
            }
        }

#ifdef __test
        for (myvvi& vv : vvvi)      // houses
        {
            for (myvi& v : vv)      // color
            {
                for (int i : v)     // target
                    cout << i << ", ";
                cout << endl;
            }
            cout << "=====================" << endl;
        }
#endif

        int ans = INT_MAX;
        for (int i = 1; i <= n; ++i)
        {
            ans = min(ans, vvvi[m - 1][i][target]);
        }
        return ans == (INT_MAX >> 2) ? -1 : ans;
    }


};

int main()
{

    LT lt;

    //myvi v = { 0,0,0,0,0 };
    //myvvi vv = { {1,10},{10,1},{10,1},{1,10},{5,1} };
    //int m = 5, n = 2, t = 3;

    //myvi v = { 0,2,1,2,0 };
    //myvvi vv = { {1,10},{10,1},{10,1},{1,10},{5,1} };
    //int m = 5, n = 2, t = 3;

    myvi v = { 3,1,2,3 };
    myvvi vv = { {1,1,1},{1,1,1},{1,1,1},{1,1,1} };
    int m = 4, n = 3, t = 3;

    cout << lt.lta(v, vv, m, n, t) << endl;

    return 0;
}
