
#include "../header/myheader.h"

class LT1175
{
public:

// D D

//    int numPrimeArrangements(int n)
//    {
//        auto countPrimes = [](int n)
//        {
//            vector p(max(2, n+1), 1);
//            for(auto i{2}; i*i<=n; ++i)
//            if(p[i]) for(auto j{i*i}; j<=n; p[j]=0, j+=i);
//            return count(begin(p)+2, end(p), 1);
//        };
//
//        auto factorial = [](int n)
//        {
//            long out{1};
//            for(; n; out = (out*(n--)) % 0x3B9ACA07);
//            return out;
//        };
//
//        int p = countPrimes(n);
//        return (factorial(p)*factorial(n-p)) % 0x3B9ACA07;
//    }
// hao diao...


//        int[] non = new int[n+1];
//        int[] cnt = {0, 1};
//        long res = 1;
//        for (int i=2; i<=n; i++) {
//            if (non[i] == 0)
//                for (int m=i*i; m<=n; m+=i)
//                    non[m] = 1;
//            res = res * ++cnt[non[i]] % 1_000_000_007;
//        }
//        return (int) res;
// ???


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Prime Arrangements.
//Memory Usage: 6.2 MB, less than 14.50% of C++ online submissions for Prime Arrangements.
// 2,3,5,7,11 .. 在 下标+1为素数 上。
// 等于就是 分2组，然后 各自排列？
    int lt1175a(int n)
    {
        long ans = 1;
        int cntPrime = 0;
        int cntNotPrime = 1;
        bool isPrime[101] = {false};
        for (int i = 1; i <= n; i++)
        {
            isPrime[i] = true;
        }

        for (int i = 2; i <= n; i++)
        {
            if (isPrime[i])
            {
                cntPrime++;
                for (int j = 2; j * i <= n; j++)
                {
                    isPrime[j * i] = false;
                }
            }
            else
            {
                cntNotPrime++;
            }
        }
//        cout<<cntPrime<<" : "<<cntNotPrime<<endl;
        int mod = 1E9 + 7;
        while (cntPrime > 0)
        {
            ans = (ans * cntPrime) % mod;
            cntPrime--;
        }
        while (cntNotPrime > 0)
        {
            ans = (ans * cntNotPrime) % mod;
            cntNotPrime--;
        }

        return (int) ans;
    }


};

int main()
{
//    int n = 5;
    int n = 100;

    LT1175 lt;

    cout<<lt.lt1175a(n)<<endl;

    return 0;
}
