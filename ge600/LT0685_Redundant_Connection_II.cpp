
#include "../header/myheader.h"

class LT0685
{
public:



// bu, root.的入度可能为1。
    vector<int> lt0685b(vector<vector<int>>& edges)
    {
        vector<int> arr(edges.size() + 1, 0);
        int douIn = 0;
        for (vector<int>& e : edges)
        {
            arr[e[1]]++;
            if (arr[e[1]] == 2)
                douIn = e[1];
        }
        if (douIn == 0) // root.
        {
            // 如果出度都是1 或者 只有1个结点的出度是2，就减去最后一条。
            // 如果有>=2个结点的出度是2。 减 最后一个出度为2的结点的 入度的那条边。
        }
        else
        {
            // 视为无向图，找环， 环上 指向 douIn 这个结点的 边 就是 结果。
        }
        return nullptr;
    }



// 应该只可能 1个点 的入度为2。
    vector<int> lt0685a(vector<vector<int>>& edges)
    {
        vector<int> uf(edges.size() + 1, 0);
        unordered_set<int> douIn;
        for (vector<int>& e : edges)
        {
            uf[e[1]]++;
            if (uf[e[1]] == 2)
                douIn.insert(e[1]);
        }
        for (int i = 0; i < uf.size(); i++)
        {
            uf[i] = i;
        }
        vector<int> ans(2, -1);
        for (vector<int>& e : edges)
        {
            int t1 = fuf(uf, e[0]);
            int t2 = fuf(uf, e[1]);
            if (t1 == t2)
            {
                ans[0] = e[0];
                ans[1] = e[1];
            }

            uf[t2] = uf[t1];

            #ifdef __test
            cout<<t1<<" , "<<t2<<" , ";
            for_each(begin(uf), end(uf), fun_cout);
            cout<<endl;
            #endif // __test
        }
        return ans;
    }

    int fuf(vector<int>& uf, int i)
    {
        if (uf[i] == i)
            return i;
        return fuf(uf, uf[i]);
    }

};

int main()
{

//    vector<vector<int>> vv = {{1,2},{1,3},{2,3}};
//    vector<vector<int>> vv = {{1,2},{2,3},{3,4},{4,1},{1,5}};
    vector<vector<int>> vv = {{2,1},{3,1},{4,2},{1,4}};     // 2,1... occurs last, bushi 1,4 ma ?.... 要变成一颗树，只有一个root，每个结点最多一个parent

    LT0685 lt;

    vector<int> v = lt.lt0685a(vv);
    cout<<v[0]<<", "<<v[1]<<endl;

    return 0;
}
