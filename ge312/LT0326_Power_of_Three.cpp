
#include "../header/myheader.h"

class LT0326
{
public:

//    Runtime: 56 ms, faster than 44.20% of C++ online submissions for Power of Three.
//Memory Usage: 8 MB, less than 68.42% of C++ online submissions for Power of Three.

// n/3会损失小数，所以需要%3保证整除。
//        if(n<=0) return false;
//        while(n>1)
//        {
//            if(n%3 != 0)
//                return false;
//            n = n/3;
//        }
//        return true;

// log以3为底的n的结果。
//	return n > 0 && (Math.log10(n) / Math.log10(3))%1 == 0;


// int范围内最大的3的次方数是3^19，就是1162261467，int范围内所有3的次方数都能吧这个数整除。
//return n > 0 && 1162261467 % n ==0;


    bool lt0326a(int n)
    {
        if (n == 1)
            return true;
        if (n == 0 || n % 3 != 0)
            return false;
        int t = 1;
        while (t < n)
        {
            t *= 3;
        }
        return t == n;
    }
};


int main()
{
    int args[] = {27,0,9,45,1};
    LT0326 lt;
    for (int i : args)
    {
        cout<<endl<<lt.lt0326a(i)<<endl;
    }
    return 0;
}
