
#include "../header/myheader.h"

int guess(int num);

class LT0374
{
public:



// discuss
//        lo, hi = 1, n
//        while lo < hi:
//            mid = (lo + hi) / 2
//            if guess(mid) == 1:
//                lo = mid + 1
//            else:
//                hi = mid
//        return lo




//    Runtime: 4 ms, faster than 93.51% of C++ online submissions for Guess Number Higher or Lower.
//    Memory Usage: 8.2 MB, less than 30.32% of C++ online submissions for Guess Number Higher or Lower.

    int lt0374a(int n)
    {
        int result = n / 2;
        int t1 = 0;
        long long low = 1;
        long long high = n;
        long long mid = 0;
        while ((t1 = guess(result)) != 0)
        {
//            mid = (low + high) / 2;     // == result
            if (t1 < 0)     // aim更小
            {
                high = result;
                result = (low + result - 1) / 2;
            }
            else
            {
                low = result;
                result = (result + 1 + high) / 2;
            }
            #ifdef __test
            cout<<"...  "<<result;
            system("pause");
            #endif // __test
        }
        return result;
    }
};

int aim = 6;

int guess(int num)
{
    if (aim == num)
        return 0;
    return (aim < num ? -1 : 1);
}

int main()
{
    int n = 10;
    LT0374 lt;
    cout<<endl<<lt.lt0374a(n)<<endl;
    return 0;
}

