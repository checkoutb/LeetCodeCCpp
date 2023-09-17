
#include "../header/myheader.h"

class LT2740
{
public:

    // D D





    //Runtime90 ms
    //    Beats
    //    83.75 %
    //    Memory59.7 MB
    //    Beats
    //    15.6 %
    // max - min
    int findValueOfPartition(vector<int>& nums)
    {
        sort(begin(nums), end(nums));
        int ans = nums[1] - nums[0];
        for (int i = 2; i < nums.size(); ++i)
        {
            ans = min(ans, nums[i] - nums[i - 1]);
        }
        return ans;
    }
};

int main()
{

    LT2740 lt;


    return 0;
}
