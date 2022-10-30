
#include "../header/myheader.h"

class LT2435
{
public:

    // D D

    // memo + dfs

    // 觉得差不多，但是就是慢。 把 if(x!=0) 注释掉 也是这个速度。





//Runtime: 1388 ms, faster than 15.91 % of C++ online submissions for Paths in Matrix Whose Sum Is Divisible by K.
//Memory Usage : 127.6 MB, less than 78.26 % of C++ online submissions for Paths in Matrix Whose Sum Is Divisible by K.
    int lt2435a(vector<vector<int>>& grid, int k)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        int ans = 0;
        const int MOD = 1e9 + 7;

        vector<vector<vector<int>>> vvvi(sz1, vector<vector<int>>(sz2, vector<int>(k, 0)));

        vvvi[0][0][grid[0][0] % k] = 1;

        for (int i = 1; i < sz1; ++i)
        {
            for (int a = 0; a < k; ++a)
            {
                if (vvvi[i - 1][0][a] != 0)     // .
                {
                    vvvi[i][0][(a + grid[i][0]) % k] += vvvi[i - 1][0][a];
                    vvvi[i][0][(a + grid[i][0]) % k] %= MOD;
                }
            }
        }

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 1; j < sz2; ++j)
            {
                int t2 = grid[i][j];
                for (int a = 0; a < k; ++a)
                {
                    if (vvvi[i][j - 1][a] != 0)
                    {
                        vvvi[i][j][(a + t2) % k] += vvvi[i][j - 1][a];
                        vvvi[i][j][(a + t2) % k] %= MOD;
                    }
                    if (i != 0)
                    {
                        if (vvvi[i - 1][j][a] != 0)
                        {
                            vvvi[i][j][(a + t2) % k] += vvvi[i - 1][j][a];
                            vvvi[i][j][(a + t2) % k] %= MOD;
                        }
                    }
                }
            }
        }
        ans = vvvi[sz1 - 1][sz2 - 1][0];
        return ans;
    }
};

int main()
{

    LT2435 lt;

    //myvvi vv = { {5,2,4},{3,0,5},{0,7,2} };
    //int k = 3;

    //myvvi vv = { {0,0} };
    //int k = 5;

    myvvi vv = { {7,3,4,9},{2,3,6,2},{2,3,7,0} };
    int k = 1;

    cout << lt.lt2435a(vv, k) << endl;

    return 0;
}
