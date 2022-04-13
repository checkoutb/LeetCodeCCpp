
#include "../header/myheader.h"

class LT2226
{
public:


// D D

// int l = 0, r = 10000000;
// ... candies的max是 10000000






// <= or < , (+1 or +0) / 2, mid+1 or +0 ...
//Runtime: 351 ms, faster than 33.72% of C++ online submissions for Maximum Candies Allocated to K Children.
//Memory Usage: 84.4 MB, less than 12.77% of C++ online submissions for Maximum Candies Allocated to K Children.
// 不能merge，只能split。  就是要分成 k 个组，每个组中糖果个数的 最小值的 最大值。
    int lt2226a(vector<int>& candies, long long k)
    {
        long l = 0L, r = 1000L * INT_MAX;
        while (l < r)
        {
            long mid = (l + r + 1) / 2;
            if (mid == 0)
                return 0;
            long cnt = 0;
            for (int i : candies)
            {
                cnt += (i / mid);
            }
            #ifdef __test
            cout<<l<<", "<<mid<<", "<<r<<endl;
            #endif // __test
            if (cnt >= k)
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        return l;
    }

};

int main()
{

    LT2226 lt;

//    myvi v = {5,8,6};
//    int k = 3;

    myvi v = {2,5};
    int k = 11;

    cout<<lt.lt2226a(v, k);

    return 0;
}
