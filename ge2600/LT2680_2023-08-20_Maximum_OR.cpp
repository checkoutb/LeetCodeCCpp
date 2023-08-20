
#include "../header/myheader.h"

class LT2680
{
public:


// D D

        // vector<ll> pre(n, 0), suf(n, 0);
        // for(int i = 1 ; i < n ; i++)
        //     pre[i] = pre[i-1]|nums[i-1],
        //     suf[n-i-1] = suf[n-i]|nums[n-i];
        // for(int i = 0 ; i < n ; i++) {
        //     ans = max(ans, pre[i]|suf[i]|((ll)nums[i]<<k));
        // }
// 直接前面的or， 后面的or， 然后自己<<k。


// Runtime305 ms
// Beats
// 11.61%
// Memory84.2 MB
// Beats
// 96.13%

    // 肯定是 某个 最高位的 值 执行 k 次 << 。 感觉只能 遍历 最高位的所有值啊。
    // 能覆盖最多的空位。
    long long maximumOr(vector<int>& nums, int k)
    {
        vector<int> vi(47, 0);
        for (int t2 : nums)
        {
            for (int i = 0; i < 31; ++i)
            {
                if (t2 < (1 << i))
                    break;

                if ((t2 & (1 << i)) != 0)
                {
                    ++vi[i];
                }
            }
        }
        int mxbit = -1;
        for (int i = 30; i >= 0; --i)
        {
            if (vi[i] != 0)
            {
                mxbit = i;
                break;
            }
        }
        long long ans = 0LL;
        for (int t2 : nums)
        {
            if ((t2 & (1 << mxbit)) == 0)
                continue;
            
            for (int i = 0; i <= mxbit; ++i)
            {
                if ((t2 & (1 << i)) != 0)
                {
                    --vi[i];
                    ++vi[i + k];
                }
            }
            long long t3 = 0LL;
            for (int i = 0; i < vi.size(); ++i)
            {
                if (vi[i] != 0)
                {
                    t3 |= (1LL << i);
                }
            }
            ans = max(ans, t3);

            for (int i = 0; i <= mxbit; ++i)
            {
                if ((t2 & (1 << i)) != 0)
                {
                    ++vi[i];
                    --vi[i + k];
                }
            }
        }
        return ans;
    }

};

int main()
{

    LT2680 lt;

    myvi vi = {8,1,2};
    int k{2};

    cout<<lt.maximumOr(vi, k)<<endl;

    return 0;
}
