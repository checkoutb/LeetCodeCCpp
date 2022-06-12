
#include "../../header/myheader.h"

class LT5270
{
public:





// AC
// .. dp ..dan...
// 50^3
// ... distince int ... 0 to sz1*sz2-1 ....
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        vector<vector<int>> vvi(sz1, vector<int>(sz2, INT_MAX));
        for (int i = 0; i < sz2; ++i)
        {
            vvi[0][i] = grid[0][i];
        }
        for (int i = 0; i < sz1 - 1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                int t3 = grid[i][j];
                for (int k = 0; k < sz2; ++k)       // [i][j] move to [i+1][k]
                {
                    int t2 = grid[i+1][k];
                    vvi[i+1][k] = min(vvi[i+1][k], vvi[i][j] + t2 + moveCost[t3][k]);
                }
            }
        }
        int ans = INT_MAX;
        for (int j = 0; j < sz2; ++j)
        {
            ans = min(ans, vvi[sz1 - 1][j]);
        }
        return ans;
    }

};

int main()
{

    LT5270 lt;

    myvvi vv = {{5,3},{4,0},{2,1}};
    myvvi vv2 = {{9,8},{1,5},{10,12},{18,6},{2,4},{14,3}};

    cout<<lt.minPathCost(vv, vv2)<<endl;

    return 0;
}
