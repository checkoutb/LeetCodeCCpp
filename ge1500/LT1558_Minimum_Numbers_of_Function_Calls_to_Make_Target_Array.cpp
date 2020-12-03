
#include "../header/myheader.h"

class LT1558
{
public:

// D D

//        int res = 0, high = 0;
//        for (int x : nums) {
//            if (x == 0) continue;
//            // bitset::count() returns the number of set bits in the binary representation
//            res += bitset<32>(x).count();
//            // __builtin_clz(x) counts the leading zeros of the integer
//            high = max(high, 31 - __builtin_clz(x));
//        }
//        return res + high;
// 对每个元素，计算 二进制中 1的个数， 每个1都需要 调用一次方法。
// 计算 最高位， 获得 /2 的次数。   31-前导0的个数， 就是 最高位。     1不算，1不能调用/2， 调用--。


//__builtin_popcount

//res += log10(maxN)/log10(2);


//            res += Integer.bitCount(a);
//            max = Math.max(max, Integer.numberOfTrailingZeros(Integer.highestOneBit(a)));


//    return accumulate(begin(n), end(n), 0, [&](int s, int i) { return s + bitset<32>(i).count(); })
//        + log2(*max_element(begin(n), end(n)));



//Runtime: 160 ms, faster than 32.96% of C++ online submissions for Minimum Numbers of Function Calls to Make Target Array.
//Memory Usage: 25.8 MB, less than 57.46% of C++ online submissions for Minimum Numbers of Function Calls to Make Target Array.
// 某个下标+1， 全部*2
// 反向， 优先全部/2， 如果不能被整除， 就只能 -- 了。
    int lt1558a(vector<int>& nums)
    {
        int ans = 0;
        int notAll0 = true;
        while (notAll0)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] % 2)
                {
                    nums[i]--;
                    ans++;
                }
            }
            notAll0 = false;
            for (int i = 0; i < nums.size(); ++i)
            {
                if (nums[i])
                    notAll0 = true;
                nums[i] /= 2;
            }
            if (notAll0)
                ans++;
        }
        return ans;
    }

};

int main()
{
    cout<<__builtin_clz(1)<<endl;

//    myvi v = {1,5};
//    myvi v = {2,2};
//    myvi v = {3,2,2,4};
    myvi v = {2,4,8,16};

    LT1558 lt;

    cout<<lt.lt1558a(v)<<endl;

    return 0;
}
