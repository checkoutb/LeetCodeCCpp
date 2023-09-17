
#include "../../header/myheader.h"

class LT
{
public:

    // D D



    //Runtime115 ms
    //    Beats
    //    25.10 %
    //    Memory21.8 MB
    //    Beats
    //    19.74 %

    // tle...
    // n <= 12
    int shortestPathLength(vector<vector<int>>& graph)
    {
        int ans = INT_MAX;
        for (int i = 0; i < graph.size(); ++i)
        {
            ans = min(ans, bfs(graph, i));
        }
        return ans;
    }

    //int dfsa1(vector<vector<int>>& vvi, int node, int flg, vector<vector<int>>& vv2)
    //{
    //    if (vv2[node][flg] != -1)
    //        return vv2[node][flg];

    //    for (int nxt : vvi[node])
    //    {

    //    }
    //}

    // tle
    int bfs(vector<vector<int>>& vvi, int node)
    {
        queue<tuple<int, int, int>> que;
        que.push(std::make_tuple(node, 1 << node, 0));
        const int ALL = (1 << vvi.size()) - 1;

        vector<vector<bool>> vv2(vvi.size(), vector<bool>(ALL + 1, false));     // ACCEPT
        vv2[node][1 << node] = true;

        while (!que.empty())
        {
            auto [nd, flg, stp] = que.front();
#ifdef __test
            //cout << que.size() << endl;
            //cout << nd << ", " << flg << ", " << stp << " - " << (vvi.size() * 2 - 1) << endl;
#endif
            que.pop();
            if (flg == ALL)
            {
                return stp;
            }
            if (stp >= vvi.size() * 2 - 1)
                continue;       // tle

            for (int nxt : vvi[nd])
            {
                if (vv2[nxt][flg | (1 << nxt)] == false)
                {
                    que.push(make_tuple(nxt, flg | (1 << nxt), stp + 1));
                    vv2[nxt][flg | (1 << nxt)] = true;
                }
            }
        }
        return INT_MAX;
    }

};

int main()
{

    LT lt;

    //myvvi vv = { {1,2,3},{0},{0},{0} };
    myvvi vv = { {2,3,5,7},{2,3,7},{0,1},{0,1},{7},{0},{10},{9,10,0,1,4},{9},{7,8},{7,6} };

    cout << lt.shortestPathLength(vv) << endl;

    return 0;
}
