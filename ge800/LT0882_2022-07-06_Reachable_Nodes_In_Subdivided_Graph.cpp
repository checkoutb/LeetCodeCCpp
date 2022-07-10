
#include "../header/myheader.h"

class LT0882
{
public:

    // D
    
    // Dijkstra ...

    

    // tle¡£¡£¡£
    int lt0882a(vector<vector<int>>& edges, int maxMoves, int n)
    {
        unordered_map<int, vector<int>> map2;

        for (int i = 0; i < edges.size(); ++i)
        {
            map2[edges[i][0]].push_back(i);
            map2[edges[i][1]].push_back(i);
        }

        vector<int> vst(n, -1);
        //vector<int> mx(edges.size());
        //vst[0] = maxMoves;
        vector<vector<int>> mx(2, vector<int>(edges.size()));

        dfsa1(edges, map2, vst, mx, maxMoves, 0, -1);

        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (vst[i] != -1)
                ans++;
        for (int i = 0; i < mx[0].size(); ++i)
            ans += min(mx[0][i] + mx[1][i], edges[i][2]);

#ifdef __test
        showVectorInt(vst);
        showVectorInt(mx[0]);
        showVectorInt(mx[1]);
#endif

        return ans;
    }

    void dfsa1(vector<vector<int>>& vvi, unordered_map<int, vector<int>>& map2, vector<int>& vst, vector<vector<int>>& mx, int moves, int node, int parent)
    {
#ifdef __test
        cout << " -- " << node << ", " << moves << endl;
#endif
        if (vst[node] >= moves)
            return;
        vst[node] = moves;

        for (int idx : map2[node])
        {
            vector<int> p = getNodeCnt(vvi, node, idx);
            int mxidx = p[0];
            int nxt = p[1];

            if (nxt == parent)
                continue;

            int cnt = p[2];
            mx[mxidx][idx] = max(mx[mxidx][idx], min(moves, cnt));
            //moves -= cnt;
            //moves--;
            dfsa1(vvi, map2, vst, mx, moves - cnt - 1, nxt, node);
        }

    }

    vector<int> getNodeCnt(vector<vector<int>>& vvi, int st, int idx)
    {
        vector<int>& vi = vvi[idx];
        if (vi[0] == st)
            return {0, vi[1], vi[2]};
        else
            return {1, vi[0], vi[2]};
    }

};

int main()
{

    LT0882 lt;

    //myvvi vv = { {0,1,10},{0,2,1},{1,2,2} };
    //int m = 6, n = 3;

    //myvvi vv = { {0,1,4},{1,2,6},{0,2,8},{1,3,1} };
    //int m = 10, n = 4;

    //myvvi vv = { {1,3,2},{4,2,3},{4,2,1} };
    //int m = 123, n = 123;

    //myvvi vv = { {2, 4, 2},{3, 4, 5},{2, 3, 1},{0, 2, 1},{0, 3, 5} };
    //int m = 14;
    //int n = 5;

    myvvi vv = { {1, 2, 5},{0, 3, 3},{1, 3, 2},{2, 3, 4},{0, 4, 1} };       // 13
    int m = 7;
    int n = 5;

    //myvvi vv = { {1, 2, 4},{1, 4, 5},{1, 3, 1},{2, 3, 4},{3, 4, 5} };
    //int m = 17;
    //int n = 5;


    cout << lt.lt0882a(vv, m, n) << endl;

    return 0;
}
