
#include "../header/myheader.h"

class LT2104
{
public:

// D D

// ...
// 好像是 分开算，算min，算max。 算这个min 影响了多少范围。。。但是。。



//Runtime: 111 ms, faster than 45.09% of C++ online submissions for Sum of Subarray Ranges.
//Memory Usage: 10.5 MB, less than 39.74% of C++ online submissions for Sum of Subarray Ranges.
    long long lt2104a(vector<int>& nums)
    {
        long long ans = 0LL;

        for (int i = 0; i < nums.size(); ++i)
        {
            int mx = nums[i];
            int mn = mx;
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[j] > mx)
                    mx = nums[j];
                else if (nums[j] < mn)
                    mn = nums[j];
                ans += (mx - mn);
            }
        }

        return ans;
    }

};

int main()
{

    LT2104 lt;


    return 0;
}
