
#include "../../header/myheader.h"

class LT
{
public:


    // D D




// Runtime
// 317ms
// Beats23.70%of users with C++
// Memory
// 122.52MB
// Beats9.50%of users with C++
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> vvi(n);
        for (vector<int>& vi : edges)
        {
            vvi[vi[0]].push_back(vi[1]);
            vvi[vi[1]].push_back(vi[0]);
        }
        vector<int> ans(n);
        vector<vector<int>> vp(n, vector<int>(2, 0));       // <sum, cnt>
        // cnt not contain node

        dfsb1(vvi, 0, -1, vp);
        ans[0] = vp[0][0];

#ifdef __test
        for (myvi& v : vp)
        {
            cout<<" "<<v[0]<<", "<<v[1]<<endl;
        }
#endif

        for (int nxt : vvi[0])
        {
            dfsb2(vvi, nxt, 0, vp, ans[0], n, ans);
        }
        return ans;

    }

    void dfsb2(vector<vector<int>>& vvi, int node, int parent, vector<vector<int>>& vp2, int psum, int n, vector<int>& ans)
    {
        int sum2 =
        // vp2[node][0] +       // .. not need [0]
        psum + (n - vp2[node][1] - 1) - (vp2[node][1] + 1);
        ans[node] = sum2;

        for (int nxt : vvi[node])
        {
            if (nxt == parent)
                continue;
            dfsb2(vvi, nxt, node, vp2, sum2, n, ans);
        }
    }

    vector<int>& dfsb1(vector<vector<int>>& vvi, int node, int pnt, vector<vector<int>>& vp2)
    {
        int sum2 {0};
        int cnt {0};

        for (int nxt : vvi[node])
        {
            if (nxt == pnt)
                continue;

            vector<int> vi = dfsb1(vvi, nxt, node, vp2);
            sum2 += vi[0];
            cnt += vi[1] + 1;
        }
        sum2 += cnt;
        vp2[node][0] = sum2;
        vp2[node][1] = cnt;
        return vp2[node];
    }



    // tle
    vector<int> sumOfDistancesInTree__ee(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> vvi(n);
        for (vector<int>& vi : edges)
        {
            vvi[vi[0]].push_back(vi[1]);
            vvi[vi[1]].push_back(vi[0]);
        }
        vector<int> ans(n);
        vector<unordered_map<int, pair<int, int>>> vm(n);
        for (int i = 0; i < n; ++i)
        {
            ans[i] = dfsa1(vvi, i, -1, vm).first;
        }
        return ans;
    }

    // sum, node' count
    pair<int, int> dfsa1(vector<vector<int>>& vvi, int node, int parent, vector<unordered_map<int, pair<int, int>>>& vm)
    {
        if (vm[node].contains(parent))
            return vm[node][parent];

        int t2 = 0;
        int cnt = 0;
        pair<int, int> p;
        for (int nxt : vvi[node])
        {
            if (nxt != parent)
            {
                p = dfsa1(vvi, nxt, node, vm);
                t2 += p.first;
                cnt += p.second;
            }
        }
        t2 += cnt;
        ++cnt;
        p = std::make_pair(t2, cnt);
        vm[node][parent] = p;
        return p;
    }
};

int main()
{

    LT lt;

    int n{6};
    myvvi vv {{1,0},{2,0},{2,3},{2,4},{2,5}};

    myvi v = lt.sumOfDistancesInTree(n, vv);

    showVectorInt(v);

    return 0;
}
