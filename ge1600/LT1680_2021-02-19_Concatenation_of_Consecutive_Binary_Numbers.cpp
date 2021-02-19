
#include "../header/myheader.h"

class LT1680
{
public:

// D D

//        for (int i = 1; i <= n; ++i) {
//            if ((i & (i - 1)) == 0)
//                ++bitCount;
//            sum = ((sum << bitCount) % mod);
//            sum += i;
//        }
// i & (i - 1) == 0  <=>  1000 & 0111


// 0ms
//using ll = long long;
//vector<ll> dp;
//const ll MOD=1'000'000'007;
//const int N = 1'00'010;
//
//class Solution {
//public:
//
//    void fill() {
//        dp.resize(N);
//        dp[1] = 1;
//        for(int i = 2; i < N; ++i) {
//            ll len = log2(i) + 1;
//            len = (1LL<<len);
//            dp[i] = (dp[i - 1] * len) % MOD;
//            dp[i] = (dp[i] + i) % MOD;
//        }
//    }
//
//    int concatenatedBinary(int n) {
//        if (dp.empty()) {
//            fill();
//        }
//        return dp[n];
//    }
//};
// ...  1'00'000 ...   java: 1_00_000

//  inline static constexpr int64_t kMod = 1e9 + 7;


//        for (uint64_t i = n; i >= 1; i--)
//        {
//            uint64_t currentWidth = 64 - __builtin_clzl(i);
//            result = (result + shift * i) % m;
//            shift = (shift * (1 << currentWidth)) % m;
//        }


//        for (int i = 1; i <= n; i++)
//            sum = (sum * (int)Math.pow(2, Integer.toBinaryString(i).length()) + i) % MOD


//        for(int i = 1; i <= n; i++) {
//            if((i & (i - 1)) == 0)
//                length++;
//            sum = ((sum << length) | i) % MOD;
//        }


//return (int) LongStream.range(1, n + 1).reduce(0, (sum, i) -> (sum * (int) Math.pow(2, Long.toBinaryString(i).length()) + i) % 1_000_000_007);



//Runtime: 28 ms, faster than 89.66% of C++ online submissions for Concatenation of Consecutive Binary Numbers.
//Memory Usage: 6.3 MB, less than 14.52% of C++ online submissions for Concatenation of Consecutive Binary Numbers.
// 1 2 3
// 1 10 11
// (1 * 2^2 + 2) * 2^2 + 3
// 6*4+3 = 27
// 10^5 100000 =
// 2^10 = 1024   2048 4096 8192 16000 32000 64000 128000  2^17
//
    int lt1680a(int n)
    {
        const int mod = 1E9 + 7;
        vector<int> pw2;
        for (int i = 0; i <= 17; ++i)
        {
            pw2.push_back(1 << i);          // 1 2 4 8
        }
        long ans = 1;
        int pw2i = 2;
        for (int i = 2; i <= n; ++i)
        {
            if (pw2[pw2i] == i)
                pw2i++;
            ans <<= pw2i;
            ans += i;
            ans %= mod;
        }
        return (int) ans;
    }

};

int main()
{
    myvi v = {1,3,1'2};

    LT1680 lt;

    for (int i : v)
        cout<<lt.lt1680a(i)<<endl;

    return 0;
}
