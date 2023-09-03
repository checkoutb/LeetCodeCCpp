
#include "../../header/myheader.h"

class LT100018
{
public:



// 2268 / 27495	Ouha 	12	1:55:52	0:08:31 	0:19:48 1	1:25:52 5

// g .. tarjan.

    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges,
        vector<vector<int>>& queries)
    {
        vector<vector<int>> vvi(n, vector<int>(27, 0));
        vector<vector<int>> vv2(n);     // <node, weight>
        for (int i = 0; i < edges.size(); ++i)
        {
            vv2[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            vv2[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        dfsa1(vv2, vvi, 0, 0, 0);
    }

    // 1<<0  find a,   1<<1  find b
    // tle?
    // yao yong tarjan de , wo ...
    int lca(vector<vector<int>>& vv2, int node, int parent, int a, int b)
    {
        if (node == a)
        {

        }
    }

    void dfsa1(vector<vector<int>>& vv2, vector<vector<int>>& vvi, int node, int parent, int edge)
    {
        for (int i = 1; i <= 26; ++i)
        {
            vvi[node][i] = vvi[parent][i];
        }
        ++vvi[node][edge];

        for (vector<int>& vi : vv2[node])
        {
            if (vi[0] == parent)
                continue;

            dfsa1(vv2, vvi, vi[0], node, vi[1]);
        }
    }

};

int main()
{

    LT100018 lt;


    return 0;
}
