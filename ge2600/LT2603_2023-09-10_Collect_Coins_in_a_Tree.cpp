
#include "../header/myheader.h"

class LT2603
{
public:

    // D

    // bfs



    // g



    // 0
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges)
    {
        int cnt = std::reduce(begin(coins), end(coins));
        int sz1 = coins.size();
        vector<vector<int>> vvi(sz1);
        for (vector<int>& vi : edges)
        {
            vvi[vi[0]].push_back(vi[1]);
            vvi[vi[1]].push_back(vi[0]);
        }
        int ans = dfsa1(vvi, 0, -1, cnt, coins);
        return ans;
    }

    // odd: none.  even: length*2
    // -4
    int dfsa1(vector<vector<int>>& vvi, int node, int parent, int& cnt, vector<int>& coins, int dis2par)
    {
        if (cnt == 0)
            return 1;

        if (coins[node])
            --cnt;

        int t3 = -10;       // max length
        int t4 = 0;
        for (int chd : vvi[node])
        {
            if (chd == parent)
                continue;

            int t2 = dfsa1(vvi, chd, node, cnt, coins);
            if (t2 == 1)
            {
                continue;
            }
            t3 = max(t2, t3);
            if (t2 >= -2)
            {
                t4 += t2 + 2;
            }
        }
        if (t3 == -10)
        {
            if (coins[node] == 1)
            {
                return -4;
            }
            else
                return 1;
        }
        else if (t3 <= -2)  // -4, -2
        {
            if (dis2par < 0)
            {

            }
            return t3 + 2;
        }
        else
        {
            return t4;
        }
    }
};

int main()
{

    LT2603 lt;
    myvi v = { 1,0,0,0,0,1 };
    myvvi vv = { {1,0},{1,2},{2,3},{3,4},{4,5} };


    //myvi v = { 0,0,0,1,1,0,0,1 };
    //myvvi vv = { {0,1},{0,2},{1,3},{1,4},{2,5},{5,6},{5,7} };

    cout << lt.collectTheCoins(v, vv) << endl;
    return 0;
}
