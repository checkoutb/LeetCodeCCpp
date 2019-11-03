
#include "../header/myheader.h"

class LT0507
{
public:


// .....抄sqrt后，直接0ms。。。确实，max2必然大于sqrt的，但是为什么差距这么大。测试案例中应该有很多质数吧。或者几个超大质数。


// return ((num == 6) || (num == 28) || (num == 496) || (num == 8128) || (num == 33550336))
// 。。。。
// 156 / 156 test cases passed.


//def checkPerfectNumber(self, num):
//    k = num.bit_length() / 2
//    return num > 1 and num == (2 << k) - 1 << k
// ！！！！？？？？


//Runtime: 464 ms, faster than 33.14% of C++ online submissions for Perfect Number.
//Memory Usage: 8.1 MB, less than 87.50% of C++ online submissions for Perfect Number.
    bool lt0507a(int num)
    {
        int sum = num == 1 ? 0 : 1;
        int max2 = num;
//        int root = sqrt(num);
        for (int i = 2; i < max2; i++)         // i < max2    i <= root
        {
            if (num % i == 0)
            {
                sum += (i + num / i);
                max2 = num / i;
                if (max2 > num)         // 增加这个后，468，476ms。。。
                    return false;
            }
        }
        return num == sum;
    }
};

int main()
{
    int n = 28;

    LT0507 lt;
    cout<<" : "<<lt.lt0507a(n);

    return 0;
}
