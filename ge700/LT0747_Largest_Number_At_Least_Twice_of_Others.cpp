
#include "../header/myheader.h"

class LT0747
{
public:


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Largest Number At Least Twice of Others.
//Memory Usage: 6.2 MB, less than 100.00% of C++ online submissions for Largest Number At Least Twice of Others.
    int lt0747a(vector<int>& nums)
    {
        if (nums.size() == 1)
            return 0;
        int m1 = max(nums[0], nums[1]);
        int m2 = min(nums[0], nums[1]);
        int i1 = m1 == nums[0] ? 0 : 1;
        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i] > m1)
            {
                m2 = m1;
                m1 = nums[i];
                i1 = i;
            }
            else
            {
                if (nums[i] > m2)
                {
                    m2 = nums[i];
                }
            }
        }
        return m2 <= m1 / 2 ? i1 : -1;
    }

};

int main()
{

    vector<int> v = {0,0,3,2};
    LT0747 lt;

    cout<<lt.lt0747a(v)<<endl;

    return 0;
}
