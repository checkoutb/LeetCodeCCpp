
#include "../header/myheader.h"

class LT1318
{
public:

// D D

//return popcount(c ^= a | b) + popcount(a & b & c);
//A simpler way to represent Step 2 is a & b & ~c, so for all bit positions where a bit is 0 in c but is 1 in both a and b, the bit is 1 in a & b & ~c


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Flips to Make a OR b Equal to c.
//Memory Usage: 6.3 MB, less than 17.66% of C++ online submissions for Minimum Flips to Make a OR b Equal to c.
// ... (a or b) xor c .... ... 1-1 -> 1... yinggai 2..
    int lt1318a(int a, int b, int c)
    {
        int t2 = (a & b);
        a = (a | b) ^ c;
        int ans = 0;
        while (a > 0)
        {
            if ((a % 2) && (t2 % 2))
            {
                ans++;
            }
            ans += (a % 2);
            a >>= 1;
            t2 >>= 1;
        }
        return ans;
    }

};

int main()
{
//    int a{2}, b{6}, c{5};
//    int a{4}, b{2}, c{7};
    int a{1}, b{2}, c{3};

    LT1318 lt;

    cout<<lt.lt1318a(a, b, c);

    return 0;
}
