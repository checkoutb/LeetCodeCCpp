
#include "../header/myheader.h"

class LT2493
{
public:

    // D D



    //Runtime490 ms
    //    Beats
    //    75.45 %
    //    Memory50.8 MB
    //    Beats
    //    37.98 %

    // 对每个点都做一次bfs。tle？
    // 是不是只需要一次bfs 就可以知道 -1 还是 其他？
    // 1次 bfs + 1次dfs， 但是 dfs 无法处理环啊。
    // 未连接。 那要uf啊。 每个连通的 最大gp。
    int lt2493a(int n, vector<vector<int>>& edges)
    {
        int sz1 = edges.size();
        vector<vector<int>> vvi(n + 1);
        
        vector<int> uf(n + 1);

        for (vector<int> vi : edges)
        {
            int t2 = ufa(uf, vi[0]);
            int t3 = ufa(uf, vi[1]);

            if (t2 != t3)
                uf[t2] = t3;

            vvi[vi[0]].push_back(vi[1]);
            vvi[vi[1]].push_back(vi[0]);
        }

        unordered_map<int, int> map2;

        for (int i = 1; i <= n; ++i)
        {
            int t2 = bfsa1(vvi, i, n);
            if (t2 == -1)
                return -1;

            map2[ufa(uf, i)] = max(t2, map2[ufa(uf, i)]);
        }
        int ans = 0;
        for (auto [k, v] : map2)
        {
            ans += v;
        }
        return ans;
    }

    int ufa(vector<int>& uf, int idx)
    {
        return uf[idx] == 0 ? idx : uf[idx] = ufa(uf, uf[idx]);
    }

    int bfsa1(vector<vector<int>>& vvi, int st, int n)
    {
        int gp = 1;

        vector<int> vi(n + 1);
        vi[st] = 1;
        
        queue<int> que1;
        que1.push(st);

        while (!que1.empty())
        {
            int t2 = que1.front();
            que1.pop();

            int mygp = vi[t2];
            gp = max(gp, mygp);

            for (int nxt : vvi[t2])
            {
                if (vi[nxt] == 0)
                {
                    vi[nxt] = mygp + 1;
                    que1.push(nxt);
                }
                else
                {
                    if (abs(vi[nxt] - mygp) != 1)
                        return -1;
                }
            }
        }

        return gp;
    }

};

int main()
{

    LT2493 lt;


    return 0;
}
