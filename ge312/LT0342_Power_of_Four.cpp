
#include "../header/myheader.h"

class LT0342
{
public:



// discuss
// return num > 0 && (num&(num-1)) == 0 && (num & 0x55555555) != 0;
//                                        010101010101，，就是求奇数次方。
// return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
//                     2的次方                    2的奇数次方%3==2,2的偶数次方%3==1.


//        int cnt = 0;
//        for (; num > 0; num >>= 2) {
//            int t = num & 3;
//
//            if (t == 1) {
//                if (++cnt > 1)
//                    return false;
//            } else if (t > 0)
//                return false;
//        }
//        return cnt == 1;


// 或者把int范围内所有4的次方列举出来。。

//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Power of Four.
//Memory Usage: 8.3 MB, less than 5.63% of C++ online submissions for Power of Four.
// 全是4ms的。
    bool lt0342b(int num)
    {
        if (num <= 0)
            return false;
        double dou = log(num) / log(4);
        int di = (int) dou;
        return (dou - di) < 0.00001;
    }

    // 又看了power of three...算了下 4^15 是int中最大的值。。。。log也不错。
    // ....4^15..2 是符合的。。8 也是符合的。。。。。
    // error。。。
    bool lt0342a(int num)
    {
        return num > 0 && 1073741824 % num == 0 && num != 2;
    }
};

int main()
{
    int n = 16;

    LT0342 lt;
    cout<<endl<<endl<<lt.lt0342b(n)<<endl;
    return 0;
}
