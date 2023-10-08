
#include "../header/myheader.h"

class LT2858
{
public:





//Runtime453 ms
//Beats
//75.76%
//Memory243.8 MB
//Beats
//41.72%
    // heng you yi si, 树左旋，右旋，只修改了一条边
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> vvi(n);     // bi-direct
        vector<set<int>> vsi(n);        // direct
        for (vector<int>& vi : edges)
        {
            vvi[vi[0]].push_back(vi[1]);
            vvi[vi[1]].push_back(vi[0]);
            vsi[vi[0]].insert(vi[1]);
        }
        int t2 = dfsa1(vvi, 0, -1, vsi);
        vector<int> ans(n, 0);
        dfsa2(vvi, 0, -1, vsi, t2, ans);
        return ans;
    }

    void dfsa2(vector<vector<int>>& vvi, int node, int parent, vector<set<int>>& vsi, int cnt, vector<int>& ans)
    {
        ans[node] = cnt;
        for (int nxt : vvi[node])
        {
            if (nxt == parent)
                continue;
            int t2 = 0;
            if (vsi[node].find(nxt) == vsi[node].end())
            {
                t2 = cnt - 1;           // ... cnt -= 1
            }
            else
            {
                t2 = cnt + 1;
            }
            dfsa2(vvi, nxt, node, vsi, t2, ans);
        }
    }

    int dfsa1(vector<vector<int>>& vvi, int node, int parent, vector<set<int>>& vsi)
    {
        int ans = 0;
        for (int nxt : vvi[node])
        {
            if (nxt == parent)
                continue;
            if (vsi[node].find(nxt) == vsi[node].end())
            {
                ++ans;
            }
            ans += dfsa1(vvi, nxt, node, vsi);
        }
        return ans;
    }


};

int main()
{

    LT2858 lt;


    return 0;
}
