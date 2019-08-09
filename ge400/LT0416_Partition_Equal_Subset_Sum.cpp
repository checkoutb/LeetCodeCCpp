
#include "../header/myheader.h"

class LT0416
{
public:


// detail
// 一种recursion，每次加或不加。然后下一个递归。


// discuss
//        const int MAX_NUM = 100;
//        const int MAX_ARRAY_SIZE = 200;
//        bitset<MAX_NUM * MAX_ARRAY_SIZE / 2 + 1> bits(1);
//        int sum = 0;
//        for (auto n : nums) {
//            sum += n;
//            bits |= bits << n;
//        }
//        return !(sum % 2) && bits[sum / 2];
// 1,5,11,5
// bits init:1
// n == 1 :     11
// 5 :             1100011
// 11 : 110001100000000000
//          110001100001100011
// 5 : 11000110000110001100000
//     11000110001110001100011
// bits应该是代表 数值任意+- 可能得到的值。还做了一个转换。

//A tiny example, nums=[2, 3, 5], initial bits is 1, traversing through nums
//    when num=2, bits=101, which represents nums can sum to 0 and 2
//    when num=3, bits=101101, which represents nums can sum to 0, 2, 3, 5
//    when num=5, bits=10110101101, which represents nums can sum to 0, 2, 3, 5, 7, 8, 10

// dp......
// 初始1代表了0.没有任何数的时候就是0.
// bits 代表不+n， bits<<n 代表+n， | 后就是 所有的可能。



//        volumn /= 2;
//        // dp def
//        boolean[] dp = new boolean[volumn + 1];
//        // dp init
//        dp[0] = true;
//        // dp transition
//        for (int i = 1; i <= nums.length; i++) {
//            for (int j = volumn; j >= nums[i-1]; j--) {
//                dp[j] = dp[j] || dp[j - nums[i-1]];
//            }
//        }
//        return dp[volumn];

// dp下标代表可以组成的值。
// j<nums[i-1] 不会对dp发生影响(会越界)，所以跳过。
// 初始时只有0可到达，
// 1，5，11，5，
// i=1时， dp[]只有 dp[1] = dp[1] || dp[0] 发生了改变
// i=2时， 5， dp[5] = dp[5-5]  dp[6] = dp[6-5]    2个位发生了变化。


// dp应该也可以：for每个n，for(dp){dp中为true的下标+n 也为true，下标+n>half 就不考虑。}



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Partition Equal Subset Sum.
//Memory Usage: 8.2 MB, less than 100.00% of C++ online submissions for Partition Equal Subset Sum.


    bool lt0416a(vector<int>& nums)
    {
        int sum = 0;
        int max1 = 0;
        for (auto& n : nums)
        {
            sum += n;
            max1 = max(max1, n);
        }
        if (sum % 2 == 1 || max1 * 2 > sum)
            return false;

        sort(nums.begin(), nums.end());

        bool ans = recursiona1(nums, nums.size() - 1, 0, sum / 2);
        return ans;
    }

    bool recursiona1(vector<int>& nums, int index, int sum, int half)
    {
        if (sum > half || index < 0)
        {
            return false;
        }
        if (sum == half)
        {
            return true;
        }
        while (index >= 0)
        {
            if (recursiona1(nums, index - 1, sum + nums[index], half))
            {
                return true;
            }
            index--;
        }
        return false;
    }
};

int main()
{
    vector<int> nums = {1,5,11,5};

    LT0416 lt;
    cout<<endl<<lt.lt0416a(nums)<<endl;

    return 0;
}
