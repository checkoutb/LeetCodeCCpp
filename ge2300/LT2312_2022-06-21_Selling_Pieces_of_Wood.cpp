
#include "../header/myheader.h"

class LT2312
{
public:

    // D D

    //long long dp[201][201] = {};
    //for (auto& p : prices)
    //    dp[p[0]][p[1]] = p[2];
    //for (int w = 1; w <= m; ++w) {
    //    for (int h = 1; h <= n; ++h) {
    //        for (int a = 1; a <= w / 2; ++a)
    //            dp[w][h] = max(dp[w][h], dp[a][h] + dp[w - a][h]);
    //        for (int a = 1; a <= h / 2; ++a)
    //            dp[w][h] = max(dp[w][h], dp[w][a] + dp[w][h - a]);
    //    }
    //}
    //return dp[m][n];




//Runtime: 944 ms, faster than 31.43 % of C++ online submissions for Selling Pieces of Wood.
//Memory Usage : 39 MB, less than 8.49 % of C++ online submissions for Selling Pieces of Wood.
    // ...
    // 横切后，竖切 就可以根据 价格/宽度 来决定。边角料怎么处理。 或者 dp ？
    // 先横切，先后切 都得尝试。。
    // 而且。 可以 memo 保存 这个宽度，这个长度的 最大。。。
    // 。。还有 横切后，竖切，再横切。。有没有？
    // 那就是 纯粹的dp了？
    // bu，dp是可以 只切一半的，  这里必须全部切完。。
    // 不。 整体 dp
    long long lt2312a(int m, int n, vector<vector<int>>& prices)
    {
        vector<vector<long long>> vvi(m + 1, vector<long long>(n + 1, 0LL));
        map<int, vector<vector<int>>> map2;       // high
        map<int, vector<vector<int>>> map3;       // width

        for (vector<int>& vi : prices)
        {
            map2[vi[0]].push_back(vi);
            map3[vi[1]].push_back(vi);
            vvi[vi[0]][vi[1]] = vi[2];
        }

        for (int i = 0; i <= m; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                vvi[i][j] = max(vvi[i][j], max(
                    (i == 0 ? 0 : vvi[i - 1][j]),
                    (j == 0 ? 0 : vvi[i][j - 1])));
            }
        }

        for (int i = 0; i <= m; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                vvi[i][j] = -vvi[i][j];
            }
        }

        long long ans = dfsa1(map2, map3, m, n, vvi);
        return ans;
    }

    long long dfsa1(map<int, vector<vector<int>>>& map2, map<int, vector<vector<int>>>& map3, int h, int w, vector<vector<long long>>& vvi)
    {
        if (vvi[h][w] >= 0)
            return vvi[h][w];

        long long ans = abs(vvi[h][w]);

        // 横切
        for (map<int, vector<vector<int>>>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            if (it->first < h)
            {
                long long t2 = dfsa1(map2, map3, it->first, w, vvi);
                long long t3 = dfsa1(map2, map3, h - it->first, w, vvi);
                ans = max(ans, t2 + t3);
            }
            else
            {
                break;
            }
        }

        // 竖切
        for (map<int, vector<vector<int>>>::iterator it = map3.begin(); it != map3.end(); it++)
        {
            if (it->first < w)
            {
                long long t2 = dfsa1(map2, map3, h, it->first, vvi);
                long long t3 = dfsa1(map2, map3, h, w - it->first, vvi);
                ans = max(ans, t2 + t3);
            }
            else
                break;
        }
        
        vvi[h][w] = ans;
        return ans;
    }

};

int main()
{

    LT2312 lt;

    //int m{ 3 }, n{ 5 };
    //myvvi vv = { {1,4,2},{2,2,7},{2,1,3} };

    int m{ 4 }, n{ 6 };
    myvvi vv = { {3,2,10},{1,4,2},{4,1,3} };

    cout << lt.lt2312a(m, n, vv) << endl;

    return 0;
}
