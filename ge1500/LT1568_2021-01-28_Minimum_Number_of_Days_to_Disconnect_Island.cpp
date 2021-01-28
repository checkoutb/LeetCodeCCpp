
#include "../header/myheader.h"

class LT1568
{
public:

// D D

// Tarjan




//Runtime: 124 ms, faster than 67.35% of C++ online submissions for Minimum Number of Days to Disconnect Island.
//Memory Usage: 8.6 MB, less than 98.98% of C++ online submissions for Minimum Number of Days to Disconnect Island.
// .. 看了 Discuss title。  确实，要么 已经是 分割的， 要么是一个整体， 如果是一个整体，最多 切2次， 就是把 2天可以 切出一个角。
    int lt1568a(vector<vector<int>>& grid)
    {
        if (isDisconnect(grid))
            return 0;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] > 0)
                {
                    grid[i][j] = 0;
                    if (isDisconnect(grid))
                        return 1;
                    grid[i][j] = 1;
                }
        return 2;
    }

    int tag = 2;

    bool isDisconnect(vector<vector<int>>& grid)
    {
        tag++;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] != 0)
                {
                    filla1(grid, i, j);
                    goto AAA;           // 还是得加 {}， break。。
                }
            }
        return true;            // all water
        AAA:
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] != tag && grid[i][j] != 0)
                    return true;
            }
        return false;
    }

    void filla1(vector<vector<int>>& grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || grid[i][j] == tag)
            return;
        grid[i][j] = tag;
        filla1(grid, i + 1, j);
        filla1(grid, i - 1, j);
        filla1(grid, i, j + 1);
        filla1(grid, i, j - 1);
    }

};

int main()
{
//    myvvi vv = {{0,1,1,0},{0,1,1,0},{0,0,0,0}};
//    myvvi vv = {{1,1}};
//    myvvi vv = {{1,0,1,0}};
//    myvvi vv = {{1,1,0,1,1},
//                {1,1,1,1,1},
//                {1,1,0,1,1},
//                {1,1,1,1,1}};
//    myvvi vv = {{1,1},{1,0}};

    myvvi vv = {{0,0,0},{0,1,0},{0,0,0}};

    LT1568 lt;

    cout<<lt.lt1568a(vv)<<endl;

    return 0;
}
