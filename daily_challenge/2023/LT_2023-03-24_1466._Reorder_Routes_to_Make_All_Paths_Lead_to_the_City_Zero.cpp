
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //int dfs(vector<vector<int>>& al, int prev, int node) {
    //    return accumulate(begin(al[node]), end(al[node]), 0, [&](int sum, int to) {
    //        return sum + (abs(to) == prev ? 0 : dfs(al, node, abs(to)) + (to > 0));
    //        });
    //}
    //int minReorder(int n, vector<vector<int>>& connections) {
    //    vector<vector<int>> al(n);
    //    for (auto& c : connections) {
    //        al[c[0]].push_back(c[1]);
    //        al[c[1]].push_back(-c[0]);
    //    }
    //    return dfs(al, 0, 0);
    //}
    // 负数很6




    //Runtime371 ms
    //    Beats
    //    77.62 %
    //    Memory115 MB
    //    Beats
    //    54.54 %
    // tree，所以只有一条路，通往0.
    int lta(int n, vector<vector<int>>& connections)
    {
        vector<vector<int>> vvi(n);
        vector<vector<int>> vv2(n);
        for (vector<int>& vi : connections)
        {
            vvi[vi[0]].push_back(vi[1]);
            vv2[vi[1]].push_back(vi[0]);
        }

        int ans = dfsa1(vvi, vv2, 0, -1);
        return ans;
    }

    int dfsa1(vector<vector<int>>& vvi, vector<vector<int>>& vv2, int node, int parent)
    {
        int ans = 0;
        for (int nxt : vvi[node])
        {
            ans += parent == nxt ? 0 : (1 + dfsa1(vvi, vv2, nxt, node));
        }
        for (int nxt : vv2[node])
        {
            ans += parent == nxt ? 0 : (0 + dfsa1(vvi, vv2, nxt, node));
        }
        return ans;
    }

};

int main()
{

    LT lt;

    int n = 6;
    myvvi vv = { {0,1},{1,3},{2,3},{4,0},{4,5} };

    cout << lt.lta(n, vv) << endl;

    return 0;
}
