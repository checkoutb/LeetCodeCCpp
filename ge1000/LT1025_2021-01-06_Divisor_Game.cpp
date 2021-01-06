
#include "../header/myheader.h"

class LT1025
{
public:

// D D

// just return N % 2 == 0




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Divisor Game.
//Memory Usage: 6.3 MB, less than 19.40% of C++ online submissions for Divisor Game.
// x至少有1, N==1时就结束了，   0<x<N
// 要找一条路，这条路上，无论B怎么选， A都是赢。
// 质数的情况下，只能-1.
// 可以减去因子。
// 不，感觉是dp了：
// 1必输
// 2win
// 3lose
// 4win  A:4-3   B:3-2  A:2-1   B:...
// 5
// AB都是optimally，所以 可以角色互换，  就看你第一步走哪里了。
// 5, 如果A-1, 就是4,  4存在必赢的走法，所以 B必赢。
// 就是 第一步 就要走到 比现在小的，且 必输的(这里的必输点会是B的) 点，走不到 就是输
    bool lt1025a(int N)
    {
        vector<bool> vwin(N + 1, false);
        for (int i = 2; i <= N; ++i)
        {
            for (int j = 1, mxj = sqrt(i); j <= mxj; ++j)
            {
                if (i % j == 0 && vwin[i - j] == false)
                {
                    vwin[i] = true;
                    break;
                }
            }
        }
        return vwin[N];
    }

};

int main()
{
//    int n{2};
    int n{3};

    LT1025 lt;

    cout<<lt.lt1025a(n);

    return 0;
}
