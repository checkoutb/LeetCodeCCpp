
#include "../header/myheader.h"

class LT0712
{
public:

    // D D

    //if (s1[i] == s2[j]) {
    //    dp[i + 1][j + 1] = dp[i][j] + int(s1[i]) * 2;
    //}
    //else {
    //    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
    //}
// 相等的时候 不需要 [-1][0] 和 [0][-1]


    //if (a[i - 1] == b[j - 1])
    //    dp[i][j] = dp[i - 1][j - 1];
    //else
    //    dp[i][j] = min(dp[i - 1][j] + a[i - 1],
    //        dp[i][j - 1] + b[j - 1]);




    // 1000 * 1000 * 4 == 4mb。。
//Runtime: 73 ms, faster than 40.00 % of C++ online submissions for Minimum ASCII Delete Sum for Two Strings.
//Memory Usage : 15.2 MB, less than 60.54 % of C++ online submissions for Minimum ASCII Delete Sum for Two Strings.
    // 删除最少 <=> 保存最多
    int lt0712a(string s1, string s2)
    {
        int sz1 = s1.size();
        int sz2 = s2.size();
        int sum2 = 0;
        for (int i = 0; i < sz1; ++i)
            sum2 += s1[i];
        for (int i = 0; i < sz2; ++i)
            sum2 += s2[i];

        vector<vector<int>> vvi(sz1, vector<int>(sz2, 0));

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (s1[i] == s2[j])
                {
                    vvi[i][j] = max(max(i > 0 ? vvi[i - 1][j] : 0, j > 0 ? vvi[i][j - 1] : 0), ((i > 0 && j > 0) ? vvi[i - 1][j - 1] : 0) + s1[i]);
                }
                else
                {
                    vvi[i][j] = max(i > 0 ? vvi[i - 1][j] : 0, j > 0 ? vvi[i][j - 1] : 0);
                }
            }
        }
        return sum2 - vvi[sz1 - 1][sz2 - 1] * 2;
    }

};

int main()
{

    LT0712 lt;

    //string s1 = "sea";
    //string s2 = "eat";

    //string s1 = "delete";
    //string s2 = "leet";

    string s1 = "b";
    string s2 = "a";

    cout << lt.lt0712a(s1, s2) << endl;

    return 0;
}
