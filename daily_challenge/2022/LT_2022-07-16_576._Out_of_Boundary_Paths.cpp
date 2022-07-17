
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //unsigned int g[2][50][50] = {};
    //while (N-- > 0)
    //    for (auto k = 0; k < m; ++k)
    //        for (auto l = 0, nc = (N + 1) % 2, np = N % 2; l < n; ++l)
    //            g[nc][k][l] = ((k == 0 ? 1 : g[np][k - 1][l]) + (k == m - 1 ? 1 : g[np][k + 1][l])
    //                + (l == 0 ? 1 : g[np][k][l - 1]) + (l == n - 1 ? 1 : g[np][k][l + 1])) % 1000000007;
    //return g[1][i][j];


    //unsigned int g[50][50] = {}, r[50];
    //while (N-- > 0)
    //    for (auto k = 0; k <= m; ++k)
    //        for (auto l = 0; l < n; ++l) {
    //            auto tmp = r[l];
    //            r[l] = (k == m ? 0 : ((k == 0 ? 1 : g[k - 1][l]) + (k == m - 1 ? 1 : g[k + 1][l])
    //                + (l == 0 ? 1 : g[k][l - 1]) + (l == n - 1 ? 1 : g[k][l + 1])) % 1000000007);
    //            if (k > 0) g[k - 1][l] = tmp;
    //        }
    //return g[i][j];



    // ¿ÉÄÜÊÇmapÂý¡£
//Runtime: 53 ms, faster than 15.68 % of C++ online submissions for Out of Boundary Paths.
//Memory Usage : 25 MB, less than 7.20 % of C++ online submissions for Out of Boundary Paths.
    int lta(int m, int n, int maxMove, int startRow, int startColumn)
    {
        vector<vector<unordered_map<int, int>>> vvm(m, vector<unordered_map<int, int>>(n));
        return dfsa1(vvm, startRow, startColumn, maxMove);
    }

    int dfsa1(vector<vector<unordered_map<int, int>>>& vvm, int row, int col, int move)
    {
#ifdef __test
        cout << row << ", " << col << ", " << move << endl;
#endif
        if (row < 0 || col < 0 || row >= vvm.size() || col >= vvm[0].size())
            return 1;
        if (move == 0)
            return 0;
        if (vvm[row][col].find(move) != end(vvm[row][col]))
            return vvm[row][col][move];

        int arr[] = { 1,0,-1,0,1 };
        int ans = 0;
        const int MOD = 1e9 + 7;
        for (int i = 1; i < 5; ++i)
        {
            ans = (ans + dfsa1(vvm, row + arr[i], col + arr[i - 1], move - 1)) % MOD;
        }
        vvm[row][col][move] = ans;
        return ans;
    }

};

int main()
{

    LT lt;

    myvi v = { 8,4,10,5,0 };

    cout << lt.lta(v[0], v[1], v[2], v[3], v[4]) << endl;

    return 0;
}
