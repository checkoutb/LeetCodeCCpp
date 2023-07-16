
#include "../../header/myheader.h"

class LT6927
{
public:



    // AC

    // yiban yishang
    // kending haishi x a
    int minimumIndex(vector<int>& nums)
    {
        int mx = nums[0];
        int mxcnt = 1;
        int sz1 = nums.size();
        for (int i = 1; i < sz1; ++i)
        {
            if (mxcnt == 0)
            {
                mx = nums[i];
                mxcnt = 1;
                continue;
            }
            if (nums[i] != mx)
            {
                --mxcnt;
            }
            else
            {
                ++mxcnt;
            }
        }
        #ifdef __test
        cout<<mx<<", "<<mxcnt<<endl;
        #endif // __test
        int t3 = 0;
        for (int val : nums)
            if (val == mx)
                ++t3;
        mxcnt = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (nums[i] == mx)
                ++mxcnt;

            if ((mxcnt * 2 > (i + 1)) && ((t3 - mxcnt) * 2 > (sz1 - i - 1)))
                return i;
        }
        return -1;
    }
};

int main()
{

    LT6927 lt;

    myvi v = {1,2,2,2};

    cout<<lt.minimumIndex(v)<<endl;

    return 0;
}
