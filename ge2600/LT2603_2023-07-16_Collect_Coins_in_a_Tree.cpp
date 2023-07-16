
#include "../header/myheader.h"

class LT2603
{
public:


// g




// tree, huidao yuandian
// 2dian la zhixian, ranhou cong di xiang shang.
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges)
    {
        int sz1 = coins.size();
        vector<vector<int>> vvi(sz1);
        for (int i = 0; i < edges.size(); ++i)
        {
            vvi[edges[i][0]].push_back(edges[i][1]);
            vvi[edges[i][1]].push_back(edges[i][0]);
        }
        int sum2 = std::accumulate(begin(coins), end(coins), 0);
        pair<int, int> p = dfsa1(coins, vvi, 3, -1, 0, sum2);
        return p.second;
    }

    // <node count, length>
    pair<int, int> dfsa1(vector<int>& coins, vector<vector<int>>& vvi, int node, int parent, int depth, int sumCoin)
    {
        int cnt = 0;
        int len = 0;
        int t2 = 0;         // sub-tree that contain coin
        vector<int> vi;
        for (int nxt : vvi[node])
        {
            if (nxt == parent)
                continue;

            pair<int, int> p2 = dfsa1(coins, vvi, nxt, node, depth + 1, sumCoin);
            if (p2.first != 0)
            {
                ++t2;
                cnt += p2.first;
                vi.push_back(p2.second);
//                len = p2.second;
            }
        }
        if (cnt == sumCoin && t2 == 1)
            return std::make_pair(cnt, vi[0]);

        if (vi.size() == 1)
        {
            len = vi[0] + 2;
        }
        else if (vi.size() > 1)
        {
            for (int i = 0; i < vi.size(); ++i)
            {
                len += max(0, vi[i] + 2);
            }
        }
        if (coins[node] == 1)
        {
            cnt++;
            if (cnt == 1)
            {
                len = -4;
            }
        }
        return std::make_pair(cnt, len);
    }

};

int main()
{

    LT2603 lt;

    myvi v = {1,0,0,0,0,1};
    myvvi vv = {{1,0},{1,2},{2,3},{3,4},{4,5}};

    cout<<lt.collectTheCoins(v, vv)<<endl;

    return 0;
}
