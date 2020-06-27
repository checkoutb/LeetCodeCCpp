
#include "../header/myheader.h"

class LT0980
{
public:


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths III.
//Memory Usage: 7.2 MB, less than 50.46% of C++ online submissions for Unique Paths III.
    int lt0980a(vector<vector<int>>& grid)
    {
        int ii = 0;
        int jj = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 0)
                {
                    num0++;
                }
                if (grid[i][j] == 1)
                {
                   ii = i;
                   jj = j;
                }
            }
        }
        grid[ii][jj] = -1;
        dfsa1(grid, ii + 1, jj, 0);
        dfsa1(grid, ii - 1, jj, 0);
        dfsa1(grid, ii, jj + 1, 0);
        dfsa1(grid, ii, jj - 1, 0);
        grid[ii][jj] = 1;
        return ans;
    }

    int ans = 0;
    int num0 = 0;

    int dfsa1(vector<vector<int>>& grid, int i, int j, int cnt)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] < 0)
            return -1;
        if (grid[i][j] == 2)
        {
            if (cnt == num0)
                ans++;
            return 1;
        }
        grid[i][j] = -1;
        dfsa1(grid, i + 1, j, cnt + 1);
        dfsa1(grid, i - 1, j, cnt + 1);
        dfsa1(grid, i, j + 1, cnt + 1);
        dfsa1(grid, i, j - 1, cnt + 1);
        grid[i][j] = 0;

        return 0;
    }

};

int main()
{

    vector<vector<int>> g = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};

    LT0980 lt;

    cout<<lt.lt0980a(g)<<endl;

    return 0;
}
