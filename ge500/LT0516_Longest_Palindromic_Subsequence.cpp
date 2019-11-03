
#include "../header/myheader.h"

class LT0516
{
public:

// dp
//                if (s.charAt(i) == s.charAt(j)) {
//                    dp[i][j] = dp[i+1][j-1] + 2;
//                } else {
//                    dp[i][j] = Math.max(dp[i+1][j], dp[i][j-1]);
//                }

// reverse, LCS


// ??? 只会穷举。。。
    // 61 / 83  tle...
    int len = 0;
    int lt0516a(string s)
    {
        if(s.size() < 1)
        {
            return 0;
        }
        recursiona1(s, 0, s.size() - 1, 0);
        return len;
    }

    void recursiona1(string s, int f, int e, int sz1)
    {
        if (f > e)
        {
            len = std::max(len, sz1);
            return;
        }
        int e2 = e;
        char ch = s[f];
        for (; e >= f; e--)
        {
            if (ch == s[e])
                break;
        }
        if (ch == s[e])
        {
            recursiona1(s, f + 1, e - 1, sz1 + (1 + (f != e)));         // + 优先于 !=....
        }
        else
        {
            len = std::max(len, sz1);
        }
        recursiona1(s, f + 1, e2, sz1);
    }
};

int main()
{
//    string s = "bbbabbb";
    string s = "cbbd";

    LT0516 lt;
    cout<<lt.lt0516a(s)<<endl;

    return 0;
}
