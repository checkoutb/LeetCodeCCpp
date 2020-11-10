
#include "../header/myheader.h"

class LT1192
{
public:


// D

// Tarjan's bridge



// .. buxingde , {1,2,3} - a - b - d/c - e - {6,7,8}
// 而且 只有一条路， 这个写不出。。
    vector<vector<int>> lt1192b(int n, vector<vector<int>>& connections)
    {
        vector<vector<int>> ans;
        vector<int> arr(n.size(), 0);
        for (int i = 0; i < arr.size(); i++)
            arr[i] = i;
        for (vector<int>& conn : connections)
        {
            arr[conn[0]] = arr[conn[1]];
        }
        return ans;
    }


// error
// ... ，，， 只能并查集了，，   分成2个集合，中间有一条边相连，，这种情况下， 没有点的度为1。。。
// 度为1？  而且 减去度为1的 边后，可能会出现另一条度为1的，需要 递归。
// 并查集？  集合中的点 到 其他 集合 只有一条路
    vector<vector<int>> lt1192a(int n, vector<vector<int>>& connections)
    {
//        vector<int, vector<int>> v(n, vector<int>());       // 度 : 其他点, zhijie
        vector<vector<pair<int, vector<int>>>> v(n, vector<pair<int, vector<int>>>());            // size 就是 度, 得保存下 connection。。。
        vector<vector<int>> ans;
        unordered_set<long> set2;
        long mul = 1E6;
        for (vector<int>& vi : connections)
        {
            v[vi[0]].push_back({vi[1], vi});
            v[vi[1]].push_back({vi[0], vi});
        }

        int cnt1 = 0;
        queue<int> que1;
        for (int i = 0; i < v.size(); ++i)
        {
            if (v[i].size() == 1)
                que1.push(i);
//                cnt1++;
        }

        while (!que1.empty())
        {
            int sz2 = que1.size();
            while (sz2-- > 0)
            {
                vector<pair<int, vector<int>>>& vp = v[que1.front()];
                que1.pop();
                pair<int, vector<int>>& p = vp[0];
                int t1 = p.second[0];
                int t2 = p.second[1];
                int t3 = max(t1, t2);
                t1 = min(t1, t2);
                t2 = t3;
                if (set2.find(t1 * mul + t2) == set2.end()) {
                    ans.push_back(p.second);
                    set2.insert(t1 * mul + t2);
                }
                vp.clear();
            }
            for (int i = 0; i < v.size(); ++i)
            {
                if (v[i].size() == 1)
                    que1.push(i);
            }
        }

        return ans;
    }

};

int main()
{
//    int n = 4;
//    vector<vector<int>> vv = {{0,1},{1,2},{2,0},{1,3}};

    int n = 6;
    vector<vector<int>> vv = {{0,1},{1,2},{2,0},{1,3},{3,4},{4,5},{5,3}};

    LT1192 lt;

    vector<vector<int>> ans = lt.lt1192a(n, vv);
    cout<<ans.size()<<endl;;

    for (vector<int>& vi : ans)
    {
//        showVectorInt(vi);
        for (int i : vi)
        {
            cout<<i<<", ";
        }
        cout<<endl;
    }

    return 0;
}
