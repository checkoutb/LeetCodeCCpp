
#include "../header/myheader.h"

class LT3070
{
public:




// Runtime
// 189ms
// Beats28.66%of users with C++
// Memory
// 99.38MB
// Beats30.60%of users with C++
    int countSubmatrices(vector<vector<int>>& grid, int k)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        vector<vector<int>> vvi(sz1, vector<int>(sz2));
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            int sum2 = 0;
            for (int j = 0; j < sz2; ++j)
            {
                sum2 += grid[i][j];
                vvi[i][j] = (i > 0 ? vvi[i - 1][j] : 0) + sum2;
                if (vvi[i][j] <= k)
                    ++ans;
                else
                    break;
            }
        }
        return ans;
    }

};

int main()
{

    LT3070 lt;

    myvvi vv {{7,6,3},{6,6,1}};
    int k{18};

    cout<<lt.countSubmatrices(vv, k);

    return 0;
}
