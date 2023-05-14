
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //int longestPalinSubseq(string A) {
    //    string s1 = A;
    //    reverse(s1.begin(), s1.end());
    //    return lcs(A, s1);
    //}


    //int minInsertions(string s) {
    //    int n = s.size();
    //    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    //    for (int ind1 = n - 1; ind1 >= 0; ind1--) {
    //        for (int ind2 = ind1 + 1; ind2 < n; ind2++) {
    //            if (s[ind1] == s[ind2])dp[ind1][ind2] = dp[ind1 + 1][ind2 - 1];
    //            else dp[ind1][ind2] = 1 + min(dp[ind1 + 1][ind2], dp[ind1][ind2 - 1]);
    //        }
    //    }
    //    return dp[0][n - 1];
    //}

    

    //Runtime127 ms
    //    Beats
    //    7.44 %
    //    Memory28.3 MB
    //    Beats
    //    62.28 %
    int ltb(string s)
    {
        int sz1 = s.size();
        if (sz1 == 1)
            return 0;
        vector<vector<int>> vvi(sz1, vector<int>(sz1, 0));      // max equal length
        int ans = sz1 - 1;
        int t2 = ans;               // ....  = 0
        for (int i = 0; i < sz1; ++i)
        {
#ifdef __test
            if (i == 16)
            {
                cout << "111" << endl;
            }
#endif

            for (int j = sz1 - 1; j > i; --j)
            {
                vvi[i][j] = (s[i] == s[j] ? 2 : 0) + (i > 0 && j < sz1 - 1 ? vvi[i - 1][j + 1] : 0);
                if (j < sz1 - 1)
                    vvi[i][j] = max(vvi[i][j], vvi[i][j + 1]);
                
                if (i > 0 && j < sz1)
                {
                    vvi[i][j] = max(vvi[i][j], vvi[i - 1][j + 0]);              // j + 1 ....
                }

                //if (s[i] == s[j])
                //{
                //    vvi[i][j] = vvi[i - 1][j + 1] + 2;
                //}
                //else
                //{
                //    vvi[i][j] = vvi[i - 1][j + 1];
                //}
            }
            //ans = min(ans, min());
            if (i > 0 && i < sz1 - 1)
            {
                if (s[i] == s[i + 1])
                {
                    t2 = i < sz1 - 2 ? sz1 - vvi[i - 1][i + 2] - 2 : (sz1 - 2);
                }
                ans = min(ans, min(sz1 - vvi[i - 1][i + 1] - 1, t2));
            }
            else
            {
                if (i == 0)
                {
                    ans = min(ans, (s[i] == s[i + 1]) ? sz1 - 2 : ans);
                }
                else
                {
                    if (s[i] == s[i - 1])
                        ans = min(ans, sz1 - 2);
                }
            }
        }

#ifdef __test
        cout << " , ";
        for (char ch : s)
            cout << ch << ", ";
        cout << endl;
        int z = 0;
        for (myvi& vi : vvi)
        {
            cout << s[z++] << ": ";
            for (int i : vi)
                cout << i << ", ";
            cout << endl;
        }
#endif

        return ans;
    }


    // ...
    // sz1 <= 500
    int lta(string s)
    {
        int ans = INT_MAX;
        int sz1 = s.size();
        for (int i = sz1 / 2; i < sz1; ++i)
        {
            if (i * 2 - sz1 - 1 > ans)
                break;



        }
        for (int i = sz1 / 2 - 1; i >= 0; --i)
        {

        }
        return ans;
    }

    int calCnt(string& s, int st, int en)
    {
        int sz1 = s.size();
        while (st >= 0 && en < sz1)
        {

        }
    }

};

int main()
{

    LT lt;

    //string s = "mbadm";
    //string s = "zzazz";
    //string s = "leetcode";

    // asdas da sdqwef asd ff sd  few
    string s = "asdasdasdqwefasdffsdfew";       // 13
    //string s = "a";
    //string s = "ccewnxhytsr";       // 9


    cout << lt.ltb(s) << endl;

    return 0;
}
