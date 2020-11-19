
#include "../header/myheader.h"

class LT1376
{
public:

// D D

//        int A = 0, dp[n];
//        memset(dp, 0, sizeof(dp));


//vector<vector<int>> children;
// not map.


//informTime[n] += dfs( manager[n], manager, informTime );
// dp


//int dfs(int i, vector<vector<int>> &m, vector<int>& informTime, int mx = 0) {
//    for (auto d : m[i])
//        mx = max(mx, dfs(d, m, informTime));
//    return informTime[i] + mx;
//}
//int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
//    vector<vector<int>> m(n);
//    for(auto i = 0; i < manager.size(); ++i)
//        if (manager[i] != -1)
//            m[manager[i]].push_back(i);
//    return dfs(headID, m, informTime);
//}





//Runtime: 708 ms, faster than 40.51% of C++ online submissions for Time Needed to Inform All Employees.
//Memory Usage: 139.5 MB, less than 33.33% of C++ online submissions for Time Needed to Inform All Employees.
    int lt1376a(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        unordered_map<int, vector<int>> map2;           // manager :
        for (int i = 0; i < n; ++i)
        {
            map2[manager[i]].push_back(i);
        }

        dfsa1(headID, map2, informTime, 0);

        return ans;
    }
    int ans = 0;

    void dfsa1(int sup, unordered_map<int, vector<int>>& map2, vector<int>& times, int used)
    {
        if (map2.find(sup) != map2.end())
        {
            vector<int>& vi = map2[sup];
            used += times[sup];
            for (int i : vi)
            {
                dfsa1(i, map2, times, used);
            }
        }
        else
        {
            ans = max(ans, used);
        }
    }

};

int main()
{
//    int n{1}, h{0};
//    vector<int> m = {-1};
//    vector<int> t = {0};

//    int n{6}, h{2};
//    vector<int> m = {2,2,-1,2,2,2};
//    vector<int> t = {0,0,1,0,0,0};

//    int n{7}, h{6};
//    vector<int> m = {1,2,3,4,5,6,-1};
//    vector<int> t = {0,6,5,4,3,2,1};

//    int n{15}, h{0};
//    vector<int> m = {-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6};
//    vector<int> t = {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0};

    int n{4}, h{2};
    vector<int> m = {3,3,-1,2};
    vector<int> t = {0,0,162,914};

    LT1376 lt;

    cout<<lt.lt1376a(n,h,m,t);

    return 0;
}
