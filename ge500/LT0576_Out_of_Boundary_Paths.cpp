
#include "../header/myheader.h"

class LT0576
{
public:


// D D

//  uint dp[51][50][50] = {};
//  for (auto Ni = 1; Ni <= N; ++Ni)
//    for (auto mi = 0; mi < m; ++mi)
//      for (auto ni = 0; ni < n; ++ni)
//        dp[Ni][mi][ni] = ((mi == 0 ? 1 : dp[Ni - 1][mi - 1][ni]) + (mi == m - 1? 1 : dp[Ni - 1][mi + 1][ni])
//            + (ni == 0 ? 1 : dp[Ni - 1][mi][ni - 1]) + (ni == n - 1 ? 1 : dp[Ni - 1][mi][ni + 1])) % 1000000007;
//  return dp[N][i][j];


//    unsigned int g[2][50][50] = {};
//    while (N-- > 0)
//        for (auto k = 0; k < m; ++k)
//            for (auto l = 0, nc = (N + 1) % 2, np = N % 2; l < n; ++l)
//                g[nc][k][l] = ((k == 0 ? 1 : g[np][k - 1][l]) + (k == m - 1 ? 1 : g[np][k + 1][l])
//                    + (l == 0 ? 1 : g[np][k][l - 1]) + (l == n - 1 ? 1 : g[np][k][l + 1])) % 1000000007;
//    return g[1][i][j];


//import numpy as np
//
//class Solution(object):
//    def findPaths(self, m, n, N, i, j):
//        paths = np.zeros((m, n), dtype=np.int64)
//        paths[i][j] = 1
//        out = 0
//        mod = 10**9 + 7
//        for _ in range(N):
//            prev = paths % mod
//            paths = prev - prev
//            paths[1:] += prev[:-1]
//            paths[:-1] += prev[1:]
//            paths[:,1:] += prev[:,:-1]
//            paths[:,:-1] += prev[:,1:]
//            out += 4 * prev.sum() - paths.sum()
//        return int(out % mod)





//Runtime: 16 ms, faster than 55.67% of C++ online submissions for Out of Boundary Paths.
//Memory Usage: 6.8 MB, less than 74.31% of C++ online submissions for Out of Boundary Paths.
    int lt0576a(int m, int n, int N, int i, int j)
    {
        vector<vector<int>> vv(m, vector<int>(n, 0));
        vector<vector<int>> vvt(m, vector<int>(n, 0));
        int ans = 0;
        int mod = 1E9 + 7;
        vv[i][j] = 1;
        for (int i = 1; i <= N; i++)
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    vvt[i][j] = 0;
                }
            }
            for (int i = 0; i < m; i++)
            {
                ans += (vv[i][0] + vv[i][n - 1]) % mod;
                ans %= mod;
            }
            for (int j = 0; j < n; j++)
            {
                ans += (vv[0][j] + vv[m - 1][j]) % mod;
                ans %= mod;
            }
            if (i == N)
                break;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (vv[i][j] == 0)
                        continue;

                    addVal(vvt, i + 1, j, vv[i][j]);
                    addVal(vvt, i - 1, j, vv[i][j]);
                    addVal(vvt, i, j + 1, vv[i][j]);
                    addVal(vvt, i, j - 1, vv[i][j]);
                }
            }
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    vv[i][j] = vvt[i][j];
                }
            }
        }

        return ans;
    }

    void addVal(vector<vector<int>>& vvt, int i, int j, int val)
    {
        if (i < 0 || i == vvt.size() || j < 0 || j == vvt[0].size())
            return;         // can add to ans...
        vvt[i][j] += val;
        vvt[i][j] = vvt[i][j] % (1000000007);           // xie 1E9 + 7, bianyi baocuo...
    }
};



int main()
{

//    int q{2},w{2},e{2},r{0},t{0};
    int q{1},w{3},e{3},r{0},t{1};

    LT0576 lt;

    cout<<lt.lt0576a(q,w,e,r,t)<<endl;

    return 0;
}
