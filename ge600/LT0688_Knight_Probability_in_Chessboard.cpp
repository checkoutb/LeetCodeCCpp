
#include "../header/myheader.h"

class LT0688
{
public:


// D D

//    double dp[maxN][maxN][maxK];
//    bool vis[maxN][maxN][maxK];
//if(vis[r][c][k]) return dp[r][c][k];
// memo.


//        for (; K > 0; K--) {
//            vector<vector<double>> dp2(N, vector<double>(N));
//            for (int r = 0; r < N; r++) {
//                for (int c = 0; c < N; c++) {
//                    for (int k = 0; k < 8; k++) {
//                        int cr = r + dr[k];
//                        int cc = c + dc[k];
//                        if (0 <= cr && cr < N && 0 <= cc && cc < N) {
//                            dp2[cr][cc] += dp[r][c] / 8.0;
//                        }
//                    }
//                }
//            }
//            dp = dp2;
//        }




//Runtime: 204 ms, faster than 15.75% of C++ online submissions for Knight Probability in Chessboard.
//Memory Usage: 23.3 MB, less than 16.82% of C++ online submissions for Knight Probability in Chessboard.
// add memo
// tle
// k<=100, 精度？
    double lt0688a(int N, int K, int r, int c)
    {
        double ans = 0.0;
        ans = dfsa1(N, K, r, c, 1.0);
        return ans;
    }

    unordered_map<int, double> memo;

    double dfsa1(int N, int k, int r, int c, double p)
    {
        if (p == 0.0)
            return 0.0;
        if (k == 0)
            return p;
        if (memo.count(r * 100000+ c * 1000 + k))
        {
            return memo[r * 100000 + c * 1000 + k];
        }
        pair<int, vector<int>> pp = inChessboarda1(N, r, c);
        double ans = 0.0;
        if (pp.first > 0)
        {
            for (int i : pp.second)
            {
                ans += dfsa1(N, k - 1, r + arr[i][0], c + arr[i][1], p / 8.0);
            }
        }
        memo[r * 100000 + c * 1000 + k] = ans;
        return ans;
    }

    int arr[8][2] = {{1,2},{2,1},{-1,2},{2,-1},{1,-2},{-2,1},{-1,-2},{-2,-1}};

    pair<int, vector<int>> inChessboarda1(int N, int r, int c)
    {
        int ans = 0;
        vector<int> v;
        for (int i = 0; i < 8; i++)
        {
            int rr = r + arr[i][0];
            int cc = c + arr[i][1];
            if (rr >= 0 && rr < N && cc >= 0 && cc < N)
            {
                ans++;
                v.push_back(i);
            }
        }
        return {ans, v};
    }

};

int main()
{
    int a{3},s{2},d{0},f{0};

    LT0688 lt;

    cout<<lt.lt0688a(a,s,d,f)<<endl;

    return 0;
}
