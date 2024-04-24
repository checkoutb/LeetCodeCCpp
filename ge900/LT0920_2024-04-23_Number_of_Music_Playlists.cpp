
#include "../header/myheader.h"

class LT0920
{
public:




// Runtime
// 5ms
// Beats30.50%of users with C++
// Memory
// 9.30MB
// Beats50.00%of users with C++

    // 100
    // ...
    // dp[i][j] denotes the solution of i songs with j different songs. So the final answer should be dp[L][N]
    int numMusicPlaylists(int n, int goal, int k)
    {
        vector<vector<int>> vvi(goal + 1, vector<int>(n + 1, 0));
        const int MOD = 1e9 + 7;
        vvi[1][1] = n;
        for (int i = 1; i <= goal; ++i)
        {
            for (int j = 1; j <= i && j <= n; ++j)
            {
                if (i == 1 && j == 1)
                    continue;
                vvi[i][j] = (1LL * vvi[i - 1][j] * (j > k ? j - k : 0) + 1LL * vvi[i - 1][j - 1] * (max(0, n - j + 1))) % MOD;
            }
        }

#ifdef __test
        for (myvi& vi : vvi)
        {
            showVectorInt(vi);
        }
#endif

        return vvi[goal][n];
    }
};

int main()
{

    LT0920 lt;

    // myvi v {3,3,1};
    // myvi v {2,3,0};
    myvi v {2,3,1};

    cout<<lt.numMusicPlaylists(v[0],v[1],v[2])<<endl;

    return 0;
}
