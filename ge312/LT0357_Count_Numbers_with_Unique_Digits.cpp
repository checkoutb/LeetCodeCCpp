
#include "../header/myheader.h"

class LT0357
{
public:


//        int res = 9;
//        int r = 9;
//
//        while (d > 0) {
//            res*= r--;
//            d--;
//        }
// 每一位 变成了 9*9!/x!; 确实，可以合并成这样的。 9*8 + 9*1*8 + 9*8*7 == 9*9*8


//    int ans = 10, base = 9;
//    for (int i = 2; i <= n && i <= 10; i++) {
//        base = base * (9 - i + 2);
//        ans += base;
//    }
// i 做阶乘因子。
// 并且base 就是 9*9!/x!



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count Numbers with Unique Digits.
//Memory Usage: 8.3 MB, less than 6.45% of C++ online submissions for Count Numbers with Unique Digits.

// 不知道测试用例里有没有大于10的情况。应该没有，反正t3--，大于10的话就变负数了。。肯定是错的了。。
// n = max(10, n); 就可以了。

    // 各个数字唯一，那就是排列了。0.[1,9]
    // 还有前导0.。。。。。
    // 91 == 10 + (9 + 9 * 8).  1位数：[0, 9]是10个数字，2位数：个位0的情况下有9个数字，个位非0的情况下是9*8.
    // 739 == 10 + (9 + 9 * 8) + (9*8 + 9*1*8 + 9*8*7)  3位数字，个位为0，十位为0，全非0..
    // 4位数字应该是 9*8*7 + 9*8*7*2 + 9*8*7*6    个位0，中间2位某位为0，全非0.
    // 非首位为0，可以合并。
    // 4位就是 9*8*7*3 + 9*8*7*6
    int lt0357b(int n)
    {
        if (n <= 1)
            return (int) pow(10, n);
        int result = 10;
        int multi = 0;
        int all = 0;

        int t1 = 0;     // sum
        int t2 = 9;     // !
        int t3 = 8;     // factor
        for (int i = 2; i <= n; i++)
        {
            t1 = t1 + t2 * (t3 + i - 1);            // 合并后的，i-1是非首位的个数，t3是阶乘的下一个因子。
                                            // 就是 9*8*7*3 + 9*8*7*6 变成了 (9*8*7) * (6 + 4-1)
            t2 = t2 * t3;
            t3--;
            #ifdef __test
            cout<<t1<<", "<<t2<<endl;
            #endif // __test
        }
        result += t1;
        return result;
    }


    // deprecated
    // 反向算，算出相同的，然后总数-相同。
    // 而且，n大于10应该比较特殊，大于10以后，必然重复。
    // 还有，[0, 9]不算唯一。
    // n是次方，所以必然10...00.
    int lt0357a(int n)
    {
        int result = 0;
        int multi = 0;
        int all = 0;

        for (int i = 1; i < n; i++)     // 漏了 313 这种情况，那就是 排列了。还有100
        {
            multi *= 9;
            multi += 9;
        }
        all = (int) pow(10, min(11, n));

        #ifdef __test
        cout<<all<<", "<<multi<<endl;
        #endif // __test

        result = all - multi;
        return result;
    }
};

int main()
{
    // 3--739
    int n = 3;

    LT0357 lt;
    cout<<endl<<lt.lt0357b(n)<<endl;
}
