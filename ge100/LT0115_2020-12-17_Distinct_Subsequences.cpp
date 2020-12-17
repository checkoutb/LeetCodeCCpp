
#include "../header/myheader.h"

class LT0115
{
public:


// DP。。。



    int lt0115b(string s, string t)
    {
        int arrt[123] = {0};
        for (char ch : t)
            arrt[ch]++;
        int arrs[123] = {0};
        return -1;
    }


// tle.. 没看submission，， 一溜的tle。。
    int lt0115a(string s, string t)
    {
        if (s.size() < t.size())
            return 0;
        dfsa1(s, t, 0, 0);
        return ans;
    }
    int ans = 0;
    void dfsa1(string& s, string& t, int si, int ti)
    {
        if (ti == t.size())
            ans++;
        for (int i = si; i < s.size(); i++)
        {
            if (s[i] == t[ti])
            {
                dfsa1(s, t, i + 1, ti + 1);
            }
        }
    }

};

int main()
{
//    string s = "rabbbit";
//    string t = "rabbit";

    string s = "babgbag";
    string t = "bag";

    LT0115 lt;

    cout<<lt.lt0115a(s, t);

    return 0;
}
