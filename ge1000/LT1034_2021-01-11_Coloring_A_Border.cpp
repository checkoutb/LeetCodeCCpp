
#include "../header/myheader.h"

class LT1034
{
public:

// D

// dfs + check


// gg
// ??? 需要空心。。
    vector<vector<int>> lt1034a(vector<vector<int>>& grid, int r0, int c0, int color)
    {
        vector<vector<int>> orivv = grid;
        dfsa1(grid, r0, c0, grid[r0][c0], color);
//        dfsa2(grid, orivv, 0, 0, color);
        vector<vector<int>> ans = grid;

        for (int r = 0; r < grid.size(); ++r)
        {
            for (int c = 0; c < grid[0].size(); ++c)
            {
//                if (orivv[r][c] == color)
//                    continue;
                int r1 = r - 1;
                int r2 = r + 1;
                int c1 = c - 1;
                int c2 = c + 1;
                int t1 = 0;
                int t2 = 0;
                if (r1 < 0)
                    t1 = grid[r][c] - 1;
                else
                    t1 = grid[r1][c];
                if (r2 >= grid.size())
                    t2 = grid[r][c] - 1;
                else
                    t2 = grid[r2][c];
                if (t1 == t2 && t1 == color && r != 0 && r != grid.size() - 1 && c != 0 && c != grid[0].size() - 1)
                {
                    ans[r][c] = orivv[r][c];
                }
                if (c1 < 0)
                    t1 = grid[r][c] - 1;
                else
                    t1 = grid[r][c1];
                if (c2 >= grid[0].size())
                    t2 = grid[r][c] - 1;
                else
                    t2 = grid[r][c2];
                if (t1 == t2 && t1 == color && r != 0 && r != grid.size() - 1 && c != 0 && c != grid[0].size() - 1)
                {
                    ans[r][c] = orivv[r][c];
                }
            }
        }
        return ans;
    }

    // deprecated
    void dfsa2(vector<vector<int>>& vv, vector<vector<int>>& orivv, int r, int c, int to)
    {
        if (r >= vv.size() || c >= vv[0].size())
            return;
        if (orivv[r][c] == to)
            return;
        int r1 = r - 1;
        int r2 = r + 1;
        int c1 = c - 1;
        int c2 = c + 1;
        int t1 = 0;
        int t2 = 0;
        if (r1 < 0)
            t1 = vv[r][c] - 1;
        else
            t1 = vv[r1][c];
        if (r2 >= vv.size())
            t2 = vv[r][c] - 1;
        else
            t2 = vv[r2][c];
        if (t1 == t2 && t1 == to)
        {
            dfsa2(vv, orivv, r + 1, c, to);
            dfsa2(vv, orivv, r, c + 1, to);
            vv[r][c] = orivv[r][c];
            return;
        }
        if (c1 < 0)
            t1 = vv[r][c] - 1;
        else
            t1 = vv[r][c1];
        if (c2 >= vv[0].size())
            t2 = vv[r][c] - 1;
        else
            t2 = vv[r][c2];

//        if (r == 1 && c == 1)
//            cout<<t1<<", "<<t2<<endl;

        if (t1 == t2 && t1 == to)
        {
            dfsa2(vv, orivv, r + 1, c, to);
            dfsa2(vv, orivv, r, c + 1, to);
            vv[r][c] = orivv[r][c];
            return;
        }
    }

    void dfsa1(vector<vector<int>>& vv, int r, int c, int col, int to)
    {
        if (col == to)
            return;
        if (r < 0 || c < 0 || r >= vv.size() || c >= vv[0].size() || vv[r][c] != col)
            return;
        vv[r][c] = to;
        dfsa1(vv, r + 1, c, col, to);
        dfsa1(vv, r - 1, c, col, to);
        dfsa1(vv, r, c + 1, col, to);
        dfsa1(vv, r, c - 1, col, to);
    }

};

int main()
{
//    myvvi vv = {{1,1,1},{1,1,1},{1,1,1}};
//    int r{1}, c{1}, col{2};

//[[1,1,1,1,1,2],
// [1,2,1,1,1,2],
// [1,1,1,1,1,2]]
    myvvi vv = {{1,2,1,2,1,2},
                {2,2,2,2,1,2},
                {1,2,2,2,1,2}};
    int r{1}, c{3}, col{1};

    LT1034 lt;

    myvvi v2 = lt.lt1034a(vv, r, c, col);

    for (myvi& vi : v2)
    {
        for (int& i : vi)
            cout<<i<<", ";
        cout<<endl;
    }

    return 0;
}
