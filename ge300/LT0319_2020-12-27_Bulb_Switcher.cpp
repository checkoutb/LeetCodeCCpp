
#include "../header/myheader.h"

class LT0319
{
public:

// D D




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Bulb Switcher.
//Memory Usage: 6 MB, less than 99.82% of C++ online submissions for Bulb Switcher.
// 1    0   0   1   0   0   0   1   1   0 0
// 0    1   1   0
// .. 12 的时候想到了，  分解因子， 2数相乘， 就是说 开关会被转换 2次，  除了 3*3 4*4 5*5 这种 只会被转换一次。   1*12=12。
// 上面8 还错了，应该是 0。
// 直接 sqrt 就可以了。。。
    int lt0319a(int n)
    {
        int cnt = 0;
        int t2 = 1;
        while (t2 * t2 <= n)
        {
            cnt++;
            t2++;
        }
        return cnt;
    }

};

int main()
{
    myvi v = {3,0,1};

    LT0319 lt;

    for (int i : v)
        cout<<lt.lt0319a(i)<<endl;

    return 0;
}
