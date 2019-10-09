
#include "../header/myheader.h"

class LT0441
{
public:


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Arranging Coins.
//Memory Usage: 8.2 MB, less than 92.86% of C++ online submissions for Arranging Coins.

    // x*(x+1) = n*2
    // x^2 + x - n*2 = 0
    // 求根公式。
    int lt0441a(int n)
    {
        long long n2 = n;           // 直接 = n*2，是越界的，因为n*2是一个int。
        n2 *= 2;
        int x = (int) (-1 + sqrt(1 + n2 * 4))/2;
        return x;
    }
};

int main()
{
    int n = 10;

    LT0441 lt;
    cout<<lt.lt0441a(n)<<endl;

    return 0;
}
