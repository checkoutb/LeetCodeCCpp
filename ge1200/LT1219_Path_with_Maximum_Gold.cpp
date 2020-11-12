
#include "../header/myheader.h"

class LT1219
{
public:

// D D




//Runtime: 80 ms, faster than 69.71% of C++ online submissions for Path with Maximum Gold.
//Memory Usage: 7.7 MB, less than 5.23% of C++ online submissions for Path with Maximum Gold.
    int lt1219a(vector<vector<int>>& grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                dfsa1(grid, i, j, 0);
            }
        }
        return mxgold;
    }
    int mxgold = 0;
    void dfsa1(vector<vector<int>>& grid, int i, int j, int gold)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
        {
            mxgold = std::max(mxgold, gold);
            return;
        }
        int nowgold = grid[i][j];
        gold += nowgold;
        grid[i][j] = 0;
        dfsa1(grid, i + 1, j, gold);
        dfsa1(grid, i - 1, j, gold);
        dfsa1(grid, i, j + 1, gold);
        dfsa1(grid, i, j - 1, gold);
        grid[i][j] = nowgold;
    }

};

int main()
{

//    vector<vector<int>> vv = {{0,6,0},{5,8,7},{0,9,0}};
    vector<vector<int>> vv = {{1,0,7},{2,0,6},{3,4,5},{0,3,0},{9,0,20}};

    LT1219 lt;

    cout<<lt.lt1219a(vv)<<endl;

    return 0;
}
