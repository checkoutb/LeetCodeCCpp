
#include "../header/myheader.h"

class LT1706
{
public:

// D D

//        int m = grid.size(), n = grid[0].size();
//        vector<int> res;
//        for (int i = 0; i < n; ++i) {
//            int i1 = i, i2;
//            for (int j = 0; j < m; ++j) {
//                i2 = i1 + grid[j][i1];
//                if (i2 < 0 || i2 >= n || grid[j][i2] != grid[j][i1]) {
//                    i1 = -1;
//                    break;
//                }
//                i1 = i2;
//            }
//            res.push_back(i1);
//        }

// 有个 dfs， 有个 图(?)。



//Runtime: 24 ms, faster than 94.77% of C++ online submissions for Where Will the Ball Fall.
//Memory Usage: 13.2 MB, less than 90.05% of C++ online submissions for Where Will the Ball Fall.
// 1  \   -1 /
    vector<int> lt1706a(vector<vector<int>>& grid)
    {
        vector<int> ans(grid[0].size(), -1);
        for (int j = 0; j < ans.size(); ++j)
        {
            int i2 = 0;
            int j2 = j;
            while (i2 != grid.size())
            {
                if (grid[i2][j2] == 1)
                {
//                    i2 = i2;
                    j2++;
                    if (j2 == grid[0].size())
                        break;
                    if (grid[i2][j2] == -1)
                        break;
                    i2++;
                }
                else
                {
                    j2--;
                    if (j2 == -1)
                        break;
                    if (grid[i2][j2] == 1)
                        break;
                    i2++;
                }
            }
            if (i2 == grid.size())
            {
                ans[j] = j2;
            }
        }
        return ans;
    }

    // 不需要dfs，每个球 只有一条路，没有分叉，
//    vector<int> ans;
//    void dfsa1(vector<vector<int>>& vv, int i, int j, int t2)
//    {
//        if (i == vv.size())
//        {
//            ans[t2] = j;
//            return;
//        }
//        if (j == -1 || j == vv[0].size())
//            return;
//
//        if (vv[i][j] == 1)      // \ .
//        {
//            int i2 = i;
//            int j2 = j + 1;
//            if (j2 == v[0].size())
//                return;
//            if (v[i2][j2] == -1)
//                return;
//            dfsa1()
//        }
//        else            // /
//        {
//
//        }
//    }

};

int main()
{
//    myvvi vv = {{1,1,1,-1,-1},{1,1,1,-1,-1},{-1,-1,-1,1,1},{1,1,1,1,-1},{-1,-1,-1,-1,-1}};
//    myvvi vv = {{-1}};

    myvvi vv = {{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1},{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1}};

    LT1706 lt;

    myvi v = lt.lt1706a(vv);

    showVectorInt(v);

    return 0;
}
