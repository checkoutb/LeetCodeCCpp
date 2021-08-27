
#include "../header/myheader.h"

class LT0828
{
public:


// D

// 上一次出现在什么时候，下一次出现在什么时候，   这2个界限的范围内的，包含自己的所有substring， 都只含有一个自己。




// tle.
    int lt0828a(string s)
    {
        int sz1 = s.size();
        vector<vector<int>> vvi(sz1, vector<int>(26, 0));
        int ans = 0;
        vvi[0][s[0] - 'A'] = 1;
        for (int i = 1; i < sz1; ++i)
        {
            int t2 = s[i] - 'A';
            vvi[i][t2]++;
            for (int j = 0; j < 26; ++j)
            {
                vvi[i][j] += vvi[i - 1][j];
                if (vvi[i][j] == 1)
                    ans++;
            }
        }
//        cout<<ans<<", "<<sz1<<endl;
        ans += sz1;

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = i + 2; j < sz1; ++j)
            {
                for (int k = 0; k < 26; ++k)
                {
                    if ((vvi[j][k] - vvi[i][k]) == 1)
                    {
//                        cout<<j<<", "<<i<<", "<<k<<endl;
                        ans++;
                    }
                }
            }
        }

        return ans;
    }

};

int main()
{
//    string s = "ABC";
//    string s = "ABA";
    string s = "LEETCODE";

    LT0828 lt;

    cout<<lt.lt0828a(s)<<endl;

    return 0;
}
