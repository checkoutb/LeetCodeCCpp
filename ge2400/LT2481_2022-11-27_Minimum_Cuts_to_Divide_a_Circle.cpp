
#include "../header/myheader.h"

class LT2481
{
public:






    //Runtime5 ms
    //    Beats
    //    16.67 %
    //    Memory5.8 MB
    //    Beats
    //    100 %
    // 要么2^x 要么 直接n
    // 不，6可以三刀切。 所以是 odd even？
    // 对称的。
    int lt2481a(int n)
    {
        //return n % 2 == 0 ? n / 2 : n;

        return n % 2 == 0 ? n / 2 : (n == 1 ? 0 : n);           // 1
    }

};

int main()
{

    LT2481 lt;


    return 0;
}
