
#include "../header/myheader.h"

class LT1614
{
public:

// D D





//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum Nesting Depth of the Parentheses.
//Memory Usage: 6.5 MB, less than 23.80% of C++ online submissions for Maximum Nesting Depth of the Parentheses.
    int lt1614a(string s)
    {
        int dep = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                ++dep;
            }
            else if (s[i] == ')')
            {
                ans = max(dep, ans);
                --dep;
            }
        }
        return ans;
    }

};

int main()
{
//    string s = "(1+(2*3)+((8)/4))+1";
    string s = "1";

    LT1614 lt;

    cout<<lt.lt1614a(s);

    return 0;
}
