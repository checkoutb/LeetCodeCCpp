
#include "../header/myheader.h"

class LT3122
{
public:


    // D D

        // vector<int> dp(10);
        // for (int j = 0; j < n; ++j) {
        //     vector<int> v(10);
        //     for (int i = 0; i < m; ++i) {
        //         ++v[candy[i][j]];
        //     }
        //     vector<int> temp(10, INT_MAX);
        //     for (int i = 0; i < 10; ++i) {
        //         int t = INT_MAX;
        //         for (int j = 0; j < 10; ++j) {
        //             if (j != i) {
        //                 t = min(t, dp[j]);
        //             }
        //         }
        //         temp[i] = min(temp[i], t + m - v[i]);
        //     }
        //     dp = temp;
        // }



// int cnt[1000][10] = {}, dp[1001][2] = {}, top[1001] = {};
// int minimumOperations(vector<vector<int>>& g) {
//     int m = g.size(), n = g[0].size();
//     vector<int> ids{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//     for (int i = 0; i < m; ++i)
//         for (int j = 0; j < n; ++j)
//             ++cnt[j][g[i][j]];
//     for (int i = 1; i <= n; ++i) {
//         partial_sort(begin(ids), begin(ids) + 3, end(ids), [&](int a, int b){ return cnt[i - 1][a] > cnt[i - 1][b]; });
//         for (int id = 0; id < 3; ++id) {
//             int cur = cnt[i - 1][ids[id]] + dp[i - 1][ids[id] == top[i - 1]];
//             if (cur > dp[i][0]) {
//                 dp[i][1] = exchange(dp[i][0], cur);
//                 top[i] = ids[id];
//             }
//             else if (cur > dp[i][1])
//                 dp[i][1] = cur;
//         }
//     }
//     return n * m - dp[n][0];
// }





// Runtime
// 243ms
// Beats44.44%of users with C++
// Memory
// 116.85MB
// Beats11.11%of users with C++
    int minimumOperations(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        vector<vector<int>> vvi(sz2, vector<int>(10, 0));
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                ++vvi[j][grid[i][j]];
            }
        }

        int arr[10] = {0};
        for (int j = 0; j < sz2; ++j)
        {
            int mx1i = -1;
            int mx2i = -1;
            int mx1v = -1;
            int mx2v = -1;
            for (int i = 0; i < 10; ++i)
            {
                if (arr[i] >= mx1v)
                {
                    mx2v = mx1v;
                    mx2i = mx1i;
                    mx1v = arr[i];
                    mx1i = i;
                }
                else if (arr[i] > mx2v)
                {
                    mx2v = arr[i];
                    mx2i = i;
                }
            }
            int arr2[10] = {0};
            for (int i = 0; i < 10; ++i)
            {
                if (i == mx1i)
                {
                    arr2[i] = mx2v + vvi[j][i];
                }
                else
                {
                    arr2[i] = mx1v + vvi[j][i];
                }
            }
            swap(arr, arr2);
        }
        int mx = 0;
        for (int i = 0; i < 10; ++i)
        {
            mx = max(mx, arr[i]);
        }
        return sz1 * sz2 - mx;
    }

//     int dfsa1(vector<vector<int>>& vvi, int col, int prev, vector<vector<int>>& vv2)
//     {
//         if (col == vvi[0].size())
//             return 0;
//
//     }
};

int main()
{

    LT3122 lt;


    return 0;
}
