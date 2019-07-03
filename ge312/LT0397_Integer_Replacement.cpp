
#include "../header/myheader.h"

class LT0397
{
public:

// details
//        if(n == INT_MAX)
//            return 32;
//        res++;
//        if(n & 1)
//        {
//
//            if((n + 1) % 4 == 0)
//                integerReplacement(n + 1);
//            else
//                integerReplacement(n - 1);
//        }
//        else
// res 是类属性。


//        if(n%2==0)
//            return 1 + integerReplacement(n/2);
//        else
//        {
//            if(((n+1)/2)%2==0)
//            {
//                return 1 + integerReplacement(n+1);
//            }
//            else
//            {
//                return 1 + integerReplacement(n-1);
//            }
//        }
// 提前判断。




//    Runtime: 8 ms, faster than 39.85% of C++ online submissions for Integer Replacement.
//    Memory Usage: 8.3 MB, less than 51.09% of C++ online submissions for Integer Replacement.

    int lt0397a(int n)
    {
        int ans = recursiona1(n, 0);
        return ans;
    }

    int recursiona1(int64_t n, int c)           // n == INT_MAX, n+1...
    {
        if (n == 1)
            return c;
        int ans = 0;
        if (n % 2 == 0)
        {
            n /= 2;
            ans = recursiona1(n, c + 1);
        }
        else
        {
            int c1 = recursiona1(n + 1, c + 1);
            int c2 = recursiona1(n - 1, c + 1);
            ans = min(c1, c2);
        }
        return ans;
    }
};

int main()
{
    int n = 8;

    LT0397 lt;
    cout<<lt.lt0397a(n)<<endl;

    return 0;
}
