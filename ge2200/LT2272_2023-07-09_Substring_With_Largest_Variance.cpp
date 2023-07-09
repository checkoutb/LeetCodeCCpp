
#include "../header/myheader.h"

class LT2272
{
public:







    // O(26*n* ?? )
    // O(n*n*26)
    int ltb(string s)
    {
        int sz1 = s.size();
        vector<vector<int>> vvi(26);

        for (int i = 0; i < sz1; ++i)
        {
            vvi[s[i] - 'a'][]
        }
        return -1;
    }


    // tle 123/138

    // 2 char's diff, max
    // int[26 + 1 + 1]
    // if a/b/c..z is min
    int lta(string s)
    {
        int sz1 = s.size();
        vector<vector<int>> vvi(sz1, vector<int>(28, 0));        // tle?
        for (int i = 0; i < sz1; ++i)
        {
            vvi[i][s[i] - 'a']++;
            vvi[i][26] = s[i] - 'a';        // mn
            vvi[i][27] = s[i] - 'a';        // mx
        }
        int t2 = 0;
        int ans = 0;
        for (int i = 1; i < sz1; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                t2 = s[i] - 'a';
                ++vvi[j][t2];       // substr: [j, i]
                if (vvi[j][t2] > vvi[j][vvi[j][27]])
                {
                    vvi[j][27] = t2;
                }
                else if (vvi[j][t2] < vvi[j][vvi[j][26]])
                {
                    vvi[j][26] = t2;
                }
                else if (t2 == vvi[j][26])
                {
                    for (int k = 0; k < 26; ++k)
                    {
                        if (vvi[j][k] != 0 && vvi[j][k] < vvi[j][t2])
                        {
                            t2 = k;
                        }
                    }
                    vvi[j][26] = t2;
                }
                if (vvi[j][vvi[j][27]] - vvi[j][vvi[j][26]] > ans)
                    ans = vvi[j][vvi[j][27]] - vvi[j][vvi[j][26]];
            }
        }
        return ans;
    }

};

int main()
{

    LT2272 lt;

    //string s = "aababbb";
    string s = "asdfgahj";

    cout << lt.lta(s) << endl;

    return 0;
}
