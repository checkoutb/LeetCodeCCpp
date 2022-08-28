
#include "../header/myheader.h"

class LT2390
{
public:

    // D D

    //for (int i = 0; i < s.size(); ++i)
    //    if (s[i] == '*')
    //        j--;
    //    else
    //        s[j++] = s[i];


    //if (ch == '*') {
    //    str.pop_back();
    //}
    //else {
    //    str.push_back(ch);
    //}


//Runtime: 139 ms, faster than 33.33 % of C++ online submissions for Removing Stars From a String.
//Memory Usage : 24.7 MB, less than 16.67 % of C++ online submissions for Removing Stars From a String.
    string lt2390a(string s)
    {
        string ans;
        int cnt = 0;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] == '*')
            {
                cnt++;
            }
            else
            {
                if (cnt > 0)
                {
                    cnt--;
                }
                else
                {
                    ans.push_back(s[i]);
                }
            }
        }
        reverse(begin(ans), end(ans));
        return ans;
    }

};

int main()
{

    LT2390 lt;


    return 0;
}
