
#include "../header/myheader.h"

class LT1139
{
public:


// D D

//The main trick here is to use two dp 2d array to respectively store the maximum left-side outreach point and top-side outreach point.

//        int[][] dpr = new int[grid.length+1][grid[0].length+1];
//        int[][] dpc = new int[grid.length+1][grid[0].length+1];
//        int dist, max=0;
//        for (int r=1;r<=grid.length;r++){
//            for (int c=1;c<=grid[0].length;c++){
//                if (grid[r-1][c-1]==0) continue;
//                dpr[r][c] = dpr[r-1][c]+1;
//                dpc[r][c] = dpc[r][c-1]+1;
//                dist = Math.min(dpr[r][c],dpc[r][c]);
//                for (int i=dist;i>=1;i--){
//                    if (dpr[r][c-i+1]>=i
//                        && dpc[r-i+1][c]>=i){
//                        max = Math.max(max, i*i);
//                        break;
//                    }


//        vector<vector<int>> left(m, vector<int>(n)), top(m, vector<int>(n));
//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < n; ++j) {
//                left[i][j] = A[i][j] + (j && A[i][j] ? left[i][j - 1] : 0);
//                top[i][j] = A[i][j] + (i && A[i][j] ? top[i - 1][j] : 0);
//            }
//        }
//        for (int l = min(m, n); l > 0; --l)
//            for (int i = 0; i < m - l + 1; ++i)
//                for (int j = 0; j < n - l + 1; ++j)
//                    if (min({top[i + l - 1][j], top[i + l - 1][j + l - 1], left[i][j + l - 1], left[i + l - 1][j + l - 1]}) >= l)
//                        return l * l;





//Runtime: 24 ms, faster than 96.97% of C++ online submissions for Largest 1-Bordered Square.
//Memory Usage: 11.2 MB, less than 8.79% of C++ online submissions for Largest 1-Bordered Square.
    int lt1139a(vector<vector<int>>& grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.size() - ans; i++)
        {
            for (int j = 0; j < grid[0].size() - ans; j++)
            {
                if (grid[i][j] == 1)
                {
                    int mxj = j;
                    for (; mxj < grid[0].size(); mxj++)
                    {
                        if (grid[i][mxj] == 0)
                        {
                            break;
                        }
                    }
                    mxj--;
                    for (int m = j; m <= mxj - ans; m++)
                    {
                        for (int n = j + ans; n <= mxj; n++)
                        {
                            if (isSquarea1(grid, i, m, n))
                            {
                                ans = max(ans, n - m + 1);
                            }
                        }
                    }
                    j = mxj;
                }
            }
        }

        return ans * ans;
    }

    bool isSquarea1(vector<vector<int>>& grid, int i, int st, int en)
    {
        if (grid.size() <= (i + en - st))
            return false;
        int sz1 = en - st + 1;
        for (int i2 = 0; i2 < sz1; i2++)
        {
            if (grid[i + i2][st] == 0)
                return false;
            if (grid[i + i2][en] == 0)
                return false;
        }
        for (int i2 = 0; i2 < sz1; i2++)
        {
            if (grid[i + en - st][st + i2] == 0)
                return false;
        }
        return true;
    }
};

int main()
{

//    vector<vector<int>> vv = {{1,1,1},{1,0,1},{1,1,1}};
//    vector<vector<int>> vv = {{1,1,0,0}};
    vector<vector<int>> vv = {
    {1,1,0},
    {1,1,1},{1,0,1},{1,1,1}};

    LT1139 lt;

    cout<<lt.lt1139a(vv)<<endl;

    return 0;
}
