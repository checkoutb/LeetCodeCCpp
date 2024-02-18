
#include "../header/myheader.h"

class LT2997
{
public:




// Runtime
// 118ms
// Beats55.44%of users with C++
// Memory
// 88.83MB
// Beats70.13%of users with C++
    int minOperations(vector<int>& nums, int k)
    {
        int t2 = 0;
        for (int i : nums)
        {
            t2 ^= i;
        }

        int ans = 0;
        for (int i = 0; i < 31; ++i)
        {
            if ((t2 & (1 << i)) != (k & (1 << i)))
            {
                ++ans;
            }
        }
        return ans;
    }

};

int main()
{

    LT2997 lt;


    return 0;
}
