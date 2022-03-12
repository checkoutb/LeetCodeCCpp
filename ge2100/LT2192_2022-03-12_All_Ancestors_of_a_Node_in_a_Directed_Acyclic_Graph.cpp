
#include "../header/myheader.h"

class LT2192
{
public:

// D D

//    vector<vector<int>> res(n), al(n);
//    function<void(int, int)> dfs = [&](int i, int anc){
//        for (auto j : al[i])
//            if (res[j].empty() || res[j].back() != anc) {
//                res[j].push_back(anc);
//                dfs(j, anc);
//            }
//    };
//    for (auto &e: edges)
//        al[e[0]].push_back(e[1]);
//    for (int i = 0; i < n; ++i)
//        dfs(i, i);
//    return res;





//Runtime: 629 ms, faster than 37.08% of C++ online submissions for All Ancestors of a Node in a Directed Acyclic Graph.
//Memory Usage: 119 MB, less than 57.01% of C++ online submissions for All Ancestors of a Node in a Directed Acyclic Graph.
    vector<vector<int>> lt2192a(int n, vector<vector<int>>& edges)
    {
        vector<set<int>> vvi(n);
        unordered_map<int, unordered_set<int>> map2;
        for (int i = 0; i < edges.size(); ++i)
        {
            map2[edges[i][1]].insert(edges[i][0]);
        }
        vector<bool> vb(n, false);
        for (int i = 0; i < n; ++i)
        {
            dfsa1(map2, vb, i);
        }
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; ++i)
        {
            ans[i] = vector<int>(begin(map2[i]), end(map2[i]));
            sort(begin(ans[i]), end(ans[i]));
        }
        #ifdef __test
        for (int i : map2[6])
            cout<<i<<", ";
        cout<<endl;
        for (int i : map2[3])
            cout<<i<<", ";
        cout<<endl;
        #endif // __test
        return ans;
    }

    void dfsa1(unordered_map<int, unordered_set<int>>& map2, vector<bool>& vb, int tar)
    {
        if (vb[tar])
            return;

        vector<int> vi(map2[tar].begin(), map2[tar].end());
        for (int i : vi)
        {
            dfsa1(map2, vb, i);
            map2[tar].insert(begin(map2[i]), end(map2[i]));
        }

//        for (int t : map2[tar])
//        {
//            dfsa1(map2, vb, t);
//            #ifdef __test
//            if (tar == 6)
//            {
//                cout<<t<<": ";
//                for (int x : map2[t])
//                    cout<<x<<", ";
//                cout<<endl;
//            }
//            #endif // __test
////            map2[tar].insert(begin(map2[t]), end(map2[t]));
//        }
//        for (int t : map2[tar])
//        {
//            map2[tar].insert(begin(map2[t]), end(map2[t]));
//        }

        vb[tar] = true;
    }


};

int main()
{

    LT2192 lt;

    myvvi vv = {{0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}};
    int n = 8;

    myvvi vv2 = lt.lt2192a(n, vv);

    for (myvi& v : vv2)
    {
        cout<<v.size()<<" : ";
        for (int i : v)
            cout<<i<<", ";
        cout<<endl;
    }

    return 0;
}
