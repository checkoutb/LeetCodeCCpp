
#include "../header/myheader.h"

class LT2392
{
public:

    // D D

    //vector<int> khansAlgo(vector<vector<int>>& r, int k) {
    //    vector<int> cnt(k + 1, 0);
    //    vector<int> adj[k + 1];
    //    for (auto x : r) {
    //        cnt[x[1]]++;
    //        adj[x[0]].push_back(x[1]);
    //    }
    //    vector<int> row;
    //    queue<int> q;
    //    for (int i = 1; i <= k; i++) {
    //        if (cnt[i] == 0) {
    //            q.push(i);
    //        }
    //    }
    //    while (!q.empty()) {
    //        int t = q.front();
    //        q.pop();
    //        row.push_back(t);
    //        for (auto x : adj[t]) {
    //            cnt[x]--;
    //            if (cnt[x] == 0) {
    //                q.push(x);
    //            }
    //        }
    //    }
    //    return row;
    //}
// 数组 而不是 map 。 。 count 而不是 set




    //auto fn = [&](vector<vector<int>>& edges) {
    //    vector<vector<int>> graph(k);
    //    vector<int> indeg(k);
    //    for (auto& e : edges) {
    //        graph[e[0] - 1].push_back(e[1] - 1);
    //        ++indeg[e[1] - 1];
    //    }

    //    queue<int> q;
    //    vector<int> ans;
    //    for (int u = 0; u < k; ++u)
    //        if (indeg[u] == 0) q.push(u);
    //    while (q.size()) {
    //        int u = q.front(); q.pop();
    //        ans.push_back(u);
    //        for (auto& v : graph[u])
    //            if (--indeg[v] == 0) q.push(v);
    //    }
    //    return ans;
    //};

    //vector<int> row = fn(aboveConditions), col = fn(leftConditions);
    //if (row.size() < k || col.size() < k) return vector<vector<int>>();
    //vector<int> rmap(k), cmap(k);
    //for (int i = 0; i < k; ++i) {
    //    rmap[row[i]] = i;
    //    cmap[col[i]] = i;
    //}
    //vector<vector<int>> ans(k, vector<int>(k));
    //for (int x = 0; x < k; ++x)
    //    ans[rmap[x]][cmap[x]] = x + 1;
    //return ans;




//Runtime: 208 ms, faster than 100.00 % of C++ online submissions for Build a Matrix With Conditions.
//Memory Usage : 67.4 MB, less than 85.71 % of C++ online submissions for Build a Matrix With Conditions.
    // 行和列 是完全分隔的。
    // 拓扑啊。  
    // 谁在最下面，谁在 次下面。
    // 或者说 没有 数字 在 它上面。
    vector<vector<int>> lt2392a(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions)
    {
        //unordered_map<int, vector<int>> map2;       // num, above
        unordered_map<int, unordered_set<int>> map2;
        unordered_map<int, vector<int>> map3;       // ... child.
        
        for (vector<int>& vi : rowConditions)
        {
            //map2[vi[1]].push_back(vi[0]);
            map2[vi[1]].insert(vi[0]);
            map3[vi[0]].push_back(vi[1]);
        }
        
        vector<int> vr(k + 1, -1);
        queue<int> que;

        for (int i = 1; i <= k; ++i)
        {
            if (map2.find(i) == map2.end())
                que.push(i);
        }
        int idx = 0;
        while (!que.empty())
        {
            int t2 = que.front();
            que.pop();
            if (vr[t2] != -1)
                continue;

            vr[t2] = idx++;

            for (int chd : map3[t2])
            {
                map2[chd].erase(t2);
                if (map2[chd].empty() && vr[chd] == -1)
                {
                    que.push(chd);
                }
            }
        }

        for (int i = 1; i <= k; ++i)
        {
            if (vr[i] == -1)
                return {};
        }

        map2.clear();
        map3.clear();

        for (vector<int>& vi : colConditions)
        {
            map2[vi[1]].insert(vi[0]);
            map3[vi[0]].push_back(vi[1]);
        }
        vector<int> vc(k + 1, -1);
        
        que = queue<int>();

        for (int i = 1; i <= k; ++i)
        {
            if (map2.find(i) == map2.end())
            {
                que.push(i);
            }
        }
        idx = 0;
        while (!que.empty())
        {
            int t2 = que.front();
            que.pop();
            if (vc[t2] != -1)
                continue;

            vc[t2] = idx++;
            for (int chd : map3[t2])
            {
                map2[chd].erase(t2);
                if (map2[chd].empty() && vc[chd] == -1)
                {
                    que.push(chd);
                }
            }
        }

        vector<vector<int>> ans(k, vector<int>(k, 0));

        for (int i = 1; i <= k; ++i)
        {
            if (vc[i] == -1)
                return {};

            ans[vr[i]][vc[i]] = i;
        }

        return ans;

        //unordered_map<int, vector<int>> map2;       // num, below
        //vector<int> vr(k + 1);
        //unordered_set<int> set2;        // below.
        //for (vector<int>& vi : rowConditions)
        //{
        //    map2[vi[0]].push_back();
        //}

    }

};

int main()
{

    LT2392 lt;

    int k = 3;
    myvvi vv = { {1,2},{3,2} };
    myvvi vv2 = { {2,1},{3,2} };

    myvvi v2 = lt.lt2392a(k, vv, vv2);

    for (myvi& vi : v2)
    {
        for (int i : vi)
            cout << i << ", ";
        cout << endl;
    }

    return 0;
}
