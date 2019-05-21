
#include "../header/myheader.h"

class LT0372
{
public:



    // discuss
//    a^1234567 % k = (a^1234560 % k) * (a^7 % k) % k = (a^123456 % k)^10 % k * (a^7 % k) % k
//    f(a,1234567) = f(a, 1234560) * f(a, 7) % k = f(f(a, 123456),10) * f(a,7)%k;

//        int last_digit = b.back();
//        b.pop_back();


// 还有费马小定理，中国剩余定理。
// 如果p是一个质数，而整数a不是p的倍数，则有a^（p-1）≡1（mod p）。
// https://leetcode.com/problems/super-pow/discuss/84475/Fermat-and-Chinese-Remainder

//def superPow(self, a, b):
//    def mod(p):
//        return pow(a, reduce(lambda e, d: (10*e + d) % (p-1), b, 0), p) if a%p else 0
//    return (764 * mod(7) + 574 * mod(191)) % 1337



// 还有欧拉。。好吧，欧拉定理又称 费马-欧拉 定理。
// https://leetcode.com/problems/super-pow/discuss/84466/Math-solusion-based-on-Euler's-theorem-power-called-only-ONCE-C%2B%2BJava1-line-Python

//def superPow(self, a, b):
//    return 0 if a % 1337 == 0 else pow(a, reduce(lambda x, y: (x * 10 + y) % 1140, b) + 1140, 1337)





    // 4/54 tle
    // 不知道怎么缩小b的值。

    // a^b%1337  == (a^x1 % 1337 + a^x2 % 1337 .... )% 1337   成立么？主要是21亿的限制，a^x1应该是21亿下最大值。
    // 1337 应该是个质数吧。不管如何，当x有1337个的时候 可以直接归0.。。并且相加>1337的时候也可以减去1337
    // 并且x1 和 x(n-1) 是相同的，只有最后一个x才有可能不同。
    // b 如何分解。b 能用 %1337 简化吗？  a^b%1337  == a^(b%1337)%1337   是否成立？应该不成立。。不成立
//    >>> 10 ** 14 % 13
//    9
//    >>> 10 ** 15 % 13
//    12
//    >>> 10 ** 2 % 13
//    9
    // a是20亿时。
    // a末尾是0，且b>1337时，必然是0.
    // 那就是另一种方法了，简化a，放弃高位。对对对，只有a的后4位才有意义，前面的没用。
    // a^b%1337  (a%1337)^b%1337 是否。。
    // 这个好像成立的。。。4，5个例子全成立。。。
    // a 分解成 (1337*y + az)， a^b ==> (1337*y + az)^b 因式分解后，除了 az^b 以外，全都带有 1337， 1337x % 1337 就是0.
    // ...1337^3 > 23亿。。。
    // 。。。直接大数减法吧。。
    int lt0372a(int a, vector<int>& b)
    {
        a = a % 1337;
        int t1 = 1;
        int max1 = INT_MAX / a;
        while (minus1a(b, b.size() - 1))
        {
            t1 *= a;
            if (t1 > max1)
                t1 %= 1337;

            #ifdef __test
            cout<<t1<<endl;
            #endif // __test

        }
        return t1%1337;
    }

    bool minus1a(vector<int>& b, int index)
    {
        if (index < 0)
            return false;
        if (b[index] > 0)
        {
            b[index]--;
            return true;
        }
        else
        {
            if (minus1a(b, index - 1))
            {
                b[index] = 9;
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};

int main()
{
    int a = 2;
    vector<int> b = {1,0};

    LT0372 lt;
    cout<<endl<<lt.lt0372a(a, b)<<endl;

    return 0;
}
