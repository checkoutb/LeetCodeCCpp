
#include "../../header/myheader.h"

class LT100031
{
public:


    // AC
    int sumIndicesWithKSetBits(vector<int>& nums, int k)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int cnt = 0;
            int t2 = i;
            while (t2 > 0 && cnt <= k)
            {
                cnt += t2 % 2;
                t2 /= 2;
            }
            if (cnt == k)
            {
                ans += nums[i];
            }
        }
        return ans;
    }

};

int main()
{

    LT100031 lt;


    return 0;
}
