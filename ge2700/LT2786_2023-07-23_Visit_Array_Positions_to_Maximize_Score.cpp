
#include "../header/myheader.h"

class LT2786
{
public:




//Runtime205 ms
//Beats
//100%
//Memory99.4 MB
//Beats
//93.33%

    // parities,  奇偶 ？
    long long maxScore(vector<int>& nums, int x)
    {
        int sz1 = nums.size();
        long long mx0 = nums[0];    // 2 4 6
        long long mx1 = nums[0];    // 1 3 5
        if (nums[0] % 2 == 1)
            mx0 -= x;
        else
            mx1 -= x;

        for (int i = 1; i < sz1; ++i)
        {
            if (nums[i] % 2 == 1)
            {
                mx1 = max(mx1 + nums[i], mx0 + nums[i] - x);
            }
            else
            {
                mx0 = max(mx0 + nums[i], mx1 + nums[i] - x);
            }
        }
        return max(mx0, mx1);
    }

};

int main()
{

    LT2786 lt;


    return 0;
}
