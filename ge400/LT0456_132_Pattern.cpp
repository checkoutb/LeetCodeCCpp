
#include "../header/myheader.h"

class LT0456
{
public:


// d && d
// stack
// 从后向前，保存次大的，如果存在小于次大的，就ok。 次大通过stack来获得。


//Runtime: 436 ms, faster than 26.56% of C++ online submissions for 132 Pattern.
//Memory Usage: 9.8 MB, less than 100.00% of C++ online submissions for 132 Pattern.

    bool lt0456b(vector<int>& nums)
    {
        if (nums.size() <= 2)
            return false;

        int max1, min1, imax, imin;
        imax = -1;
        int sz1 = nums.size();
        while (true)
        {
            imin = imax + 1;
            while (imin < sz1 - 1 && nums[imin] > nums[imin + 1])
                imin++;
            imax = imin + 1;
            while (imax < sz1 - 1 && nums[imax] < nums[imax + 1])
                imax++;
            if (imax >= sz1)
                break;
            max1 = nums[imax];
            min1 = nums[imin];
            for (int i = imax + 1; i < sz1; i++)
            {
                if (nums[i] > min1 && nums[i] < max1)
                    return true;
            }
        }
        return false;
    }

    // error... i < j ...
    bool lt0456a(vector<int>& nums)
    {
        if (nums.size() <= 2)
            return false;
        int max1 = std::max(nums[0], nums[1]);
        int min1 = std::min(nums[0], nums[1]);
        int sz1 = nums.size();

        for (int i = 2; i < sz1; i++)
        {
            int val = nums[i];
            if (val > min1 && val < max1)
                return true;
            else
            {
                min1 = min(min1, val);
                max1 = max(max1, val);
            }
        }
        return false;
    }
};

int main()
{
    vector<int> n = {1,0,1,-4,-3};

    LT0456* lt = new LT0456();
    cout<<lt->lt0456b(n)<<endl;

    return 0;

}
