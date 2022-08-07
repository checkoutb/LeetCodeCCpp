
#include "../../header/myheader.h"

class LT6139
{
public:



    // AC
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_set<int> set2(begin(restricted), end(restricted));
        unordered_map<int, vector<int>> map2;
        for (vector<int>& vi : edges)
        {
            if (set2.find(vi[0]) != set2.end() || set2.find(vi[1]) != set2.end())
                continue;
            map2[vi[0]].push_back(vi[1]);
            map2[vi[1]].push_back(vi[0]);
        }
        int ans = 1;
        vector<bool> vst(n, false);
        vst[0] = true;
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            if (map2.find(node) != map2.end())
            {
                for (int nxt : map2[node])
                {
                    if (!vst[nxt])
                    {
                        q.push(nxt);
                        ans++;
                        vst[nxt] = true;
                    }
                }
            }
        }
        return ans;
    }

};

int main()
{

    LT6139 lt;

    int n = 7;
    myvvi vv = { {0,1},{1,2},{3,1},{4,0},{0,5},{5,6} };
    myvi v = { 4,5 };


    cout << lt.reachableNodes(n, vv, v) << endl;

    return 0;
}
