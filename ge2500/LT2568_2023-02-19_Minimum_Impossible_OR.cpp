
#include "../header/myheader.h"

class LT2568
{
public:

    // D D

    //int mask = 0;
    //for (auto& x : nums)
    //    if ((x & x - 1) == 0) mask |= x;
    //for (int i = 0; i < 32; ++i)
    //    if ((mask & 1 << i) == 0) return 1 << i;
    //return -1;

    // 只有 2^a ，才会 x&x-1 == 0..  只有 一个bit为1的时候 才会 ==0



    //Runtime150 ms
    //    Beats
    //    80 %
    //    Memory47.6 MB
    //    Beats
    //    90 %
    // 2^x
    int lt2568a(vector<int>& nums)
    {
        int sz1 = nums.size();
        sort(begin(nums), end(nums));
        if (nums[0] != 1)
            return 1;

        int t2 = 1;
        for (int i = 0; i < sz1; ++i)
        {
            if (nums[i] == t2)
            {
                t2 *= 2;
            }
            else if (nums[i] > t2)
                break;
        }
        return t2;
    }

};

int main()
{

    LT2568 lt;


    return 0;
}
