
#include "../header/myheader.h"

class LT1320
{
public:

// D D

//     int dp[27][27][301];     。。。。。。

// int memo[27][27][301] = {[0 ... 26][0 ... 26][0 ... 300] = -1};
// 不知道什么版本支持这种写法。



//    auto cost = [](int c1, int c2) {
//      if (c1 == kRest) return 0;
//      return abs(c1 / 6 - c2 / 6) + abs(c1 % 6 - c2 % 6);
//    };
//
//    // min cost to type word[i:n]. l, r are the last finger positions.
//    function<int(int, int, int)> dp = [&](int i, int l, int r) {
//      if (i == n) return 0;
//      if (mem[i][l][r] >= 0) return mem[i][l][r];
//      int c = word[i] - 'A';
//      return mem[i][l][r] = min(dp(i + 1, c, r) + cost(l, c),
//                                dp(i + 1, l, c) + cost(r, c));
//    };


//https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/discuss/477659/4%2B-DP-Solutions
//    int dp[2][27][27] = {};
//    for (int pos = word.size() - 1; pos >= 0; --pos) {
//        auto to = word[pos] - 'A';
//        for (int i = 0; i < 27; ++i) {
//            for (int j = 0; j < 27; ++j) {
//                dp[pos % 2][i][j] = min(dp[(pos + 1) % 2][to][i] +
//                    cost(j, to), dp[(pos + 1) % 2][to][j] + cost(i, to));
//            }
//        }
//    }
//    return dp[0][26][26];

//    int dp[301][27][27] = {};
//    for (int pos = word.size() - 1; pos >= 0; --pos) {
//        auto to = word[pos] - 'A';
//        for (int i = 0; i < 27; ++i) {
//            for (int j = 0; j < 27; ++j) {
//                dp[pos][i][j] = min(dp[pos + 1][to][i] + cost(j, to), dp[pos + 1][to][j] + cost(i, to));
//            }
//        }
//    }
//    return dp[0][26][26];

//    if (pos >= word.size()) return 0;
//    if (dp[other][pos] == -1) {
//        auto to = word[pos] - 'A', last = word[pos - 1] - 'A';
//        dp[other][pos] = min(cost(last, to) + minimumDistance(word, pos + 1, other),
//            cost(other, to) + minimumDistance(word, pos + 1, last));
//    }
//    return dp[other][pos];

//    if (pos >= word.size()) return 0;
//    if (dp[left][right][pos] == -1) {
//        auto to = word[pos] - 'A';
//        dp[left][right][pos] = min(cost(left, to) + minimumDistance(word, pos + 1, to, right),
//            cost(right, to) + minimumDistance(word, pos + 1, left, to));
//    }
//    return dp[left][right][pos];

//    Start with DFS
//    Add memoisation
//    Using your top-down solution, come up with a bottom-up one
//    Optimize memory for the bottom-up solution



//    def minimumDistance(self, A):
//        def d(a, b):
//            return a and abs(a / 6 - b / 6) + abs(a % 6 - b % 6)
//
//        dp, dp2 = {(0, 0): 0}, {}
//        for c in (ord(c) + 1 for c in A):
//            for a, b in dp:
//                dp2[c, b] = min(dp2.get((c, b), 3000), dp[a, b] + d(a, c))
//                dp2[a, c] = min(dp2.get((a, c), 3000), dp[a, b] + d(b, c))
//            dp, dp2 = dp2, {}
//        return min(dp.values())


//        vector<int> dp(26);
//        int res = 0, save = 0, n = word.size();
//        for (int i = 0; i < n - 1; ++i) {
//            int b = word[i] - 'A', c = word[i + 1] - 'A';
//            for (int a = 0; a < 26; ++a)
//                dp[b] = max(dp[b], dp[a] + d(b, c) - d(a, c));
//            save = max(save, dp[b]);
//            res += d(b, c);
//        }
//        return res - save;




//Runtime: 56 ms, faster than 54.55% of C++ online submissions for Minimum Distance to Type a Word Using Two Fingers.
//Memory Usage: 13.2 MB, less than 51.73% of C++ online submissions for Minimum Distance to Type a Word Using Two Fingers.
// hint 2:
//dp[i][j][k]: smallest movements when you have one finger on i-th char
//and the other one on j-th char already having written k first characters from word.
    int lt1320c(string word)
    {
        int sz1 = word.size();
//        vector<vector<vector<int>>> vvvi();           // 300^3...  应该不需要k。 k是for循环的。
        const int ZXC = 10000000;
        vector<vector<int>> vvi(sz1 + 1, vector<int>(sz1 + 1, ZXC));      // 下标0代表没有使用， 所以 这里下标1 对应 word下标0.
        vvi[0][1] = 0;
        vvi[1][0] = 0;
        for (int i = 2; i <= sz1; ++i)      // 真正的是word[i-1]
        {
            // 感觉任何时候都是 使用 没有使用过的手指 最好的啊。
//            vvi[0][i + 1] = ;
//            vvi[i + 1][0] = ;
//            vvi[i][i - 1] = ;
            // 要遍历哪些 一根手指在 i-1 上的 就是上一层。 或者i-1列。
            // 0 不需要distance。。
            if (vvi[i - 1][0] != ZXC)
            {
                vvi[i][0] = min(vvi[i][0], vvi[i - 1][0] + distancec1(word[i - 2], word[i - 1]));
                vvi[i - 1][i] = min(vvi[i - 1][i], vvi[i - 1][0]);
            }
            if (vvi[0][i - 1] != ZXC)
            {
                // 上三角矩阵，缓存 distance(i, i-1);
                vvi[0][i] = min(vvi[0][i], vvi[0][i - 1] + distancec1(word[i - 2], word[i - 1]));
                vvi[i][i - 1] = min(vvi[i][i - 1], vvi[0][i - 1]);
            }
            for (int j = 1; j <= sz1; ++j)
            {
                if (vvi[i - 1][j] != ZXC)       // 行   i-1是 下标i-2的char
                {
                    vvi[i][j] = min(vvi[i][j], vvi[i - 1][j] + distancec1(word[i - 2], word[i - 1]));       // 使用第一根
                    vvi[i - 1][i] = min(vvi[i - 1][i], vvi[i - 1][j] + distancec1(word[j - 1], word[i - 1]));      // 使用第二根
                }
                if (vvi[j][i - 1] != ZXC)       // lie
                {
                    vvi[j][i] = min(vvi[j][i], vvi[j][i - 1] + distancec1(word[i - 2], word[i - 1]));
                    vvi[i][i - 1] = min(vvi[i][i - 1], vvi[j][i - 1] + distancec1(word[j - 1], word[i - 1]));
                }
            }
//            for (int j = )
        }

        int ans = INT_MAX;
        for (int i = 0; i <= sz1; ++i)
        {
            ans = min(ans, vvi[i][sz1]);
            ans = min(ans, vvi[sz1][i]);
        }
        #ifdef __test
        for (myvi& v : vvi)
        {
            for (int i : v)
                if (i == 10000000)
                    cout<<"-1, ";
                else
                    cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test
        return ans;
    }
    int distancec1(char a, char b)
    {
        int aa = a - 'A';           // Upper
        int bb = b - 'A';
        int ans = abs((aa / 6) - (bb / 6)) + abs((aa % 6) - (bb % 6));
        #ifdef __test
//        cout<<a<<", "<<b<<", "<<ans<<" ?? "<<aa<<", "<<bb<<endl;
        #endif // __test
        return ans;
    }

//    int lt1320b(string word)
//    {
//
//    }
//    // dfs要用greedy，好像也不行啊。。
//    void dfsb1(string& word, int idx, int x1, int y1, int x2, int y2)
//    {
//
//    }


// 好像dp不了。。dfs
//// use this or use this...
//// 5hang 6lie  zuihou yz
//    int lt1320a(string word)
//    {
//        int x1 = -1, y1 = x1, x2 = x1, y2 = x1;
//        int sz1 = word.size();
////        vector<vector<>>
//        // 好像有4种可能。。
//        vector<int> vi(4, 0);           // 从未使用右：本次使用左，本次使用右，   从未使用左：本次使用左，本次使用右。
////        vector<vector<int>> vvi(4, vector<int>(2, 0));
////        vvi[][] = ;
////        vvi[][] = ;
////        vvi[][] = ;
////        vvi[][] = ;
////        vvi[][] = ;
////        vvi[][] = ;
////        vvi[][] = ;
////        vvi[][] = ;
////  zuo you   haofan.
////        vector<vector<vector<int>>> vvvi = {{{};
//        x1 = word[0] / 5;
//        vector<vector<int>> vvi = {{},{},{},{}};
//        for (int i = 0; i < )
//    }

};

int main()
{
//    string s = "CAKE";      // 3
//    string s = "HAPPY";     // 6
//    string s = "NEW";     // 3
    string s = "YEAR";      // 7

    LT1320 lt;

    cout<<lt.lt1320c(s)<<endl;

    return 0;
}
