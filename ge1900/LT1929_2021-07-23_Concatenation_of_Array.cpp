
#include "../header/myheader.h"

class LT1929
{
public:

// D D





//Runtime: 12 ms, faster than 58.58% of C++ online submissions for Concatenation of Array.
//Memory Usage: 12.4 MB, less than 84.76% of C++ online submissions for Concatenation of Array.
    vector<int> lt1929a(vector<int>& nums)
    {
        int sz1 = nums.size();
        vector<int> ans(sz1 * 2, 0);
        for (int i = 0; i < sz1; ++i)
        {
            ans[i] = nums[i];
            ans[i + sz1] = nums[i];
        }
        return ans;
    }

};

int main()
{

    LT1929 lt;


    return 0;
}
