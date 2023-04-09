
#include "../../header/myheader.h"

class LT
{
public:

    // D D





    // 和 2年半前的代码 (差不多) 一模一样。
    // 
    //Runtime18 ms
    //    Beats
    //    31.89 %
    //    Memory9.5 MB
    //    Beats
    //    77.35 %
    int lta(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (grid[i][0] == 0)
                dfs_convert_to_water(grid, i, 0);
            if (grid[i][sz2 - 1] == 0)
                dfs_convert_to_water(grid, i, sz2 - 1);
        }
        for (int j = 1; j < sz2; ++j)
        {
            if (grid[0][j] == 0)
                dfs_convert_to_water(grid, 0, j);
            if (grid[sz1 - 1][j] == 0)
                dfs_convert_to_water(grid, sz1 - 1, j);
        }

        for (int i = 1; i < sz1 - 1; ++i)
        {
            for (int j = 1; j < sz2 - 1; ++j)
            {
                if (grid[i][j] == 0)
                {
                    ++ans;
                    dfs_convert_to_water(grid, i, j);
                }
            }
        }
        return ans;
    }

    int arr[5] = { 1,0,-1,0,1 };

    void dfs_convert_to_water(vector<vector<int>>& vvi, int r, int c)
    {
        if (r == -1 || c == -1 || r == vvi.size() || c == vvi[0].size())
            return;
        if (vvi[r][c] == 1)
            return;

        vvi[r][c] = 1;

        for (int i = 1; i <= 4; ++i)
            dfs_convert_to_water(vvi, r + arr[i - 1], c + arr[i]);
    }

};

int main()
{

    LT lt;


    return 0;
}
