
#include "../header/myheader.h"

class LT2784
{
public:



    // D D

//    ++nums.back();


//Runtime12 ms
//Beats
//75%
//Memory22.4 MB
//Beats
//37.50%
    bool isGood(vector<int>& nums)
    {
        int sz1 = nums.size();
        if (sz1 == 1)
            return false;
        sort(begin(nums), end(nums));
        if (nums[0] != 1)
            return false;
        for (int i = 1; i < sz1 - 1; ++i)
        {
            if (nums[i] != nums[i - 1] + 1)
                return false;
        }
        return nums[sz1 - 1] == nums[sz1 - 2];
    }

};

int main()
{

    LT2784 lt;


    return 0;
}
