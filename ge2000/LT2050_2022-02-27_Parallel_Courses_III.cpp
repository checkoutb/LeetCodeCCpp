
#include "../header/myheader.h"

class LT2050
{
public:


// D D

// 有set3以后 就不需要set2了。

//        for (auto &e : E) G[e[1] - 1].push_back(e[0] - 1);
//        function<int(int)> dfs = [&](int u) {
//            if (dist[u]) return dist[u];
//            int mx = 0;
//            for (int v : G[u]) mx = max(mx, dfs(v));
//            return dist[u] = mx + T[u];
//        };
//        for (int i = 0; i < n; ++i) dfs(i);



//Runtime: 683 ms, faster than 41.13% of C++ online submissions for Parallel Courses III.
//Memory Usage: 163.9 MB, less than 5.07% of C++ online submissions for Parallel Courses III.
// <前置课程，后置课程>
// 谁没有出现在前置中？
    int lt2050a(int n, vector<vector<int>>& relations, vector<int>& time)
    {
        vector<vector<int>> rerel(n + 1, vector<int>());        // 后置 - 前置
        unordered_set<int> set2;
        unordered_set<int> set3;
        for (vector<int>& vi : relations)
        {
            rerel[vi[1]].push_back(vi[0]);
            set2.insert(vi[0]);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (set2.find(i) == end(set2))
            {
                ans = max(ans, dfsa2050(rerel, time, i, set3));
            }
        }
        #ifdef __test
        showVectorInt(time);
        for (int i = 0; i <= n; i++)
        {
            cout<<i<<": ";
            for (int a : rerel[i])
            {
                cout<<a<<", ";
            }
            cout<<endl;
        }
        #endif // __test
//        int ans = *max_element(begin(time), end(time));
        return ans;
    }

    int dfsa2050(vector<vector<int>>& rerel, vector<int>& time, int cur, unordered_set<int>& set3)
    {
        if (rerel[cur].size() == 0 || set3.find(cur) != end(set3))
        {
            return time[cur - 1];
        }
        int mx = 0;
        for (int i : rerel[cur])
        {
            mx = max(mx, dfsa2050(rerel, time, i, set3));
        }
        set3.insert(cur);
        time[cur - 1] += mx;
        return time[cur - 1];
    }


};

int main()
{

    LT2050 lt;

//    myvvi vv = {{1,3},{2,3}};
//    myvi v = {3,2,5};
//    int n = 3;

//    myvvi vv = {{1,5},{2,5},{3,5},{3,4},{4,5}};
//    myvi v = {1,2,3,4,5};
//    int n = 5;

    int n = 9;      // 32
    myvvi vv = {{2,7},{2,6},{3,6},{4,6},{7,6},{2,1},{3,1},{4,1},{6,1},{7,1},{3,8},{5,8},{7,8},{1,9},{2,9},{6,9},{7,9}};
    myvi v = {9,5,9,5,8,7,7,8,4};


    cout<<lt.lt2050a(n, vv, v)<<endl;

    return 0;
}
