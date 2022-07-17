
#include "../header/myheader.h"

class LT1191
{
public:

    // D D

    //int n = arr.size(), sum = arr[0], mx = arr[0];
    //int64_t total = accumulate(arr.begin(), arr.end(), 0), mod = 1e9 + 7;
    //for (int i = 1; i < n * min(k, 2); i++) {
    //    sum = max(arr[i % n], sum + arr[i % n]);
    //    mx = max(mx, sum);
    //}
    //return max<int64_t>({ 0, mx, total * max(0, k - 2) + mx }) % mod;


    // kadane



//Runtime: 52 ms, faster than 99.70 % of C++ online submissions for K - Concatenation Maximum Sum.
//Memory Usage : 39.5 MB, less than 65.97 % of C++ online submissions for K - Concatenation Maximum Sum.
    // 最大前缀+最大后缀
    // 如果k==1，就看最大subarray
    // 如果sum<0 也要看最大subarray
    int lt1191a(vector<int>& arr, int k)
    {
        int sz1 = arr.size();
        const int MOD = 1e9 + 7;
        int mxpre = 0;
        int mxsuf = 0;
        int mxarr = 0;
        int sum2 = 0;
        int t2mn = 0;
        int t2pre = 0;
        int t2suf = 0;
        for (int i = 0; i < sz1; ++i)
        {
            sum2 += arr[i];
            t2pre += arr[i];
            t2suf += arr[sz1 - 1 - i];
            t2mn = min(t2mn, t2pre);
            mxpre = max(mxpre, t2pre);
            mxsuf = max(mxsuf, t2suf);
            mxarr = max(mxarr, t2pre - t2mn);
        }

#ifdef __test
        cout << mxpre << ", " << mxarr << ", " << mxsuf << endl;
        cout << t2pre << " - " << t2mn << " - " << t2suf << " ---- " << sum2 << endl;
#endif

        int ans = 0;
        if (sum2 <= 0)
        {
            ans = k == 1 ? mxarr : max(mxarr, mxpre + mxsuf);
            ans %= MOD;
        }
        else
        {
            ans = k == 1 ? mxarr : (((1LL * (k - 2) * sum2) % MOD + (mxpre + mxsuf) % MOD) % MOD);
        }
        return ans;
    }

};

int main()
{

    LT1191 lt;

    //myvi v = { 1,2 };
    //int k = 3;

    //myvi v = { 1,-2,1 };
    //int k = 5;

    //myvi v = { -1,-2 };
    //int k = 5;

    myvi v = {-5, -2, 0, 0, 3, 9, -2, -5, 4};       // 20        5+2*3+9
    int k = 5;


    cout << lt.lt1191a(v, k) << endl;

    return 0;
}
