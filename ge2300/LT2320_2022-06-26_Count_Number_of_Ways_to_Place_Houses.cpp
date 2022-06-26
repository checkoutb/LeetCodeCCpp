
#include "../header/myheader.h"

class LT2320
{
public:

    // D D

    // 上下是对称的，所以 只需要计算 一侧，然后 ^2 下。
    // 单侧的话是 Fibonacci

    //int a = 1, b = 1, c = 2, mod = 1e9 + 7;
    //for (int i = 0; i < n; ++i) {
    //    c = (a + b) % mod;
    //    a = b;
    //    b = c;
    //}


    //vector<long long> dp(n + 10);
    //int mod = 1e9 + 7;
    //dp[0] = 1, dp[1] = 2;
    //for (int i = 2; i <= n; ++i)
    //    dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    //return dp[n] * dp[n] % mod;



//Runtime: 8 ms, faster than 100.00 % of C++ online submissions for Count Number of Ways to Place Houses.
//Memory Usage : 5.8 MB, less than 100.00 % of C++ online submissions for Count Number of Ways to Place Houses.
    // 左侧是否有。4种状态。
    // 0：全空，1上有下空，2上空下有，3上下都有
    int lt2320a(int n)
    {
        int arr[4] = { 1,1,1,1 };           // n == 1
        const int MOD = 1e9 + 7;

        while (n-- > 1)
        {
            int arr2[4] = { 0,0,0,0 };

            // 0
            arr2[0] = ((arr[0] + arr[1]) % MOD + (arr[2] + arr[3]) % MOD) % MOD;
            arr2[1] = (arr[0] + arr[2]) % MOD;
            arr2[2] = (arr[0] + arr[1]) % MOD;
            arr2[3] = arr[0];

            for (int i = 0; i < 4; ++i)
                arr[i] = arr2[i];
        }
        return ((arr[0] + arr[1]) % MOD + (arr[2] + arr[3]) % MOD) % MOD;
    }

};

int main()
{

    LT2320 lt;

    int n = 2;

    cout << lt.lt2320a(n) << endl;

    return 0;
}
