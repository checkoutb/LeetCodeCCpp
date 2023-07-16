
#include "../../header/myheader.h"

class LT6889
{
public:



// AC
    int sumOfSquares(vector<int>& nums)
    {
        int sz1 = nums.size();
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (sz1 % (i + 1) == 0)
            {
                ans += nums[i] * nums[i];
            }
        }
        return ans;
    }

};

int main()
{

    LT6889 lt;


    return 0;
}
