
#include "../header/myheader.h"

class LT2750
{
public:




// Runtime187 ms
// Beats
// 94.50%
// Memory235.2 MB
// Beats
// 65.38%
    // 1 value == 1
    int numberOfGoodSubarraySplits(vector<int>& nums)
    {
        int lst1 = -1;
        long long ans = 1LL;
        const long long MOD = 1e9 + 7;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 1)
                continue;
            
            ans = ans * (lst1 == -1 ? 1 : (i - lst1)) % MOD;
            lst1 = i;
        }
        return lst1 == -1 ? 0 : static_cast<int>(ans);      // [0, 0]
    }

};

int main()
{

    LT2750 lt;


    return 0;
}
