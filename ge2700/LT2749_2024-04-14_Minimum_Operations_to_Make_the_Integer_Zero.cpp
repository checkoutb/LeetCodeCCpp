
#include "../header/myheader.h"

class LT2749
{
public:





// Runtime
// 4ms
// Beats36.64%of users with C++
// Memory
// 7.21MB
// Beats83.21%of users with C++

    // 1,1 -> -1
    // 85,42 -> -1
    //      85 = 42*2 + 1  , 1

    // num1 = nums2 * n + x,  x's bit's count <= n
    // so n <= 31 ?
    int makeTheIntegerZero(int num1, int num2)
    {
        long long n1 = num1;
        long long n2 = num2;
        // if (n1 == n2)        // [1,1] -> -1
        //     return 0;

        for (int i = 1; i < 40; ++i)
        {
            long long t2 = n1 - n2 * i;
            // if (t2 <= 0)
            if (t2 < i)     // ...
                break;

            int t3 = bitcnt(t2);
            if (t3 <= i)
                return i;
        }

        return -1;
    }

    int bitcnt(long long n)
    {
        int ans = 0;
        while (n > 0LL)
        {
            if (n & 1LL)
                ++ans;
            n >>= 1;
        }
        return ans;
    }
};

int main()
{

    LT2749 lt;


    return 0;
}
