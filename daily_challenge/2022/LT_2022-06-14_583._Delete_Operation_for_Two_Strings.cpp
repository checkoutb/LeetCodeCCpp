
#include "../../header/myheader.h"

class LT
{
public:

    // D D




//Runtime: 15 ms, faster than 82.94 % of C++ online submissions for Delete Operation for Two Strings.
//Memory Usage : 12 MB, less than 56.25 % of C++ online submissions for Delete Operation for Two Strings.
    // longest common subsequence
    int lta(string word1, string word2)
    {
        int sz1 = word1.size();
        int sz2 = word2.size();
        vector<vector<int>> dp(sz1, vector<int>(sz2));
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (word1[i] == word2[j])
                {
                    dp[i][j] = (i > 0 && j > 0) ? dp[i - 1][j - 1] + 1 : 1;
                }
                else
                {
                    dp[i][j] = max((i > 0 ? dp[i - 1][j] : 0), (j > 0 ? dp[i][j - 1] : 0));
                }
            }
        }
        return word1.size() + word2.size() - dp[sz1 - 1][sz2 - 1] * 2;
    }

};

int main()
{

    LT lt;


    return 0;
}
