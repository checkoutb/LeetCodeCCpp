
#include "../header/myheader.h"

class LT1556
{
public:

// D D

//        string s = to_string(n), res;
//        for (int i = 0; i < s.size(); ++i) {
//            if (i > 0 && (s.size() - i) % 3 == 0)
//                res += ".";
//            res += s[i];
//        }


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Thousand Separator.
//Memory Usage: 6.3 MB, less than 47.13% of C++ online submissions for Thousand Separator.
    string lt1556a(int n)
    {
        if (n == 0)
            return "0";
        string ans;
        int cnt = 0;
        while (n > 0)
        {
            if (cnt == 3)
            {
                ans = '.' + ans;
                cnt = 0;
            }
            ans = to_string(n % 10) + ans;
            n /= 10;
            cnt++;
        }
        return ans;
    }

};

int main()
{
    int n = 1223678;

    LT1556 lt;

    cout<<lt.lt1556a(n);

    return 0;
}
