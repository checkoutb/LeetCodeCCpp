
#include "../header/myheader.h"

class LT2538
{
public:

    // D D

    //function<pair<ll, ll>(int, int)> dfs = [&](int cur, int par) -> pair<ll, ll> {
    //    int p = price[cur];
    //    if (g[cur].size() == 1) return make_pair(p, 0);
    //    ll max_s1 = 0, max_s2 = 0;
    //    for (int nxt : g[cur]) {
    //        if (nxt == par) continue;
    //        auto [s1, s2] = dfs(nxt, cur);
    //        if (max_s1 == 0) res = max(res, s1);
    //        else res = max(res, max_s2 + p + s1);
    //        res = max(res, max_s1 + p + s2);
    //        max_s1 = max(max_s1, s1);
    //        max_s2 = max(max_s2, s2);
    //    }
    //    return make_pair(max_s1 + p, max_s2 + p);
    //};
    //dfs(0, -1);




    //Runtime505 ms
    //    Beats
    //    91.35 %
    //    Memory159.2 MB
    //    Beats
    //    95.93 %
    // min price : price[root]
    // max : 最
    // max - min = path - root / or path - leaf noded
    // 所以，就是找 max(2个端点间的sum，减去一个端点)。 任意2个点的距离。
    // root，必然是 度为1 的。
    long long lt2538a(int n, vector<vector<int>>& edges, vector<int>& price)
    {
        if (n == 1)
            return 0LL;
        if (n == 2)
            return max(price[0], price[1]);

        vector<vector<int>> vvi(n);
        for (vector<int>& vi : edges)
        {
            vvi[vi[0]].push_back(vi[1]);
            vvi[vi[1]].push_back(vi[0]);
        }
        long long ans = 0LL;

        for (int i = 0; i < n; ++i)
        {
            if (vvi[i].size() > 1)
            {
                dfsa1(vvi, i, price, -1, ans);
                break;
            }
        }

        return ans;
    }

    // 包含端点的max， 不包含端点的max(max-端点)
    pair<long long, long long> dfsa1(vector<vector<int>>& vvi, int node, vector<int>& prc, int par, long long& ans)
    {
        if (vvi[node].size() == 1)
        {
            return make_pair(prc[node], 0);
        }
        long long mx1 = -123123123LL;    // pair.1th, contain leaf-node
        long long mx2 = -123123123LL;    // pair.2nd, no leaf node
        for (int nxt : vvi[node])
        {
            if (nxt == par)
                continue;

            pair<long long, long long> pii = dfsa1(vvi, nxt, prc, node, ans);

            ans = max(ans, prc[node] + max(mx1 + pii.second, mx2 + pii.first));
            mx1 = max(mx1, pii.first);
            mx2 = max(mx2, pii.second);
        }
        return make_pair(prc[node] + mx1, prc[node] + mx2);
    }

};

int main()
{

    LT2538 lt;

    //int n = 3;
    //myvvi vv = { {1,0},{1,2} };
    //myvi v = { 1,1,1 };

    int n = 6;
    myvvi vv = { {1,0},{1,2},{1,3},{3,4},{3,5} };
    myvi v = { 9,8,7,6,10,5 };

    cout << lt.lt2538a(n, vv, v) << endl;

    return 0;
}
