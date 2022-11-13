
#include "../header/myheader.h"

class LT2466
{
public:

    // D D

    //vector<int64_t> dp(high + 1);
    //dp[0] = 1;
    //for (int i = 1; i <= high; ++i) {
    //    if (i >= zero) {
    //        dp[i] += dp[i - zero];
    //    }
    //    if (i >= one) {
    //        dp[i] += dp[i - one];
    //    }
    //    dp[i] %= M;
    //}


    // dp[i] = dp[i - zero] + dp[i - one]


    //Runtime49 ms
    //    Beats
    //    16.67 %
    //    Memory12.6 MB
    //    Beats
    //    33.33 %
    int lt2466a(int low, int high, int zero, int one)
    {
        const int MOD = 1e9 + 7;
        int ans = 0;
        vector<int> v0(high + 1);
        vector<int> v1(high + 1);

        v0[zero] = 1;
        v1[one] = 1;

        for (int i = min(zero, one); i < high; ++i)
        {
            if (v0[i] != 0)
            {
                if (i + zero <= high)
                {
                    v0[i + zero] = (v0[i + zero] + v0[i]) % MOD;
                }
                if (i + one <= high)
                {
                    v1[i + one] = (v1[i + one] + v0[i]) % MOD;
                }
            }
            if (v1[i] != 0)
            {
                if (i + zero <= high)
                    v0[i + zero] = (v0[i + zero] + v1[i]) % MOD;
                if (i + one <= high)
                    v1[i + one] = (v1[i + one] + v1[i]) % MOD;
            }
        }

        for (int i = low; i <= high; ++i)
        {
            ans = (ans + v1[i]) % MOD;
            ans = (ans + v0[i]) % MOD;
        }
        return ans;
    }

};

int main()
{

    LT2466 lt;

    //int l = 3, h = 3, z = 1, o = 1;
    int l = 2, h = 3, z = 1, o = 2;

    cout << lt.lt2466a(l, h, z, o);

    return 0;
}
