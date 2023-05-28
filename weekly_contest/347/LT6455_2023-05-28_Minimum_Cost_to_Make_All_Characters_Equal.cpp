
#include "../../header/myheader.h"

class LT6455
{
public:



    // AC
    long long minimumCost(string s)
    {
        int sz1 = s.size();
        vector<vector<long long>> vvl(2, vector<long long>(sz1, 1LL << 62));
        vector<vector<long long>> vvl2(2, vector<long long>(sz1, 1LL < 62));

        vvl[0][0] = s[0] != '0';
        vvl[1][0] = s[0] == '0';

        for (int i = 1; i < sz1; ++i)
        {
            if (s[i] == '0')
            {
                vvl[0][i] = vvl[0][i - 1];
                vvl[1][i] = vvl[0][i - 1] + i + 1;
            }
            else
            {
                vvl[1][i] = vvl[1][i - 1];
                vvl[0][i] = vvl[1][i - 1] + i + 1;
            }
        }

        vvl2[0][sz1 - 1] = s[sz1 - 1] != '0';
        vvl2[1][sz1 - 1] = s[sz1 - 1] == '0';
        for (int i = sz1 - 2; i >= 0; --i)
        {
            if (s[i] == '0')
            {
                vvl2[0][i] = vvl2[0][i + 1];
                vvl2[1][i] = vvl2[0][i + 1] + sz1 - i;
            }
            else
            {
                vvl2[1][i] = vvl2[1][i + 1];
                vvl2[0][i] = vvl2[1][i + 1] + sz1 - i;
            }
        }

        #ifdef __test
        for (int i = 0; i < sz1; ++i)
        {
            cout<<vvl[0][i]<<", ";
        }
        cout<<endl;
        for (int i = 0; i < sz1; ++i)
        {
            cout<<vvl[1][i]<<", ";
        }
        cout<<endl;
        for (int i = 0; i < sz1; ++i)
        {
            cout<<vvl2[0][i]<<", ";
        }
        cout<<endl;
        for (int i = 0; i < sz1; ++i)
        {
            cout<<vvl2[1][i]<<", ";
        }
        cout<<endl;

        #endif // __test

        long long ans = min(min(vvl[0][sz1 - 1], vvl[1][sz1 - 1]), min(vvl2[0][0], vvl2[1][0]));

        for (int i = 0; i < sz1 - 1; ++i)
        {
            ans = min(ans, min(vvl[0][i] + vvl2[0][i + 1], vvl[1][i] + vvl2[1][i + 1]));
//            cout<<ans<<endl;
        }
        return ans;
    }

};

int main()
{

    LT6455 lt;

    string s = "010101";


    cout<<lt.minimumCost(s)<<endl;

    return 0;
}
