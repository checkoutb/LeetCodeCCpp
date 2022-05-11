
#include "../header/myheader.h"

class LT2267
{
public:

// D D

//if ((size(grid) + size(grid[0]) - 1) % 2 == 1) {


//        vector<bitset<100>> dp(size(grid[0]) + 1);
//        for (int i = 0; i < size(grid); ++i) {
//            dp[0][0] = !i;
//            for (int j = 0; j < size(grid[0]); ++j) {
//                dp[j + 1] = grid[i][j] == '(' ? (dp[j] | dp[j + 1]) << 1: (dp[j] | dp[j + 1]) >> 1;
//            }
//        }
//        return dp.back()[0];


//int visited[100][100][101] = {};
//bool hasValidPath(vector<vector<char>>& grid, int i = 0, int j = 0, int bal = 0) {
//    int m = grid.size(), n = grid[0].size();
//    bal += grid[i][j] == '(' ? 1 : -1;
//    if (bal < 0 || bal > (m + n) / 2 || visited[i][j][bal])
//        return false;
//    visited[i][j][bal] = true;
//    if (i == m - 1 && j == n - 1 && bal == 0)
//        return true;
//    if (i < m - 1 && hasValidPath(grid, i + 1, j, bal))
//        return true;
//    if (j < n - 1 && hasValidPath(grid, i, j + 1, bal))
//        return true;
//    return false;
//}



//    vector<bitset<100>> dp(n + 1);
//    for (int i = 0; i < m; i++) {
//        dp[0][0] = !i;
//        for (int j = 0; j < n; j++)
//            dp[j + 1] = grid[i][j] == '(' ? (dp[j] | dp[j + 1]) << 1: (dp[j] | dp[j + 1]) >> 1;
//    }
//    return dp[n][0];


//        int m = A.size(), n = A[0].size(), maxk = (m + n + 1) / 2;
//        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(maxk + 10)));
//        dp[0][0][1] = 1;
//        for (int i = 0; i < m; ++i)
//            for (int j = 0; j < n; ++j)
//                for (int k = 1; k <= maxk; ++k) {
//                    dp[i][j + 1][k] |= dp[i][j][k + (A[i][j] == '(' ? -1 : 1)];
//                    dp[i + 1][j][k] |= dp[i][j][k + (A[i][j] == '(' ? -1 : 1)];
//                }
//        return dp[m][n - 1][1];



//Runtime: 158 ms, faster than 82.93% of C++ online submissions for Check if There Is a Valid Parentheses String Path.
//Memory Usage: 25.6 MB, less than 44.76% of C++ online submissions for Check if There Is a Valid Parentheses String Path.
    bool lt2267b(vector<vector<char>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        if (((sz1 + sz2) % 2 == 0) || grid[0][0] == ')' || grid[sz1 - 1][sz2 - 1] == '(')
            return false;

        unordered_map<int, bool> map2;
        bool ans = dfsb1(grid, 0, 0, 0, map2);

        return ans;
    }

    bool dfsb1(vector<vector<char>>& vvc, int m, int n, int cnt, unordered_map<int, bool>& map2)
    {
        if (cnt < 0 || m == vvc.size() || n == vvc[0].size())
            return false;
        if ((m == (vvc.size() - 1)) && (n == (vvc[0].size() - 1)))
            return cnt == 1;

        int t2 = (m * 100 + n) * 100 + cnt;
        if (map2.find(t2) != map2.end())
            return map2[t2];                // always false

        cnt += (vvc[m][n] == '(' ? 1 : -1);
        if (dfsb1(vvc, m, n + 1, cnt, map2) || dfsb1(vvc, m + 1, n, cnt, map2))
            return true;

        map2[t2] = false;
        return false;
    }


// error
// ... 错上加错了。。
    bool lt2267a(vector<vector<char>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        if (((sz1 + sz2) % 2 == 0) || grid[0][0] == ')')
            return false;

        unordered_map<int, int> map2;
        int ans = 0;
        ans = dfsa1(grid, 0, 0, 0, map2, ans);

        cout<<ans<<endl;

        return ans;
    }

    int dfsa1(vector<vector<char>>& vvc, int m, int n, int cnt, unordered_map<int, int>& map2, int& ans)
    {
        if (cnt < 0 || m == vvc.size() || n == vvc[0].size())
            return 0;
        if ((m == vvc.size() - 1) && (n == vvc[0].size() - 1))
            return 1;

        int t2 = (m * 100 + n) * 100 + cnt;
        if (map2.find(t2) != map2.end())
        {
//            ans += map2[t2];
            return map2[t2];
        }
        cnt += (vvc[m][n] == '(' ? 1 : -1);
        int ta = dfsa1(vvc, m + 1, n, cnt, map2, ans);
        int tb = dfsa1(vvc, m, n + 1, cnt, map2, ans);
        map2[t2] = ta + tb;
        return ta + tb;
    }

};

int main()
{

    LT2267 lt;

    vector<vector<char>> vvc = {{'(','(','('},{')','(',')'},{'(','(',')'},{'(','(',')'}};

    cout<<lt.lt2267b(vvc)<<endl;

    return 0;
}
