
#include "../header/myheader.h"

class LT2555
{
public:

    // D D

    //int res = 0, n = A.size(), j = 0;
    //vector<int> dp(n + 1, 0);
    //for (int i = 0; i < n; ++i) {
    //    while (A[j] < A[i] - k)
    //        ++j;
    //    dp[i + 1] = max(dp[i], i - j + 1);
    //    res = max(res, i - j + 1 + dp[j]);
    //}




    //    Sorry, there are not enough accepted submissions to show data
    //Runtime86 ms
    //    Beats
    //    100 %
    //    Memory60.2 MB
    //    Beats
    //    100 %
    int lt2555a(vector<int>& prz, int k)
    {
        int sz1 = prz.size();
        vector<int> vi;
        vector<int> v2;
        for (int i = 0; i < sz1; ++i)
        {
            int cnt = 1;
            while (i + 1 < sz1 && prz[i] == prz[i + 1])
            {
                ++cnt;
                ++i;
            }
            vi.push_back(prz[i]);
            v2.push_back(cnt);
        }

        int sz2 = vi.size();
        vector<int> v3(sz2);
        int st = 0;
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < sz2; ++i)
        {
            cnt += v2[i];
            while (vi[st] < vi[i] - k)
            {
                cnt -= v2[st];
                ++st;
            }
            v3[i] = i == 0 ? cnt : max(cnt, v3[i - 1]);             // 做一个 prefix max
            ans = max(ans, cnt + ((st - 1 >= 0) ? v3[st - 1] : 0));     // 取当前segment 加上 前面的 一个segment。
        }
        return ans;
    }

};

int main()
{

    LT2555 lt;

    //myvi v = { 1,1,2,2,3,3,5 };
    //int k = 2;

    myvi v = { 1,2,3,4 };
    int k = 0;

    cout << lt.lt2555a(v, k) << endl;

    return 0;
}
