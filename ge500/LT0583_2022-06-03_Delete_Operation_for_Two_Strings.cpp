
#include "../header/myheader.h"

class LT0583
{
public:

    // D D

    //if (s1[i - 1] == s2[j - 1]) {
    //    dp[i][j] = 1 + dp[i - 1][j - 1];
    //}
    //else {
    //    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    //}
    // 相等的时候，直接+1.



//Runtime: 24 ms, faster than 63.97 % of C++ online submissions for Delete Operation for Two Strings.
//Memory Usage : 12.2 MB, less than 49.68 % of C++ online submissions for Delete Operation for Two Strings.
    // longest common subsequence
    int lt0583a(string word1, string word2)
    {
        int sz1 = word1.size();
        int sz2 = word2.size();
        vector<vector<int>> vvi(sz1, vector<int>(sz2, 0));
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                vvi[i][j] = max((i == 0 ? 0 : vvi[i - 1][j]), (j == 0 ? 0 : vvi[i][j - 1]));
                if (word1[i] == word2[j])
                {
                    vvi[i][j] = max(vvi[i][j], ((i == 0 || j == 0) ? 0 : vvi[i - 1][j - 1]) + 1);
                }
            }
        }
        return sz1 + sz2 - vvi[sz1 - 1][sz2 - 1] * 2;
    }

};

int main()
{

    LT0583 lt;

    //string s1 = "sea";
    //string s2 = "eat";

    string s1 = "leetcode";
    string s2 = "letco";

    cout << lt.lt0583a(s1, s2) << endl;

    return 0;
}
