
#include "../header/myheader.h"

class LT1594
{
public:

// D

// dp
// vector<vector<pair<long, long>>> dp(r, vector<pair<long, long>>(c));



// tle...
    int lt1594a(vector<vector<int>>& grid)
    {
        dfsa1(grid, 0, 0, grid[0][0]);
        return ans % int (1E9 + 7);
    }
    long ans = -1;
    void dfsa1(vector<vector<int>>& vv, int i, int j, long prod)
    {
        if (i == vv.size() - 1 && j == vv[0].size() - 1)
        {
            ans = max(prod, ans);
            return;
        }
        if (i + 1 < vv.size())
        {
            dfsa1(vv, i + 1, j, prod * vv[i + 1][j]);
        }
        if (j + 1 < vv[0].size())
            dfsa1(vv, i, j + 1, prod * vv[i][j + 1]);
    }

};

int main()
{

//    myvvi vv = {{-1,-1,-2},{-2,-1,-3},{-3,-2,-1}};
    myvvi vv = {{1,-2,1}, {1,-2,1}, {3,-4,1}};
//    myvvi vv = {{1,3},{0,-4}};
//    myvvi vv = {{1,4,4,0},{-2,0,0,1},{1,-1,1,1}};

    LT1594 lt;

    cout<<lt.lt1594a(vv);

    return 0;
}
