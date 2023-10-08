
#include "../header/myheader.h"

class LT2760
{
public:





//Runtime55 ms
//Beats
//90.78%
//Memory91.4 MB
//Beats
//7.92%

    // 1st ele even
    // even - odd - even 0101010101010101
    // <= threshold
    int longestAlternatingSubarray(vector<int>& nums, int threshold)
    {
        int ans = 0;
        int t2 = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > threshold)
                continue;
            if (nums[i] % 2 == 0)
            {
                t2 = i;
                while (i + 1 < nums.size() && nums[i + 1] <= threshold && (nums[i] % 2 != nums[i + 1] % 2))
                {
                    ++i;
                }
                t2 = i - t2 + 1;
                ans = max(t2, ans);
            }
        }
        return ans;
    }

};

int main()
{

    LT2760 lt;


    return 0;
}
