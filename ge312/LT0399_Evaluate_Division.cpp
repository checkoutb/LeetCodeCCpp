
#include "../header/myheader.h"

class LT0399
{
public:


// details

//    typedef unordered_map<string, unordered_map<string, double>> graph;
//
//    graph buildGraph(vector<vector<string>>& equations, vector<double>& values) {
//        graph g;
//        for (int i = 0; i < equations.size(); i++) {
//            string num = equations[i][0], den = equations[i][1];
//            g[num][num] = g[den][den] = 1.0;
//            g[num][den] = values[i];
//            g[den][num] = 1.0 / values[i];
//        }
//        for (auto& p : g) {
//            string k = p.first;
//            for (auto& q : p.second) {
//                string i = q.first;
//                for (auto& r : p.second) {
//                    string j = r.first;
//                    g[i][j] = g[i][k] * g[k][j];
//                }
//            }
//        }
//        return g;
//    }
// no zero, no contradiction.. 所以能类似floyd，来保证全部更新。


//    double dfs(unordered_map<string, vector<string>>& edges, unordered_map<string, vector<double>>& weights, string start, string end, unordered_set<string>& visited, double total) {
//        if(visited.find(start) != visited.end())
//            return 0.0;
//        if(edges.find(start) == edges.end())
//            return 0.0;
//        if(start == end)
//            return total;
//
//        visited.insert(start);
//
//        for(int i = 0; i < edges[start].size(); i++) {
//            double ans = dfs(edges, weights, edges[start][i], end, visited, total * weights[start][i]);
//            if(ans != 0.0) {
//                visited.erase(start);
//                return ans;
//            }
//        }
//
//        visited.erase(start);
//        return 0.0;
//    }
// 这里没有更新操作，有提前退出。 是不是就是我的dfs慢的原因？



//Runtime: 1248 ms, faster than 5.11% of C++ online submissions for Evaluate Division.
//Memory Usage: 9.3 MB, less than 74.51% of C++ online submissions for Evaluate Division.
// most are 4ms...

    vector<double> lt0399b(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
    {
        map<string, map<string, double>> map1;
        int sz1 = values.size();
        int sz2 = queries.size();

        for (int i = 0; i < sz1; i++)
        {
            vector<string>& v1 = equations[i];
            double d1 = values[i];
            map1[v1[0]][v1[1]] = d1;
            map1[v1[1]][v1[0]] = 1 / d1;
            map1[v1[0]][v1[0]] = 1;
            map1[v1[1]][v1[1]] = 1;
        }

        vector<double> ans(sz2);

        for (int i = 0; i < sz2; i++)
        {
            double d2 = calValueb1(map1, queries[i]);
            ans[i] = d2;
        }
        return ans;
    }

    double calValueb1(map<string, map<string, double>>& map1, vector<string>& q)
    {
//        if (!map1.contains(q[0]))         // c++ 20
//            return -1;

        if (map1.find(q[0]) == map1.end() || map1.find(q[1]) == map1.end())
            return -1;

        map<string, double>& map2 = map1[q[0]];
//        if (map2.contains(q[1]))
        if (map2.find(q[1]) != map2.end())
            return map2[q[1]];

//        stack<string> stk1;
//        stack<double> stk2;
        vector<string> v3;
        dfsb1(map1, map2, q[0], v3);

        if (map2.find(q[1]) != map2.end())
            return map2[q[1]];
        else
            return -1;
    }

    void dfsb1(map<string, map<string, double>>& map1, map<string, double>& map2, string s, vector<string>& v3, double v = 1.0)
    {
        v3.push_back(s);
        map<string, double>& map3 = map1[s];
        for (auto it = map3.begin(); it != map3.end(); ++it)
        {
//            if (map2.find(it->first) != map2.end())
//                continue;
            if (find(v3.begin(), v3.end(), it->first) != v3.end())
            {
                continue;
            }
            map2[it->first] = v * it->second;

            #ifdef __test
            cout<<s<<" - "<<it->first<<" : "<<map2[it->first]<<endl;
            #endif // __test

            dfsb1(map1, map2, it->first, v3, v * it->second);
        }
        v3.pop_back();
    }


//    // 图。
//    // floyd, dijkstra,     stack.
//    //
//    vector<double> lt0399a(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
//    {
////        unordered_map<string, unordered_set<string>> map1;  // reachable
////        unordered_map<string, unordered_set<string>> map2;  // unreachable
//        unordered_map<pair<string, string>, double> map3;
//
//        int sz1 = values.size();
//        for (int i = 0; i < sz1; i++)
//        {
//            vector<string>& vs = equations[i];
//            double value = values[i];
//            pair<string, string> p1(vs[0], vs[1]);
////            unordered_set set1 = map1[vs[0]];
////            map1[vs[0]].insert(vs[1]);
//            map3[p1] = value;
//        }
//
//        int sz2 = queries.size();
//        vector<double> ans(sz2);
//
//        for (int i = 0; i < sz2; i++)
//        {
//            double d = calValuea1(map3, queries[i]);
//            ans[i] = d;
//        }
//        return ans;
//    }
//
//    double calValuesa1(unordered_map<pair<string, string>, double>& map3, vector<string>& q)
//    {
//        pair<string, string> p2(q[0], q[1]);
//        auto p4 = map3.find(p2);
//        if (p4 != map3.end())
//        {
//            return p4->sencond;
//        }
//        else
//        {
//            double d = recursiona1(map3, q);
//            return d;
//        }
//    }
//
//    double recursiona1(unordered_map<pair<string, string>, double>& map3, vector<string>& q)
//    {
//        return 1.0;
//    }

};


int main()
{
    vector<vector<string>> v1 = {{"a", "b"}, {"b", "c"}};
    vector<double> v2 = {2.0, 3.0};
    vector<vector<string>> v3 = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

    LT0399 lt;
    vector<double> ans = lt.lt0399b(v1, v2, v3);

    cout<<endl<<"------------------"<<endl;
    for(auto p : ans)
    {
        cout<<p<<", ";
    }
    cout<<endl<<"------------------"<<endl;

    return 0;
}
