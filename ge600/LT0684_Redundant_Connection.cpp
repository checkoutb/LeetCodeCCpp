
#include "../header/myheader.h"

class LT0684
{
public:


// D D

// dfs
//    private boolean dfs(int u, int v, int pre, List<Set<Integer>> adjList){
//        if(u == v)
//            return true;
//        for(int w : adjList.get(u)){
//            if(w == pre) continue;
//            boolean ret = dfs(w, v, u, adjList);
//            if(ret) return true;
//        }
//        return false;
//    }
// v 没有变。 找环。

// 一旦 t1 == t2， 可以直接返回。





//Runtime: 12 ms, faster than 88.73% of C++ online submissions for Redundant Connection.
//Memory Usage: 8.9 MB, less than 73.42% of C++ online submissions for Redundant Connection.
// 应该能按 入度为1来 算出结果吧。  1-3,2-3,3-4,..
    vector<int> lt0684a(vector<vector<int>>& edges)
    {
        vector<int> uf(edges.size() + 1, 0);
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
//    vector<vector<int>> vv = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    vector<vector<int>> vv = {{1,4},{3,4},{1,3},{1,2},{4,5}};

    LT0684 lt;

    vector<int> v = lt.lt0684a(vv);

    cout<<v[0]<<", "<<v[1]<<endl;

    return 0;
}
