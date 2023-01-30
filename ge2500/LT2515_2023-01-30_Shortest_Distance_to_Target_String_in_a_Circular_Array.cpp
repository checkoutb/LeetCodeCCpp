
#include "../header/myheader.h"

class LT2515
{
public:





    //Runtime37 ms
    //    Beats
    //    42.27 %
    //    Memory14.4 MB
    //    Beats
    //    99.57 %
    int lt2515a(vector<string>& words, string target, int startIndex)
    {
        int sz1 = words.size();
        int ans = sz1 + 2;

        for (int i = 0; i < sz1; ++i)
        {
            if (target == words[i])
            {
                ans = min(ans, min((i - startIndex + sz1) % sz1, (startIndex - i + sz1) % sz1));
            }
        }

        return (ans == sz1 + 2) ? -1 : ans;
    }

};

int main()
{

    LT2515 lt;

    //vector<string> vs = { "hello","i","am","leetcode","hello" };
    //string tar = "hello";
    //int si = 1;

    vector<string> vs = { "a","b","lll" };
    string tar = "lll";
    int si = 0;

    cout << lt.lt2515a(vs, tar, si) << endl;

    return 0;
}
