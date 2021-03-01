
#include "../header/myheader.h"

class LT1716
{
public:

// D D

//        while (n > 0) {
//            for (int i = 0; i < 7 && n-- > 0; ++i) ans += s + i;
//            s++;
//        }



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Calculate Money in Leetcode Bank.
//Memory Usage: 5.8 MB, less than 97.91% of C++ online submissions for Calculate Money in Leetcode Bank.
// 第x周 是 28 + 7x - 7   21 + 7x
// 前a周，   21*a + (7+14+21+...)
    int lt1716a(int n)
    {
        int week = n / 7;
        int day = n % 7;
        int ans = 21 * week + (7 + week * 7) * week / 2;
        ans += (week + 1 + week + day) * day / 2;
        return ans;
    }

};

int main()
{
    myvi v = {4,10,20};

    LT1716 lt;

    for (int i : v)
        cout<<lt.lt1716a(i)<<endl;

    return 0;
}
