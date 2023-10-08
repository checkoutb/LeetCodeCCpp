
#include "../../header/myheader.h"

class LT
{
public:

// D D




//Runtime0 ms
//Beats
//100%
//Memory6.7 MB
//Beats
//17.22%

    // 10   2^5   32   334  36
    // 11  335 45  56 30 443 48   3332 54
    // 12 3333 81  2^6 64  552
    // 13 3334
    // 30 3^10 59049  2^15 32768  5^6 15625
    // 4 22 > 13
    // 5 23
    // 6 222 < 33
    // 7 223 > 331
    // 8 233 > 2222
    // 9 333 > 2223
    //
    // iterate  2^x * 3^y   2x+3y=n      2^x * 3^(..)
    //   5 == 2+3,   5^1 < 2^1 * 3^1
    //   7 = 4+3  7^1 < 3*4
    // 4,  4 != 1+3,  need 2^x * 3^y
    // 3^2 > 2^3
    // more 3. then 2
    int integerBreak(int n)
    {
        if (n <= 3)
            return n - 1;

        int cnt3 = n / 3;
        if (n % 3 == 1)
            --cnt3;
        int ans = pow(3, cnt3) * ((n % 3 == 0) ? 1 : (n - 3 * cnt3));
        return ans;
    }
};

int main()
{

    LT lt;


    return 0;
}
