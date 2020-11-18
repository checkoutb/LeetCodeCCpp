
#include "../header/myheader.h"

class LT1342
{
public:

// D D

//            if(num%2)
//                ans++, num--;
//            else
//                num /= 2, ans++;

//    return num ? __builtin_popcount(num) + 31 - __builtin_clz(num) : 0;
// ... c++ de ............

//    def numberOfSteps (self, num: int) -> int:
//        digits = f'{num:b}'
//        return digits.count('1') - 1 + len(digits)


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Steps to Reduce a Number to Zero.
//Memory Usage: 6.3 MB, less than 17.21% of C++ online submissions for Number of Steps to Reduce a Number to Zero.
// 感觉 优先 /2 就可以了。
// 感觉像： 转为二进制，最高位1所在位数 + 还有多少个1  就是结果？
    int lt1342(int num)
    {
        int ans = 0;
        while (num > 0)
        {
            if (num % 2 == 1)
            {
                ans++;
                num -= 1;
            }
            else
            {
                num >>= 1;
                ans++;
            }
        }
        return ans;
    }

};

int main()
{

    vector<int> v = {14,8,123};

    LT1342 lt;

    for (int i : v)
        cout<<lt.lt1342(i)<<endl;

    int num = 123;
    cout<<(__builtin_popcount(num) + 31 - __builtin_clz(num))<<endl;

    return 0;
}
