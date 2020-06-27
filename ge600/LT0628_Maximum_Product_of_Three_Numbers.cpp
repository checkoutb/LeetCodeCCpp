
#include "../header/myheader.h"

class LT0628
{
public:


// D D
//        int max1 = Integer.MIN_VALUE, max2 = Integer.MIN_VALUE, max3 = Integer.MIN_VALUE, min1 = Integer.MAX_VALUE, min2 = Integer.MAX_VALUE;
//        for (int n : nums) {
//            if (n > max1) {
//                max3 = max2;
//                max2 = max1;
//                max1 = n;
//            } else if (n > max2) {
//                max3 = max2;
//                max2 = n;
//            } else if (n > max3) {
//                max3 = n;
//            }
//
//            if (n < min1) {
//                min2 = min1;
//                min1 = n;
//            } else if (n < min2) {
//                min2 = n;
//            }
//        }
//        return Math.max(max1*max2*max3, max1*min1*min2);


//        int f[2][4], i, j;
//        f[0][0] = f[1][0] = 1;
//        for (j = 3; j > 0; --j) {
//            f[0][j] = INT_MIN;
//            f[1][j] = INT_MAX;
//        }
//
//        for (i = 0; i < nums.size(); ++i) {
//            for (j = 3; j > 0; --j) {
//                if (f[0][j - 1] == INT_MIN) {
//                    continue;
//                }
//                f[0][j] = max(f[0][j], max(f[0][j - 1] * nums[i], f[1][j - 1] * nums[i]));
//                f[1][j] = min(f[1][j], min(f[0][j - 1] * nums[i], f[1][j - 1] * nums[i]));
//            }
//        }
//        return f[0][3];

// 列j代表几个数的乘积， 行代表max或min。 因为min*负数 可能变成max。




//Runtime: 132 ms, faster than 61.39% of C++ online submissions for Maximum Product of Three Numbers.
//Memory Usage: 27.7 MB, less than 46.47% of C++ online submissions for Maximum Product of Three Numbers.
// -1000 * -1000 * 1000      -1000 * 1000 * 1000
// abs 后 最大的？个数，，不 最大的?个正数，最小的？个负数。 3个正，2个负
// nums 全负数。就是t2.
    int maximumProduct(vector<int>& nums)
    {
        std::sort(std::begin(nums), end(nums));
        int t1 = nums[0] * nums[1] * nums[nums.size() - 1];
        int t2 = nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];
        return max(t1, t2);
    }

};

int main()
{

    LT0628 lt;


    return 0;
}
