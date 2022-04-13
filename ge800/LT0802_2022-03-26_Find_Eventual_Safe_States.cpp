
#include "../header/myheader.h"

class LT0802
{
public:

// D D



//    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//        int n = graph.size();
//        seen.resize(n, 0);
//        vector<int> res;
//        for(int i = 0; i < n; i++)
//            if(find(i, graph))
//                res.push_back(i);
//
//        return res;
//    }
//
//    bool find(int curr, vector<vector<int>>& graph)
//    {
//        if(seen[curr] == 1) return true;
//        if(seen[curr] == 2) return false;
//
//        seen[curr] = 2;
//        for(int next : graph[curr])
//            if(!find(next, graph))
//                return false;
//
//        seen[curr] = 1;
//        return true;
//    }
// 先设置为2，如果遍历中遇到，则说明是环，就 return，不会设置为1。


//    bool dfs(vector<vector<int>>& graph, vector<int>& dp, int index){
//        if(dp[index]) return 1==dp[index];
//        dp[index] = -1;
//        for(auto& n: graph[index]) if(dfs(graph, dp, n)==false) return false;
//        return dp[index] = 1;
//    }



//Runtime: 352 ms, faster than 18.96% of C++ online submissions for Find Eventual Safe States.
//Memory Usage: 52.1 MB, less than 38.66% of C++ online submissions for Find Eventual Safe States.
// 找环，指向这个环的，都不行。
    vector<int> lt0802a(vector<vector<int>>& graph)
    {
        int sz1 = graph.size();
//        vector<bool> vb(sz1, false);            // reach circle
        vector<int> vi(sz1, 0);         // 0: unknow, 1: no circle, 2: circle ....  byte.
        unordered_set<int> set2;
        for (int i = 0; i < sz1; ++i)
        {
            dfsa1(graph, i, vi, set2);
        }
        vector<int> ans;
        for (int i = 0; i < sz1; ++i)
            if (vi[i] == 1)
                ans.push_back(i);
        return ans;
    }

    // return: is circle
    bool dfsa1(vector<vector<int>>& vvi, int node, vector<int>& vi, unordered_set<int>& set2)
    {
        if (vi[node] != 0)
        {
            return vi[node] == 2;
        }
        if (set2.find(node) != set2.end())
        {
            return true;
        }
        bool circle = false;
        set2.insert(node);
        for (int i = 0; i < vvi[node].size(); ++i)
        {
            if (dfsa1(vvi, vvi[node][i], vi, set2))
            {
                circle = true;
                break;
            }
        }
        set2.erase(node);
        vi[node] = circle ? 2 : 1;
        return circle;
    }

};

int main()
{

    LT0802 lt;

//    myvvi vv = {{1,2},{2,3},{5},{0},{5},{},{}};
    myvvi vv = {{1,2,3,4},{1,2},{3,4},{0,4},{}};

    myvi v = lt.lt0802a(vv);

    showVectorInt(v);

    return 0;
}
