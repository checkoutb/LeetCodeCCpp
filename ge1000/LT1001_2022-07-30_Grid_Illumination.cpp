
#include "../header/myheader.h"

class LT1001
{
public:

    // D D


    //vector<int> res;
    //unordered_map<int, int> x, y, a_d, d_d;
    //unordered_map<int, unordered_set<int>> ls;
    //for (auto l : lamps) {
    //    auto i = l[0], j = l[1];
    //    if (ls[i].insert(j).second) ++x[i], ++y[j], ++a_d[i + j], ++d_d[i - j];
    //}
    //for (auto q : queries) {
    //    auto i = q[0], j = q[1];
    //    if (x[i] || y[j] || a_d[i + j] || d_d[i - j]) {
    //        res.push_back(1);
    //        for (auto li = i - 1; li <= i + 1; ++li)
    //            for (auto lj = j - 1; lj <= j + 1; ++lj) {
    //                if (ls[li].erase(lj)) {
    //                    --x[li], --y[lj], --a_d[li + lj], --d_d[li - lj];
    //                }
    //            }
    //    }
    //    else res.push_back(0);
    //}


    //struct pairHash {
    //    size_t operator()(const pair<int, int>& x) const { return x.first ^ x.second; }
    //};
    //vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
    //    vector<int> res;
    //    unordered_map<int, int> x, y, a_d, d_d;
    //    unordered_set<pair<int, int>, pairHash> ls;
    //    for (auto l : lamps) {
    //        auto i = l[0], j = l[1];
    //        if (ls.insert({ i, j }).second) ++x[i], ++y[j], ++a_d[i + j], ++d_d[i - j];
    //    }
    //    for (auto q : queries) {
    //        auto i = q[0], j = q[1];
    //        if (x[i] || y[j] || a_d[i + j] || d_d[i - j]) {
    //            res.push_back(1);
    //            for (int li = i - 1; li <= i + 1; ++li)
    //                for (int lj = j - 1; lj <= j + 1; ++lj) {
    //                    if (ls.erase({ li, lj })) {
    //                        --x[li], --y[lj], --a_d[li + lj], --d_d[li - lj];
    //                    }
    //                }
    //        }
    //        else res.push_back(0);
    //    }
    //    return res;
    //}
    // 自定义hash


//Runtime: 848 ms, faster than 62.80 % of C++ online submissions for Grid Illumination.
//Memory Usage : 151.6 MB, less than 30.42 % of C++ online submissions for Grid Illumination.
    // 灯，初始 关闭。
    // lamps 开灯，可以多次 开灯。
    // 开灯时，照亮 横，竖，斜
    // query， 这个灯是不是亮着？，然后关闭它 以及 它周围8个灯。
    // n <= 10^9 。。 数组都没得做。
    // 2万个灯。 2万次查询。  
    // 感觉是 横y 竖x (x+y)  
    // diagonal 对角线，   是不是 不包含 反/副对角线。。。 矩阵和几何。  当 矩阵
    // 行， 列， 一条对角线在0列的位置。
    // 。。 包含 反/副对角线。。。
    vector<int> lt1001a(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries)
    {
        unordered_map<int, int> mapr;
        unordered_map<int, int> mapc;
        unordered_map<int, int> mapd;
        unordered_map<int, int> mapa;

        unordered_map<int, unordered_map<int, int>> map2;

        for (vector<int>& vi : lamps)
        {
            if (map2[vi[0]][vi[1]] == 0)
            {
                map2[vi[0]][vi[1]] = 1;
                mapr[vi[0]]++;
                mapc[vi[1]]++;
                mapd[vi[0] - vi[1]]++;
                mapa[vi[0] + vi[1]]++;
            }
        }

        vector<int> ans(queries.size());

        int arr[][2] = { {-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{0,0} };

        for (int i = 0; i < queries.size(); ++i)
        {
            int r = queries[i][0];
            int c = queries[i][1];
            if (mapr[r] > 0 || mapc[c] > 0 || mapd[r - c] > 0 || mapa[r + c] > 0)
                ans[i] = 1;

            for (int i = 0; i < 9; ++i)
            {
                int nr = r + arr[i][0];
                int nc = c + arr[i][1];
                if (nr < 0 || nc < 0 || nr >= n || nc >= n)
                    continue;
                if (map2.find(nr) != map2.end() && map2[nr].find(nc) != map2[nr].end() && map2[nr][nc] == 1)
                {
                    map2[nr][nc] = 0;
                    mapr[nr]--;
                    mapc[nc]--;
                    mapd[nr - nc]--;
                    mapa[nr + nc]--;
                }
            }
        }
        return ans;
    }

};

int main()
{

    LT1001 lt;

    int n = 6;
    myvvi vv = { {1, 1} };
    myvvi vv2 = { {2, 0}, { 1, 0 }};        // [1,0]

    myvi v = lt.lt1001a(n, vv, vv2);

    showVectorInt(v);

    return 0;
}
