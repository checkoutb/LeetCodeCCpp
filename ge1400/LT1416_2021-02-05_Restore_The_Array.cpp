
#include "../header/myheader.h"

class LT1416
{
public:

// D D

//        if (i == s.length()) return 1; // base case -> Found a valid way
//        if (s.charAt(i) == '0') return 0; // all numbers are in range [1, k] and there are no leading zeros -> So numbers starting with 0 mean invalid!
//        if (dp[i] != null) return dp[i];
//        int ans = 0;
//        long num = 0;
//        for (int j = i; j < s.length(); j++) {
//            num = num * 10 + s.charAt(j) - '0'; // num is the value of the substring s[i..j]
//            if (num > k) break; // num must be in range [1, k]
//            ans += dfs(s, k, j + 1, dp);
//            ans %= 1_000_000_007;
//        }
//        return dp[i] = ans;
// 应该算 memo + dfs


//        for i in range(1, n):
//            for j in range(t):
//                if i-j >= 0 and 1 <= int(s[i-j:i+1]) <= k and s[i-j:i+1][0] != "0":
//                    count[i+1] += count[i-j]
//        return count[-1] % 1000000007



//        vector<int> dp(n + 1, 0);
//        dp[n] = 1; // the base case
//        for (int i=n-1; i>=0; --i) {
//            int num = s[i] - '0', j = i + 1;
//            while (num > 0 && num <= k && j < n + 1) {
//                dp[i] = (dp[i] + dp[j]) % 1000000007;
//		        // a tiny trick to avoid overflow
//                num = (j < n && num <= k / 10) ? 10 * num + (s[j] - '0') : INT_MAX;
//                j++;
//            }
//        }


//    vector<int> dp(s.size() + 1);
//    dp[s.size()] = 1;
//    for (int i = s.size() - 1; i >= 0; --i) {
//        if (s[i] == '0')
//            continue;
//        for (long sz = 1, n = 0; i + sz <= s.size(); ++sz) {
//            n = n * 10 + s[i + sz - 1] - '0';
//            if (n > k)
//                break;
//            dp[i] = (dp[i] + dp[i + sz]) % 1000000007;
//        }
//    }


//    int s_sz = s.size(), dp_sz = to_string(k).size() + 1;
//    vector<int> dp(dp_sz);
//    dp[s_sz % dp_sz] = 1;
//    for (int i = s_sz - 1; i >= 0; --i) {
//        dp[i % dp_sz] = 0;
//        if (s[i] == '0')
//            continue;
//        for (long sz = 1, n = 0; i + sz <= s_sz; ++sz) {
//            n = n * 10 + s[i + sz - 1] - '0';
//            if (n > k)
//                break;
//            dp[i % dp_sz] = (dp[i % dp_sz] + dp[(i + sz) % dp_sz]) % 1000000007;
//        }
//    }




// pw < INT_MAX / 10 , 感觉不太对。。
//Runtime: 84 ms, faster than 43.88% of C++ online submissions for Restore The Array.
//Memory Usage: 11.9 MB, less than 84.18% of C++ online submissions for Restore The Array.
    int lt1416a(string s, int k)
    {

        vector<int> vi(s.size());
        const int mod = 1E9 + 7;
        for (int i = 0; i < s.size(); ++i)
        {
            int pw = 1;
            int val = 0;
            int cnt = 0;
            for (int j = i; j >= 0 && val < k && pw < INT_MAX / 10; --j, pw *= 10)
            {
                if (s[j] == '0')
                {
//                    pw *= 10;
                    continue;
                }
                val += pw * (s[j] - '0');
                #ifdef __test
                cout<<val<<",";
                #endif // __test
                if (val <= k)
                {
                    cnt += (j == 0 ? 1 : vi[j - 1]);
                    cnt %= mod;
                }
//                pw *= 10;
            }
            vi[i] = cnt;
        }
        #ifdef __test
        showVectorInt(vi);
        #endif // __test

        return vi[vi.size() - 1];
    }

};

int main()
{
//    string s = "1317";
//    int k = 2000;
    string s = "1234567890";
    int k = 90;

    LT1416 lt;

    cout<<lt.lt1416a(s, k)<<endl;

    return 0;
}
