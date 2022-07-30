
#include "../header/myheader.h"

class LT1463
{
public:

    // D D


    //int ff(vector<vector<int>>& grid, int i, int c1, int c2) {
    //    int m = grid.size();
    //    int n = grid[0].size();
    //    if (i == m) return 0;
    //    if (c1 < 0 || c2 < 0 || c1 >= n || c2 >= n) return INT_MIN;
    //    if (dp[i][c1][c2] != -1) return dp[i][c1][c2];

    //    int maxAns = 0;

    //    for (int k = 0; k < 3; k++) {
    //        for (int r = 0; r < 3; r++) {
    //            maxAns = max(maxAns, ff(grid, i + 1, c1 + dy[k], c2 + dy[r]));
    //        }
    //    }

    //    maxAns += (c1 == c2) ? grid[i][c1] : grid[i][c1] + grid[i][c2];
    //    return dp[i][c1][c2] = maxAns;
    //}





//Runtime: 195 ms, faster than 29.99 % of C++ online submissions for Cherry Pickup II.
//Memory Usage : 16.9 MB, less than 15.39 % of C++ online submissions for Cherry Pickup II.
    int lt1463a(vector<vector<int>>& grid)
    {
        int sz1 = grid.size(), sz2 = grid[0].size();
        vector<vector<vector<int>>> vvvi(sz1, vector<vector<int>>(sz2, vector<int>(sz2, -1)));   // row, robot1, robot2

        vvvi[0][0][sz2 - 1] = grid[0][sz2 - 1] + grid[0][0];
        int arr[3] = { 1,0,-1 };
        for (int i = 0; i < sz1 - 1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                for (int k = 0; k < sz2; ++k)
                {
                    if (vvvi[i][j][k] == -1)
                    {
                        continue;
                    }
                    int t2 = vvvi[i][j][k];
                    for (int a : arr)
                    {
                        int j2 = j + a;
                        if (j2 < 0 || j2 >= sz2)
                            continue;
                        for (int b : arr)
                        {
                            int k2 = k + b;
                            if (k2 < 0 || k2 >= sz2)
                                continue;
                            vvvi[i + 1][j2][k2] = max(vvvi[i + 1][j2][k2], t2 + grid[i + 1][j2] + (j2 != k2 ? grid[i + 1][k2] : 0));
                        }
                    }

                }
            }
        }
        int ans = 0;

        for (int i = 0; i < sz2; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                ans = max(ans, vvvi[sz1 - 1][i][j]);
            }
        }

        return ans;
    }

};

int main()
{

    LT1463 lt;

    myvvi vv = { {3,1,1},{2,5,1},{1,5,5},{2,1,1} };


    cout << lt.lt1463a(vv) << endl;

    return 0;
}
