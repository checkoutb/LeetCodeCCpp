
#include "../../header/myheader.h"

class LT100047
{
public:




//2000 / 21253	Ouha 	12	0:34:36	0:02:57 	0:33:29 	0:34:36
//601	Ouha  	12	0:34:36	0:02:57 	0:33:29 	0:34:36

//623 / 21263	Ouha 	12	0:34:36	0:02:57 	0:33:29 	0:34:36


//leetcode.cn   358    xx    12  0:34:45


// error
    long long countPaths(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> vvi(n + 1);
        for (vector<int>& vi : edges)
        {
            vvi[vi[0]].push_back(vi[1]);
            vvi[vi[1]].push_back(vi[0]);
        }

        long long ans = 0LL;
        vector<bool> vb(n + 1, false);
        for (int i = 2; i <= n; ++i)
        {
            if (vb[i] == false)
            {
                for (int j = i + i; j <= n; j += i)
                    vb[j] = true;
            }
        }

        set<int> prm;
        for (int i = 2; i <= n; ++i)
            if (!vb[i])
                prm.insert(i);

        dfsa2(vvi, 1, -1, prm, ans);

//        for (int i : prm)
//        {
//            map<int, int> map2;
//            for (int nxt : vvi[i])
//            {
//                dfsa1(vvi, nxt, i, 0, prm, map2);
//            }
//            long long sum2 = 0LL;
//            for (auto& p : map2)
//            {
//                sum2 += 1LL * (p.first + 1) * p.second;
//            }
//        }
        return ans;
    }


    // before prm, after prm
    // <= prm, > prm
    vector<int> dfsa2(vector<vector<int>>& vvi, int node, int parent, set<int>& prm, long long& ans)
    {
        bool isp = prm.find(node) != prm.end();

        int befp = 0;
        int aftp = 0;

        int t2 = 0;
        int t3 = 0;
        for (int nxt : vvi[node])
        {
            if (nxt == parent)
                continue;

            vector<int> vi = dfsa2(vvi, nxt, node, prm, ans);

            #ifdef __test
            cout<<node<<"        - "<<isp<<", "<<vi[0]<<", "<<vi[1]<<", "<<t2<<", "<<t3<<" - "<<ans<<endl;
            #endif // __test

            if (isp)
            {
                ans += 1LL * vi[1] * (t3);
                t2 += vi[1];
                ans += vi[1];
            }
            else
            {
                ans += 1LL * vi[0] * (t3) + 1LL * (vi[1]) * t2;
                ans += vi[0];
                t2 += vi[0];        // before
                t3 += vi[1];        // after
            }
        }

        #ifdef __test
        cout<<node<<", "<<t2<<", "<<isp<<"--------"<<t3<<",,,"<<ans<<endl;
        #endif // __test

        return {t2 + isp, t3 + !isp};
    }


    // error
    void dfsa1(vector<vector<int>>& vvi, int node, int parent, int depth, set<int>& prm, map<int, int>& map2)
    {
        if (prm.find(node) != prm.end())
        {
            if (depth != 0)
                ++map2[depth];
            return;
        }

        for (int nxt : vvi[node])
        {
            if (nxt == parent)
                continue;

            dfsa1(vvi, nxt, node, depth + 1, prm, map2);
        }
    }

//    vector<int> dfsa1(vector<vector<int>>& vvi, int node, int parent, long long& ans)
//    {
//
//    }

};

int main()
{

    LT100047 lt;

//    int n = 5;
//    myvvi vv = {{1,2},{1,3},{2,4},{2,5}};

    int n = 9;      // 17   少了[4,5,9] [6,4,5,9]
    myvvi vv = {{7,4},{3,4},{5,4},{1,5},{6,4},{9,5},{8,7},{2,8}};

    cout<<lt.countPaths(n, vv)<<endl;

    return 0;
}
