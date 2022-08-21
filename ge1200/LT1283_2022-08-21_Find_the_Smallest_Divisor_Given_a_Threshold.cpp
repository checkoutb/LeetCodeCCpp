
#include "../header/myheader.h"

class LT1283
{
public:

    // D D

    //while (l <= r)
    //{
    //    int m = l + (r - l) / 2;
    //    int sum = 0;
    //    for (auto i : nums)
    //    {
    //        sum += ceil((float)i / m);
    //    }
    //    if (sum > threshold) l = m + 1;
    //    else r = m - 1;
    //}
    //return l;


    //int left = 1, right = 1e6, m, sum;
    //while (left < right) {
    //    m = (left + right) / 2, sum = 0;
    //    for (int i : A)
    //        sum += (i + m - 1) / m;
    //    if (sum > threshold)
    //        left = m + 1;
    //    else
    //        right = m;
    //}
    //return left;



    //while (l < r) {
    //    int divisor = l + (r - l) / 2;
    //    // if (Arrays.stream(nums).map(n -> (int)Math.ceil(1.0 * n / divisor)).sum() > threshold)
    //    if (Arrays.stream(nums).map(n -> (n + divisor - 1) / divisor).sum() > threshold)
    //        l = divisor + 1;
    //    else
    //        r = divisor;
    //}


    //def smallestDivisor(self, nums, threshold) :
    //    class Lazy :
    //        def __getitem__(self, d) :
    //            return -sum(-x / d for x in nums) <= threshold
    //    return bisect.bisect_left(Lazy(), True, 1, 10 * *6)


    //def smallest_divisor(nums, threshold)
    //    (1..10 * *6).bsearch{ | d | -nums.sum { | x | -x / d } <= threshold }
    //end




//Runtime: 86 ms, faster than 34.69 % of C++ online submissions for Find the Smallest Divisor Given a Threshold.
//Memory Usage : 22.3 MB, less than 24.14 % of C++ online submissions for Find the Smallest Divisor Given a Threshold.
    int lt1283a(vector<int>& nums, int threshold)
    {
        int l = 1, r = INT_MIN;
        for (int n : nums)
        {
            //l = min(l, n);
            r = max(r, n);
        }
        int ans = -1;
        while (l <= r)
        {
            int md = (l + r) / 2;
            int t2 = divide_sum(nums, md);

#ifdef __test
            cout << l << " - " << md << " - " << r << " === " << t2 << endl;
#endif

            if (t2 > threshold)
            {
                l = md + 1;
            }
            else
            {
                ans = md;
                r = md - 1;
            }
        }
        return ans;
    }

    int divide_sum(vector<int>& vi, int md)
    {
        int ans = 0;
        int t2 = md - 1;
        for (int n : vi)
        {
            ans += (n + t2) / md;
        }
        return ans;
    }

};

int main()
{

    LT1283 lt;

    //myvi v = { 1,2,5,9 };
    //int t = 6;

    myvi v = { 44,22,33,11,1 };
    int t = 5;

    cout << lt.lt1283a(v, t) << endl;

    return 0;
}
