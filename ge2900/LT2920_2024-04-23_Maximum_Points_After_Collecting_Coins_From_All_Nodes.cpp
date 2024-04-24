
#include "../header/myheader.h"

class LT2920
{
public:








// Runtime
// 424ms
// Beats60.00%of users with C++
// Memory
// 208.28MB
// Beats39.50%of users with C++


    // + (coin[i] - k)
    // or + (coin[i] / 2) , and subtree's coin all will /2
    //
    // if subtree's coin sum < k * subtree node count,  just / 2
    // if coin[i] > k,   choose 1
    //
    // /2 will lose how much, is < k ?
    //
    // /2, coin<10^5,  so 2^14 ?   depth-diff > 14, always 0
    // 是不是一旦 除以2， 下层就 必然/2 ？

    // hint 1: Let dp[x][t] be the maximum points we can get from the subtree rooted at node x and the second operation has been used t times in its ancestors.
    // ...

    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k)
    {
        int sz1 = coins.size();
        vector<vector<int>> vvi(sz1);
        for (vector<int>& vi : edges)
        {
            vvi[vi[0]].push_back(vi[1]);
            vvi[vi[1]].push_back(vi[0]);
        }
        vector<vector<int>> vv2(sz1, vector<int>(15, -1));

        dfsa1(vvi, vv2, 0, -1, coins, k, 0);

        return vv2[0][0];
    }

    int dfsa1(vector<vector<int>>& vvi, vector<vector<int>>& vv2, int node, int parent, vector<int>& coins, int k, int shl)
    {
        if (shl == vv2[node].size())
            return 0;
        if (vv2[node][shl] != -1)
            return vv2[node][shl];

        int t2 = coins[node] >> shl;
        int ans = t2 - k;
        // no >>
        for (int nxt : vvi[node])
        {
            if (nxt == parent)
                continue;
            ans += dfsa1(vvi, vv2, nxt, node, coins, k, shl);
        }

        // >> 1
        int t3 = t2 >> 1;
        for (int nxt : vvi[node])
        {
            if (nxt == parent)
                continue;

            t3 += dfsa1(vvi, vv2, nxt, node, coins, k, shl + 1);
        }

        ans = max(ans, t3);
        vv2[node][shl] = ans;

        return ans;

//         int t2 = coins[node];
//         for (int i = 0; i < vv2[node].size(); ++i)
//         {
//             if (vv2[node][i] == -1)
//                 vv2[node][i] = 0;
//
//             vv2[node][i] += t2 - k;
//
//
//
//             t2 >>= 1;
//             if (parent != -1 && vv2[parent][i] == -1)
//                 break;
//         }

//         for (int nxt : vvi[node])
//         {
//             if (nxt == parent)
//                 continue;
//
//             int t2 = coins[node];
//             for (int i = 0; i < vv2[0].size(); ++i)
//             {
//
//
//                 t2 >>= 1;
//                 if (vv2[parent][i] == -1)
//                     break;
//             }
//
//         }
    }
};

int main()
{

    LT2920 lt;


    return 0;
}
