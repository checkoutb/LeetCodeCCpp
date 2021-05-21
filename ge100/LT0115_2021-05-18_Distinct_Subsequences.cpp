
#include "../header/myheader.h"

class LT0115
{
public:


// gg

// dp
    int lt0115a(string s, string t)
    {
        int sz1 = s.size();
        int sz2 = t.size();
        vector<vector<int>> vvi(sz1 + 1, vector<int>(sz2 + 1, 0));
        for (int i = 1; i <= sz1; ++i)
        {
            for (int j = 1; j <= sz2; ++j)
            {
//                cout<<i<<", "<<j<<endl;
                if (s[i - 1] == t[j - 1])
                {
                    vvi[i][j] = vvi[i - 1][j] + vvi[i][j - 1] + vvi[i - 1][j - 1] + 1;
//                    vvi[i][j] = max(vvi[i - 1][j], vvi[i][j - 1]);
//                    vvi[i][j] = max(vvi[i][j], vvi[i - 1][j - 1] + 1);
                }
                else
                {
                    vvi[i][j] = vvi[i - 1][j] + vvi[i][j - 1];
//                    vvi[i][j] = max(vvi[i - 1][j], vvi[i][j - 1]);
                }
            }
        }
        #ifdef __test
        for (myvi& vi : vvi)
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
    string s{"bagbagbag"}, t{"bag"};

    LT0115 lt;

    cout<<lt.lt0115a(s, t)<<endl;

    return 0;
}
