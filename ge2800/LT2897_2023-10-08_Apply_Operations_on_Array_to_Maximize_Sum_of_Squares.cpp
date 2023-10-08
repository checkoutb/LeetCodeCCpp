
#include "../header/myheader.h"

class LT2897
{
public:

// D D




//Runtime158 ms
//Beats
//100%
//Memory86 MB
//Beats
//66.67%
    // k max
    // or
    // 25 48   9 25
    // bit count ?
    int maxSum(vector<int>& nums, int k)
    {
        int arr[31] = {0};
        for (int num : nums)
        {
            for (int i = 0; i < 31 && num >= (1 << i); ++i)
            {
                if ((num & (1 << i)) != 0)
                    ++arr[i];
            }
        }
        int ans = 0;
        const int MOD = 1e9 + 7;
        int t2 = 0;
        while (k-- > 0)
        {
            t2 = 0;
            for (int i = 0; i < 31; ++i)
            {
                if (arr[i] > 0)
                {
                    --arr[i];
                    t2 |= (1 << i);
                }
            }
            ans = (ans + 1LL * t2 * t2) % MOD;
        }
        return ans;
    }

};

int main()
{

    LT2897 lt;


    return 0;
}
