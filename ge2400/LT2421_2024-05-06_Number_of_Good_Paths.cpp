
#include "../header/myheader.h"

class LT2421
{
public:


    // hint : ...


    // g, tle


//   1
//  3 3
// 5
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges)
    {
        int sz1 = vals.size();
        vector<vector<int>> vvi(sz1);

        for (vector<int>& e : edges)
        {
            vvi[e[0]].push_back(e[1]);
            vvi[e[1]].push_back(e[0]);
        }
        int ans = sz1;
        pair<int, int> p = std::make_pair(-123, 0);
        dfsa2(vvi, 0, -1, p, vals, ans);
        return ans;
    }

    vector<pair<int, int>> dfsa2(vector<vector<int>>& vvi, int node, int parent, pair<int, int> p, vector<int>& vi, int& ans)
    {
        // if (vi[node] > p.first)
        // {
        //     p.first = vi[node];
        //     p.second = 1;
        // }
        // else if (vi[node] == p.first)
        // {
        //     // ans += p.second;
        //     ++p.second;
        // }

        map<int, int> map2;

        for (int nxt : vvi[node])
        {
            if (nxt == parent)
                continue;

            vector<pair<int, int>> vpii = dfsa2(vvi, nxt, node, p, vi, ans);
            for (pair<int, int>& p4 : vpii)
            {
                if (p4.first < vi[node])
                    continue;
                ans += map2[p4.first] * p4.second;
                map2[p4.first] += p4.second;
            }
        }

        ans += map2[vi[node]];
        ++map2[vi[node]];
        vector<pair<int, int>> vp;
        for (const pair<int, int>& pp : map2)     // return map2 ?
            vp.push_back(pp);

#ifdef __test
        cout<<" ========== "<<node<<endl;
        for (pair<int, int>& p : vp)
            cout<<p.first<<", "<<p.second<<endl;
#endif

        return vp;
    }

    pair<int, int> dfsa1(vector<vector<int>>& vvi, int node, int parent, pair<int, int> p, vector<int>& vi, int& ans)
    {
        pair<int, int> p2;
        p2.first = vi[node];
        p2.second = 1;
        if (p2.first > p.first)
        {
            p.first = p2.first;
            p.second = 1;
        }
        else if (p2.first == p.first)
        {
            ans += p.second;
            ++p.second;
        }
        pair<int, int> p3;
        map<int, int> map2;
        for (int nxt : vvi[node])
        {
            if (nxt == parent)
                continue;

            p3 = dfsa1(vvi, nxt, node, p, vi, ans);
            ans += map2[p3.first] * p3.second;
            map2[p3.first] += p3.second;
            if (p3.first > p2.first)
            {
                p2.first = p3.first;
                p2.second = 1;
            }
            else if (p2.first == p3.first)
                ++p2.second;
        }

        return p2;
    }
};




int main()
{

    LT2421 lt;

    myvi v = {1,3,2,1,3};
    myvvi vv = {{1,0},{2,0},{2,3},{2,4}};

    cout<<lt.numberOfGoodPaths(v, vv);

    return 0;
}
