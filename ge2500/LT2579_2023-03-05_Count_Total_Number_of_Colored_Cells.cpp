
#include "../header/myheader.h"

class LT2579
{
public:

    // D D

    // lee215 的 cut and combine 很秀。。 完全没有考虑过这种。
    // 就是 n=3 的时候 可以 切割组合 成  一个 3*3 ， 一个 2*2
    //                      或者 2个 2*3， 一个 1*1



    //Runtime3 ms
    //    Beats
    //    66.67 %
    //    Memory6 MB
    //    Beats
    //    66.67 %
    // 1 3 5 3 1
    long long lt2579a(int n)
    {
        return 1LL * (2 * n - 1 + 1) / 2 * (n) * 2 - (2 * n - 1);
    }

};

int main()
{

    LT2579 lt;


    return 0;
}
