
#include "../header/myheader.h"

class LT1638
{
public:

// D D

//            int miss = 0;
//            for (int pos = 0; i + pos < s.size() && j + pos < t.size(); ++pos) {
//                if (s[i + pos] != t[j + pos] && ++miss > 1)
//                    break;
//                res += miss;
//            }


//    int dpl[101][101] = {}, dpr[101][101] = {};
//    for (int i = 1; i <= s.size(); ++i)
//        for (int j = 1; j <= t.size(); ++j)
//            if (s[i - 1] == t[j - 1])
//                dpl[i][j] = 1 + dpl[i - 1][j - 1];
//    for (int i = s.size(); i > 0; --i)
//        for (int j = t.size(); j > 0; --j)
//            if (s[i - 1] == t[j - 1])
//                dpr[i - 1][j - 1] = 1 + dpr[i][j];
//    for (int i = 0; i < s.size(); ++i)
//        for (int j = 0; j < t.size(); ++j)
//            if (s[i] != t[j])
//                res += (dpl[i][j] + 1) * (dpr[i + 1][j + 1] + 1);


//    int countSubstrings(string s, string t) {
//        int res = 0 ;
//        for (int i = 0; i < s.length(); ++i)
//            res += helper(s, t, i, 0);
//        for (int j = 1; j < t.length(); ++j)
//            res += helper(s, t, 0, j);
//        return res;
//    }
//
//    int helper(string s, string t, int i, int j) {
//        int res = 0, pre = 0, cur = 0;
//        for (int n = s.length(), m = t.length(); i < n && j < m; ++i, ++j) {
//            cur++;
//            if (s[i] != t[j])
//                pre = cur, cur = 0;
//            res += pre;
//        }
//        return res;
//    }


// t[i + m/n] -> 11
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count Substrings That Differ by One Character.
//Memory Usage: 6.2 MB, less than 91.76% of C++ online submissions for Count Substrings That Differ by One Character.
// 最多加个memo， 不，dp，  找到一个不同的，然后向2侧扩展，如果相同，继续扩展。 *
    int lt1638a(string s, string t)
    {
//        unordered_set<long> set2;
        int ans = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            char chs = s[i];
            for (int j = 0; j < t.size(); ++j)
            {
                if (chs != t[j])
                {
                    int m = 1;
                    int n = 1;
                    while (i + m < s.size() && j + m < t.size() && s[i + m] == t[j + m])
                    {
                        m++;
                    }
                    while (i - n >= 0 && j - n >= 0 && s[i - n] == t[j - n])
                        n++;
                    ans += m * n;
//                    #ifdef __test
//                    cout<<i<<", "<<j<<", "<<m<<", "<<n<<endl;
//                    #endif // __test
//                    for (int s2 = -n + 1; s2 <= 0; ++s2)
//                    {
//                        for (int e = 0; e < m; ++e)
//                        {
//                            #ifdef __test
//                            cout<<s.substr(i + s2, e - s2 + 1)<<" : "<<t.substr(j + s2, e - s2 + 1)<<endl;
//                            #endif // __test
//
//                            set2.insert((i + s2) * 1000000000L + (i + e) * 1000000L + (j + s2) * 1000L + (j + e));
//                        }
//                    }

//                    for (int is = i - n + 1; is <= i; is++)
//                    {
//                        for (int ie = i; ie < i + m; ++ie)
//                        {
//                            #ifdef __test
//                            cout<<is * 1000 + ie<<endl;
//                            #endif // __test
////                            set2.insert(is * 1000 + ie);
//                            set2.insert(is * 1000000000L + ie * 1000000L + )
//                        }
//                    }
                }
            }
        }
        #ifdef __test
//        cout<<ans<<endl;
        #endif // __test
//        ans = set2.size();
        return ans;
    }

};

int main()
{
//    string s{"aba"}, t{"baba"};
    string s{"ab"}, t{"bb"};
//    string s{"a"}, t{"a"};
//    string s{"abe"}, t{"bbc"};      // a-3, b-1, e-3, ab-1 be-1
                // a ab a a b e e be e ....

    LT1638 lt;

    cout<<lt.lt1638a(s, t);

    return 0;
}
