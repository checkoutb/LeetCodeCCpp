
#include "../header/myheader.h"

class LT1443
{
public:

// D D

//    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
//        std::vector<std::vector<int>> adj(n);
//        std::vector<bool> visited(n, false);
//        for(const auto &e: edges) adj[e[0]].emplace_back(e[1]), adj[e[1]].emplace_back(e[0]);
//        auto [s, _]{dfs(0, adj, visited, hasApple)};
//        return s;
//    }
//    static std::pair<int,bool> dfs(int i, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited, std::vector<bool>& hasApple) {
//        int sum{0};
//        bool apple{hasApple[i]};
//        visited[i] = true;
//        for(const auto &n: adj[i]) {
//            if(visited[n]) continue;
//            auto [s, a]{dfs(n, adj, visited, hasApple)};
//            apple |= a;
//            if(a) sum += 2+s;
//        }
//        return {sum, apple};
//    }
// ....  _ 这人肯定会python。。。




// 或者bfs 把树梳理一遍。确保 不能出现 子结点指向父结点的情况。
//Runtime: 368 ms, faster than 41.90% of C++ online submissions for Minimum Time to Collect All Apples in a Tree.
//Memory Usage: 69.2 MB, less than 32.39% of C++ online submissions for Minimum Time to Collect All Apples in a Tree.
    int lt1443a(int n, vector<vector<int>>& edges, vector<bool>& hasApple)
    {
        unordered_map<int, vector<int>> map2;       // node : {childs};
        for (vector<int>& vi : edges)
        {
            map2[vi[0]].push_back(vi[1]);
            map2[vi[1]].push_back(vi[0]);
        }
        int ans = dfsa1(map2, 0, hasApple, -1);
        return max(0, ans);
    }

    int dfsa1(unordered_map<int, vector<int>>& map2, int val, vector<bool>& vb, int parent)
    {
        if (map2.find(val) == map2.end())
            return vb[val] ? 0 : -1;
        vector<int>& childs = map2[val];
        int ans = 0;
        for (int i : childs)
        {
            if (i == parent)
                continue;
            int t1 = dfsa1(map2, i, vb, val);
            if (t1 >= 0)
                ans += (t1 + 2);
        }
        if (ans != 0)
            return ans;
        return vb[val] ? 0 : -1;
    }

};

int main()
{
//    vector<vector<int>> vv = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
//    vector<bool> vb = {false,false,true,false,false,true,false};
//    int n{7};

    int n{7};
    vector<vector<int>> vv = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
    vector<bool> vb = {false,false,false,false,false,false,false};

//    int n{4};
//    vector<vector<int>> vv = {{0,2},{0,3},{1,2}};
//    vector<bool> vb = {false,true,false,false};         // 4


    LT1443 lt;

    cout<<lt.lt1443a(n, vv, vb);

    return 0;
}
