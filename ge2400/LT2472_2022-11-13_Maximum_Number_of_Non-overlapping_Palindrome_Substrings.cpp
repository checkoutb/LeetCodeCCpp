
#include "../header/myheader.h"

class LT2472
{
public:

    // D D

    // Only check substrings of length k and k + 1
    //for (int i = k - 1; i < n; i++) {
    //    dp[i + 1] = dp[i];
    //    if (helper(s, i - k + 1, i))       dp[i + 1] = Math.max(dp[i + 1], 1 + dp[i - k + 1]);
    //    if (i - k >= 0 && helper(s, i - k, i)) dp[i + 1] = Math.max(dp[i + 1], 1 + dp[i - k]);
    //}


    //int n = s.size(), ans = 0, start = 0;
    //for (int center = 0; center < 2 * n; center++) {
    //    int left = center / 2;
    //    int right = left + center % 2;
    //    while (left >= start && right < n && s[left] == s[right]) {
    //        if (right + 1 - left >= k) {
    //            ans++;
    //            start = right + 1;
    //            break;
    //        }
    //        left--; right++;
    //    }
    //}
    // 包含了 奇数，偶数 长度的 回文


    //Runtime3 ms
    //    Beats
    //    88.89 %
    //    Memory6.5 MB
    //    Beats
    //    66.67 %
    int lt2472a(string s, int k)
    {
        int sz1 = s.size();
        if (k == 1)
            return sz1;

        vector<int> vi(sz1);

        for (int i = 0; i < sz1; ++i)
        {
            int st = i, en = i;
            while ((en - st + 1) < k && st - 1 >= 0 && en + 1 < sz1 && s[st - 1] == s[en + 1] && vi[st - 1] == 0)
            {
                st--;
                ++en;
            }
            if (en - st + 1 >= k)
            {
                vi[en] = 1;
                i = en;
            }
            else
            {
                if ((i + 1 < sz1) && s[i] == s[i + 1])
                {
                    st = i, en = i + 1;
                    while ((en - st + 1) < k && st - 1 >= 0 && en + 1 < sz1 && s[st - 1] == s[en + 1] && vi[st - 1] == 0)
                    {
                        st--;
                        ++en;
                    }
                    if (en - st + 1 >= k)
                    {
                        vi[en] = 1;
                        i = en;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (vi[i] != 0)
                ++ans;
        }
        return ans;
    }

};

int main()
{

    LT2472 lt;

    string s = "abcdefg";
    int k = 2;

    cout << lt.lt2472a(s, k) << endl;

    return 0;
}
