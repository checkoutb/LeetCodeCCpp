
#include "../header/myheader.h"

class LT2565
{
public:

    // D D




    //Runtime11 ms
    //    Beats
    //    94.52 %
    //    Memory11.8 MB
    //    Beats
    //    26.21 %
    // r - l + 1.
    // 尽可能集中。
    int lt2565a(string s, string t)
    {
        int sz1 = s.size();
        int sz2 = t.size();

        vector<int> vi(sz2, -1);
        vector<int> v2(sz2, -1);

        int idx = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (s[i] == t[idx])
            {
                vi[idx] = i;
                ++idx;
            }
        }
        if (vi[sz2 - 1] != -1)
            return 0;
        //if (vi[0] == -1)      // ba  cb
        //    return sz2;

        int ans = sz2 - idx;

        idx = sz2 - 1;
        for (int i = sz1 - 1; i >= 0; --i)
        {
            if (s[i] == t[idx])
            {
                v2[idx] = i;
                --idx;
            }
        }
        ans = min(ans, idx + 1);
        idx = 0;        // v2
        for (int i = 0; i < sz2; ++i)       // vi
        {
            if (vi[i] == -1)
                break;

            // keep (0, i]  [idx, sz2)

            if (idx <= i)
                idx = i + 1;

            while (idx < sz2 && v2[idx] <= vi[i])
                ++idx;

            ans = min(ans, idx - i - 1);
        }
        return ans;
    }

};

int main()
{

    LT2565 lt;

    //string s = "abacaba";
    //string t = "bzaa";

    //string s = "acdedcdbabecdbebda";
    //string t = "bbecddb";

    string s = "aaaaaaba";      // ba
    string t = "caaaabe";       // cb

    cout << lt.lt2565a(s, t) << endl;

    return 0;
}
