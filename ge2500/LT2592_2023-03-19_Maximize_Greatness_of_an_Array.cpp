
#include "../header/myheader.h"

class LT2592
{
public:

    // D D



    //Runtime134 ms
    //    Beats
    //    100 %
    //    Sorry, there are not enough accepted submissions to show data
    //    Memory75.9 MB
    //    Beats
    //    100 %
    int lt2592a(vector<int>& nums)
    {
        int sz1 = nums.size();
        sort(begin(nums), end(nums));
        int idx = sz1 - 1;
        int ans = 0;
        for (int i = sz1 - 1; i >= 0; --i)
        {
            if (nums[idx] > nums[i])
            {
                --idx;
                ++ans;
            }
        }
        return ans;
    }

};

int main()
{

    LT2592 lt;


    return 0;
}
