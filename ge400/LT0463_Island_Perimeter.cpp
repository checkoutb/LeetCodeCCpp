
#include "../header/myheader.h"

class LT0463
{
public:


// d & d

// islands * 4 - neighbours * 2。 邻居是右侧或下侧的；左，上不记录。，左，上在计算它们自己的时候，就把本节点计算为 邻居了。
// 有一个邻居，说明自己与邻居各减少一条边。


// 估计找到一块陆地，然后展开更快。

//Runtime: 76 ms, faster than 47.78% of C++ online submissions for Island Perimeter.
//Memory Usage: 16.1 MB, less than 100.00% of C++ online submissions for Island Perimeter.

    int lt0463a(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();

        int ans = 0;

        for (int i = 0; i < sz1; i++)
        {
            for (int j = 0; j < sz2; j++)
            {
                if (grid[i][j] == 1)
                {
                    ans += (isWater(i+1, j, grid) + isWater(i-1, j, grid) + isWater(i, j-1, grid) + isWater(i, j+1, grid));
                }
            }
        }

        return ans;
    }

    int isWater(int i, int j, vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();

        if (i < 0 || i >= sz1 || j < 0 || j >= sz2 || grid[i][j] == 0)
            return 1;

        return 0;
    }
};

int main()
{
    vector<vector<int>> g = {{0,1,0,0},
                             {1,1,1,0},
                             {1,1,0,0},
                             {1,1,0,0}};

    LT0463 lt;

    cout<<lt.lt0463a(g)<<endl;

    return 0;
}
