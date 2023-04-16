
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //int n = target.length(), mod = 1e9 + 7;
    //vector<long> res(n + 1);
    //res[0] = 1;
    //for (int i = 0; i < words[0].length(); ++i) {
    //    vector<int> count(26);
    //    for (auto& w : words)
    //        count[w[i] - 'a']++;
    //    for (int j = n - 1; j >= 0; --j) {
    //        res[j + 1] += res[j] * count[target[j] - 'a'] % mod;
    //    }
    //}
    //return res[n] % mod;



    //Runtime317 ms
    //    Beats
    //    52.59 %
    //    Memory53.9 MB
    //    Beats
    //    48.28 %
    int lta(vector<string>& words, string target)
    {
        const int MOD = 1e9 + 7;
        int sz1 = words.size();
        int sz2 = words[0].size();
        int szt = target.size();

        vector<vector<int>> vvi(sz2, vector<int>(26, 0));

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                ++vvi[j][words[i][j] - 'a'];
            }
        }

#ifdef __test
        for (myvi& vi : vvi)
        {
            for (int i : vi)
                cout << i << ", ";
            cout << endl;
        }
        cout << "\n\n=============\n\n";
#endif

        vector<vector<int>> vv2(sz2, vector<int>(szt, 0));
        vv2[0][0] = vvi[0][target[0] - 'a'];
        for (int i = 1; i < sz2; ++i)
        {
            vv2[i][0] = vvi[i][target[0] - 'a'];
            vv2[i][0] = (vv2[i][0] + vv2[i - 1][0]) % MOD;

            for (int j = 1; j <= i && j < szt; ++j)
            {
                vv2[i][j] = (vv2[i][j] + 1LL * vv2[i - 1][j - 1] * vvi[i][target[j] - 'a']) % MOD;
                vv2[i][j] = (vv2[i][j] + vv2[i - 1][j]) % MOD;
            }
        }

#ifdef __test
        for (myvi& vi : vv2)
        {
            for (int i : vi)
                cout << i << ", ";
            cout << endl;
        }
#endif

        return vv2[sz2 - 1][szt - 1];

        //vector<vector<int>> vv2(szt, vector<int>(sz2, 0));

        //for (int i = 0; i < szt; ++i)
        //{
        //    int t2 = target[i] - 'a';


        //}


    }

};

int main()
{

    LT lt;

    //vector<string> vs{ "acca","bbbb","caca" };
    //string tar = "aba";

    vector<string> vs{ "abba","baab" };
    string tar = "bab";

    cout << lt.lta(vs, tar) << endl;

    return 0;
}
