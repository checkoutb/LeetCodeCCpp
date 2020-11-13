
#include "../header/myheader.h"

class LT1254
{
public:

// D D

//        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[r].size())
//            return false;
//        if(grid[r][c] == -1 || grid[r][c] == 1)
//            return true;
//        grid[r][c] = -1;
//
//        bool t1 = dfs(grid, r+1, c);
//        bool t2 = dfs(grid, r, c+1);
//        bool t3 = dfs(grid, r-1, c);
//        bool t4 = dfs(grid, r, c-1);
//
//        return t1 && t2 && t3 && t4;
// 碰到边就是false。


//int fill(vector<vector<int>>& g, int i, int j) {
//    if (i < 0 || j < 0 || i >= g.size() || j >= g[i].size() || g[i][j])
//        return 0;
//    return (g[i][j] = 1) + fill(g, i + 1, j) + fill(g, i, j + 1)
//        + fill(g, i - 1, j) + fill(g, i, j - 1);
//}
//int closedIsland(vector<vector<int>>& g, int res = 0) {
//    for (int i = 0; i < g.size(); ++i)
//        for (int j = 0; j < g[i].size(); ++j)
//            if (i * j == 0 || i == g.size() - 1 || j == g[i].size() - 1)
//                fill(g, i, j);
//    for (int i = 0; i < g.size(); ++i)
//        for (int j = 0; j < g[i].size(); ++j)
//            res += fill(g, i, j) > 0;
//    return res;
//}



//Runtime: 20 ms, faster than 96.81% of C++ online submissions for Number of Closed Islands.
//Memory Usage: 9.8 MB, less than 70.74% of C++ online submissions for Number of Closed Islands.
// 多少个 1形成的圈。
// 扩散出去，碰到
// 不，把边上的岛干掉，剩下的就是 在水里的岛了。
    int lt1254a(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        for (int i = 0; i < sz1; ++i)
        {
            if (grid[i][0] == 0)
                filla1(grid, i, 0);
            if (grid[i][sz2 - 1] == 0)
                filla1(grid, i, sz2 - 1);
        }
        for (int j = 0; j < grid[0].size(); ++j)
        {
            if (grid[0][j] == 0)
                filla1(grid, 0, j);
            if (grid[sz1 - 1][j] == 0)
                filla1(grid, sz1 - 1, j);
        }
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (grid[i][j] == 0)
                {
                    ans++;
                    filla1(grid, i, j);
                }
            }
        }
        return ans;
    }

    void filla1(vector<vector<int>>& grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 1)
            return;
        grid[i][j] = 1;
        filla1(grid, i + 1, j);
        filla1(grid, i - 1, j);
        filla1(grid, i, j + 1);
        filla1(grid, i, j - 1);
    }

//    bool dfsa1(vector<vector<int>>& grid, int i, int j)
//    {
//
//    }
};

int main()
{

//    vector<vector<int>> vv = {{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}};
//    vector<vector<int>> vv = {{0,0,1,0,0},{0,1,0,1,0},{0,1,1,1,0}};
    vector<vector<int>> vv = {{1,1,1,1,1,1,1},
               {1,0,0,0,0,0,1},
               {1,0,1,1,1,0,1},
               {1,0,1,0,1,0,1},
               {1,0,1,1,1,0,1},
               {1,0,0,0,0,0,1},
               {1,1,1,1,1,1,1}};

    LT1254 lt;

    cout<<lt.lt1254a(vv);

    return 0;
}
