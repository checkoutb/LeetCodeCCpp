
#include "../header/myheader.h"

class LT2421
{
public:





// tle.  从 unordered_map 改成 map， 还是tle。
// 多叉树吗？
    int lt2421a(vector<int>& vals, vector<vector<int>>& edges)
    {
        //unordered_map<int, int> map2;

        int sz1 = vals.size();
        vector<vector<int>> vvi(sz1);

        for (vector<int>& vi : edges)
        {
            vvi[vi[0]].push_back(vi[1]);
            vvi[vi[1]].push_back(vi[0]);
        }

        int ans = 0;

        dfsa1(vals, vvi, 0, -1, ans);

        return ans + sz1;
    }

    map<int, int> dfsa1(vector<int>& vi, vector<vector<int>>& vvi, int node, int parent, int& ans2)
    {
        map<int, int> ans;
        map<int, int> map2;
        int val = vi[node];
        for (int chd : vvi[node])
        {
            if (chd == parent)
                continue;

            map2 = dfsa1(vi, vvi, chd, node, ans2);

            for (auto& p : map2)
            {
                if (p.first < val)
                    continue;

//                ans[p.first] += p.second;

                ans2 += p.second * ans[p.first];
                ans[p.first] += p.second;

            }
        }
        ans2 += ans[val];
        ++ans[val];


//        int t2 = 0;
//        for (auto& p : ans)
//        {
//            t2 = p.second;
//            ans2 += 1LL * (1 + t2) * t2 / 2;
//        }

        return ans;
    }


};

int main()
{

    LT2421 lt;

//    myvi v = {1,3,2,1,3};
//    myvvi vv = {{0,1},{0,2},{2,3},{2,4}};

    myvi v = {1,1,2,2,3};
    myvvi vv = {{1,0},{1,2},{3,2},{2,4}};

    int a = lt.lt2421a(v, vv);

    cout<<a<<endl;

    return 0;
}
