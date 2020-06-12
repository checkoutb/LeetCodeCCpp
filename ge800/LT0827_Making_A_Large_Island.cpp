
#include "../header/myheader.h"

class LT0827
{
public:


// 。
// 将1改成 该岛的面积 + 1000000 or 2000000 or...。如果0这个点连接了2个岛(面积%1000000 == ，面积/1000000 ！= )，那么.


// 还有5%的老弟。。
//Runtime: 1856 ms, faster than 5.23% of C++ online submissions for Making A Large Island.
//Memory Usage: 21.8 MB, less than 11.11% of C++ online submissions for Making A Large Island.
// baoli.. 50*50
    int lt0827a(vector<vector<int>>& grid)
    {
        int ans = 0;
        int sz2 = grid.size();
        int contain0 = false;
        for (int i = 0; i < sz2; i++)
        {
            for (int j = 0; j < sz2; j++)
            {
                if (!grid[i][j])
                {
                    contain0 = true;
                    grid[i][j] = 1;
                    ans = max(ans, areaa1(grid));
                    grid[i][j] = 0;
                }
            }
        }
        if (!contain0)
        {
            ans = sz2 * sz2;
        }
        return ans;
    }

    int areaa1(vector<vector<int>>& grid)
    {
        int fil = -1;
        int sz2 = grid.size();
        for (int i = 0; i < sz2; i++)
        {
            for (int j = 0; j < sz2; j++)
            {
                if (grid[i][j] == 1)
                {
                    filla1(grid, fil, i, j);
                    fil--;
                }
            }
        }
        vector<int> cnt(-fil, 0);
        for (int i = 0; i < sz2; i++)
        {
            for (int j = 0; j < sz2; j++)
            {
                if (grid[i][j] < 0)
                {
                    cnt[-grid[i][j]]++;
                    grid[i][j] = 1;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < cnt.size(); i++)
        {
            ans = max(ans, cnt[i]);
        }
        return ans;
    }

    void filla1(vector<vector<int>>& grid, int fil, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid.size())
            return;
        if (grid[i][j] != 1)
            return;
        grid[i][j] = fil;
        filla1(grid, fil, i, j + 1);
        filla1(grid, fil, i, j - 1);
        filla1(grid, fil, i + 1, j);
        filla1(grid, fil, i - 1, j);
    }
};

int main()
{

    vector<vector<int>> g = {{1,1},{1,1}};

    LT0827 lt;

    cout<<lt.lt0827a(g)<<endl;

    return 0;
}
