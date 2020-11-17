
#include "../header/myheader.h"

class LT1319
{
public:

// D D

// 只要 边 >= 机器-1， 就能保证 必然 连通，  < 则必然不连通。
// dfs + visited， 寻找 多少个 子连通， 子连通数量-1 就是 结果。


//vector<int> ds(n, -1);
//int find(vector<int> &ds, int i) {
//    return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
//}

//    for (auto &c : connections) {
//        auto i = find(ds, c[0]), j = find(ds, c[1]);
//        if (i != j) {
//            if (ds[j] < ds[i])
//                swap(i, j);
//            ds[i] += ds[j];
//            ds[j] = i;
//            --n;
//        }
//    }
//... ds[i] < 0 ? i  ..  第一次 dsi 还是负数(-2)， dsj指向 dsi...


//Runtime: 208 ms, faster than 84.85% of C++ online submissions for Number of Operations to Make Network Connected.
//Memory Usage: 39.5 MB, less than 73.11% of C++ online submissions for Number of Operations to Make Network Connected.
    int lt1319a(int n, vector<vector<int>>& connections)
    {
        int cable = 0;

        vector<int> v(n);
        for (int i = 1; i < n; ++i)
            v[i] = i;

        for (vector<int>& vi : connections)
        {
            int st = min(vi[0], vi[1]);
            int en = max(vi[0], vi[1]);
            int rst = getRoota1(v, st);
            int ren = getRoota1(v, en);
            if (rst == ren)
            {
                cable++;
            }
            else
            {
                v[rst] = ren;
            }
        }
        unordered_set<int> set2;
        for (int i = 0; i < n; ++i)
        {
            set2.insert(getRoota1(v, i));
        }
        return cable >= (set2.size() - 1) ? (set2.size() - 1) : -1;
    }

    int getRoota1(vector<int>& v, int idx)
    {
        if (v[idx] == idx)
            return idx;
        int t = getRoota1(v, v[idx]);
        v[idx] = t;
        return t;
    }

};

int main()
{

//    vector<vector<int>> conn = {{0,1},{0,2},{0,3},{1,2},{1,3}};
//    int n = 6;

//    vector<vector<int>> conn = {{0,1},{0,2},{0,3},{1,2}};
//    int n = 6;

    vector<vector<int>> conn = {{0,1},{0,2},{3,4},{2,3}};
    int n = 5;

    LT1319 lt;

    cout<<lt.lt1319a(n, conn);

    return 0;
}
