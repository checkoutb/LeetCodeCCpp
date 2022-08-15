
#include "../header/myheader.h"

class LT2373
{
public:

    // D D

    //vector<vector<int>> res(n - 2, vector<int>(n - 2));
    //for (int i = 0; i < n - 2; ++i)
    //    for (int j = 0; j < n - 2; ++j)
    //        for (int ii = i; ii < i + 3; ++ii)
    //            for (int jj = j; jj < j + 3; ++jj)
    //                res[i][j] = max(res[i][j], g[ii][jj]);



//Runtime: 27 ms, faster than 28.57 % of C++ online submissions for Largest Local Values in a Matrix.
//Memory Usage : 11.1 MB, less than 85.71 % of C++ online submissions for Largest Local Values in a Matrix.
    vector<vector<int>> lt2373a(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = sz1 - 1; j > 1; --j)
            {
                grid[i][j] = max(grid[i][j - 2], max(grid[i][j - 1], grid[i][j]));
            }
        }
        vector<vector<int>> ans(sz1 - 2, vector<int>(sz1 - 2));

        for (int i = 0; i < sz1 - 2; ++i)
        {
            for (int j = 0; j < sz1 - 2; ++j)
            {
                ans[i][j] = max(grid[i][j + 2], max(grid[i + 1][j + 2], grid[i + 2][j + 2]));
            }
        }
        return ans;
    }

};

int main()
{

    LT2373 lt;

    myvvi vv = { {9,9,8,1},{5,6,2,6},{8,2,6,4},{6,2,2,2} };

    myvvi vv2 = lt.lt2373a(vv);

    for (myvi& v : vv2)
    {
        for (int i : v)
            cout << i << ", ";
        cout << endl;
    }

    return 0;
}
