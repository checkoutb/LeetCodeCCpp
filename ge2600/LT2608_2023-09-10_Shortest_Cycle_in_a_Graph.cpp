
#include "../header/myheader.h"

class LT2608
{
public:



    // g


    int findShortestCycle(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> vvi(n);
        for (vector<int>& vi : edges)
        {
            vvi[vi[0]].push_back(vi[1]);
            vvi[vi[1]].push_back(vi[0]);
        }
        vector<int> vi(n, -1);
    }

    int dfsa1(vector<vector<int>>& vvi, int node, int parent, vector<int>& vi, int len)
    {
        if (vi[node] != -1)
        {
            return len - vi[node];
        }
        vi[node] = len;
        int ans = INT_MAX;
        for (int chd : vvi[node])
        {
            if (chd == parent)
                continue;
            int t2 = dfsa1(vvi, chd, node, vi, len + 1);
            ans = min(ans, t2);
        }
        return ans;
    }
};

int main()
{

    LT2608 lt;


    return 0;
}
