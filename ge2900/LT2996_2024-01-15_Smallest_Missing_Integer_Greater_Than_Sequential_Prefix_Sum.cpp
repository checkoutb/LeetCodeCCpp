
#include "../header/myheader.h"

class LT2996
{
public:

    // D D


    // sort(begin(nums) + i, end(nums));
    // for (i = i - 1; i < nums.size(); ++i)
    //     if (nums[i] == sum)
    //         ++sum;


// Runtime
// 4ms
// Beats66.89%of users with C++
// Memory
// 19.49MB
// Beats32.97%of users with C++
    int missingInteger(vector<int>& nums)
    {
        int t2 = nums[0];
        for (int i = 1; i < nums.size() && nums[i] == nums[i - 1] + 1; ++i)
        {
            t2 += nums[i];
        }

        set<int> set2(begin(nums), end(nums));

        while (set2.find(t2) != set2.end())
        {
            ++t2;
        }
        return t2;
    }

};

int main()
{

    LT2996 lt;


    return 0;
}
