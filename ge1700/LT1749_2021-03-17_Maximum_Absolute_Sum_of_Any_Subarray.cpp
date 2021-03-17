
#include "../header/myheader.h"

class LT1749
{
public:

// D D

//    for (auto n : nums) {
//        max_sum = max(0, n + max_sum);
//        min_sum = min(0, n + min_sum);
//        res = max({res, max_sum, -min_sum});
//    }
// 不需要t1, t2.


//        for (int& a: A) {
//            s += a;
//            mi = min(mi, s);
//            ma = max(ma, s);
//        }
//        return ma - mi;





//Runtime: 60 ms, faster than 82.72% of C++ online submissions for Maximum Absolute Sum of Any Subarray.
//Memory Usage: 41.4 MB, less than 28.07% of C++ online submissions for Maximum Absolute Sum of Any Subarray.
// hint2: kadane: 出现负数就归0。
    int lt1749a(vector<int>& nums)
    {
        int mx = 0;
        int mn = 0;
        int t1 = 0;
        int t2 = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            mx = max(t1 += nums[i], mx);
            mn = min(t2 += nums[i], mn);
            t1 = t1 < 0 ? 0 : t1;
            t2 = t2 > 0 ? 0 : t2;
        }
//        cout<<mx<<", "<<mn<<endl;
        return max(mx, -mn);
    }

};

int main()
{
    myvi v = {1,-3,2,3,-4};
//    myvi v = {2,-5,1,-4,3,-2};

    LT1749 lt;

    cout<<lt.lt1749a(v)<<endl;

    return 0;
}
