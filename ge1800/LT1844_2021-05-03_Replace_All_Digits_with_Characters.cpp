
#include "../header/myheader.h"

class LT1844
{
public:

// D D

//s[i] += s[i-1] - '0';


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Replace All Digits with Characters.
//Memory Usage: 6.1 MB, less than 20.00% of C++ online submissions for Replace All Digits with Characters.
    string lt18344a(string s)
    {
        for (int i = 1; i < s.size(); i += 2)
            s[i] = s[i - 1] + s[i] - '0';
        return s;
    }

};

int main()
{
    vector<string> vs = {"a1c1e1", "a1b2c3d4e"};

    LT1844 lt;

    for (string& s : vs)
        cout<<lt.lt18344a(s)<<endl;

    return 0;
}
