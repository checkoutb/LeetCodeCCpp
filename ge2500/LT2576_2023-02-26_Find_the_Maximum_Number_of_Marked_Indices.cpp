
#include "../header/myheader.h"

class LT2576
{
public:

    // D D

    // 
    //sort(begin(nums), end(nums));
    //for (int j = n - n / 2; j < n; ++j)
    //    i += 2 * nums[i] <= nums[j];
    //return i * 2;


    // 但不知道为什么，无法证明。只是感觉可以。
    //Runtime170 ms
    //    Beats
    //    100 %
    //    Memory60 MB
    //    Beats
    //    30.77 %
    // ? meiyou silu
    int lt2576a(vector<int>& nums)
    {
        int sz1 = nums.size();
        sort(begin(nums), end(nums));

        int md = (sz1 + 1) / 2;
        int ans = 0;

        for (int i = 0; md < sz1; ++i)
        {
            while (md < sz1 && nums[md] < nums[i] * 2)
                ++md;
            if (md < sz1)
                ++ans;
            ++md;
        }

        return ans * 2;
    }

};

int main()
{

    LT2576 lt;

    myvi v = { 2,3,4,5 };

    cout << lt.lt2576a(v) << endl;

    return 0;
}
