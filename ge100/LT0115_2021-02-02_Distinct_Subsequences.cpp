
#include "../header/myheader.h"

class LT0115
{
public:

// D


// 任意的s子串，都能找到subseq 匹配 ""(来自t)，所以 dp[x][0] = 1
//    if the current character in S doesn't equal to current character T, then we have the same number of distinct subsequences as we had without the new character.
//    if the current character in S equal to the current character T,
//then the distinct number of subsequences: the number we had before plus the distinct number of subsequences we had with less longer T and less longer S.
// 如果不想等，那么s[i] 匹配不到t[j], 所以 dp[i][j] 的值 还是 只匹配到 t[j-1]的值
// 如果相等， s[i] 可以存在 subseq中， 也可以不放到subseq中， 如果放，那么就是 [i-1][j-1] 的基础上 各自加上i,j， 所以 个数不变。 dp[i-1][j-1]
//      如果不放， 那么就 是 到t[j-1]的值。   dp[i][j-1]



// 估计类似 昨天的，10, 44
    int lt0115a(string s, string t)
    {
        int sz1 = s.size();
        int sz2 = t.size();
        vector<vector<int>> vvi(sz1 + 1, vector<int>(sz2 + 1, 0));
        vvi[0][0] = 1;          // "" to "", size0 : size0
        for (int i = 0; i < sz1; ++i)
            vvi[i][0] = 1;
//        for (int j = 0; j < sz2; ++j)
//            vvi[0][j] = 1;

        for (int i = 1; i <= sz1; ++i)
        {
            for (int j = 1; j <= sz2; ++j)
            {
                if (s[i - 1] == t[j - 1])
                {
                    vvi[i][j] = vvi[i - 1][j - 1] + vvi[i][j - 1];                         // discuss...
//                    vvi[i][j] = vvi[i - 1][j - 1];
                }
                else
                {
                    vvi[i][j] = vvi[i][j - 1];
//                    vvi[i][j] = vvi[i - 1][j] + vvi[i - 1][j - 1] + vvi[i][j - 1];
                }
            }
        }
        #ifdef __test
        for (vector<int>& vi : vvi)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test
        return vvi[sz1][sz2];
    }

};

int main()
{
//    string s{"rabbbit"}, t{"rabbit"};
    string s{"babgbag"}, t{"bag"};

    LT0115 lt;

    cout<<lt.lt0115a(s, t)<<endl;

    return 0;
}
