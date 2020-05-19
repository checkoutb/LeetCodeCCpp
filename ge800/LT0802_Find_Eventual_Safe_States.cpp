
#include "../header/myheader.h"

class LT0802
{
public:





// 91 / 111. tle.
// 有环就不行
    vector<int> lt0802a(vector<vector<int>>& graph)
    {
        set<int> cycle;
        vector<int> passed;
        vector<int> ans;
        for (int i = 0; i < graph.size(); i++)
        {
            dfsa1(graph, passed, i, cycle, ans);
            if (cycle.find(i) == cycle.end())
                ans.push_back(i);
        }
//        vector<int> ans(graph.size() - cycle.size(), 0);
//        int j = 0;
//        for (int i = 0; i < graph.size(); i++)
//        {
//            if (cycle.find(i) == cycle.end())
//            {
//                ans[j++] = i;
//            }
//        }
        return ans;
    }

    void dfsa1(vector<vector<int>>& graph, vector<int>& passed, int now, set<int>& cycle, vector<int>& ans)
    {
        if (cycle.count(now))
        {
            cycle.insert(passed.begin(), passed.end());
            return;
        }
        for (int i : ans)
        {
            if (i == now)
                return;
        }
        for (int i : passed)
        {
            if (now == i)
            {
                cycle.insert(passed.begin(), passed.end());
                return;
            }
        }
        passed.push_back(now);
        for (int i : graph[now])
        {
            dfsa1(graph, passed, i, cycle, ans);
        }
        passed.pop_back();
    }
};

int main()
{

    vector<vector<int>> g = {{1,2},{2,3},{5},{0},{5},{},{}};

    LT0802 lt;

    vector<int> ans = lt.lt0802a(g);

    for_each(ans.begin(), ans.end(), fun_cout);
    cout<<endl;

    return 0;
}
