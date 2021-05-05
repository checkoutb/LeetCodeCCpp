
#include "../header/myheader.h"

class LT1848
{
public:

// D D

//    for (int i = 0; i < nums.size() && res > abs(start - i); ++i)
//        if (nums[i] == target)
//            res = min(res, abs(start - i));


//Runtime: 4 ms, faster than 90.00% of C++ online submissions for Minimum Distance to the Target Element.
//Memory Usage: 9.8 MB, less than 10.00% of C++ online submissions for Minimum Distance to the Target Element.
    int lt1848a(vector<int>& nums, int target, int start)
    {
        int ans = 0;
        if (nums[start] == target)
            return ans;
        int l = start - 1;
        int r = start + 1;
        while (true)
        {
            if (l >= 0 && nums[l] == target)
            {
                ans = start - l;
                break;
            }
            if (r < nums.size() && nums[r] == target)
            {
                ans = r - start;
                break;
            }
            --l;
            ++r;
        }
        return ans;
    }

};

int main()
{

    LT1848 lt;


    return 0;
}
