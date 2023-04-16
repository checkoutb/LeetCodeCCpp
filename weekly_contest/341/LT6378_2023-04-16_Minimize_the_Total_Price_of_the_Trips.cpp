
#include "../../header/myheader.h"

class LT6378
{
public:


    // 536 / 15130	Ouha 	17	0:56:06	0:02:49 	0:14:58 2	0:22:46 1	0:41:06
    // 265	Ouha  	17	0:56:06	0:02:49 	0:14:58 2	0:22:46 1	0:41:06
    // 不知道最终是哪个。


    // AC
    // 
    //  User Accepted: 186
    //  User Tried : 435
    //    Total Accepted : 195
    //    Total Submissions :
    // 
    // 可惜，第二道，第三道错了几次。不知道罚完时后，会多少。
    // 
    // 不相邻的节点 可以 半价。
    // 无环 ， 路径只有一条吧。
    int lta(int n, 
        vector<vector<int>>& edges, 
            vector<int>& price, 
                vector<vector<int>>& trips)
    {

        int sz1 = edges.size();

        vector<vector<int>> vvi(n, vector<int>());

        for (int i = 0; i < sz1; ++i)
        {
            vvi[edges[i][0]].push_back(edges[i][1]);
            vvi[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> vi(n, 0);
        for (int i = 0; i < trips.size(); ++i)
        {
            dfsa1(vvi, trips[i][0], -1, vi, trips[i][1]);
        }

        pair<int, int> p = dfsa2(vvi, 0, -1, vi, price);

        return min(p.first, p.second);
    }

    // half
    // return <if node half, if node not half>
    pair<int, int> dfsa2(vector<vector<int>>& vvi, int node, int parent, vector<int>& vi, vector<int>& price)
    {
        int hf = price[node] / 2 * vi[node];     // node is half
        int al = price[node] * vi[node];     // node is not half

        for (int nxt : vvi[node])
        {
            if (nxt == parent)
                continue;

            pair<int, int> p = dfsa2(vvi, nxt, node, vi, price);
            hf += p.second;
            al += min(p.first, p.second);
        }

        return make_pair(hf, al);
    }

    // travel
    bool dfsa1(vector<vector<int>>& vvi, int node, int parent, vector<int>& vi, int tar)
    {
        if (node == tar)
        {
            ++vi[tar];
            return true;
        }

        for (int nxt : vvi[node])
        {
            if (nxt == parent)
                continue;

            if (dfsa1(vvi, nxt, node, vi, tar))
            {
                ++vi[node];
                return true;
            }
        }
        return false;
    }

};

int main()
{

    LT6378 lt;

    int n = 4;
    myvvi vv = { {1,0},{1,2},{1,3} };
    myvi vi = { 2,2,10,6 };
    myvvi vv2 = { {0,3},{2,1},{2,3} };


    cout << lt.lta(n, vv, vi, vv2) << endl;

    return 0;
}
