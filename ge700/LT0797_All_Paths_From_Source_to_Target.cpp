
#include "../header/myheader.h"

class LT0797
{
public:


// Discuss
//    void dfs(vector<vector<int>>& g, vector<vector<int>>& res, vector<int>& path, int cur) {
//        path.push_back(cur);
//        if (cur == g.size() - 1)
//            res.push_back(path);
//        else for (auto it: g[cur])
//            dfs(g, res, path, it);
//        path.pop_back();
//    }
// else for
// vector<int>& path



//Runtime: 36 ms, faster than 85.39% of C++ online submissions for All Paths From Source to Target.
//Memory Usage: 15.4 MB, less than 60.00% of C++ online submissions for All Paths From Source to Target.
    vector<vector<int>> lt0797a(vector<vector<int>>& graph)
    {
        vector<vector<int>> ans;        // 不能带()...
        vector<int> passed;
        dfsa1(graph, 0, passed, ans);
        return ans;
    }

    void dfsa1(vector<vector<int>>& graph, int i, vector<int> passed, vector<vector<int>>& ans)
    {
        passed.push_back(i);
        if (i == graph.size() - 1)
            ans.push_back(passed);

        for (int j : graph[i])
        {
            dfsa1(graph, j, passed, ans);
        }
    }

};

int main()
{
    vector<vector<int>> vv = {{1,2},{3},{3},{}};

    LT0797 lt;

    vector<vector<int>> ans = lt.lt0797a(vv);

    for (vector<int> v : ans)
    {
        for (int i : v)
        {
            cout<<i<<", ";
        }
        cout<<endl;
    }

    return 0;
}
