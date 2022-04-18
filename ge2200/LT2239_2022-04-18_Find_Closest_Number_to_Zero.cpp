
#include "../header/myheader.h"

class LT2239
{
public:

// D D


//        int ans = 1e6;
//        for(int x : nums) {
//            if(abs(x) <= abs(ans)) {
//                ans = x;
//            }
//        }
// ... abs(0-x) == abs(x) ..   0-x = -x    x-0 = x


//    return *min_element(begin(nums), end(nums), [](int a, int b) {
//        return abs(a) < abs(b) || (abs(a) == abs(b) && a > b);
//    });


//    def findClosestNumber(self, A):
//        return max([-abs(a), a] for a in A)[1]


//https://leetcode.com/problems/find-closest-number-to-zero/discuss/1954364/Proper-benchmarks-3.4-ms-Python
// 虽然看不懂，但是我大受震撼。


//Runtime: 27 ms, faster than 85.71% of C++ online submissions for Find Closest Number to Zero.
//Memory Usage: 19.6 MB, less than 42.86% of C++ online submissions for Find Closest Number to Zero.
    int lt2239a(vector<int>& nums)
    {
        int diff = std::abs(0 - nums[0]);
        int ans = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (std::abs(0 - nums[i]) < diff || (std::abs(0 - nums[i]) == diff && nums[i] > ans))
            {
                ans = nums[i];
                diff = abs(0 - nums[i]);
            }
        }
        return ans;
    }

};

int main()
{

    LT2239 lt;


    return 0;
}
