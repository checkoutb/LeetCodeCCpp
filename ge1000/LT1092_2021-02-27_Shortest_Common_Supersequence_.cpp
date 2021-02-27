
#include "../header/myheader.h"

class LT1092
{
public:

// D D

//    string shortestCommonSupersequence(string& A, string& B) {
//        int i = 0, j = 0;
//        string res = "";
//        for (char c : lcs(A, B)) {
//            while (A[i] != c)
//                res += A[i++];
//            while (B[j] != c)
//                res += B[j++];
//            res += c, i++, j++;
//        }
//        return res + A.substr(i) + B.substr(j);
//    }
//
//    string lcs(string& A, string& B) {
//        int n = A.size(), m = B.size();
//        vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));
//        for (int i = 0; i < n; ++i)
//            for (int j = 0; j < m; ++j)
//                if (A[i] == B[j])
//                    dp[i + 1][j + 1] = dp[i][j] + A[i];
//                else
//                    dp[i + 1][j + 1] = dp[i + 1][j].size() > dp[i][j + 1].size() ?  dp[i + 1][j] : dp[i][j + 1];
//        return dp[n][m];
//    }



//string shortestCommonSupersequence(string a, string b, string res = "") {
//  vector<vector<short>> dp(a.size() + 1, vector<short>(b.size() + 1));
//  for (int i = 1; i <= a.size(); ++i)
//    for (int j = 1; j <= b.size(); ++j)
//      if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
//      else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//  for (int i = a.size(), j = b.size(); i || j; ) {
//    if (i > 0 && dp[i][j] == dp[i - 1][j]) res = a[--i] + res;
//    else if (j > 0 && dp[i][j] == dp[i][j - 1]) res = b[--j] + res;
//    else res = a[--i] + res, --j;
//  }
//  return res;
//}



// 看了 lcs 方法 修复了 自己的 i==0 || j == 0 , 以后还是 sz1 + 1 sz2 + 1吧。。。
//Runtime: 24 ms, faster than 50.00% of C++ online submissions for Shortest Common Supersequence .
//Memory Usage: 12.9 MB, less than 48.64% of C++ online submissions for Shortest Common Supersequence .
// error.
// 最长公共子串，然后添加其他的。
// 1000 * 1000 ..
    string lt1092a(string str1, string str2)
    {
        int sz1 = str1.size();
        int sz2 = str2.size();
        vector<vector<int>> vv(sz1, vector<int>(sz2));
        vector<int> v1;
        vector<int> v2;
//        int lst = 0;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (str1[i] == str2[j])
                {
                    if (i == 0 || j == 0)
                        vv[i][j] = 1;
                    else
                    {

                    // 又提交了一次，  确实， 不需要 max(max) 。。。。。。 之前错 是因为 下面 的错。
//                        vv[i][j] = vv[i - 1][j - 1] + 1;        // not max(max())         // ... 昨天 看到一个是 不用 的啊。。。。
                        vv[i][j] = max(vv[i - 1][j - 1] + 1, max(vv[i - 1][j], vv[i][j - 1]));

                    }
                    // zheli jilu v1 v2 ?
//                    v1.push_back
//                    int t2 = v[i][j];
//
//                    lst = max(lst, t2);
//                    if (v1.empty())
//                    {
//                        v1.push_back(i);
//                        v2.push_back(j);
//                    }
//                    else
//                    {
//                        int t1 = v1.back();
//                        int t2 = v2.back();
//                        if (i > t1 && j > t2)
//                        {
//                            v1.push_back(i);
//                            v2.push_back(j);
//                        }
//                    }
                }
                else
                {
                    if (i == 0 || j == 0)
                    {
//                        vv[i][j] = 0;                   // ...................lcs........ cuo zai zheli ,,,,,,,,,,,
                        if (i == 0 && j == 0)
                        {
                            vv[i][j] = 0;
                        }
                        else
                        {
                            if (i == 0)
                                vv[i][j] = vv[i][j - 1];
                            else
                                vv[i][j] = vv[i - 1][j];
                        }
                    }
                    else
                        vv[i][j] = max(vv[i - 1][j], vv[i][j - 1]);

                }
            }
        }
        #ifdef __test
