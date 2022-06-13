
#include "../header/myheader.h"

class LT1034
{
public:

    // D D

    //From an initial point, perform DFSand flip the cell color to negative to track visited cells.
    //After DFS is complete for the cell, check if this cell is inside.If so, flip its color back to the positive.
    //In the end, cells with the negative color are on the border.Change their color to the target color.
    // dfs找到连接的区域，并取负。 
    // 遍历，对于负数，判断4个方向是不是负数，决定是不是内部，内部则取正。
    // 遍历，对于负数，变成 形参 color。





//Runtime: 17 ms, faster than 87.47 % of C++ online submissions for Coloring A Border.
//Memory Usage : 13.8 MB, less than 46.67 % of C++ online submissions for Coloring A Border.
    vector<vector<int>> lt1034a(vector<vector<int>>& grid, int row, int col, int color)
    {
        int sz1 = grid.size(), sz2 = grid[0].size();
        unordered_set<int> vst;
        queue<pair<int, int>> que1;
        vst.insert(row * 100 + col);
        que1.push(std::make_pair(row, col));
        unordered_set<int> border;
        int arr[] = { 1,0,-1,0,1 };
        int cl = grid[row][col];
        while (!que1.empty())
        {
            int x = que1.front().first;
            int y = que1.front().second;
            que1.pop();
            bool b2 = false;    // border ?
            for (int i = 0; i < 4; ++i)
            {
                int x2 = x + arr[i];
                int y2 = y + arr[i + 1];
                if (x2 < 0 || y2 < 0 || x2 == sz1 || y2 == sz2)
                {
                    b2 = true;
                    continue;
                }
                if (grid[x2][y2] != cl)
                    b2 = true;
                else
                {
                    if (vst.find(x2 * 100 + y2) == vst.end())
                    {
                        vst.insert(x2 * 100 + y2);
                        que1.push({ x2, y2 });
                    }
                }
            }
            if (b2)
                border.insert(x * 100 + y);
        }
        for (int i : border)
        {
            grid[i / 100][i % 100] = color;
        }
        return grid;
    }

};

int main()
{

    LT1034 lt;


    return 0;
}
