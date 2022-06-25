
#include "../header/myheader.h"

class LT2311
{
public:

    // D D

    // dp  很慢

    //int dp[1010] = {}, j = 0;
    //for (char& v : s) {
    //    if (dp[j] * 2 + v - '0' <= k)
    //        dp[++j] = dp[j] * 2 + v - '0';
    //    for (int i = j; i > 0; --i)
    //        dp[i] = min(dp[i], dp[i - 1] * 2 + v - '0');
    //}



//Runtime: 7 ms, faster than 46.26 % of C++ online submissions for Longest Binary Subsequence Less Than or Equal to K.
//Memory Usage : 6.7 MB, less than 88.38 % of C++ online submissions for Longest Binary Subsequence Less Than or Equal to K.
    // 全0. 从后往前 取 1
    int lt2311a(string s, int k)
    {
        long long n = 0;
        int ans = 0;
        for (char ch : s)
            ans += (ch == '0');

        long long pw = 1;
        for (int i = s.size() - 1; i >= 0 && pw < INT_MAX; --i, pw <<= 1)
        {
            if (s[i] == '1')
            {
                n += pw;
                if (n > k)
                {
                    return ans;
                }
                ans++;
            }
        }
        return ans;
    }

};

int main()
{

    LT2311 lt;

    //string s = "1001010";
    //int k = 5;

    string s = "00101001";
    int k = 1;

    cout << lt.lt2311a(s, k) << endl;

    return 0;
}
