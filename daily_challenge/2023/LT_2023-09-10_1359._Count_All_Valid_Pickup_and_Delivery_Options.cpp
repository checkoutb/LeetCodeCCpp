
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //long long res = 1, cap = 1000000007;
    //for (int i = 1; i < n + 1; ++i) res = res * i % cap;
    //for (int i = 1; i < 2 * n; i += 2) res = res * i % cap;
    //return res;


    // UI怎么回老版了？ ..有个切换功能
    // 新版更方便 看别人代码。不需要新开页面。
    // 之前觉得新版不好，应该是 找不到 runtime, memory usage (好像是找不到，或者很麻烦，或者没有百分比)

//Runtime: 2 ms, faster than 56.67 % of C++ online submissions for Count All Valid Pickupand Delivery Options.
//Memory Usage : 6 MB, less than 43.33 % of C++ online submissions for Count All Valid Pickupand Delivery Options.

    // p2 (d2) p1 (d2) d1 (d2)
    // 123 -> 29830541
    // 拿和放的 排列。  放之前，必须先拿
    int countOrders(int n)
    {
        const int MOD = 1e9 + 7;
        long long t2 = 1LL;     // n == 1, ans
        long long t3 = 0LL;
        while (n > 1)
        {
            //t3 = n * 2 - 1;        // location of pickup
            // n*2-2  ... 1

            t2 = t2 * (1LL * (1 + n * 2 - 1) * (n * 2 - 1) / 2) % MOD;

            --n;
        }
        return t2;
    }

};

int main()
{

    LT lt;


    return 0;
}
