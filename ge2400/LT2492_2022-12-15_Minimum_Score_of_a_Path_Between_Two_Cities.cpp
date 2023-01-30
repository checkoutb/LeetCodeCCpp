
#include "../header/myheader.h"

class LT2492
{
public:

    // D D

    // uf


    //vector<bool> vis(n + 1, false);
    //queue<int> q;
    //q.push(1);
    //vis[1] = true;
    //while (!q.empty()) {
    //    int x = q.front();
    //    q.pop();
    //    for (auto i : graph[x]) {
    //        res = min(res, i.second);                            // 放外面。
    //        if (vis[i.first] != 1) {
    //            vis[i.first] = 1;
    //            q.push(i.first);
    //        }
    //    }
    //}



    //Runtime469 ms
    //    Beats
    //    94.81 %
    //    Memory127.3 MB
    //    Beats
    //    68.88 %
    // 连通分量中最小edge。
    int lt2492a(int n, vector<vector<int>>& roads)
    {
        int ans = INT_MAX;
        int sz1 = roads.size();
        vector<vector<pair<int, int>>> vvp(n + 1);

        for (vector<int>& vi : roads)
        {
            vvp[vi[0]].push_back(std::make_pair(vi[1], vi[2]));
            vvp[vi[1]].push_back(std::make_pair(vi[0], vi[2]));
        }

        vector<bool> vst(n + 1);
        //vst[1] = true;
        queue<int> que1;
        que1.push(1);

        while (!que1.empty())
        {
            int t2 = que1.front();
            que1.pop();
            if (vst[t2])
                continue;
            //for (pair<int, int> pii : vvp[t2])
            for (auto [nxt, dis] : vvp[t2])
            {
                //if (vst[nxt] == false)
                {
                    ans = min(ans, dis);
                    //vst[nxt] = true;
                    que1.push(nxt);
                }
            }

            vst[t2] = true;
        }

        return ans;
    }

};

int main()
{

    LT2492 lt;


    return 0;
}
