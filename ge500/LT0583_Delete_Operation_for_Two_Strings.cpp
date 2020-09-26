
#include "../header/myheader.h"

class LT0583
{
public:


// D
// dp, int[word1.length+1][word2.length+1]
//            if(i == 0 || j == 0) dp[i][j] = 0;
//            else dp[i][j] = (word1.charAt(i-1) == word2.charAt(j-1)) ? dp[i-1][j-1] + 1
//                    : Math.max(dp[i-1][j], dp[i][j-1]);



// tle.. 29 / 1307 。。。
// 最长 有序 不连续 子串。
// 。。。talk is cheap....code is hard...
    int lt0583a(string word1, string word2)
    {
        dfsa1(word1, word2, 0, 0, 0);
        return ans;
    }

    int ans = INT_MAX;

    void dfsa1(string s1, string s2, int i1, int i2, int len)
    {
        if (i1 >= s1.length() || i2 >= s2.length())
        {
            int t1 = s1.size() + s2.size() - 2 * len;
            if (t1 < ans)
                ans = t1;
            return;
        }
        dfsa1(s1, s2, i1 + 1, i2, len);

        char ch = s1[i1];
        for (; i2 < s2.length(); i2++)
        {
            if (s2[i2] == ch)
            {
                len++;
                break;
            }
        }
        dfsa1(s1, s2, i1 + 1, i2 + 1, len);
    }

};

int main()
{

    string s1{"sea"}, s2{"eat"};
//    string s1{""}, s2{"a"};

    LT0583 lt;

    cout<<lt.lt0583a(s1, s2)<<endl;

    return 0;
}
