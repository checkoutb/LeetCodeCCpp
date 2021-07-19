
#include "../header/myheader.h"

class LT1392
{
public:

// D

//        int n = s.length();
//        int[] lps = new int[n];
//        for (int i = 1, j = 0; i < n; i++) {
//            while (j > 0 && s.charAt(i) != s.charAt(j)) j = lps[j-1];
//            if (s.charAt(i) == s.charAt(j)) lps[i] = ++j;
//        }
//        return s.substring(0, lps[n-1]);
// KMP


//        long l = 0, r = 0, p = 1, mod = (long)1e9 + 7;
//        int k = 0, n = s.length();
//        for (int i = 0; i < n - 1; i++) {
//            l = (l * 128 + s.charAt(i)) % mod;
//            r = (r + p * s.charAt(n - i - 1)) % mod;
//            if (l == r) k = i + 1;
//            p = p * 128 % mod;
//        }
//        return s.substring(0, k);
// Rolling hash


//    for (int i = 0, j = s.length() - 1; j > 0; ++i, --j) {
//        int first = s[i] - 'a', last = s[j] - 'a';
//        h1 = (h1 * 26 + first) % mod;
//        h2 = (h2 + mul * last) % mod;
//        mul = mul * 26 % mod;
//        if (h1 == h2)
//            len = i + 1;
//    }
// hash


//    for (int i = 1; i < s.size(); ++i) {
//        if (s[i] == s[j])
//            dp[i] = ++j;
//        else if (j > 0) {
//            j = dp[j - 1];
//            --i;
//        }
//    }
// kmp





// g hash不会写。

// tle。。。。
//hint: Use Longest Prefix Suffix (KMP-table) or String Hashing.
    string lt1392b(string s)
    {
        int h1 = 0, h2 = 0;
        int sz1 = s.size();
        for (int i = 0; i < s.size() - 1; ++i)
            h1 = (h1 + s[i]) % MOD;
        h2 = (h1 - s[0] + s[sz1 - 1] + MOD) % MOD;
        string ans = "";
        for (int i = sz1 - 2; i >= 0; --i)
        {
            #ifdef __test
            cout<<h1<<" - "<<h2<<".... "<<s[i]<<", "<<s[sz1 - 1 - i]<<", "<<i<<endl;
            #endif // __test
            if (h1 == h2)
            {
                for (int j = 0; j <= i; ++j)
                {
                    if (s[j] != s[sz1 - i - 1 + j])
                        goto AAA;
                }
                ans = s.substr(0, i + 1);
                break;
                AAA:
                continue;
            }
            h1 = hash1(h1, s[i]);
            h2 = hash2(h2, s[sz1 - i - 1], i);
        }
        return ans;
    }
    const int PRI = 67;           // ..并不会。 这里应该取一个大数，还是小数， 每位都不同的数，还是什么。。
    const int MOD = 1E9 + 7;
    // ch is last
    int hash1(int h, char ch)
    {
        return (h - ch + MOD) % MOD;
//        return (h + ch) % MOD;
//        return (int) ((h << 1) % MOD + ((ch - 'a') * PRI) % MOD) % MOD;           // <<1 ? 这样最多保存 32位的信息。    如果没有<<1，那么也不需要-'a'。。
    }

    // ch is first
    int hash2(int h, char ch, int len)
    {
        return (h - ch + MOD) % MOD;

//        return (h + ch) % MOD;          // tle

        // 这个会说 left shift of 67 by 26 places cannot be represented in type 'int'
        // 。。。 我就是想越界啊。。。
//        return (int) (((((ch - 'a') * PRI) << len) % MOD) + h) % MOD;         // << 的优先级真低。。。
    }



// tle....  全a... 预处理下？？
// 怎么觉得只能硬算了，最多加个hash，来加速，减少substr。  从大到小。 。 。
// 不，可以加速， leetcodeleet ，  l只在 0, 8 出现，。。 然后 le，只在0,8 出现。。。 想起来pocheman(可能拼错了)的 char* arr[] ...
    string lt1392a(string s)
    {
//        if (s.size() <= 1)
//            return "";
//        char* arr[].....      length???
        vector<char*> vcp;
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == s[0])
                vcp.push_back(&s[i + 1]);       // + 1
        }
        int idx = 1;
        string ans = "";
//        string ans = s.substr(0, idx);
        while (!vcp.empty())
        {
            for (vector<char*>::iterator it = vcp.begin(); it != vcp.end(); )
            {
                // where is the begin... length... idx...
                if (**it == '\0')            // 有些说\0结尾，有些说没有规定。。
                {
                    ans = s.substr(0, idx);
                    it = vcp.erase(it);
                }
                else
                {
                    if (**it == s[idx])
                    {
                        (*it)++;            // pointer ++
                        it++;
                    }
                    else
                    {
                        it = vcp.erase(it);
                    }
                }
            }
            idx++;
        }
        #ifdef __test
        cout<<idx<<", "<<ans.size()<<", "<<ans<<endl;
        #endif // __test

        return ans;
    }

};

int main()
{
    string a = "asdf";
    char ch = a[4];
//    if (ch == '\0')
//    {
//        cout<<"is 0"<<endl;
//    }
//    else
//    {
//        cout
//    }
//    cout<<(ch == '\0')<<"."<<ch<<"."<<endl;               // 1
//    ch = a[5];
//    cout<<(ch == '\0')<<"."<<ch<<"."<<endl;           // 0      都是无法打印的字符。

//    string s = "level";
//    string s = "ababab";
//    string s = "leetcodeleet";
//    string s = "a";
    string s = "abcsdfwab";

    LT1392 lt;

    cout<<lt.lt1392b(s)<<endl;

    return 0;
}
