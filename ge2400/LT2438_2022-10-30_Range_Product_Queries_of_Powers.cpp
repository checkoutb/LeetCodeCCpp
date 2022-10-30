
#include "../header/myheader.h"

class LT2438
{
public:

    // D D

    // segment tree



    //int modPow(int x, unsigned int y, unsigned int m)
    //{
    //    if (y == 0)
    //        return 1;
    //    long p = modPow(x, y / 2, m) % m;
    //    p = (p * p) % m;
    //    return y % 2 ? (p * x) % m : p;
    //}
    //vector<int> productQueries(int n, vector<vector<int>>& qs) {
    //    vector<int> pws{ 1 }, res;
    //    int mod = 1000000007;
    //    for (int b = 0; b < 30; ++b)
    //        if (n & (1 << b))
    //            pws.push_back((1LL << b) * pws.back() % mod);

    //    transform(begin(qs), end(qs), back_inserter(res), [&](const auto& q) {
    //        return (long long)pws[q[1] + 1] * modPow(pws[q[0]], mod - 2, mod) % mod;
    //    });
    //    return res;
    //}


    //vector<int> pws, res;
    //long long products[29][29] = {};
    //for (int b = 0; b < 30; ++b)
    //    if (n & (1 << b))
    //        pws.push_back(1 << b);
    //for (int i = 0; i < pws.size(); ++i)
    //    for (int j = i; j < pws.size(); ++j)
    //        products[i][j] = (j > i ? products[i][j - 1] : 1) * pws[j] % 1000000007;
    //transform(begin(qs), end(qs), back_inserter(res), [&](const auto& q) { return products[q[0]][q[1]]; });
    //return res;



//Runtime: 553 ms, faster than 82.17 % of C++ online submissions for Range Product Queries of Powers.
//Memory Usage : 140.2 MB, less than 91.26 % of C++ online submissions for Range Product Queries of Powers.
    // 一个 int ，只需要32个 bit。 而 一个 bit 代表了 一个 2的power
    // 而且可以 prefix ？ 不， long 也不够。 得 1+2+...+31 个bit
    // 但是可以 cache。 毕竟 31 * 31, 而 queries.size() < 10^5
    vector<int> lt2438a(int n, vector<vector<int>>& queries)
    {
        vector<int> vi;

        for (int i = 0; i < 32; ++i)
        {
            if (n & (1 << i))
            {
                vi.push_back((1 << i));
            }
        }

        int sz1 = queries.size();
        vector<int> ans(sz1, 0);
        const int MOD = 1e9 + 7;
        vector<vector<int>> vvi(vi.size(), vector<int>(vi.size(), 0));
        long long t2 = 0LL;
        for (int i = 0; i < vi.size(); ++i)
        {
            t2 = 1LL;

            for (int j = i; j < vi.size(); ++j)
            {
                t2 *= vi[j];
                t2 %= MOD;
                vvi[i][j] = t2;
            }
        }

        for (int i = 0; i < sz1; ++i)
        {
            ans[i] = vvi[queries[i][0]][queries[i][1]];
        }

        return ans;
    }

};

int main()
{

    LT2438 lt;


    return 0;
}
