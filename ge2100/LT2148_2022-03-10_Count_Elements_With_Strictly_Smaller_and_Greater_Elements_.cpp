
#include "../header/myheader.h"

class LT2148
{
public:

// D D


//    const auto mm = minmax_element(begin(n), end(n));
//    return count_if(begin(n), end(n), [&](int n){ return n > *mm.first && n < *mm.second; });


//Runtime: 7 ms, faster than 46.58% of C++ online submissions for Count Elements With Strictly Smaller and Greater Elements .
//Memory Usage: 9.1 MB, less than 43.76% of C++ online submissions for Count Elements With Strictly Smaller and Greater Elements .
// sort  while (a[i]==a[i-1]) ...
    int lt2148a(vector<int>& nums)
    {
        int mx = nums[0];
        int mn = nums[0];
        int mncnt = 1;
        int mxcnt = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] >= mx)
            {
                if (nums[i] == mx)
                    mxcnt++;
                else
                    mx = nums[i], mxcnt = 1;
            }
            if (nums[i] <= mn)      // 不能else， [-11,-11,1,2,3]
            {
                if (nums[i] == mn)
                    mncnt++;
                else
                    mn = nums[i], mncnt = 1;
            }
        }
        return max(0, (int) nums.size() - mncnt - mxcnt);
    }

};

int main()
{

    LT2148 lt;


    return 0;
}
