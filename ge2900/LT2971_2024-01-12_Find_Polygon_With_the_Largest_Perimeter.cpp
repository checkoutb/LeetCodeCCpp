
#include "../header/myheader.h"

class LT2971
{
public:




// 150ms
// Beats38.22%of users with C++
// Memory
// 79.09MB
// Beats79.47%of users with C++

    // example 2
    long long largestPerimeter(vector<int>& nums)
    {
        std::sort(std::begin(nums), end(nums));
        long long sum2 = std::accumulate(begin(nums), end(nums), 0LL);
        for (size_t i = nums.size() - 1; i >= 2; --i)
        {
            sum2 -= nums[i];
            if (sum2 > nums[i])
                return sum2 + nums[i];
        }
        return -1LL;
    }

};

int main()
{

    LT2971 lt;


    return 0;
}
