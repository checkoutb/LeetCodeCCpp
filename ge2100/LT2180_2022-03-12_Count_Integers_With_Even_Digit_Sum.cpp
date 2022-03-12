
#include "../header/myheader.h"

class LT2180
{
public:

// D D

//        int temp = num, sum = 0;
//        while (num > 0) {
//            sum += num % 10;
//            num /= 10;
//        }
//        return sum % 2 == 0 ? temp / 2 : (temp - 1) / 2;
// 。


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count Integers With Even Digit Sum.
//Memory Usage: 5.9 MB, less than 26.86% of C++ online submissions for Count Integers With Even Digit Sum.
// < 1000 , brute-force
// 看example 2， 感觉是 /2 。。。  对，--，找到比自己小或等于的 最大的 想加为偶数的值 /2 就是结果 。
    int lt2180a(int num)
    {
        int ans = 0;
        int t2 = 0;
        int n = num;
        while (n > 0)
        {
            t2 += n % 10;
            n /= 10;
        }
        while (t2 & 1)
        {
            num--;
            n = num;
            t2 = 0;
            while (n > 0)
            {
                t2 += n % 10;
                n /= 10;
            }
        }
        return num / 2;
    }

};

int main()
{

    LT2180 lt;


    return 0;
}
