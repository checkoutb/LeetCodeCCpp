
#include "../header/myheader.h"

class LT2427
{
public:

    // D D

    // for (int n = 2; n <= __gcd(a, b); ++n)

    // for (int n = 1; (hi%n) == 0 && n <= sqrt(hi); ++n)



//Runtime: 0 ms, faster than 100.00 % of C++ online submissions for Number of Common Factors.
//Memory Usage : 6 MB, less than 32.17 % of C++ online submissions for Number of Common Factors.
    int lt2427a(int a, int b)
    {
        int ans = 1;
        for (int i = 2, mxi = min(a, b); i <= mxi; ++i)
        {
            if ((a % i == 0) && (b % i == 0))
                ++ans;
        }
        return ans;
    }

};

int main()
{

    LT2427 lt;


    return 0;
}
