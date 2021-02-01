
#include "../header/myheader.h"

class LT0044
{
public:

// D D

// in detail, 4-8ms
// 线性
//Worst case definitely not linear. Should be O(NM)
//        const char* star=NULL;
//        const char* ss=s;
//        while (*s){
//            //advancing both pointers when (both characters match) or ('?' found in pattern)
//            //note that *p will not advance beyond its length
//            if ((*p=='?')||(*p==*s)){s++;p++;continue;}
//
//            // * found in pattern, track index of *, only advancing pattern pointer
//            if (*p=='*'){star=p++; ss=s;continue;}
//
//            //current characters didn't match, last pattern pointer was *, current pattern pointer is not *
//            //only advancing pattern pointer
//            if (star){ p = star+1; s=++ss;continue;}
//
//           //current pattern pointer is not star, last patter pointer was not *
//           //characters do not match
//            return false;
//        }
//       //check for remaining characters in pattern
//        while (*p=='*'){p++;}
//        return !*p;



//        int m = s.length(), n = p.length();
//        if (n > 30000) return false; // the trick
//        vector<bool> cur(m + 1, false);
//        cur[0] = true;
//        for (int j = 1; j <= n; j++) {
//            bool pre = cur[0]; // use the value before update
//            cur[0] = cur[0] && p[j - 1] == '*';
//            for (int i = 1; i <= m; i++) {
//                bool temp = cur[i]; // record the value before update
//                if (p[j - 1] != '*')
//                    cur[i] = pre && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
//                else cur[i] = cur[i - 1] || cur[i];
//                pre = temp;
//            }
//        }
//        return cur[m];


//        int m = s.length(), n = p.length();
//        int i = 0, j = 0, asterisk = -1, match;
//        while (i < m) {
//            if (j < n && p[j] == '*') {
//                match = i;
//                asterisk = j++;
//            }
//            else if (j < n && (s[i] == p[j] || p[j] == '?')) {
//                i++;
//                j++;
//            }
//            else if (asterisk >= 0) {
//                i = ++match;
//                j = asterisk + 1;
//            }
//            else return false;
//        }
//        while (j < n && p[j] == '*') j++;
//        return j == n;


// 0ms
//    int f(string& s, string& p, int i, int j){
//        //i is for 's' string and j is for 'p' string
//
//        if (i == s.size() && j == p.size()) return 2;
//        if (i == s.size() && p[j] != '*') return 0;
//        //everything matched but p string got over but s string is not over
//        if (j == p.size()) return 1;
//        if (p[j] == '*'){
//            if(j+1<p.size() && p[j+1] == '*') //skip the duplicate
//                return f(s, p, i, j+1);
//            for(int k=0; k<=s.size()-i; k++){
//                int res = f(s, p, i+k, j+1);
//                if(res == 0 || res == 2) return res;
//            }
//        }
//        if (p[j] == '?' || s[i] == p[j])
//            return f(s,p,i+1,j+1);
//        return 1;
//    }
//
//    bool isMatch(string s, string p) {
//        return f(s, p, 0, 0) > 1;
//    }


// 16 ms
//        if(s==p) return true;
//        if(p=="") return false;
//        int slen = s.size(), plen = p.size(), i;
//        bool DP[2][slen+1];
//        DP[0][0] = true;
//        for(i=1; i<=slen; i++) DP[0][i] = false;
//        for(i=1; i<=plen; i++) {
//            int nowr = i%2, prer = (i+1)%2;
//            DP[nowr][0] = p[i-1]=='*' ? DP[prer][0] : false;
//            for(int j=1; j<=slen; j++) {
//                DP[nowr][j] = p[i-1]=='*' ? DP[prer][j]|DP[nowr][j-1] : false;
//                if(p[i-1]=='?' || p[i-1]==s[j-1]) DP[nowr][j] = DP[prer][j-1];
//            }
//        }
//        return DP[(i-1)%2][slen];


// 。。。 看着 LT0010 的 Discuss 写这道。
//Runtime: 768 ms, faster than 5.98% of C++ online submissions for Wildcard Matching.
//Memory Usage: 11.3 MB, less than 50.58% of C++ online submissions for Wildcard Matching.
    bool lt0044c(string s, string p)
    {
        int sz1 = s.size();
        int sz2 = p.size();
        vector<vector<bool>> vvb(sz1 + 1, vector<bool>(sz2 + 1, false));
        vvb[0][0] = true;
        int t2 = 0;
//        if (p[0] == '*')            // s为"" 可以匹配多少 p
//        {
//
//        }
        while (p[t2] == '*')
            vvb[0][++t2] = true;

        for (int i = 1; i <= sz1; ++i)
        {
            char chs = s[i - 1];
            for (int j = 1; j <= sz2; ++j)
            {
                char chp = p[j - 1];
                if (chs == chp || chp == '?')
                {
                    vvb[i][j] = vvb[i - 1][j - 1];
                }
                else
                {
                    if (chp == '*')
                    {
                        for (int k = 0; k <= i; ++k)
                        {
                            if (vvb[k][j - 1])
                            {
                                vvb[i][j] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        bool ans = vvb[sz1][sz2];
        return ans;
    }



// error
    bool lt0044b(string s, string p)
    {
        int sz1 = s.size();
        int sz2 = p.size();
        vector<vector<bool>> vvb(sz2, vector<bool>(sz1, false));
        for (int j = 0; j < sz2; ++j)
        {
            char chp = p[j];
            for (int i = 0; i < sz1; ++i)
            {
                char chs = s[i];
                if (chs == chp)
                {
                    vvb[i][j] = true;
                    if (i > 0 && j > 0)
                        vvb[i][j] = vvb[i - 1][j - 1];
                }
                else
                {
                    if (std::isalpha(chp))
                    {
                        vvb[i][j] = false;
                    }
                    else
                    {
                        if (chp == '?')
                        {
                            vvb[i][j] = true;
                            if (i > 0 && j > 0)
                                vvb[i][j] = vvb[i - 1][j - 1];
                        }
                        else
                        {
                            vvb[i][j] = true;
                            if (i > 0 && j > 0)
                                vvb[i][j] = vvb[i - 1][j - 1];
                        }
                    }
                }
            }
        }
    }


// error
// 0 <= s.length, p.length <= 2000
//    '?' Matches any single character.
//    '*' Matches any sequence of characters (including the empty sequence).
    bool lt0044a(string s, string p)
    {
        int szs = s.size();
        int szp = p.size();
        vector<vector<bool>> vvb(szs, vector<bool>(szp));
        int fst = 0;
        for (int i = 0; i < szs; ++i)
        {
            char chs = s[i];
            for (int j = fst; j < szp; ++j)
            {

                char chp = p[j];
                if (std::isalpha(chp))      // chs == chp ?         if (!vvb[i][j])
                {
                    vvb[i][j] = chp == chs;
                    if (i > 0 && j > 0)
                        vvb[i][j] = vvb[i - 1][j - 1] and vvb[i][j];
                    break;
                }
                else
                {
                    if (chp == '?')
                    {
                        vvb[i][j] = true;
                        if (i > 0 && j > 0)
                            vvb[i][j] = vvb[i - 1][j - 1] and vvb[i][j];
                        break;
                    }
                    else        // *
                    {
                        vvb[i][j] = true;
                        if (i > 0)
                            vvb[i][j] = vvb[i - 1][j] and vvb[i][j];
                    }
                }
            }
        }
        return vvb[szs - 1][szp - 1];
    }

};

int main()
{
//    string s{"aa"}, p{"aa"};
//    string s{"aa"}, p{"*"};
//    string s{"cb"}, p{"?a"};
//    string s{"adceb"}, p{"*a*b"};
    string s{"acdcb"}, p{"a*c?b"};

    LT0044 lt;

    cout<<lt.lt0044c(s, p)<<endl;

    return 0;
}
