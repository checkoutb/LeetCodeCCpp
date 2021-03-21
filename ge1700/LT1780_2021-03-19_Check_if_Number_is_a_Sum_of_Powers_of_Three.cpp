
#include "../header/myheader.h"

class LT1780
{
public:

// D D

//        long long base = 1;
//        while (3 * base <= n)
//            base *= 3;
//        while (n && base) {
//            if (n >= base) {
//                n -= base;
//            }
//            base /= 3;
//        }
//        return n == 0;
// ... 3^n  永远大于 3^(n-1) + 3^(n-2)....
// 所以当 n >= base 时, 直接减去， 如果现在不减，  后续base 越来越小，更不可能。


//        while (n > 0) {
//            if (n % 3 == 2) {
//                return false;
//            }
//            n /= 3;
//        }
//        return true;


//    while (n > 0 && n % 3 != 2)
//        n = n % 3 == 1 ? n - 1 : n / 3;
//    return n == 0;


//bool checkPowersOfThree1(int n, int p = 1) {
//    if (n == 0)
//        return true;
//    if (p > n)
//        return false;
//    return checkPowersOfThree1(n, p * 3) || checkPowersOfThree1(n - p, p * 3);
//}




//Runtime: 772 ms, faster than 25.00% of C++ online submissions for Check if Number is a Sum of Powers of Three.
//Memory Usage: 6.1 MB, less than 50.00% of C++ online submissions for Check if Number is a Sum of Powers of Three.
    bool lt1780b(int n)
    {
        return dfsb1(n, 0);
    }

    bool dfsb1(int remain, int pow)
    {
        if (remain == 0)
            return true;
        if (remain < 0)
            return false;
        if (pow == 15)
            return false;
        if (dfsb1(remain, pow + 1))
            return true;
        int val = (int) std::pow(3, pow);
        for (int i = pow; i < 15; ++i)
        {
            if (remain >= val)
            {
                if (dfsb1(remain - val, i + 1))
                {
                    return true;
                }
            }
            else
            {
                break;
            }
            val *= 3;
        }
        return false;
    }


// 3^15 ~= 1.43 * 10^7
    bool lt1780a(int n)
    {
//        if (n % 3 != 0)
//            return false;

//        if (n % 3 == 0)
//            return true;

//        // ????
//        return n % 3 == 0;          // 91  = 3 ^ 0  + ..

        return true;            // 21           distinct powers of three........ ... example 3...


    }

};

int main()
{

//    int n = 12;
//    int n = 91;
    int n = 21;

    LT1780 lt;

    cout<<lt.lt1780b(n)<<endl;

    return 0;
}
