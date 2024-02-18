
#include "../header/myheader.h"

class LT2915
{
public:






//     Runtime249 ms
// Beats
// 82.68%
// Memory28.9 MB
// Beats
// 90.97%

    // sum == target
    // longest subseq
    int lengthOfLongestSubsequence(vector<int>& nums, int target)
    {
        size_t sz1 = nums.size();
        std::vector<int> vi(target + 1, 0);

        for (size_t i = 0; i < sz1; ++i)
        {
            if (nums[i] > target)
                continue;
            for (size_t j = target - nums[i]; j >= 1; --j)
            {
                if (vi[j] != 0)
                {
                    vi[j + nums[i]] = std::max(vi[j + nums[i]], vi[j] + 1);
                }
            }
            if (vi[nums[i]] == 0)
                vi[nums[i]] = 1;
        }
        return vi[target] == 0 ? -1 : vi[target];
    }

};

int main()
{

    LT2915 lt;


    return 0;
}
