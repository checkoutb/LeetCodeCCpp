
#include "../header/myheader.h"

class LT2256
{
public:

// D D

//            int tmp = std::abs(static_cast<int>(prefix/count1) - static_cast<int>(sum/count2));


//        int n(size(nums)), minAverageDifference(INT_MAX), index;
//        long long sumFromFront(0), sumFromEnd(0);
// 声明并初始化变量。。


//		leftSum += nums[i];
//		rightSum = sum - leftSum;
//		long diff = Math.abs(leftSum / (i + 1) - (len - i == 1 ? 0 : rightSum / (len -i - 1)));


//    vector<long long> ps{0};
//    for (int n : nums)
//        ps.push_back(n + ps.back());
//    long long n = nums.size(), min_i = 0, sum = ps.back(), min_diff = INT_MAX;
//    for (int i = 1; i < n; ++i)
//        if (int diff = abs(ps[i] / i - (sum - ps[i]) / (n - i)); min_diff > diff) {
//            min_diff = diff;
//            min_i = i - 1;
//        }
//    return min_diff <= sum / n ? min_i : n - 1;




//Runtime: 150 ms, faster than 70.80% of C++ online submissions for Minimum Average Difference.
//Memory Usage: 78.4 MB, less than 61.24% of C++ online submissions for Minimum Average Difference.
// 10^5 * 10^5
    int lt2256a(vector<int>& nums)
    {
        int sz1 = nums.size();
        long sum2 = std::accumulate(begin(nums), end(nums), 0L);
        long cnt2 = sz1;
        long sum3 = 0L;
        long cnt3 = 0L;
        int ans = -1;
        long mn = LONG_MAX;
        for (int i = 0; i < sz1 - 1; ++i)
        {
            sum3 += nums[i];
            cnt3++;
            sum2 -= nums[i];
            cnt2--;
            long t2 = (sum3 / cnt3) - (sum2 / cnt2);
            t2 = std::abs(t2);
            if (t2 < mn)
            {
                ans = i;
                mn = t2;
            }
        }
        sum3 += nums[sz1 - 1];
        cnt3++;
        long t2 = (sum3 / cnt3);
        if (t2 < mn)
        {
            ans = sz1 - 1;
            mn = t2;
        }
        return ans;
    }

};

int main()
{

    LT2256 lt;

//    myvi v = {2,5,3,9,5,3};
//    myvi v = {0};
//    myvi v = {INT_MAX, INT_MAX, INT_MAX};
//    myvi v = {4,2,0};         // 2
    myvi v = {0,0,0};       // 0

    cout<<lt.lt2256a(v)<<endl;


    return 0;
}
