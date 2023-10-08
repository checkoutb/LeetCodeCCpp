
#include "../header/myheader.h"

class LT2801
{
public:

// D







// g

    // 像一道周赛的题目。
    // 10^100 ..     100
    int countSteppingNumbers(string low, string high)
    {
        int const MOD = 1e9 + 7;

        int szh = high.size();
        int szl = low.size();


        // [first digit][length]
        vector<vector<int>> vvi(10, vector<int>(szh + 1, 0));

        for (int i = 0; i < 10; ++i)
            vvi[i][1] = 1;

        for (int i = 2; i <= szh; ++i)  // length
        {
            int t2 = 0;
            for (int j = 1; j < 10; ++j)
            {
                t2 = (t2 + vvi[j][i - 1]) % MOD;
            }
            for (int j = 1; j < 10; ++j)
            {
                vvi[j][i] = t2;
            }
            vvi[0][i] = (vvi[1][i - 1] + vvi[0][i]) % MOD;
            vvi[9][i] = (vvi[8][i - 1] + vvi[9][i]) % MOD;
            for (int j = 1; j < 9; ++j)
            {
                vvi[j][i] += (vvi[j + 1][i - 1] + vvi[j - 1][i - 1]) % MOD;
                vvi[j][i] %= MOD;
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


        int ans = 0;
        ans = cala1(high, vvi) - cala1(low, vvi);
        if (ans < 0)
        {
            ans = ans + MOD;
        }

        for (int i = 1; i < low.size(); ++i)
        {
            if (abs(low[i] - low[i - 1]) != 1)
                goto AAA;
        }

        ans = (ans + 1) % MOD;

        AAA:

        return ans;
    }

    // <= s
    int cala1(string& s, vector<vector<int>>& vvi)
    {
        const int MOD = 1e9 + 7;
        int ans = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            for (int j = 1; j <= (s[i] - '0'); ++j)
            {
                ans = (ans + vvi[j][s.size() - i]) % MOD;
            }
        }
        #ifdef __test
        cout<<s<<" - "<<ans<<endl;
        #endif // __test
        return ans;
    }

};

int main()
{

    LT2801 lt;

    string l = "1";
    string h = "11";

    cout<<lt.countSteppingNumbers(l, h)<<endl;

    return 0;
}
