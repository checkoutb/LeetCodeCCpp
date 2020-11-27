
#include "../header/myheader.h"

class LT1513
{
public:

// D D

//            if(s[i]=='1')
//            {
//                dp[i] = (dp[i-1] + 1)%mod;
//                ans = (ans + dp[i])%mod;
//            }

//        for (char c: s) {
//            count = c == '1' ? count + 1 : 0;
//            res = (res + count) % mod;
//        }

//    for (long i = 0, j = 0; i <= s.size(); ++i)
//        if (i == s.size() || s[i] == '0') {
//            res = (res + (i - j) * (i - j + 1) / 2) % 1000000007;
//            j = i + 1;
//        }

//        for (char c : s.toCharArray()) {
//            if (c == '1') res = (res + ++cnt) % mod;  // added cnt of subarrays ended with c;
//            else cnt = 0;
//        }



//Runtime: 24 ms, faster than 6.36% of C++ online submissions for Number of Substrings With Only 1s.
//Memory Usage: 9.9 MB, less than 9.96% of C++ online submissions for Number of Substrings With Only 1s.
    int lt1513a(string s)
    {
        int len = 0;
        int ans = 0;
        int mod = 1E9 + 7;
        s += ' ';
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '1')
            {
                len++;
            }
            else
            {
                if (len > 0)
                {
                    ans = (ans + int (long (len) * (len + 1) / 2 % mod)) % mod;
                }
                len = 0;
            }
        }
        return ans;
    }

};

int main()
{

//    string s = "0110111";
//    string s = "101";
    string s = "111111";

    LT1513 lt;

    cout<<lt.lt1513a(s)<<endl;

    return 0;
}
