
#include "../header/myheader.h"

class LT0695
{
public:

// D D

// bfs




//Runtime: 24 ms, faster than 96.98% of C++ online submissions for Max Area of Island.
//Memory Usage: 23.4 MB, less than 70.29% of C++ online submissions for Max Area of Island.
    int lt0695a(vector<vector<int>>& grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    ans = max(ans, calFillAreaa1(grid, i, j));
                }
            }
        }
        return ans;
    }

    int calFillAreaa1(vector<vector<int>>& grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1)
            return 0;

        int ans = 1;
        grid[i][j] = -1;
        ans += calFillAreaa1(grid, i + 1, j);
        ans += calFillAreaa1(grid, i - 1, j);
        ans += calFillAreaa1(grid, i, j + 1);
        ans += calFillAreaa1(grid, i, j - 1);
        return ans;
    }

//    int filla1(vector<vector<int>>& grid, int r, int c, int tag)
//    {
//
//    }

};

int main()
{

    vector<vector<int>> vv = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
 {0,0,0,0,0,0,0,1,1,1,0,0,0},
 {0,1,1,0,1,0,0,0,0,0,0,0,0},
 {0,1,0,0,1,1,0,0,1,0,1,0,0},
 {0,1,0,0,1,1,0,0,1,1,1,0,0},
 {0,0,0,0,0,0,0,0,0,0,1,0,0},
 {0,0,0,0,0,0,0,1,1,1,0,0,0},
 {0,0,0,0,0,0,0,1,1,0,0,0,0}};

    LT0695 lt;

    cout<<lt.lt0695a(vv)<<endl;

    return 0;
}
