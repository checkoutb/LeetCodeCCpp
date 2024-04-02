
#include "../header/myheader.h"

class LT3068
{
public:

    // D

    // ...



    // g


    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        return -1LL;
    }


    // TLE ...

    // no vvp, just map<map>.
    // Memory Limit Exceeded, 15000 node

    // 换节点作为root 会影响结果吗？ ... yes
    long long error__maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int sz1 = nums.size();
        vector<vector<int>> vvi(sz1);

        for (vector<int>& vi : edges)
        {
            vvi[vi[0]].push_back(vi[1]);
            vvi[vi[1]].push_back(vi[0]);
        }
        long long ans = 0LL;
        // vector<vector<pair<long long, long long>>> vvp(sz1, vector<pair<long long, long long>>(sz1, std::make_pair(-1, -1)));
        map<int, map<int, pair<long long, long long>>> mmap;
        for (int i = 0; i < sz1; ++i)
        {
            pair<long long, long long> p = dfsa1(nums, vvi, i, -1, k, mmap);
            ans = max(ans, p.first);
        }

        return ans;
    }

    // <0 xor, 1 xor>
    pair<long long, long long> dfsa1(vector<int>& vi, vector<vector<int>>& vvi, int node, int parent, int k, map<int, map<int, pair<long long, long long>>>& mmap) {
        if (parent != -1 && mmap[node].contains(parent))
            return mmap[node][parent];

        vector<pair<long long, long long>> vp;
        for (int nxt : vvi[node])
        {
            if (nxt != parent)
                vp.push_back(dfsa1(vi, vvi, nxt, node, k, mmap));
        }
        long long x0 = 0LL;
        long long x1 = 0LL;

        long long sum2 = 0LL;
        long long mndf = LLONG_MAX;
        int cnt1 = 0;
        for (pair<long long, long long>& p : vp)
        {
            sum2 += std::max(p.first, p.second);
            mndf = std::min(mndf, std::abs(p.first - p.second));
            cnt1 += p.second > p.first;
        }

#ifdef __test
        cout<<" "<<node<<" "<<vi[node]<<", "<<k<<", "<<sum2<<", "<<mndf<<", "<<cnt1<<endl;
#endif

        if (vp.empty())
        {
            x0 = vi[node];
            x1 = vi[node] ^ k;
        }
        else
        {
            if (mndf == 0LL)
            {
                x0 = sum2 + max(vi[node], vi[node] ^ k);
                x1 = x0;
            }
            else
            {
                if (cnt1 % 2 == 0)
                {
                    x0 = sum2 + vi[node];
                    x1 = sum2 + (vi[node] ^ k);
                }
                else
                {
                    x0 = sum2 + (vi[node] ^ k);
                    x1 = sum2 + vi[node];
                }
            }
        }

#ifdef __test
        cout<<node<<" "<<x0<<" "<<x1<<endl;
#endif

        auto p2 = std::make_pair(x0, x1);
        if (parent != -1)
            mmap[node][parent] = p2;
            // vvp[node][parent] = p2;

        return p2;
    }

};

int main()
{

    LT3068 lt;

    // myvi v {1,2,1};
    // int k = 3;
    // myvvi vv {{0,1},{0,2}};

    // myvi v {2,3};
    // int k {7};
    // myvvi vv {{0,1}};       // 9

    myvi v {24,78,1,97,44};
    int k {6};
    myvvi vv {{2,0},{1,2},{2,4},{4,3}}; // 260  最大值 不是 0为root时。

    cout<<lt.maximumValueSum(v, k, vv);

    return 0;
}
