
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //def maxAreaOfIsland(self, grid) :
    //    grid = { i + j * 1j: val for i, row in enumerate(grid) for j, val in enumerate(row) }
    //    def area(z) :
    //    return grid.pop(z, 0) and 1 + sum(area(z + 1j * *k) for k in range(4))
    //    return max(map(area, set(grid)))
// ¸´Êý¡£


    // Union Find


//Runtime: 19 ms, faster than 90.87 % of C++ online submissions for Max Area of Island.
//Memory Usage : 23.2 MB, less than 89.29 % of C++ online submissions for Max Area of Island.
    int lta(vector<vector<int>>& grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                ans = max(dfsa1(grid, i, j), ans);

#ifdef __test
        for (myvi& vi : grid)
        {
            for (int i : vi)
            {
                cout << i << ", ";
            }
            cout << endl;
        }
#endif

        return ans;
    }

    int dfsa1(vector<vector<int>>& vvi, int row, int col)
    {
        if (row < 0 || col < 0 || row == vvi.size() || col == vvi[0].size() || vvi[row][col] != 1)
            return 0;
        vvi[row][col] = 2;
        return dfsa1(vvi, row + 1, col) 
            + dfsa1(vvi, row, col + 1) 
            + dfsa1(vvi, row, col - 1) 
            + dfsa1(vvi, row - 1, col) + 1;
    }

};

int main()
{

    LT lt;

    myvvi vv = { {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, 
        { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 }, 
        { 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 
        { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0 }, 
        { 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0 }, 
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 
        { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 }, 
        { 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 }};

    cout << lt.lta(vv) << endl;

    return 0;
}
