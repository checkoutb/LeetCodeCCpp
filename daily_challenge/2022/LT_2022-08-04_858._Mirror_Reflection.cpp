
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    // return (p & -p) > (q & -q) ? 2 : (p & -p) < (q & -q) ? 0:1;


//        while(p%2==0 and q%2==0)
//        {
//            p/=2;
//            q/=2;
//
//        }
//        if(p%2!=0 and q%2==0)
//            return 0;
//        if(p%2!=0 and q%2!=0)
//            return 1;
//        return 2;

//        int g = gcd(p,q);
//        int pp = p/g;
//        int qq = q/g;
//        if (qq%2==0) return 0;
//        if (pp%2==0) return 2;
//        return 1;


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Mirror Reflection.
//Memory Usage: 6 MB, less than 26.45% of C++ online submissions for Mirror Reflection.
// 之前看过，应该是 无限扩展。  但是无限扩展的话，是不是 最小公倍数？
// q < p ，所以 是 垂直于 水平面的 2块 无限高的 玻璃 之间 互相 反射。 直到 高度 是 p 的倍数。  所以是 每次 加 q ，直到 它等于 p的 倍数。
// mq = np , 我感觉 费马要出来了。。
// 还要考虑 天花板的 反射。。 不然 1 永远不可能。
// 这个光 可能再次返回 源点吗？
// 好像 就是 最小公倍数。
    int lta(int p, int q)
    {
        int t2 = gcda(p, q);
        t2 = q * p / t2;

        int t3 = t2 / q;

        if ((t2 / p) % 2 == 0)
        {
            return 0;           // 偶数块镜子。
        }

        return (t3 % 2 == 0) ? 2 : 1;
    }

    int gcda(int a, int b)
    {
        return b == 0 ? a : gcda(b, a % b);
    }


};

int main()
{

    LT lt;

    int p = 3, q = 1;


    cout<<lt.lta(p,q)<<endl;

    return 0;
}
