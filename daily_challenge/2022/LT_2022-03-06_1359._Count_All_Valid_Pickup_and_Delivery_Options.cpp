
#include "../../header/myheader.h"

class LT
{
public:


// D D

//            dp[i] = ( dp[i-1] * ( ( ( (2*i)% mod - 1 ) % mod ) * ( i ) % mod ) % mod  ) % mod;



//        for (int i = 1; i <= n; ++i)
//            res = res * (i * 2 - 1) * i % mod;


//    for (int i=1; i<n+1; ++i) res = res * i % cap;
//    for (int i=1; i<2*n; i+=2) res = res * i % cap;


// ... 怀疑人生了。。
//Runtime: 300 ms, faster than 5.03% of C++ online submissions for Count All Valid Pickup and Delivery Options.
//Memory Usage: 54.3 MB, less than 5.03% of C++ online submissions for Count All Valid Pickup and Delivery Options.
    int ltb(int n)
    {
        vector<vector<pair<int, int>>> vvp(n * 2, vector<pair<int, int>>(n + 1));       // cishu , shengyu
        vvp[0][1] = make_pair(n, n - 1);
        int MOD = 1E9 + 7;
        for (int i = 1; i < n * 2; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                if ((j - 1) >= 0 && vvp[i - 1][j - 1].second > 0)
                {
                    vvp[i][j] = make_pair((1LL * vvp[i - 1][j - 1].first * vvp[i - 1][j - 1].second) % MOD, vvp[i - 1][j - 1].second - 1);
                }
                if ((j + 1) <= n && vvp[i - 1][j + 1].first > 0)
                {
                    int t2 = (1LL * vvp[i - 1][j + 1].first * (j + 1)) % MOD;
                    vvp[i][j].first = (vvp[i][j].first + t2) % MOD;
                    vvp[i][j].second = vvp[i - 1][j + 1].second;
                }
            }
        }
        #ifdef __test
        for (vector<pair<int, int>>& vp : vvp)
        {
            for (pair<int, int>& p : vp)
            {
                cout<<p.first<<"+"<<p.second<<", ";
            }
            cout<<endl;
        }
        #endif // __test
        return vvp[n * 2 - 1][0].first;
    }

// 第一个操作是 n 次 就是必然是 获得一个订单
// 第二个操作是 也是 n次啊， 1+(n-1) 完成1个订单 或 获得 1个订单 从n-1中。
// 3： n-1 / n  如果第二次是完成订单，那么本次只能从剩下的订单里获得，  如果第二次 是获得订单， 那么本次是 2 + (n-2)
//
// 就是 2n 次操作， 如果没有订单 就只能获得， 如果有订单 那么就是
// dfs 1000层好像也不多。。
    int lta(int n)
    {
        vector<vector<int>> vvi(n * 2, vector<int>(n + 1, 0));          // 第i次操作 后 手上有 j 个订单，  剩余订单就是 n-((i-j)/2)
        vvi[0][1] = n;
        for (int i = 1; i < n * 2; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                if ((j - 1) >= 0)
                {
                    // 获得
                    vvi[i][j] += vvi[i - 1][j - 1] * ( n - (i - (j - 1)) / 2 - j );
                }
                if ((j + 1) <= n)
                {
                    // 完成
                    vvi[i][j] += vvi[i - 1][j + 1] * (j + 1);
                }
            }
        }
        #ifdef __test
        for (myvi& vi : vvi)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test
        return vvi[n * 2 - 1][0];
    }

};

int main()
{

    LT lt;

//    int n = 1;
//    int n = 2;
    int n = 3;

    cout<<lt.ltb(n)<<endl;


    return 0;
}
