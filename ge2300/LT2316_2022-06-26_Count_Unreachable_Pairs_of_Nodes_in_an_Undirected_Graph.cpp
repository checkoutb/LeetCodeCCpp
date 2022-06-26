
#include "../header/myheader.h"

class LT2316
{
public:


    // D D






    // ... 不需要 pop_back。 for循环用 下标 就可以了。。
//Runtime: 1000 ms, faster than 50.00 % of C++ online submissions for Count Unreachable Pairs of Nodes in an Undirected Graph.
//Memory Usage : 137.6 MB, less than 100.00 % of C++ online submissions for Count Unreachable Pairs of Nodes in an Undirected Graph.
    // uf, then + * -
    // <parent, count>
    long long lt2316a(int n, vector<vector<int>>& edges)
    {
        //vector<int> uf(n, -1);

        vector<pair<int, int>> uf(n, { -1, 1 });

        for (vector<int>& vi : edges)
        {
            int t1 = ufa(uf, vi[0]);
            int t2 = ufa(uf, vi[1]);
            if (t1 != t2)
            {
                uf[t1].first = t2;
                uf[t2].second += uf[t1].second;
            }
        }

        vector<int> vi;
        int sum2 = 0;
        for (pair<int, int>& p : uf)
        {
            if (p.first == -1)
            {
                vi.push_back(p.second);
                sum2 += p.second;
            }
        }
        long long ans = 0LL;            // ll...
        while (!vi.empty())         // stk / Q
        {
            int t2 = vi[vi.size() - 1];
            vi.pop_back();
            sum2 -= t2;
            ans += 1LL * t2 * sum2;
        }
        return ans;
    }

    int ufa(vector<pair<int, int>>& uf, int idx)
    {
        if (uf[idx].first == -1)
            return idx;
        return uf[idx].first = ufa(uf, uf[idx].first);
    }

    //// ..直接 遍历 uf，转成 map ，就知道 各个连通分量的 节点数了。。。
    //pair<int, int>& ufa(vector<pair<int, int>>& uf, int idx)
    //{
    //    return (uf[idx].first == -1) ? (uf[idx]) : (uf[idx] = ufa(uf, uf[idx].first));
    //}

    //int ufa(vector<int>& uf, int idx)
    //{
    //    return uf[idx] == -1 ? idx : (uf[idx] = ufa(uf, uf[idx]));
    //}

};

int main()
{

    LT2316 lt;

    //int n = 3;
    //myvvi vv = { {0,1},{0,2},{1,2} };

    int n = 7;
    myvvi vv = { {0,2},{5,0},{2,4},{1,6},{5,4} };

    cout << lt.lt2316a(n, vv) << endl;

    return 0;
}
