
#include "../header/myheader.h"

class LT2541
{
public:


// Runtime
// 101ms
// Beats41.31%of users with C++
// Memory
// 77.11MB
// Beats6.18%of users with C++

    // 5 4 3
    // 6 5 1   -> 5-5  6-4  1-3  2-3
            // 6-5 5-4 1-3 1-3 1-3
    // ? k ??....
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k)
    {
        long long ans = 0LL;
        if (k == 0)
            k = INT_MAX;

        vector<int> diff(nums1.size());
        long long sum2 = 0LL;
        long long sum3 = 0LL;
        for (int i = 0; i < nums1.size(); ++i)
        {
            diff[i] = nums1[i] - nums2[i];
            sum2 += diff[i];
            if (abs(diff[i]) % k != 0)
            {
                return -1;
            }
            if (diff[i] > 0)
            {
                sum3 += diff[i];
            }
        }
        if (sum2 != 0)
        {
            return -1LL;
        }
        // std::sort(std::begin(diff), std::end(diff));

        ans = sum3 / k;
        return ans;
    }
};

int main()
{

    LT2541 lt;


    return 0;
}
