
#include "../header/myheader.h"

class LT0063
{
public:

// D D

//    for (int[] row : obstacleGrid) {
//        for (int j = 0; j < width; j++) {
//            if (row[j] == 1)
//                dp[j] = 0;
//            else if (j > 0)
//                dp[j] += dp[j - 1];
//        }
//    }


//        for (int i = 1; i <= m; i++)
//            for (int j = 1; j <= n; j++)
//                if (!obstacleGrid[i - 1][j - 1])
//                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//        return dp[m][n];


//Runtime: 4 ms, faster than 92.14% of C++ online submissions for Unique Paths II.
//Memory Usage: 8 MB, less than 74.66% of C++ online submissions for Unique Paths II.
    int lt0063a(vector<vector<int>>& obstacleGrid)
    {
        int sz1 = obstacleGrid.size();
        int sz2 = obstacleGrid[0].size();
        vector<int> vi(sz2);
        vi[0] = 1;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (obstacleGrid[i][j])
                {
                    vi[j] = 0;
                    continue;
                }
//                int up = i == 0 ? 0 : (obstacleGrid[i - 1][j] ? 0 : vi[j]);
//                int fnt = j == 0 ? 0 : (obstacleGrid[i][j - 1] ? 0 : vi[j]);
//                int up = i == 0 ? 0 : vi[j];
                int fnt = j == 0 ? 0 : vi[j - 1];
//                vi[j] = up +
                vi[j] = vi[j] + fnt;
            }
        }
        return vi[sz2 - 1];
    }

};

int main()
{

//    myvvi vv = {{0,0,0},{0,1,0},{0,0,0}};
//    myvvi vv = {{0,1},{0,0}};
    myvvi vv = {{0,0}};         // for j < sz1; .....

    LT0063 lt;

    cout<<lt.lt0063a(vv);

    return 0;
}
