
#include "../header/myheader.h"

class LT1091
{
public:




//Runtime: 104 ms, faster than 90.93% of C++ online submissions for Shortest Path in Binary Matrix.
//Memory Usage: 19.4 MB, less than 5.26% of C++ online submissions for Shortest Path in Binary Matrix.
// 不科学， discuss里也是 bfs，都差不多啊。
// tle
    int lt1091a(vector<vector<int>>& grid)
    {
        queue<pair<int, int>> que1;
        int sz2 = grid.size();
        if (grid[0][0] != 0 || grid[sz2 - 1][sz2 - 1] != 0)
            return -1;
        if (grid.size() == 1 && grid[0].size() == 1)
            return 1;
        que1.push({0, 0});
        int arr[][2] = {{1,1},{1,0},{0,1},{-1,-1},{-1,0},{0,-1},{1,-1},{-1,1}};
        int ans = -1;
        int ans2 = 1;
        while (!que1.empty())
        {
            int sz1 = que1.size();
            ans2++;
            while (sz1-- > 0)
            {
                pair<int, int> p = que1.front();
                que1.pop();
                grid[p.first][p.second] = 2;
                for (int i2 = 0; i2 < 8; i2++)
                {
                    int i = p.first + arr[i2][0];
                    int j = p.second + arr[i2][1];
                    if (i >= 0 && i < sz2 && j >= 0 && j < sz2 && grid[i][j] == 0)
                    {
                        que1.push({i, j});
                        grid[i][j] = 2;                                 // xiugai....
                        if (i == sz2 - 1 && j == sz2 - 1)
                        {
                            ans = ans2;
                            goto AAA;
                        }
                    }
                }
            }
        }
        AAA:
        return ans;
    }

};

int main()
{

//    vector<vector<int>> vv = {{0,1},{1,0}};
    vector<vector<int>> vv = {{0,0,0},{1,1,0},{1,1,0}};

    LT1091 lt;

    cout<<lt.lt1091a(vv);

    return 0;
}
