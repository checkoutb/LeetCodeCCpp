
#include "../header/myheader.h"

class LT2959
{
public:

// D D

//     for (auto &r : roads) {
//         d[r[0]][r[1]] = min(d[r[0]][r[1]], r[2]);
//         d[r[1]][r[0]] = min(d[r[1]][r[0]], r[2]);
//     }
//
//
//     int comb = 1 << n, res = 1;
//     for (int mask = 1; mask < comb; ++mask)
//         res += getMaxDistance(mask, n, d) <= maxDistance;
//
//
//     for (int k = 0; k < n; ++k) // Floyd-Warshall
//         if (mask & (1 << k))
//             for (int i = 0; i < n; ++i)


    // 起初 floyd 没有写对。。

//     Runtime145 ms
// Beats
// 77.89%
// Memory56.9 MB
// Beats
// 47.94%


    // 关掉哪些后，剩余的 最大距离 <= maxDistance
    // 10个点， 1000条距离， 距离数量可以缩减， 最多 90条 .  配合2^10，应该可以硬算
    // 2^10 ， 关 或 不关， 1024 很快的， dfs 最大10层 。
    // 怎么快速计算 当前状态下，最大的距离 是否大于 maxDistance
    // 关闭， 就不需要计算， 不关闭，就 和前面的 没有关闭的 点 算下 距离。
    // 点关闭后， 路也没有了。
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads)
    {
        if (roads.size() == 0)      // example 3
            return 2;

        int ans = 0;
        for (vector<int>& vi : roads)
        {
            if (vi[0] > vi[1])
            {
                swap(vi[0], vi[1]);
            }
        }
        sort(begin(roads), end(roads));
        // vector<vector<int>> vvi;
        // vvi.push_back(roads[0]);
        vector<vector<int>> vvi(n, vector<int>(n, INT_MAX));
        vvi[roads[0][0]][roads[0][1]] = roads[0][2];
        vvi[roads[0][1]][roads[0][0]] = roads[0][2];
        for (size_t i = 1; i < roads.size(); ++i)
        {
            if (roads[i][0] != roads[i - 1][0] || roads[i][1] != roads[i - 1][1])
            {
                // vvi.push_back(roads[i]);
                vvi[roads[i][0]][roads[i][1]] = roads[i][2];
                vvi[roads[i][1]][roads[i][0]] = roads[i][2];
            }
        }

        ans = dfsa1(0, n - 1, maxDistance, vvi);
        return ans;
    }

    // state's bit: 0: close,  1: not close
    // return: number of good set
    int dfsa1(int state, int n, int mxDis, vector<vector<int>>& roads)
    {
        int ans = 0;
        if (n == -1)
        {
            ans = cal_distance(state, roads) <= mxDis;
#ifdef __test
            cout<<"     "<<state<<", "<<ans<<endl;
#endif
            return ans;
        }

        ans += dfsa1(state, n - 1, mxDis, roads);       // close
        ans += dfsa1(state | (1 << n), n - 1, mxDis, roads);
        return ans;
    }

    // 任意2点 最短路径，floyd...
    int cal_distance(int state, vector<vector<int>>& vvi)
    {
        if ((state & (state - 1)) == 0)     // only 1 or 0 node
            return 0;
        int sz1 = vvi.size();
        vector<vector<int>> vv2(vvi);
        for (size_t i = 0; i < sz1; ++i)
        {
            if ((state & (1 << i)) == 0)
                continue;
            for (size_t j = 0; j < sz1; ++j)
            {
                if ((state & (1 << j)) == 0)
                    continue;
                if (j == i)
                    continue;
                for (size_t k = 0; k < sz1; ++k)
                {
                    if ((state & (1 << k)) == 0)
                        continue;
                    if (i == k || j == k)
                        continue;
                    if (vv2[j][i] == INT_MAX || vv2[i][k] == INT_MAX)
                        continue;
                    vv2[j][k] = min(vv2[j][k], vv2[j][i] + vv2[i][k]);
                }
            }
        }
        int ans = 0;
        for (size_t i = 0; i < sz1; ++i)
        {
            if ((state & (1 << i)) == 0)
                continue;
            for (size_t j = i + 1; j < sz1; ++j)
            {
                if ((state & (1 << j)) == 0)
                    continue;
                ans = max(ans, vv2[i][j]);
            }
        }
#ifdef __test
        cout<<state<<", "<<ans<<endl;
#endif
        return ans;
    }

};

int main()
{

    LT2959 lt;

    int n = 3;
    int mxd = 5;
    // myvvi vv = {{1,0,2},{1,2,10},{2,0,10}};
    myvvi vv = {{1,0,20},{1,0,10},{1,2,2},{0,2,2}};

    cout<<lt.numberOfSets(n, mxd, vv)<<endl;

    // cout<<"ee"<<endl;

    return 0;
}
