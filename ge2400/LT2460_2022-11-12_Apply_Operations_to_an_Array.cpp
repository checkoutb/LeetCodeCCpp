
#include "../header/myheader.h"

class LT2460
{
public:

    // D D

    // stable_sort(nums.begin(), nums.end(), [](int a, int b) { return !a < !b; });



    //Runtime13 ms
    //    Beats
    //    16.60 %
    //    Memory8.8 MB
    //    Beats
    //    55.99 %
    vector<int> lt2460a(vector<int>& nums)
    {
        int idx = 0;
        int en = 0;
        int sz1 = nums.size();

        for (int i = 0; i < sz1 - 1; ++i)
        {
            if (nums[i] == nums[i + 1])
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        for (int i = 0; i < sz1; ++i)
        {
            if (nums[i] != 0)
            {
                nums[en++] = nums[i];
            }
        }

        while (en < sz1)
        {
            nums[en++] = 0;
        }

        return nums;

        //for (; idx < sz1 - 1; ++idx)
        //{
        //    if (nums[idx] == nums[idx + 1])
        //    {
        //        nums[en++] = nums[idx] * 2;
        //        ++idx;
        //        nums[idx] = 0;
        //    }
        //}
        //nums[en++] = nums[sz1 - 1];
        //while (en < sz1)
        //{
        //    nums[en++] = 0;
        //}
        //return nums;
    }

};

int main()
{

    LT2460 lt;


    return 0;
}
