
#include "../header/myheader.h"

class LT2272
{
public:



// g



// tle
// substr 中 最多 - 最少， 最大值。
// prefix sum 硬算 估计tle。。。。先tle吧。。
    int lt2272a(string s)
    {
        int sz1 = s.size();
        vector<array<int, 26>> vvi(sz1);
        vvi[0][s[0] - 'a'] = 1;
        for (int i = 1; i < sz1; ++i)
        {
            for (int j = 0; j < 26; ++j)
            {
                vvi[i][j] = vvi[i - 1][j];
            }
            vvi[i][s[i] - 'a']++;
        }
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = i + 1; j < sz1; ++j)
            {
                int mx(0), mn(sz1);
                int t2 = 0;
                for (int k = 0; k < 26; ++k)
                {
                    t2 = vvi[j][k] - (i == 0 ? 0 : vvi[i - 1][k]);
                    if (t2 > mx)
                        mx = t2;
                    if (t2 != 0 && t2 < mn)
                        mn = t2;
                }
                ans = max(ans, mx - mn);
            }
        }
        return ans;
    }

};

int main()
{

    LT2272 lt;

    string s = "aababbb";
//    string s = "abcsq";

    cout<<lt.lt2272a(s)<<endl;


    return 0;
}
