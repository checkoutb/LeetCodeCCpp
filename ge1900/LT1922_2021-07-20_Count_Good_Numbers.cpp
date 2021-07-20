
#include "../header/myheader.h"

class LT1922
{
public:


// D D


//#define lli long long int
//    lli power(lli x, lli y) {
//        if(y==0) return 1;
//
//        lli ans = power(x, y/2);
//        ans = (ans*ans*(y%2 ? x : 1)) % M;
//        return ans;
//    }
//
//    int countGoodNumbers(long long n) {
//        lli x = n/2 + n%2;
//        lli y = n - x;
//        lli ans = (power(5, x) * power(4, y)) % M;
//        return ans;
//    }


//long long modPow(long long x, long long y, int m = 1000000007)
//{
//    if (y == 0)
//        return 1;
//    auto p = modPow(x, y / 2, m);
//    return p * p * (y % 2 ? x : 1) % m;
//}
//int countGoodNumbers(long long n) {
//    return modPow(5, (n + 1) / 2) * modPow(4, n / 2) % 1000000007;
//}


//long long modPow(long long x, long long y, int mod = 1000000007)
//{
//    if (y == 0)
//        return 1;
//    auto p = modPow(x, y / 2);
//    return p * p % mod * (y % 2 ? x : 1) % mod;
//}
//int countGoodNumbers(long long n) {
//    return modPow(20, n / 2) * (n % 2 ? 5 : 1) % 1000000007;
//}





//Runtime: 4 ms, faster than 22.08% of C++ online submissions for Count Good Numbers.
//Memory Usage: 7 MB, less than 5.16% of C++ online submissions for Count Good Numbers.
// 这n < 10^15 真的离谱， 10^15 个 i++，都要很久吧。。。 似乎是按天计算的。。。
// 可以 pow， 还有 dp。。。
    int lt1922a(long long n)
    {
        const int MOD = 1E9 + 7;
        long cnt1 = n / 2;          // 4
        long cnt2 = (n + 1) / 2;        // 5
        // 4^cnt1 + 5^cnt2
        map<long, long> map1;
        map<long, long> map2;
        map1[1] = 4;
        map2[1] = 5;
        long p1 = cnt1;
        long p2 = cnt2;
//        int p1 = cnt1;          // ...
//        int p2 = cnt2;
//        int p1 = (int) (std::log(cnt1) / std::log(4) + 1);        // ...
//        int p2 = (int) (std::log(cnt2) / std::log(5) + 1);
        for (long i = 1; i * 2 < p1; i *= 2)             // int i....
        {
            map1[i * 2] = map1[i] * map1[i] % MOD;
        }
        for (long i = 1; i * 2 < p2; i *= 2)            // 一个for就够了，  p1 + 1 >= p2 的。
        {
            map2[i * 2] = map2[i] * map2[i] % MOD;
        }
        long ans = 1L;
        #ifdef __test
        cout<<n<<", "<<(n / 2)<<endl;
        cout<<p1<<", "<<p2<<endl;
        for (auto& p : map1)
            cout<<p.first<<" : "<<p.second<<endl;
        for (pair<long, long> p : map2)
        {
            cout<<p.first<<" : "<<p.second<<endl;
        }
        #endif // __test
        while (p1 > 0)
        {
                    // long == long int
            for (map<long, long>::reverse_iterator it = map1.rbegin(); it != map1.rend(); it++)
            {
                if (it->first <= p1)
                {
                    ans = (ans * it->second) % MOD;
                    p1 -= it->first;
                    break;
                }
            }
        }
        while (p2 > 0)
        {
            for (map<long, long>::reverse_iterator it = map2.rbegin(); it != map2.rend(); it++)
            {
                if (it->first <= p2)
                {
                    ans = (ans * it->second) % MOD;
                    p2 -= it->first;
                    break;
                }
            }
        }

        return ans;
    }

};

int main()
{
    LT1922 lt;

    long x = 806166225460393L;

    cout<<lt.lt1922a(x)<<endl;

//    vector<long> v = {
////        1,4,50
////            ,
//            806166225460393L               // 643535977
//
//        };
//
////        cout<<v[0]<<endl;
//
//    for (int i : v)             // int i.....
//        cout<<lt.lt1922a(i)<<endl<<"============"<<endl<<endl;

    return 0;
}
