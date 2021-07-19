
#include "../header/myheader.h"

class LT1359
{
public:

// D D

//int dp[512];
//const int MOD = 1e9+7;
//int go(int n) {
//    if (n==0) return 1;
//    int &r=dp[n];
//    if (r==-1) {
//        r=1ll * go(n-1) * (n*2-1) % MOD;
//    }
//    return r;
//}
//
//class Solution {
//public:
//
//    int countOrders(int n) {
//        memset(dp,-1,sizeof(dp));
//        int r=go(n);
//        for (int i = 2; i <= n; ++i) r = 1ll * r * i % MOD;
//        return r;
//    }
//};


//        long res = 1, mod = 1e9 + 7;
//        for (int i = 1; i <= n; ++i)
//            res = res * (i * 2 - 1) * i % mod;
//        return res;


//    long long res = 1, cap = 1000000007;
//    for (int i=1; i<n+1; ++i) res = res * i % cap;
//    for (int i=1; i<2*n; i+=2) res = res * i % cap;
//    return res;


//The total number of all permutation obviously eauqls to 2n!.
//For each pair, the order is determined, so we need to divide by 2.
//So the final result is (2n)!/(2^n)



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count All Valid Pickup and Delivery Options.
//Memory Usage: 5.9 MB, less than 43.00% of C++ online submissions for Count All Valid Pickup and Delivery Options.
// 1:  p1, d1
// 2: p2 可以在1的基础上， 有3个地方可以， p2 p1 d1 ,  p1 p2 d1 , p1 d1 p1.
//          p2确定后，d2,分别可以  3 + 2 + 1 个地方。
// 3: p3 在2的基础上，   5个地方可以，  5+4+3+2+1 = 15      2有6种可能， 所以 15×6=90
    int lt1359a(int n)
    {
        int ans = 1;        // 1
        int cnt = 2;        // count(p) + count(d)
        const int MOD = (int) 1E9 + 7;
        while (n-- > 1)
        {
            long t2 = (cnt + 2) * (cnt + 1) / 2;
            ans = (t2 * ans) % MOD;
            cnt += 2;
        }
        return ans;
    }

};

int main()
{
    int mod = 1E9 + 7;
    int mod2 = 1e9 + 7;         // 我怎么记得，上次出错了，说1e9+7 是一个double，需要强转呢。。。
    cout<<mod<<", "<<mod2<<endl;

    myvi v = {1,2,3};

    LT1359 lt;

    for (int i : v)
        cout<<lt.lt1359a(i)<<endl;

    return 0;
}
