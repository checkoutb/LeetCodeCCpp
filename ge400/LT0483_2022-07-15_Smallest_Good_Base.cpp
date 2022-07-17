
#include "../header/myheader.h"

class LT0483
{
public:



    // g


    // 1 + k + k*k + k*k*k + k^4 ... = n
    // 等比数列。
    // n = 1 * (1 - k^x) / (1 - k)
    // n - kn = 1 - k^x
    // - n + kn + 1 = k^x
    // (k-1)n + 1 = k^x
    // x = log((k-1)n+1) / logk
    // 感觉是 x 可以遍历。 10^18 ~= 2^60  二进制需要60个字符，3/4/5.更短。
    // 2.4.8 .  质数。。。 不， Example 2.
    // 少一个大数类型。。
    // x * logk = log((k-1)n+1)
    // log(10^x) * logk = 
    // log(10^x + k) =                  // .. 这步错了， logM + logN = log(MN)
    // 10^x + k = (k - 1) * n + 1
    // 10^x = kn - n + 1 - k
    //      = kn - k - (n - 1)
    //      = k(n-1)-(n-1)

    // 13 - 3 - 111, 3*(12)-(12) ... != 10^3 ...
    string lt0483(string n)
    {

    }

};

int main()
{

    LT0483 lt;


    return 0;
}
