
#include "../header/myheader.h"

class LT0010
{
public:


// D D

// dp     < 10ms
//        int l=s.length(),m=p.length();
//        vector<vector<bool>> dp(l+1,vector<bool>(m+1));
//        dp[0][0]=true;
//        for(int i=2;i<=m;i++){
//            if(p[i-1]=='*') dp[0][i]=dp[0][i-2];
//        }
//
//        for(int i=1;i<=l;i++){
//            for(int j=1;j<=m;j++){
//                if(s[i-1]==p[j-1] || p[j-1]=='.'){
//                    dp[i][j]=dp[i-1][j-1];
//                }
//                else if(p[j-1]=='*'){
//                     dp[i][j]=dp[i][j-2];
//                    if(p[j-2]=='.' || p[j-2]==s[i-1]){
//                        dp[i][j]=dp[i][j]||dp[i-1][j];
//                    }
//                }
//            }
//        }

//        for (int i = 0; i <= m; i++) {
//            for (int j = 1; j <= n; j++) {
//                if (p[j - 1] == '*') {
//                    cur[j] = cur[j - 2] || (i && pre[j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
//                } else {
//                    cur[j] = i && pre[j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
//                }
//            }
//            fill(pre.begin(), pre.end(), false);
//			swap(pre, cur);
//        }

//        for (int i = 0; i <= m; i++) {
//            bool pre = cur[0];
//            cur[0] = !i;
//            for (int j = 1; j <= n; j++) {
//                bool temp = cur[j];
//                if (p[j - 1] == '*') {
//                    cur[j] = cur[j - 2] || (i && cur[j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
//                } else {
//                    cur[j] = i && pre && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
//                }
//                pre = temp;
//            }
//        }

// dfs  250ms
//        if (p.empty())
//            return s.empty();
//        bool isfirstmatch = (!s.empty() && ((s[0] == p[0]) || (p[0] =='.')));
//        if (p.length() >= 2 && p[1] == '*'){
//            return (isMatch(s, p.substr(2)) || (isfirstmatch && isMatch(s.substr(1), p)));
//        }
//        else {
//            return isfirstmatch && isMatch(s.substr(1), p.substr(1));
//        }


// 5 years.
//02/01/2021 09:40	Accepted	1936 ms	6.2 MB	cpp
//03/15/2016 19:06	Wrong Answer	N/A	N/A	c
//03/15/2016 19:05	Wrong Answer	N/A	N/A	c
//03/15/2016 19:04	Compile Error	N/A	N/A	c
//03/15/2016 18:48	Wrong Answer	N/A	N/A	c
//03/15/2016 18:47	Wrong Answer	N/A	N/A	c
//03/15/2016 18:45	Wrong Answer	N/A	N/A	c
//03/15/2016 13:16	Wrong Answer	N/A	N/A	c
//03/15/2016 13:14	Wrong Answer	N/A	N/A	c
//                                       anyway, it worked !!!!!
//Runtime: 1936 ms, faster than 5.13% of C++ online submissions for Regular Expression Matching.
//Memory Usage: 6.2 MB, less than 98.41% of C++ online submissions for Regular Expression Matching.
//    '.' Matches any single character.​​​​
//    '*' Matches zero or more of the preceding element.
// .*  代表 任意个.，  任意个任意字符。
//0 <= s.length <= 20
//0 <= p.length <= 30
    bool lt0010a(string s, string p)
    {
        bool ans = dfsa1(s, p, 0, 0);
        return ans;
    }

    bool dfsa1(string& s, string& p, int si, int pi)
    {
        if (si >= s.size())
        {
            while (pi < p.size())
            {
                if (pi + 1 == p.size() || p[pi + 1] != '*')
                {
                    return false;
                }
                pi += 2;
            }
            return true;
        }
        if (pi >= p.size())
        {
            return false;
        }
        bool isStar = (pi + 1 < p.size() && p[pi + 1] == '*');

        if (isStar)              // skip p[pi]
        {
            if (dfsa1(s, p, si, pi + 2))
                return true;
        }

        if (p[pi] == '.' || s[si] == p[pi])     // match
        {
            if (isStar)
            {
                if (dfsa1(s, p, si + 1, pi))
                    return true;
                return dfsa1(s, p, si + 1, pi + 2);
            }
            else
            {
                return dfsa1(s, p, si + 1, pi + 1);
            }
        }
        else
        {
            // no match
            if (isStar)     // skip pi , *
            {
                return dfsa1(s, p, si, pi + 2);
            }
            else
            {
                return false;
            }
        }
        return false;           // cannot reach.
    }

};

int main()
{
//    string s{"aa"}, p{"a"};
//    string s{"aa"}, p{"aa"};
//    string s{"aa"}, p{"aaa"};
//    string s{"aa"}, p{"a*"};
//    string s{"ab"}, p{".*"};
//    string s{"aab"}, p{"c*a*b*"};
    string s{"mississippi"}, p{"mis*is*p*."};

    LT0010 lt;

    cout<<lt.lt0010a(s, p)<<endl;

    return 0;
}
