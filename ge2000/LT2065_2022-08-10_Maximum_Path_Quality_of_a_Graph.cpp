
#include "../header/myheader.h"

class LT2065
{
public:

    // D D

    //if (time > maxTime)
    //    return;

    //if (visited[node] == 0)
    //    score += values[node];

    //visited[node]++;

    //if (node == 0)
    //    res = max(res, score);

    //for (auto it : graph[node])
    //{
    //    int neigh = it.first;
    //    int newTime = time + it.second;
    //    dfs(graph, values, visited, res, neigh, score, newTime, maxTime);
    //}

    //visited[node]--;



    //int n = values.size();
    //vector<vector<pair<int, int>>> graph(n);
    //for (auto& x : edges) {
    //    graph[x[0]].emplace_back(x[1], x[2]);
    //    graph[x[1]].emplace_back(x[0], x[2]);
    //}

    //int ans = 0;
    //vector<int> freq(n); freq[0] = 1;

    //function<void(int, int, int)> fn = [&](int u, int time, int val) {
    //    if (u == 0) ans = max(ans, val);
    //    for (auto& [v, t] : graph[u])
    //        if (time + t <= maxTime) {
    //            if (++freq[v] == 1) fn(v, time + t, val + values[v]);
    //            else fn(v, time + t, val);
    //            --freq[v];
    //        }
    //};

    //fn(0, 0, values[0]);
    //return ans;



//Runtime: 458 ms, faster than 25.57 % of C++ online submissions for Maximum Path Quality of a Graph.
//Memory Usage : 22 MB, less than 33.04 % of C++ online submissions for Maximum Path Quality of a Graph.
    // . 4^10 2048
    int lt2065a(vector<int>& values, vector<vector<int>>& edges, int maxTime)
    {
        int ans = 0;
        unordered_map<int, vector<pair<int, int>>> map2;
        for (vector<int>& vi : edges)
        {
            map2[vi[0]].emplace_back(std::make_pair( vi[1], vi[2] ));           // emplace_back({v11,v22})   error
            map2[vi[1]].emplace_back(make_pair( vi[0], vi[2] ));
        }
        int sz1 = values.size();
        vector<int> vst(sz1);
        vst[0]++;

        ans = dfsa1(values, map2, 0, maxTime, values[0], vst, 0);

        return ans;
    }

    int dfsa1(vector<int>& vi, unordered_map<int, vector<pair<int, int>>>& map2, int node, int mxtm, int sum2, vector<int>& vst, int tm)
    {
        int ans = 0;
        if (tm > mxtm)
            return ans;
        if (node == 0)
        {
            ans = sum2;
        }

        for (pair<int, int>& p : map2[node])
        {
            int nxt = p.first;
            int t2 = sum2;
            if (vst[nxt] == 0)
            {
                t2 += vi[nxt];
            }
            vst[nxt]++;

            int t3 = dfsa1(vi, map2, nxt, mxtm, t2, vst, tm + p.second);
            ans = max(ans, t3);

            vst[nxt]--;
        }
        return ans;
    }

};

int main()
{

    LT2065 lt;

    //myvi v = { 0,32,10,43 };
    //myvvi vv = { {0,1,10},{1,2,15},{0,3,10} };
    //int mxtm = 49;

    //myvi v = { 5,10,15,20 };
    //myvvi vv = { {0,1,10},{1,2,10},{0,3,10} };
    //int mxtm = 30;

    myvi v = { 1,2,3,4 };
    myvvi vv = { {0,1,10},{1,2,11},{2,3,12},{1,3,13} };
    int mxtm = 50;

    cout << lt.lt2065a(v, vv, mxtm) << endl;

    return 0;
}
