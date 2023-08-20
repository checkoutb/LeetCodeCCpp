
#include "../header/myheader.h"

class LT2681
{
public:

// D D

        // long long res = 0, s = 0, base = 1e9 + 7;
        // sort(nums.begin(), nums.end());
        // for (int x: nums) {
        //     res = (res + (s + x) * x % base * x % base) % base;
        //     s = (s * 2 + x) % base;
        // }
        // return res;
// 。。。。



// Runtime132 ms
// Beats
// 46.31%
// Memory92.9 MB
// Beats
// 82.99%

// 只想到： sort后 2层for 遍历， i作为min，j作为max， 中间的就是 2^n 选或不选。  2^n 可以ST表， 不过ST表没有写过。
// 但是 2层 for 肯定tle的。 并且 如果值 是distinct的， 那么 for for 遍历 值 也不行。
// 好像可以预处理下：
//      从下标 到后续的 每个下标的  2^(x) * [j]   这样的话 缺 [i]*[i]
//          2^(x) * [j] * 2 就是 前一个下标 到 j 的值。
    int sumOfPower(vector<int>& nums)
    {
        sort(rbegin(nums), rend(nums));
        const long long MOD = 1e9 + 7;
        long long ans = 0LL;
        long long t2 = 0LL;
        
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            if (i + 2 < nums.size())
                t2 += nums[i + 2];
            t2 <<= 1;
            t2 %= MOD;
            ans = (ans + 1LL * nums[i] * nums[i] % MOD * ((t2 + nums[i] + ((i + 1 < nums.size()) ? nums[i + 1] : 0)) % MOD)) % MOD;

            #ifdef __test
            cout<<i<<", "<<ans<<", "<<t2<<endl;
            #endif
        }
        return ans;
    }

};

int main()
{

    LT2681 lt;

    // myvi v = {1,2,4};
    myvi v = {1,1,1};

    cout<<lt.sumOfPower(v)<<endl;

    return 0;
}