//        showVectorInt(v1);
//        showVectorInt(v2);
        cout<<" = = == = "<<endl;
        cout<<vv[sz1 - 1][sz2 - 1]<<endl;
        for (myvi& v : vv)
        {
            for (int i : v)
                cout<<i<<", ";
            cout<<endl;
        }
        cout<<" -----------"<<endl;
        #endif // __test

        int lstj = sz2 - 1;
        int t2 = vv[sz1 - 1][sz2 - 1];
        for (int i = sz1 - 1; i >= 0 && t2 > 0; --i)
        {

//            if (t2 == 1)
//            cout<<i<<" . .. "<<" . ."<<lstj<<endl;

            for (int j = lstj; j >= 0; --j)
            {
                if (str1[i] == str2[j] && vv[i][j] == t2)
                {
                    t2--;
//                    v1.insert(v1.begin(), );
                    v1.push_back(i);
                    v2.push_back(j);
                    lstj = j - 1;
                    break;
                }
            }
        }
        std::reverse(begin(v1), end(v1));
        reverse(begin(v2), end(v2));

        #ifdef __test
        cout<<" .t2 : "<<t2<<endl;
        showVectorInt(v1);
        showVectorInt(v2);
        #endif // __test

        string ans;
        int p1 = 0;
        int p2 = 0;
        for (int i = 0; i < v1.size(); ++i)
        {
            int t1 = v1[i];
            int t2 = v2[i];
            while (p1 < t1)
            {
                ans += str1[p1++];
            }
            p1++;       // skip v1[i];
            while (p2 <= t2)
            {
                ans += str2[p2++];
            }
            #ifdef __test
            cout<<i<<", "<<p1<<" , ,"<<p2<<" : ; "<<ans<<endl;
            #endif // __test
        }
        if (p1 < str1.size())
        {
            ans += str1.substr(p1);
        }
        if (p2 < str2.size())
            ans += str2.substr(p2);
        #ifdef __test
        cout<<ans.size()<<endl;
        #endif // __test
        return ans;

//        vector<int> v1;
//        vector<int> v2;
//        int tar = 1;
//        for (int i = 0; i < sz1; ++i)
//        {
//            for (int j = 0; j < sz2; ++j)
//            {
//                if (str[i] == str[j])
//                {
//
//                }
//            }
//        }

    }

};

string lcs(string& A, string& B);

int main()
{
//    string s1 = "abac", s2 = "cab";

//    string s1 = "aabbabaa", s2 = "aabbbbbbaa";      // "aabbabbbbaa"

//    string s1 = "babbbbaa", s2 = "baabbbbba";       // "baabbbbaba"
// 1 2 3 4 5 7
// a b b b b a
// 2 4 5 6 7 8
// a b b b b a
// b a b b b b a

    string s1 = "adbcbccdcadcbcbcbbdccbddcdccababccbccbddbbbcabdbdacdbccccbabacaa";
    string s2 = "dcbaddabcaadabacbbbddccbbccdbadbdaccdccbbbdbddcbacbdbcdcaddbdadabcbaacbaaaaadbcba";
    //"adbcbaccddabcaadabacbbbddcbcbbdccdbadbdaccdccababccbccdbddcbacbdbcdcabddbdacdabcbaacccbaaaaadbacaba"



    LT1092 lt;

    cout<<lt.lt1092a(s1, s2);

    string lcs2 = lcs(s1, s2);
    cout<<"\n\n\n\n"<<lcs2<<endl;
    cout<<lcs2.size()<<endl;

    return 0;
}

string lcs(string& A, string& B) {
    int n = A.size(), m = B.size();
    vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (A[i] == B[j])
                dp[i + 1][j + 1] = dp[i][j] + A[i];
            else
                dp[i + 1][j + 1] = dp[i + 1][j].size() > dp[i][j + 1].size() ?  dp[i + 1][j] : dp[i][j + 1];
    return dp[n][m];
}
