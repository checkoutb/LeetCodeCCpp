
#include "../header/myheader.h"

class LT2598
{
public:

    // D D





    //Runtime156 ms
    //    Beats
    //    100 %
    //    Memory105.3 MB
    //    Beats
    //    27.27 %
    int lt2598a(vector<int>& nums, int value)
    {
        int sz1 = nums.size();

        vector<int> vi(value);

        for (int i : nums)
        {
            ++vi[(i % value + value) % value];
        }

        int mni = 0;
        for (int i = 1; i < vi.size(); ++i)
        {
            if (vi[i] < vi[mni])
                mni = i;
        }

        return mni + vi[mni] * value;
    }

};

int main()
{

    LT2598 lt;


    return 0;
}
