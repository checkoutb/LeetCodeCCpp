
#include "../header/myheader.h"

class LT3123
{
public:

    // D D

    // Then we backtrack to identify edges included into the shortest path:
    //
    // We start from node n - 1
    // We backtrack from node j to node i if path[i] == path[j] - wight_i_j
    //     This ensures that we backtrack along the shortest path.
    //     We mark the edge between i and j as included.

    // 不需要记录 那么多的东西。

    // pq.push({path[n - 1], n - 1}); // backtrack
    // while (!pq.empty()) {
    //     auto [len, i] = pq.top(); pq.pop();
    //     for (auto [j, e] : al[i])
    //         if (len - edges[e][2] == path[j]) {
    //             res[e] = true;
    //             pq.push({path[j], j});
    //         }
    // }



    //

// Runtime
// 379ms
// Beats100.00%of users with C++
// Memory
// 175.60MB
// Beats85.71%of users with C++

    // bfs 也可以，记录下 0到本结点的最短路径，来自哪些点。
    // dfs 估计会超时。。而且也很麻烦。 就是 [边] 的值 是 0 - n-1 的经过这条边的 最短的路径 的加权和。
    vector<bool> findAnswer(int n, vector<vector<int>>& edges)
    {
        // vector<int> vi(edges.size(), INT_MAX);

        vector<vector<tuple<int, int, int>>> vvt(n);
        for (int i = 0; i < edges.size(); ++i)
        {
            vector<int>& e = edges[i];
            vvt[e[0]].push_back(std::make_tuple(e[1], e[2], i));
            vvt[e[1]].push_back(std::make_tuple(e[0], e[2], i));
        }

        vector<vector<int>> vvi(n);     // <edge1, edges2 ....>

        // length, node, edge
        std::priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, std::greater<>> priq;
        priq.push(std::make_tuple(0, 0, -1));
        vector<int> vi(n, INT_MAX);
        // vi[0] = 0;

        int a,b,c;
        int t2,t3,t4;
        while (!priq.empty())
        {
            if (std::get<0>(priq.top()) > vi[std::get<1>(priq.top())])
            {
                priq.pop();
                continue;
            }

            // length, node, edge
            std::tie(a,b,c) = priq.top();
            priq.pop();

            if (a < vi[b])
            {
                vi[b] = a;
                vvi[b].clear();
                vvi[b].push_back(c);
            }
            else
            {
                // a == vi[b];
                vvi[b].push_back(c);
            }

            for (int i = 0; i < vvt[b].size(); ++i)
            {
                // next, weight, edge index
                std::tie(t2,t3,t4) = vvt[b][i];
                if (vi[t2] >= a + t3)
                {
                    vi[t2] = a + t3;    // .
                    priq.push(std::make_tuple(a + t3, t2, t4));
                }
            }
        }

        vvi[0].clear();

        std::queue<int> que;
        que.push(n - 1);
        vector<bool> vb(edges.size(), false);

        while (!que.empty())
        {
            for (int i = que.size(); i > 0; --i)
            {
                int t2 = que.front();
                que.pop();
                for (int e : vvi[t2])
                {
                    if (vb[e] == false)
                    {
                        vb[e] = true;
                        if (edges[e][0] == t2)
                        {
                            que.push(edges[e][1]);
                        }
                        else
                        {
                            que.push(edges[e][0]);
                        }
                    }
                }
            }
        }

        return vb;
    }

//     int dfsa1(vector<vector<tuple<int, int, int>>>& vvt, int node, int parent, int len, int endNode, vector<int>& vi, vector<int>& v2)
//     {
//         if (node == endNode)
//             return len;
//
//         // if ()
//         int mn = INT_MAX;
//         int a,b,c;
//         for (int i = 0; i < vvt[node].size(); ++i)
//         {
//             std::tie(a,b,c) = vvt[node][i];     // nxt, weight, edge idx;
//
//             if (a == parent)
//                 continue;
//
//
//
//
//         }
//     }


