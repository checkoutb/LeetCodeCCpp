
#include "../../header/myheader.h"
#include <iomanip>

class LT
{
public:

// D D

//        int maxNum = (int)sqrt((double)c);
//        int i = 0;
//        int j = maxNum;
//        while(i <= j) {
//            int diff = c - i * i;
//            if(diff == j * j) {
//                return true;
//            }
//            else if(diff < j * j) {
//                j--;
//            }
//            else {
//                i++;
//            }
//        }
// 。。。。总觉得 会漏掉一些。。。


//        HashSet<Integer> set = new HashSet<Integer>();
//
//        for (int i = 0; i <= Math.sqrt(c); i++) {
//            set.add(i * i);
//            if (set.contains(c - i * i)) {
//                return true;
//            }
//        }
//        return false;

//Fermat
//。。baidu了下，  费马。。。。。

//require 'prime'
//def judge_square_sum(c)
//  c == 0 || c.prime_division.all? { |p, e| p % 4 != 3 || e.even? }
//end


//a natural number is a sum of two squares
//if and only if each prime factor that's 3 modulo 4 occurs to an even power in the number's prime factorization.

//费马大定理
//大约在1637年左右，法国学者费马在阅读丢番图（Diophatus）《算术》拉丁文译本时，
//曾在第11卷第8命题旁写道：“将一个立方数分成两个立方数之和，或一个四次幂分成两个四次幂之和，
//或者一般地将一个高于二次的幂分成两个同次幂之和，这是不可能的。
//关于此，我确信已发现了一种美妙的证法 ，可惜这里空白的地方太小，写不下。”

//(3)没有一个形如4n+3的素数，能表示为两个平方数之和。

//一个自然数可能是:
//    一个平方数 if and only if each prime factor occurs to an even power in the number’s prime factorization.
//    两个平方数之和 if and only if each prime factor that’s 3 modulo 4 occurs to an even power in the number’s prime factorization.
//    三个平方数之和 if and only if it’s not of the form 4a(8b+7) with integers a and b.
//    四个平方数之和. Period. No condition. You never need more than four.



// AC
// 感觉只有硬算啊。。。
    bool lta(int c)
    {
        int mxi = (int) (std::sqrt(c) + 1);
        for (int i = 0; i < mxi; ++i)
        {
            int t2 = c - i * i;
//            float f2 = std::sqrt(t2);         // 返回的就已经没有小数了。。        .. 这个还有个double的版本， 看detail里有人用的 double的，可以的。
//            if ((f2 - (int) f2) < 0.0002)
            int f2 = (int) std::sqrt(t2);
            if (f2 * f2 == t2)
            {
                #ifdef __test
//                cout<<setiosflags(ios::fixed)<<setprecision(15)<<i<<", "<<f2<<", "<<t2<<endl;
                #endif // __test
                return true;
            }
        }
        return false;
    }

};

int main()
{
//    int c = 2;
    int c = 999999999;          // false

    LT lt;

    cout<<lt.lta(c)<<endl;

    return 0;
}
