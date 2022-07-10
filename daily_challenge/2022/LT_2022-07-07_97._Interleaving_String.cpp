
#include "../../header/myheader.h"

class LT
{
public:


    // D D


    //if (i == 0 && j == 0) dp[i][j] = 1;
    //else if (i == 0) dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
    //else if (j == 0) dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
    //else dp[i][j] = ((dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]) || (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]));


    //if (i == 0 && j == 0)
    //    table[i][j] = true;
    //else if (i == 0)
    //    table[i][j] = (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
    //else if (j == 0)
    //    table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
    //else
    //    table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]);



//Runtime: 0 ms, faster than 100.00 % of C++ online submissions for Interleaving String.
//Memory Usage : 6.7 MB, less than 66.40 % of C++ online submissions for Interleaving String.
    // dp?
    bool lta(string s1, string s2, string s3)
    {
        int sz1 = s1.size();
        int sz2 = s2.size();

        if (sz1 == 0)
            return s3 == s2;
        if (sz2 == 0)
            return s1 == s3;
        if (sz1 + sz2 != s3.size())
            return false;

        vector<vector<bool>> vvb(sz1 + 1, vector<bool>(sz2 + 1, false));

        for (int i = 0; i < sz1; ++i)
        {
            if (s1[i] == s3[i])
                vvb[i + 1][0] = true;
            else
                break;
        }
        for (int i = 0; i < sz2; ++i)
        {
            if (s2[i] == s3[i])
                vvb[0][i + 1] = true;
            else
                break;
        }
        vvb[0][0] = true;

        for (int i = 1; i <= sz1; ++i)       // length
        {
            for (int j = 1; j <= sz2; ++j)
            {
                if (vvb[i - 1][j] && s3[i + j - 1] == s1[i - 1])
                    vvb[i][j] = true;
                else
                {
                    if (vvb[i][j - 1] && s3[i + j - 1] == s2[j - 1])
                        vvb[i][j] = true;
                }
            }
        }

        return vvb[sz1][sz2];
    }

};

int main()
{

    LT lt;

    //string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";

    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc";

    cout << lt.lta(s1, s2, s3) << endl;

    return 0;
}
