
#include "../header/myheader.h"

class LT2302
{
public:

    // D D




//Runtime: 203 ms, faster than 87.04 % of C++ online submissions for Count Subarrays With Score Less Than K.
//Memory Usage : 95 MB, less than 53.05 % of C++ online submissions for Count Subarrays With Score Less Than K.
    long long lt2302a(vector<int>& nums, long long k)
    {
        long long sum2 = 0LL;
        int cnt = 0;
        int st = 0;
        long long ans = 0LL;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum2 += nums[i];
            cnt++;
            while (sum2 * cnt >= k)
            {
                sum2 -= nums[st++];
                cnt--;
            }
            ans += (i - st + 1);
        }
        return ans;
    }

};

int main()
{

    LT2302 lt;


    return 0;
}
