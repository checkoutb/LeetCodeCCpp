
#include "../header/myheader.h"

class LT0136
{
public:

// D D

// ans = 0,   for (i = 0; ;)



//Runtime: 48 ms, faster than 36.85% of C++ online submissions for Single Number.
//Memory Usage: 17.3 MB, less than 64.84% of C++ online submissions for Single Number.
    int lt0136a(vector<int>& nums)
    {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); ++i)
            ans ^= nums[i];
        return ans;
    }

};

int main()
{

    myvi v = {4,1,2,1,2};

    LT0136 lt;

    cout<<lt.lt0136a(v);

    return 0;
}
