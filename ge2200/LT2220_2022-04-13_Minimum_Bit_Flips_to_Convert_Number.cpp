
#include "../header/myheader.h"

class LT2220
{
public:

// D D

//    for(int i = 1 ; i< 32 ; i++)
//    {
//        if(((s&1) ^ (g&1)) == 1)
//            cnt++;
//        s = s>>1;
//        g = g>>1;
//    }

//        int ans=start^goal;
//        return __builtin_popcount(ans);


//return Integer.bitCount(start^goal);


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Bit Flips to Convert Number.
//Memory Usage: 5.9 MB, less than 78.53% of C++ online submissions for Minimum Bit Flips to Convert Number.
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Bit Flips to Convert Number.
//Memory Usage: 5.9 MB, less than 36.33% of C++ online submissions for Minimum Bit Flips to Convert Number.
    int lt2220a(int start, int goal)
    {
        int t2 = start ^ goal;
        int ans = 0;
//        while (t2 > 0)
//        {
//            ans += (t2 % 2);
//            t2 >>= 1;
//        }

        while (t2 > 0)
        {
            ans++;
            t2 &= (t2 - 1);
        }
        return ans;
    }

};

int main()
{

    LT2220 lt;


    return 0;
}
