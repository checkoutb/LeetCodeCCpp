
#include "../header/myheader.h"

class LT1745
{
public:

// D D


//bool isPal[2000][2000] = {};
//bool checkPartitioning(string s) {
//    for (int i = s.size() - 1; i >= 0; --i) {
//        for (int j = i; j < s.size(); ++j)
//            isPal[i][j] = s[i] == s[j] ? i + 1 >= j || isPal[i + 1][j - 1] : false;
//    }
//    for (auto i = 2; i < s.size(); ++i) {
//        if (isPal[i][s.size() - 1]) {
//            for (auto j = 1; j < i; ++j)
//                if (isPal[j][i - 1] && isPal[0][j - 1])
//                    return true;
//        }
//    }
//    return false;
//}
// 。。。 预先计算，后续就是O(1) 判断回文。。



//        for(int i = n - 1; i >= 0; i--) {
//            for(int j = i; j < n; j++) {
//                int len = j - i + 1;
//                if(len == 1) {
//                    dp[i][j] = true;
//                }
//                else if(len == 2) {
//                    dp[i][j] = (str[i] == str[j]);
//                }
//                else {
//                    dp[i][j] = (str[i] == str[j]) and (dp[i + 1][j - 1]);
//                }
//            }
//        }


//        bool dp[n][n];
//        memset(dp,0,sizeof(dp));


// hint 1 的 O(1) 判断回文 怎么搞？
//Runtime: 460 ms, faster than 15.37% of C++ online submissions for Palindrome Partitioning IV.
//Memory Usage: 6.6 MB, less than 95.72% of C++ online submissions for Palindrome Partitioning IV.
// hint 2: Note that one string is a prefix and another one is a suffix you can try brute forcing the rest
    bool lt1745b(string s)
    {
//        unordered_set<int> set2;
        vector<int> vi;
        for (int i = s.size() - 1; i > 0; --i)
        {
            if (s[i] == s[s.size() - 1] && isPalind(s, i, s.size() - 1))
            {
                vi.push_back(i);
//                set2.insert(i);
            }
        }
        #ifdef __test
        showVectorInt(vi);
        #endif // __test
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == s[0] && isPalind(s, 0, i))
            {
                for (vector<int>::iterator it = upper_bound(begin(vi), end(vi), i); it != end(vi); it++)
                {
                    if (s[i + 1] == s[*it - 1] && isPalind(s, i + 1, *it - 1))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }



// tle
// memo？
    bool lt1745a(string s)
    {
        return dfsa1(s, 0, 0);
    }

    bool dfsa1(string& s, int idx, int cnt)
    {
        if (idx >= s.size())
            return false;
        if (cnt == 2)
        {
            return isPalind(s, idx, s.size() - 1);
        }
        for (int i = idx; i < s.size(); ++i)
        {
            if (s[idx] == s[i] && isPalind(s, idx, i))
            {
                if (dfsa1(s, i + 1, cnt + 1))
                {
                    return true;
                }
            }
        }
        return false;

//        if (cnt == 3)
//        {
//            if (idx == s)
//        }
//        if (cnt > 3)
//            return false;
    }

    bool isPalind(string& s, int st, int en)
    {
        while (st < en)
        {
            if (s[st++] != s[en--])
                return false;
        }
        return true;
    }

};

int main()
{
//    vector<string> vs = {"abcbdd", "bcbddxy"};

//    string s = "abcbdd";
//    string s = "bcbddxy";
    string s = "babcbabaababcbabaz";

    LT1745 lt;

//    for (string& s : vs)
//        cout<<lt.lt1745a(s)<<endl;

    cout<<lt.lt1745b(s)<<endl;

    return 0;
}