    // error

    // ++ ,,, 第一次是 把返回的数组 当作 点的数组了。
    //  这次是 发现 求的是 结点0 到 结点n-1，  不是 结点0 到 其他结点。。。

    vector<bool> findAnswer_____e(int n, vector<vector<int>>& edges)
    {
        // vector<vector<pair<int, int>>> vvp(n);
        // for (int i = 0; i < edges.size(); ++i)
        // {
        //     vector<int>& e = edges[i];
        //     vvp[e[0]].push_back(std::make_pair(e[1], i));
        //     vvp[e[1]]
        // }

        vector<vector<tuple<int, int, int>>> vvt(n);
        for (int i = 0; i < edges.size(); ++i)
        {
            vector<int>& e = edges[i];
            vvt[e[0]].push_back(std::make_tuple(e[1], e[2], i));
            vvt[e[1]].push_back(std::make_tuple(e[0], e[2], i));
        }

        vector<int> vi(n, INT_MAX);

        // std::priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>> priq;
        // priq.push(std::make_pair(0, 0));
        // vector<bool> ans(edges.size(), false);
        // while (true)
        // {
        //     while (!priq.empty() && priq.top().first > vi[priq.top().second])
        //     {
        //         priq.pop();
        //     }
        //     if (priq.empty())
        //         break;
        //     pair<int, int> p
        // }

        vector<bool> ans(edges.size(), false);
        vi[0] = 0;

        // <length, node, edges>
        std::priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, std::greater<>> priq;
        priq.push(std::make_tuple(0, 0, -1));
        int a, b, c;
        int t2,t3,t4;
        while (true)
        {
            while (!priq.empty() && std::get<0>(priq.top()) > vi[std::get<1>(priq.top())])
                priq.pop();
            if (priq.empty())
                break;

            std::tie(a, b, c) = priq.top();
            priq.pop();
            if (c != -1)
                ans[c] = true;
            vi[b] = a;
            for (int i = 0; i < vvt[b].size(); ++i)
            {
                std::tie(t2,t3,t4) = vvt[b][i]; // nxt, weight, edge idx
                if (vi[t2] >= a + t3)
                {
                    vi[t2] = a + t3;        // .
                    priq.push(std::make_tuple(vi[t2], t2, t4));
                }
            }
        }

        return ans;
    }


    // error ...

    // Dijkstra
    // w > 0
    vector<bool> findAnswer__e(int n, vector<vector<int>>& edges)
    {
        vector<vector<pair<int, int>>> vvp(n);
        for (vector<int>& e : edges)
        {
            vvp[e[0]].push_back(std::make_pair(e[1], e[2]));
            vvp[e[1]].push_back(std::make_pair(e[0], e[2]));
        }
        vector<int> vi(n, INT_MAX);
        vector<bool> vb(n, false);
        // vb[0] = true;
        std::priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>> priq;       // <distance, node>
        priq.push(std::make_pair(0, 0));

        while (!priq.empty())
        {
            while (!priq.empty() && vb[priq.top().second])
            {
                priq.pop();
            }
            if (priq.empty())
                continue;

            pair<int, int> p = priq.top();
            priq.pop();
            vb[p.second] = true;

            for (pair<int, int>& nxt : vvp[p.second])
            {
                if (!vb[nxt.first] && vi[nxt.first] > p.first + nxt.second)
                {
                    vi[nxt.first] = p.first + nxt.second;
                    priq.push(std::make_pair(vi[nxt.first], nxt.first));
                }
            }
        }

        return vb;
    }
};

int main()
{

    LT3123 lt;

    int n {4};
    myvvi vv = {{2,0,1},{0,1,1},{0,3,4},{3,2,2}};

    vector<bool> vb = lt.findAnswer(n, vv);

    for (bool b : vb)
    {
        std::cout<<b<<", ";
    }
    std::cout<<endl;

    return 0;
}
