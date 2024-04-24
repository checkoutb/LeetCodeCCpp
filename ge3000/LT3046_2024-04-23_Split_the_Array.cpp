
#include "../header/myheader.h"

class LT3046
{
public:




// Runtime
// 4ms
// Beats80.22%of users with C++
// Memory
// 23.64MB
// Beats96.94%of users with C++
    bool isPossibleToSplit(vector<int>& nums)
    {
        sort(begin(nums), end(nums));
        for (int i = 2; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 2])
                return false;
        }
        return true;
    }
};

int main()
{

    LT3046 lt;


    return 0;
}
