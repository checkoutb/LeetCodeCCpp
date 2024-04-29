
#include "../header/myheader.h"

class LT3133
{
public:

    // D D

        // long long a = x;
        // while (--n > 0)
        //     a = (a + 1) | x;
        // return a;



        // n--;
        // long long a = x, b;
        // for (b = 1; n > 0; b <<= 1) {
        //     if ((b & x) == 0) {
        //         a |= (n & 1) * b;
        //         n >>= 1;
        //     }
        // }
        // return a;




// Runtime
// 7ms
// Beats10.00%of users with C++
// Memory
// 7.76MB
// Beats90.00%of users with C++

    // <   and   x
    // x & x+1 & x+2 ... x+n
    // x+y & x+y+1 & ...
    // no .. 7, 15 ..
    // x,  x+(1<< x max bit + 1)
    // no   3&4 = 0 !=3   low bit is fixed, high bit from 0 to n ,  for first is x , so & always <= x
    // 4 5 6 ... suffix zero
    //
    // .... 2,5 -> 7 ... 1001 & 1011 = 5 ...
    long long minEnd(int n, int x)
    {
        int low1 = -1;
        int high1 = -1;

        for (int i = 0; i < 30; ++i)
        {
            if (x & (1 << i))
            {
                if (low1 == -1)
                    low1 = i;
                high1 = i;
            }
        }

        int cnt0 = 0;
        for (int i = 0; i < high1; ++i)
        {
            if ((x & (1 << i)) == 0)
            {
                ++cnt0;
            }
        }

        int t2 = 1 << cnt0;
        long long ans = -1LL;
        ans = (n - 1) / t2;
        ans <<= (high1 + 1);
        ans += x;

        t2 = (n - 1) % t2;
        int idx = 0;

        // cout<<t2<<", "<<ans<<endl;

        for (int i = 0; i < high1; ++i)
        {
            // cout<<i<<", "<<x<<endl;
            if ((x & (1 << i)) == 0)
            {
                if ((t2 & (1 << idx)) != 0)
                    ans |= (1 << i);
                idx++;
            }
        }
        return ans;


        // int t2 = (1 << low1);
        // long long ans = -1LL;
        // if (t2 >= n)
        // {
        //     ans = x + n - 1;
        //     return ans;
        // }
        //
        // // n -= t2;    // - x self
        //
        // ans = (n - 1) / (1 << low1);
        // ans <<= (high1 + 1);
        // ans += x;
        // ans += (n - 1) % (1 << low1);
        // return ans;
    }
};

int main()
{

    LT3133 lt;

    // 4,x2   7
    // 10   11,

    // 2,5  7


    return 0;
}
