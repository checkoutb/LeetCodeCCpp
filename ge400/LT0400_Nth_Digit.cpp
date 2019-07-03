
#include "../header/myheader.h"

class LT0400
{
public:


// details
//            if(n-(i+1)*9*pow(10, i) > 0) {
//                n -= (i+1)*9*pow(10, i);
//                i ++;
//                continue;
//            }
//            int a = (n-1)/(i+1);
//            int b = (n-1)%(i+1);
//            int num = pow(10, i) + a;
//            for(int j = 0; j < i - b ; j ++) {
//                num = num/10;
//            }
//            num = num%10;
// (n - 1) % b... n % b == 0 且 n > 0 时，(n - 1) % b 必然 是 b - 1。最后一位。。..然后t2 = b - 1 - t2;


// discuss
//    public int findNthDigit(int n) {
//        n -= 1;
//        int digits = 1, first = 1;
//        while (n / 9 / first / digits >= 1) {
//            n -= 9 * first * digits;
//            digits++;
//            first *= 10;
//        }
//        return (first + n/digits + "").charAt(n%digits) - '0';
//    }
// 转string，charAt。。。



//    Runtime: 0 ms, faster than 100.00% of C++ online submissions for Nth Digit.
//    Memory Usage: 8.2 MB, less than 81.43% of C++ online submissions for Nth Digit.


    int lt0400a(int n)
    {
        int b = 1;      // 一个数字有多少个digit
        int64_t c = 9;      // b个digit的数字有多少个
        int64_t d = 9;
        int ans = 0;

        while (n > d)
        {
            n -= d;
            b++;
            c *= 10;
            d = c * b;
        }

        int64_t t1 = c / 9 + ((n - 1) / b);
        int t2 = n % b;
        t2 = (t2 == 0 ? 0 : b - t2);        // 0是最后一位，1,2,3,4是第1，2，3，4位。

        #ifdef __test
        cout<<t1<<", "<<t2<<", "<<c<<", "<<b<<", "<<n<<endl;
        #endif // __test

        while (t2 > 0)
        {
            t1 /= 10;
            t2--;
        }
        return t1 % 10;
    }
};

int main()
{
    int n = 1002;

    LT0400 lt;
    cout<<lt.lt0400a(n)<<endl;

    return 0;
}
