
#include "../header/myheader.h"

class LT1952
{
public:

// D D

//        int cnt = 0;
//        for(int i = 1; i <= n; i++)
//            cnt += n % i == 0;
//        return cnt == 3;
// ... 硬算。。


//    int d = 2;
//    for (int i = 2; i < n && d <= 3; i += 1)
//        d += n % i == 0;
//    return d == 3;


//    unordered_set<int> p2 = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };
//    return (int)sqrt(n) * sqrt(n) == n && p2.count(sqrt(n));




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Three Divisors.
//Memory Usage: 5.9 MB, less than 33.33% of C++ online submissions for Three Divisors.
    bool lt1952a(int n)
    {
        if (n <= 3)
            return false;
        int t2 = std::sqrt(n);
        if (t2 * t2 != n)
            return false;
        return isPrime(t2);

        // 不，还有8×8 33 44 55 66 还得看这个是不是 质数。  不是质数的话，可以通过 分解 (交换律) 来获得 2个新的 除数。
        // 4错了， 然后发现 1×4.。 所以 cnt直接2.  所以 3个只能是 1,n,sqrt(n)。
//        int cnt = 1;
//        int mxi = std::sqrt(n);
//        for (int i = 2; i <= mxi; ++i)
//        {
//            if (n % i == 0)
//            {
//                cnt++;
//                if (cnt > 3)
//                    return false;
//            }
//        }
//        return cnt == 3;
    }

    // 100 以内的质数。。
    bool isPrime(int a)
    {
        int mxi = sqrt(a);
        for (int i = 2; i <= mxi; ++i)
        {
            if (a % i == 0)
                return false;
        }
        return true;
    }

};

int main()
{

    LT1952 lt;


    return 0;
}
