
#include "../header/myheader.h"

class LT1312
{
public:

// D D

//int minInsertions(string s) {
//  return s.size() - longestPalindromeSubseq(s);
//}
//int dp[501][501] = {};
//int longestPalindromeSubseq(string &s) {
//  for (int len = 1; len <= s.size(); ++len)
//    for (int i = 0; i + len <= s.size(); ++i)
//      dp[i][i + len] = s[i] == s[i + len - 1] ? dp[i + 1][i + len - 1] + (len == 1 ? 1 : 2)
//        : max(dp[i][i + len - 1], dp[i + 1][i + len]);
//  return dp[0][s.size()];
//}
// ... for for 当char相等时，


//                if (s[i-1]==a[j-1]){
//                    dp[i][j]=1+dp[i-1][j-1];
//                }
//                else{
//                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//                }
// a = s.reverse



//        for (int i = 0; i < n; ++i)
//            for (int j = 0; j < n; ++j)
//                dp[i + 1][j + 1] = s[i] == s[n - 1 - j] ? dp[i][j] + 1 : max(dp[i][j + 1], dp[i + 1][j]);



//Runtime: 120 ms, faster than 5.42% of C++ online submissions for Minimum Insertion Steps to Make a String Palindrome.
//Memory Usage: 27.1 MB, less than 26.02% of C++ online submissions for Minimum Insertion Steps to Make a String Palindrome.
// hint 1 & 2:
// If we know the longest palindromic sub-sequence is x and the length of the string is n then,
//what is the answer to this problem? It is n - x as we need n - x insertions to make the remaining characters also palindrome.
// sub-seq...  计算这个substring 中 最大的 回文 sub-sequence, 然后 n-x个插入，就可以让这个 substring 变成回文。
// 。。。。。。。
    int lt1312a(string s)
    {
        int sz1 = s.size();
        vector<vector<int>> vvi(sz1, vector<int>(sz1, 0));
        for (int i = sz1 - 1; i >= 0; --i)
        {
            vvi[i][i] = 1;
            for (int j = i + 1; j < sz1; ++j)
            {
                vvi[i][j] = vvi[i][j - 1];
                for (int k = i; k < j; ++k)
                {
                    if (s[k] == s[j])
                    {
                        vvi[i][j] = max(vvi[i][j], vvi[k + 1][j - 1] + 2);
                        break;
                    }
                }
            }
        }
        #ifdef __test
        for (myvi& vi : vvi)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test
        return sz1 - vvi[0][sz1 - 1];

//        for (int i = 0; i < sz1; ++i)
//        {
//            vvi[i][i] = 1;
//            for (int j = i + 1;)
//        }
    }

};

int main()
{
//    string s = "zzazz";
//    string s = "mbadm";
//    string s = "leetcode";
//    string s = "g";
    string s = "no";

    LT1312 lt;

    cout<<lt.lt1312a(s)<<endl;

    return 0;
}
