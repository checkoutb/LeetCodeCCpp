
#include "../header/myheader.h"

class LT2608
{
public:



// 碰到有len 的就直接计算出长度了，因为是 for-each，所以如果是 Q，那么总有计算 O 的时候的。

// g

    // tle ...
    // hint: bfs + for-each
    int findShortestCycle(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> vvi(n);
        for (vector<int>& vi : edges)
        {
            vvi[vi[0]].push_back(vi[1]);
            vvi[vi[1]].push_back(vi[0]);
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            if (vvi[i].size() <= 1)
                continue;

//            que1.clear();
            queue<vector<int>> que1;
            que1.push(vector<int>{i, -1, 0});
            vector<bool> vb(n, false);
            vb[i] = true;
            while (!que1.empty())
            {
                int node = que1.front()[0];
                int parent = que1.front()[1];
                int len = que1.front()[2];
                if (len >= ans)
                    break;

                que1.pop();
                if (node == i && len != 0)
                {
                    ans = min(ans, len);
                    break;
                }
                for (int nxt : vvi[node])
                {
                    if (!vb[nxt])
                    {
                        que1.push(vector<int>{nxt, node, len + 1});
                        vb[nxt] = true;
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }

};

int main()
{

    LT2608 lt;

    int n = 7;
    myvvi vv = {{1,0},{1,2},{2,0},{3,4},{4,5},{5,6},{6,3}};

    cout<<lt.findShortestCycle(n, vv)<<endl;

    return 0;
}
