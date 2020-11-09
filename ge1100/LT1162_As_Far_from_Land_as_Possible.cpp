
#include "../header/myheader.h"

class LT1162
{
public:

// D

// bfs, 而且是 找出所有1，然后 开始 bfs。。 这样就不会 重复设置值了。





// tle...
//The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
// 只能直走，距离。
// 对每个1 层级扩散。
    int lt1162a(vector<vector<int>>& grid)
    {
        int cnt1 = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    dfsa1(grid, i + 1, j, 2);
                    dfsa1(grid, i - 1, j, 2);
                    dfsa1(grid, i, j + 1, 2);
                    dfsa1(grid, i, j - 1, 2);
                    cnt1++;
                }
            }
        }
        if (cnt1 == 0 || cnt1 == grid.size() * grid[0].size())
            return -1;

        int ans = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                ans = max(ans, grid[i][j]);
            }
        }
        #ifdef __test
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                cout<<grid[i][j]<<", ";
            }
            cout<<endl;
        }
        #endif // __test
        return ans - 1;
    }

    void dfsa1(vector<vector<int>>& g, int i, int j, int val)
    {
        if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] == 1 || (g[i][j] != 0 && g[i][j] < val))
            return;
        g[i][j] = val;
        dfsa1(g, i + 1, j, val + 1);
        dfsa1(g, i - 1, j, val + 1);
        dfsa1(g, i, j + 1, val + 1);
        dfsa1(g, i, j - 1, val + 1);
    }
};

int main()
{

//    vector<vector<int>> vv = {{1,0,1},{0,0,0},{1,0,1}};
    vector<vector<int>> vv = {{1,0,0},{0,0,0},{0,0,0}};

    LT1162 lt;

    cout<<lt.lt1162a(vv)<<endl;

    return 0;
}
