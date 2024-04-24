
#include "../../header/myheader.h"

class LT
{
public:

    // D D

        // while(!q.empty())
        // {
        //     int size = q.size();
        //     ans.clear(); // We write it at top so that we can take fresh nodes with us from below!
        //     while(size--)
        //     {
        //         int curr = q.front();
        //         q.pop();
        //         ans.push_back(curr);
        //         for(auto child : adj[curr])
        //         { //For each node, attached to the leaf nodes, we decrement the indegree i.e remove the leaf nodes connected to them. We keep on doing this until we reach the middle nodes.
        //             indegree[child]--;
        //             if(indegree[child]==1)
        //             {
        //                 q.push(child);
        //             }
        //         }
        //     }
        // }
    //
    // 无限移除叶子结点，直到最后1/2个结点。 。。。!!!!!!!!!!!!




// Runtime
// 167ms
// Beats20.02%of users with C++
// Memory
// 72.92MB
// Beats23.09%of users with C++

    // 1. 最长路径的中点
    // 2. 把root向最深的子树移动
    // 3. vector<map<parent, max-depth>>
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        if (n == 1)
            return {0};
        if (n == 2)
            return {0, 1};

        vector<vector<int>> vvi(n);
        for (vector<int>& vi : edges)
        {
            vvi[vi[0]].push_back(vi[1]);
            vvi[vi[1]].push_back(vi[0]);
        }

        int root = -1;
        for (int i = 0; i < n; ++i)
        {
            if (vvi[i].size() > 1)
            {
                root = i;
                break;
            }
        }

        std::pair<int, int> longest;
        vector<vector<pair<int, int>>> vvp(n);

        dfsa1(vvi, root, -1, longest, vvp);

        int mxlen = longest.first;
        int mxn = longest.second;
        vector<int> ans;

        int t2 = vvp[mxn][0].first - vvp[mxn][1].first;

        // 8 | 4   13
        // 4/2  2     6 | 6
        // 8 | 5   14
        // 3/2  1    7 | 6
        // 7 | 1  9
        // 6/2  3    4 | 4
        // 8 | 1  9
        // 7/2  3    5 | 4

        int t3 = t2 / 2;
        int node = mxn;
        while (t3 > 0)
        {
            --t3;
            node = vvp[node][0].second;
        }
        ans.push_back(node);
        if (mxlen % 2 == 0)
        {
            ans.push_back(vvp[node][0].second);
        }

        return ans;
    }

    // return max-depth
    int dfsa1(vector<vector<int>>& vvi, int node, int parent, pair<int, int>& longest, vector<vector<pair<int, int>>>& vvp)
    {
        if (vvi[node].size() == 1)
            return 1;

        for (int nxt : vvi[node])
        {
            if (nxt == parent)
                continue;
            int t2 = dfsa1(vvi, nxt, node, longest, vvp);
            vvp[node].push_back(std::make_pair(t2, nxt));
        }
        sort(std::rbegin(vvp[node]), rend(vvp[node]));
        if (vvp[node].size() > 1 && vvp[node][0].first + vvp[node][1].first + 1 > longest.first)
        {
            longest.first = vvp[node][0].first + vvp[node][1].first + 1;
            longest.second = node;
        }
        return vvp[node][0].first + 1;
    }


};

int main()
{

    LT lt;

    int n {4};
    myvvi vv {{1,0},{1,2},{1,3}};

    myvi v {lt.findMinHeightTrees(n, vv)};

    showVectorInt(v);

    return 0;
}
