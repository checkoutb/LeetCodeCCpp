
#include "../header/myheader.h"

class LT1392
{
public:

    // D D

    //long h1 = 0, h2 = 0, mul = 1, len = 0, mod = 1000000007;
    //for (int i = 0, j = s.length() - 1; j > 0; ++i, --j) {
    //    int first = s[i] - 'a', last = s[j] - 'a';
    //    h1 = (h1 * 26 + first) % mod;
    //    h2 = (h2 + mul * last) % mod;
    //    mul = mul * 26 % mod;
    //    if (h1 == h2)
    //        len = i + 1;
    //}

    // *26 *128 有什么区别？ 这里是随机一个数？ 质数是不是 优于这些？


    // KMP

    //vector<int> dp(s.size());
    //int j = 0;
    //for (int i = 1; i < s.size(); ++i) {
    //    if (s[i] == s[j])
    //        dp[i] = ++j;
    //    else if (j > 0) {
    //        j = dp[j - 1];
    //        --i;
    //    }
    //}
    //return s.substr(0, j);





    // 不行，unsigned int 提交2次，一次是 75 / 75 test cases passed, but took too long. 。。 运气。。
//Runtime: 2437 ms, faster than 5.15 % of C++ online submissions for Longest Happy Prefix.
//Memory Usage : 467.1 MB, less than 5.04 % of C++ online submissions for Longest Happy Prefix.
    // 这个 longlong 和 unsigned 混用了，应该会被提升为 longlong。。
//Runtime: 2739 ms, faster than 5.15 % of C++ online submissions for Longest Happy Prefix.
//Memory Usage : 456 MB, less than 5.04 % of C++ online submissions for Longest Happy Prefix.
    // 最开始使用了 unsigned int。。。。 超过 MOD 后 就不准了。。...1e9+7 是 10亿， 不是1亿。。还想着 27*1亿 不超过 unsigned int.
    string lt1392a(string s)
    {
        //const long long MUL = 31;
        //const long long MOD = 1e8 + 7;

        //unordered_map<long long, unordered_set<int>> map2;
        //long long t2 = 0;
        //long long pw = 1;
        //vector<long long> vi(s.size());
        //vi[s.size() - 1] = 1;

        const unsigned int MUL = 31;
        const unsigned int MOD = 1e8 + 7;

        unordered_map<unsigned int, unordered_set<int>> map2;
        unsigned int t2 = 0;
        unsigned int pw = 1;
        vector<unsigned int> vi(s.size());
        vi[s.size() - 1] = 1;

        for (int i = 0; i < s.size() - 1; ++i)
        {
            t2 = ((t2 * MUL) + (s[i] - 'a' + 1)) % MOD;
            map2[t2].insert(i);

#ifdef __test
            cout << t2 << " - " << i << endl;
#endif

            pw = (pw * MUL) % MOD;
            vi[s.size() - 2 - i] = pw;
        }

#ifdef __test
        //for (auto& p : map2)
        //{
        //    cout<<p.first<<", "<<
        //}
#endif

//        long long pw2 = 1;
//        string ans;
//        t2 = 0;
//        for (int i = s.size() - 1; i > 0; --i)
//        {
//            t2 = (t2 + (pw2 * (s[i] - 'a' + 1))) % MOD;
//            pw2 = (pw2 * MUL) % MOD;
//#ifdef __test
//            cout << t2 << " : " << i << endl;
//#endif
//            if (map2.find(t2) != map2.end())
//            {
//                cout << "gggg " << t2 << endl;
//            }
//        }
//        return ans;

//        unsigned int pw2 = 1;
//        string ans;
//        t2 = 0;
//        for (int i = s.size() - 1; i > 0; --i)
//        {
//            t2 = (t2 + (vi[i] * (s[i] - 'a' + 1)) % MOD) % MOD;
//#ifdef __test
//            cout << t2 << " : " << i << endl;
//#endif
//            if (map2.find(t2) != map2.end() && map2[t2].find(s.size() - i - 1) != map2[t2].end())
//            {
//#ifdef __test
//                cout << "?" << i << endl;
//#endif
//                for (int j = i; j < s.size(); ++j)
//                {
//                    if (s[j] != s[j - i])
//                        goto AAA;
//                }
//                ans = s.substr(i);
//                AAA:
//                continue;
//            }
//        }
//        return ans;

        t2 = ((t2 * MUL) + (s[s.size() - 1] - 'a' + 1)) % MOD;
        
        for (int i = 0; i < s.size() - 1; ++i)
        {
            unsigned int u2 = ((s[i] - 'a' + 1) * vi[i]) % MOD;
            t2 = (t2 - u2 + MOD) % MOD;

#ifdef __test
            cout << t2 << " : " << i << endl;
#endif

            if (map2.find(t2) != map2.end() && map2[t2].find(s.size() - 2 - i) != map2[t2].end())
            {
                for (int j = i + 1; j < s.size(); ++j)
                {
                    if (s[j] != s[j - i - 1])
                        goto AAA;
                }
                return s.substr(i + 1);
                AAA:
                continue;
            }
        }
        return "";
    }

};

int main()
{

    LT1392 lt;

    //string s = "level";
    //string s = "ababab";
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

    cout << lt.lt1392a(s) << endl;

    cout << endl << endl;

    unsigned int q = 1e9 + 7;
    unsigned int a = q - 3;

    unsigned int b = 27 * a % q;

    cout << b << endl;

    long long q1 = 1e9 + 7;
    long long a1 = q1 - 3;

    long long b1 = 27 * a1 % q1;

    cout << b1 << endl;

    unsigned int aa = 27 * a;
    long long aa1 = 27 * a;
    long long aa2 = 27 * a1;

    cout << aa << ", " << aa1 << ", " << aa2 << endl;

    return 0;
}
