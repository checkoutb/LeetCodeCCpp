
#include "../header/myheader.h"

class LT1444
{
public:

    // D D


    //long long dp[50][50][10];
    //memset(dp, 0, sizeof(dp));
    //dp[0][0][0] = 1;  //[hor cut][ver cut][num cuts]
    //for (int cuts = 1; cuts < k; cuts++) {
    //    printf("%d cuts\n", cuts);
    //    for (int r = 0; r < R; r++) {
    //        for (int c = 0; c < C; c++) {
    //            //how can we cut it to here
    //            //definitely cuts-1 
    //            //could come here from a hor cut or ver cut
    //            for (int _r = 0; _r < r; _r++)
    //                if (hasapple(_r, c, r, C))
    //                    dp[r][c][cuts] = (dp[r][c][cuts] + dp[_r][c][cuts - 1]) % MOD;
    //            for (int _c = 0; _c < c; _c++)
    //                if (hasapple(r, _c, R, c))
    //                    dp[r][c][cuts] = (dp[r][c][cuts] + dp[r][_c][cuts - 1]) % MOD;
    //            //printf("%lld ",dp[r][c][cuts]);
    //        }
    //        //printf("\n");
    //    }
    //    //printf("\n");
    //}





    // 1500

//Runtime: 36 ms, faster than 52.70 % of C++ online submissions for Number of Ways of Cutting a Pizza.
//Memory Usage : 8.4 MB, less than 28.63 % of C++ online submissions for Number of Ways of Cutting a Pizza.
    int lt1444b(vector<string>& pizza, int k)
    {
        int sz1 = pizza.size();
        int sz2 = pizza[0].size();

        vector<vector<int>> vvi(sz1, vector<int>(sz2, 0));
        vector<vector<vector<int>>> vvvi(sz1, vector<vector<int>>(sz2, vector<int>(k + 1, -1)));

        for (int i = sz1 - 1; i >= 0; --i)
        {
            int t2 = 0;
            for (int j = sz2 - 1; j >= 0; --j)
            {
                t2 += pizza[i][j] == 'A';
                vvi[i][j] = (i == sz1 - 1 ? 0 : vvi[i + 1][j]) + t2;
            }
        }

#ifdef __test
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                cout << vvi[i][j] << ", ";
            }
            cout << endl;
        }
#endif

        return dfsb1(vvi, vvvi, 0, 0, k);
    }

    int dfsb1(vector<vector<int>>& vvi, vector<vector<vector<int>>>& vvvi, int r, int c, int p)
    {
#ifdef __test
        //cout << r << ", " << c << ", " << p << endl;
#endif
        if (vvvi[r][c][p] != -1)
            return vvvi[r][c][p];

        if (p == 1)
        {
            vvvi[r][c][p] = (vvi[r][c] > 0);
            return vvvi[r][c][p];
        }

        int myapp = vvi[r][c];
        if (myapp == 0)
        {
            vvvi[r][c][p] = 0;
            return 0;
        }
        const int MOD = 1e9 + 7;
        int ans = 0;


        // ---
        for (int i = r + 1; i < vvi.size(); ++i)
        {
            if (vvi[i][c] != myapp)
            {
                ans = (ans + dfsb1(vvi, vvvi, i, c, p - 1)) % MOD;
            }
        }


        // |
        for (int j = c + 1; j < vvi[0].size(); ++j)
        {
            if (vvi[r][j] != myapp)
            {
                ans = (ans + dfsb1(vvi, vvvi, r, j, p - 1)) % MOD;
            }
        }


        vvvi[r][c][p] = ans;
        return ans;
    }





    // 始终是把 右下 的留下 继续切。
    // 应该预处理下， 把 value 变成 以这个坐标为 左上角 的 矩阵的 apple 数量。
    int lt1444a(vector<string>& pizza, int k)
    {
        int sz1 = pizza.size();
        int sz2 = pizza[0].size();

        vector<vector<vector<int>>> vvvi(sz1, vector<vector<int>>(sz2, vector<int>(k + 1, -1)));


        return vvvi[sz1 - 1][sz2 - 1][k];
    }

    void dfsa1(vector<vector<vector<int>>>& vvvi, int row, int col, int person)
    {
        if (vvvi[row][col][person] != -1)
            return;

        if (person == 1)
        {
            vvvi[row][col][person] = 1;
            return;
        }

        // ---
        int lstapp = -1;




        // |

    }

};

int main()
{

    LT1444 lt;

    //vector<string> vs = { "A...","AAA","..." };
    //int k = 3;

    vector<string> vs = { "A..","AA.","..." };
    int k = 3;


    cout << lt.lt1444b(vs, k) << endl;

    return 0;
}
