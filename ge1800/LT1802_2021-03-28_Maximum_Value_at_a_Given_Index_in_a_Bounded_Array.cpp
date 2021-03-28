
#include "../header/myheader.h"

class LT1802
{
public:

// D D

//        while (low < high) {
//            long mid = low + (high - low) / 2;
//            long left = mid > index ? (mid + mid - index) * (index + 1) / 2 : mid * (mid + 1) / 2 + index + 1 - mid;
//            long right = mid > n - 1 - index ? (mid - 1 + mid - n + 1 + index) * (n - 1 - index) / 2 : mid* (mid - 1) / 2 + n - index - mid;
//            long sum = left + right;
//            if (sum <= maxSum) {
//                low = mid + 1;
//            } else {
//                high = mid;
//            }
//        }


//    while (l < r) {
//        long m = (l + r + 1) / 2;
//        auto need = m * m - ((m > i ? (m - i - 1) * (m - i) : 0)
//            + (m > j ? (m - j - 1) * (m - j) : 0)) / 2;
//        if (need <= maxSum - n)
//            l = m;
//        else
//            r = m - 1;
//    }



//        while (left < right) {
//            mid = (left + right + 1) / 2;
//            if (test(n, index, mid) <= maxSum)
//                left = mid;
//            else
//                right = mid - 1;
//        }
//    long test(int n, int index, int a) {
//        int b = max(a - index, 0);
//        long res = long(a + b) * (a - b + 1) / 2;
//        b = max(a - ((n - 1) - index), 0);
//        res += long(a + b) * (a - b + 1) / 2;
//        return res - a;
//    }



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum Value at a Given Index in a Bounded Array.
//Memory Usage: 5.9 MB, less than 72.32% of C++ online submissions for Maximum Value at a Given Index in a Bounded Array.
// ... 看了example1，以为是要返回 多少种可能。
// nums[index] is maximized.  应该是指，所有可能的数组中， 最大。
// 那肯定是金字塔，二分搜索。
// 不，金字塔，直接能出公式计算sum了。
// x是 nums[index]
// { (x - index) ... x ... }
// bu, haiyou  [1.1.1.1.1.2.3.4.x.4.3]
// 1*n + sum( { max(0, x - index +/- 1) , +1 , +2, ... x-2,  x-1, x-2, ...  max(0, n-index)} )
// suan le....
    int lt1802a(int n, int index, int maxSum)
    {
        int l = 1;
        int r = maxSum - n + 1;
        while (l < r)
        {
            int mid = (l + r + 1) / 2;
            #ifdef __test
            cout<<l<<", "<<mid<<", "<<r<<endl;
            #endif // __test

            // ... haishi dei yong gongshi.
            int t2 = mid - 1;
            long sum2 = n + t2;
            if (t2 > index)
            {
                int t1 = t2 - index;
                sum2 += ((long) (t1 + t2 - 1)) * (index) / 2;
//                cout<<"    "<<t1<<", "<<t2<<", "<<index<<endl;
            }
            else
            {
                sum2 += ((long) (0 + t2)) * (t2 - 1) / 2;
            }
            if (t2 > (n - index - 1))
            {
                int t1 = t2 - n + index + 1;
                sum2 += ((long) (t1 + t2 - 1)) * (n - index - 1) / 2;
//                cout<<" 2   "<<t1<<", "<<t2<<", "<<(n-index-1)<<endl;
            }
            else
            {
                sum2 += ((long) (t2)) * (t2 - 1) / 2;
            }
            #ifdef __test
            cout<<sum2<<", "<<endl;
            #endif // __test
            if (sum2 > maxSum)
            {
                r = mid - 1;
            }
            else
            {
                l = mid;
            }
        }
        return l;
    }

};

int main()
{
//    myvi v = {4,2,6};
//    myvi v = {6,1,10};
//    myvi v = {6, 3, 32};            // 4,5,6,7,6,5

    myvi v = {6,2,931384943};

    LT1802 lt;

    cout<<lt.lt1802a(v[0], v[1], v[2]);

    return 0;
}
