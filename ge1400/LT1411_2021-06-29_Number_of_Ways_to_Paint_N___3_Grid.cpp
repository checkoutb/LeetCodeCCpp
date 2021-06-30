
#include "../header/myheader.h"

class LT1411
{
public:

// D D

//    int dp[5001][4][4][4] = {};
//    int numOfWays(int n) {
//        return dfs(n, 0, 0, 0);
//    }
//    // dfs(n, a0, b0, c0) is the number of ways to color the first n rows of the grid
//    //      keeping in mind that the previous row (n + 1) has colors a0, b0 and c0
//    int dfs(int n, int a0, int b0, int c0) {
//        if (n == 0) return 1;
//        if (dp[n][a0][b0][c0] != 0) return dp[n][a0][b0][c0];
//        int ans = 0;
//        vector<int> colors = {1, 2, 3}; // Red: 1, Yellow: 2, Green: 3
//        for (int a : colors) {
//            if (a == a0) continue; // Check if the same color with the below neighbor
//            for (int b : colors) {
//                if (b == b0 || b == a) continue; // Check if the same color with the below neighbor or the left neighbor
//                for (int c : colors) {
//                    if (c == c0 || c == b) continue; // Check if the same color with the below neighbor or the left neighbor
//                    ans += dfs(n - 1, a, b, c);
//                    ans %= 1000000007;
//                }
//            }
//        }
//        return dp[n][a0][b0][c0] = ans;
//    }



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Ways to Paint N × 3 Grid.
//Memory Usage: 6 MB, less than 59.44% of C++ online submissions for Number of Ways to Paint N × 3 Grid.
// 1   12
// 2   54       12*4.5   应该是 分为一半一半吧，  12个里，6个是三色的，6个是二色的。 红黄红的下一级有5个。。。 红黄绿 4个。
//                  3组，  按照第一个格子的颜色 分组。   但是4个里 又能分组，，     红绿红5       红绿黄 4
//                  18×3 = 54  不对
//              6×4 + 6×5  24+30 = 54    第一层 6种3色的选择，这6种，后续只有4种可以选择，     6种2色的，2色的后续有5种。
// 3   246      54/2×4 + 54/2×5 = 108 135       243....
//          估计不是/2.。
// ryr -> yry, yrg, ygy, gry, grg       2色 : 3个2色，2个3色。
// ryg -> yry, ygr, ygy, gry            3色： 2个2色 2个3色
// 1： 12   6个2色，6个3色
// 2： 2色： 6×3 + 6×2    3色：6×2 + 6×2
//     2色：30             3色：24
// 3： 2色：30×5 ， 3色：24×4       150+96   ==  246

// 1411. Number of Ways to Paint N × 3 Grid
// 这里的 '×' 有毒， 反正编译不出来东西。。

    int lt1411a(int n)
    {
        long cnt2 = 6;
        long cnt3 = 6;
        const int MOD = (int) 1E9 + 7;
        int t2, t3;
        while (n-- > 1)
        {
            t2 = (cnt2 * 3 + cnt3 * 2) % MOD;
            t3 = (cnt2 * 2 + cnt3 * 2) % MOD;
            cnt2 = t2;
            cnt3 = t3;
        }
        return (int) (cnt2 + cnt3) % MOD;
    }

};

int main()
{

//    int n = 7;
    int n = 5000;

    LT1411 lt;

    cout<<lt.lt1411a(n)<<endl;

    return 0;
}
