
#include "../header/myheader.h"

class LT0730
{
public:


    // D





    // g



    // eeeeeeeerrrrrrrrrrrrrrror  错的太远了。
    // len == 1, 
    // s[x] == s[y]   vvi[x][y] = vvi[x+1][y-1] * 2     x+1 > y-1 ?
    // 去重。。。
    int lt0730a(string s)
    {
        int sz1 = s.size();
        const int MOD = 1e9 + 7;

        vector<vector<int>> vvi(sz1, vector<int>(sz1, 0));

        for (int i = 0; i < sz1; ++i)
        {
            vvi[i][i] = 1;
        }

        for (int len = 2; len <= sz1; ++len)
        {
            for (int i = 0; i + len - 1 < sz1; ++i)
            {
                if (s[i] == s[i + len - 1])
                {
                    if (len == 2)
                    {
                        vvi[i][i + len - 1] = 3 - (s[i] == s[i + 1]);
                    }
                    else
                    {
                        vvi[i][i + len - 1] = (vvi[i + 1][i + len - 2] * 2) % MOD;
                    }
                }
                else
                {
                    vvi[i][i + len - 1] = len == 2 ? 2 : (vvi[i + 1][i + len - 2] + 2);
                }
            }
        }

#ifdef __test
        for (myvi& vi : vvi)
        {
            for (int i = 0; i < vi.size(); ++i)
                cout << vi[i] << ", ";
            cout << endl;
        }
#endif

        return vvi[0][sz1 - 1];
    }

};

int main()
{

    LT0730 lt;

    string s = "bccb";
    //string s = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba";

    cout << lt.lt0730a(s) << endl;

    return 0;
}
