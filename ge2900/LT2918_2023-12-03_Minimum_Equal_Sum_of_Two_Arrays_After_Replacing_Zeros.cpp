
#include "../header/myheader.h"

class LT2918
{
public:





//     Runtime144 ms
// Beats
// 62.29%
// Memory130.7 MB
// Beats
// 36.29%
    long long minSum(vector<int>& nums1, vector<int>& nums2)
    {
        // size_t sz1 = nums1.size();
        // size_t sz2 = nums2.size();
        long long sum1 = std::accumulate(begin(nums1), end(nums1), 0LL);
        long long sum2 = std::accumulate(std::begin(nums2), std::end(nums2), 0LL);

        int cnt1 = std::count(std::begin(nums1), end(nums1), 0);
        int cnt2 = std::count(std::begin(nums2), std::end(nums2), 0);

        sum1 += cnt1;
        sum2 += cnt2;

        if (sum1 < sum2)
        {
            return cnt1 == 0 ? -1LL : sum2;
        }
        else if (sum1 > sum2)
        {
            return cnt2 == 0 ? -1LL : sum1;
        }
        else
        {
            return sum1;
        }
    }

};

int main()
{

    LT2918 lt;


    return 0;
}
