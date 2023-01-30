
#include "../header/myheader.h"

class LT2516
{
public:

    // D D

    //int ta = cnt[0] - k, tb{ cnt[1] - k }, tc{ cnt[2] - k };
    //int ans = 0, i = 0, j = 0;
    //int c[3]{ 0 };
    //while (j < s.size()) { //ending with char j to see the longest range
    //    c[s[j] - 'a']++;

    //    while (c[0] > ta || c[1] > tb || c[2] > tc) {
    //        c[s[i] - 'a']--; i++;
    //    }
    //    ans = max(ans, j - i + 1);
    //    j++;
    //}

    // sliding windown, no binary search.



    // two pointer







    //Runtime231 ms
    //    Beats
    //    24.73 %
    //    Memory55.8 MB
    //    Beats
    //    12.64 %
    int lt2516a(string s, int k)
    {
        if (k == 0)
            return 0;

        int sz1 = s.size();

        if (sz1 < k * 3)
            return -1;

        int cnta = 0;
        int cntb = 0;
        int cntc = 0;

        //vector<int> vi(sz1);
        vector<vector<int>> vvi(sz1, vector<int>(3, 0));
        ++vvi[0][s[0] - 'a'];

        for (int i = 1; i < sz1; ++i)
        {
            vvi[i][0] = vvi[i - 1][0];
            vvi[i][1] = vvi[i - 1][1];
            vvi[i][2] = vvi[i - 1][2];
            ++vvi[i][s[i] - 'a'];
        }

        if (vvi[sz1 - 1][0] < k || vvi[sz1 - 1][1] < k || vvi[sz1 - 1][2] < k)
            return -1;


        int st = k * 3;
        int en = sz1;
        int ans = -123;
        while (st <= en)
        {
            int md = (st + en) / 2;     // time used, count got.
            cnta = vvi[md - 1][0];
            cntb = vvi[md - 1][1];
            cntc = vvi[md - 1][2];
            bool can = false;

            if (cnta >= k && cntb >= k && cntc >= k)
            {
                can = true;
            }

            for (int i = md - 1, j = sz1 - 1; i >= 0 && !can; --i, --j)
            {
                if (s[i] == 'a')
                    --cnta;
                else if (s[i] == 'b')
                    --cntb;
                else
                    --cntc;

                if (s[j] == 'a')
                    ++cnta;
                else if (s[j] == 'b')
                    ++cntb;
                else
                    ++cntc;

                if (cnta >= k && cntb >= k && cntc >= k)
                {
                    can = true;
                }
            }
            if (can)
            {
                ans = md;
                en = md - 1;
            }
            else
            {
                st = md + 1;
            }
        }

        return ans;

        //for (char ch : s)
        //{
        //    switch(ch)
        //    {
        //    case 'a':
        //        ++cnta;
        //        break;
        //    case 'b':
        //        ++cntb;
        //        break;
        //    default:
        //        ++cntc;
        //    }
        //}

        //if (cnta < k || cntb < k || cntc < k)
        //    return -1;

        //int ans = -1;

        //return ans;
    }

};

int main()
{

    LT2516 lt;

    //string s = "aabaaaacaabc";
    //int k = 2;

    string s = "aaaaaaabcca";
    int k = 2;

    cout << lt.lt2516a(s, k) << endl;

    return 0;
}
