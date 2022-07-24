
#include "../header/myheader.h"

class LT2348
{
public:

    // D D

//    for (int i = 0, j = 0; i < nums.size(); ++i) {
//        if (nums[i] != 0)
//            j = i + 1;
//         res += i - j + 1;
//    }





//Runtime: 277 ms, faster than 100.00% of C++ online submissions for Number of Zero-Filled Subarrays.
//Memory Usage: 107.6 MB, less than 50.00% of C++ online submissions for Number of Zero-Filled Subarrays.
    long long lt2348a(vector<int>& nums)
    {
        long long ans = 0LL;
        long long t2 = 0LL;

        for (int i : nums)
        {
            if (i == 0)
            {
                t2++;
                ans += t2;
            }
            else
            {
                t2 = 0LL;
            }
        }

        return ans;
    }

};

int main()
{

    LT2348 lt;


    return 0;
}
