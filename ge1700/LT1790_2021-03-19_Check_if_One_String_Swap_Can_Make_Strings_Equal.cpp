
#include "../header/myheader.h"

class LT1790
{
public:

// D D

//    vector<array<char, 2>> mis;
//    for (auto i = 0; i < s1.size() && mis.size() < 3; ++i)
//        if (s1[i] != s2[i])
//            mis.push_back({mis.empty() ? s1[i] : s2[i], mis.empty() ? s2[i] : s1[i]});
//    return mis.empty() || (mis.size() == 2 && mis[0] == mis[1]);
// ....  vector<array<char, 2>> ...


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Check if One String Swap Can Make Strings Equal.
//Memory Usage: 6.2 MB, less than 100.00% of C++ online submissions for Check if One String Swap Can Make Strings Equal.
    bool lt1790a(string s1, string s2)
    {
//        int diff = 0;
        vector<int> vi;
        for (int i = 0; i < s1.size(); ++i)
        {
            if (s1[i] != s2[i])
            {
                vi.push_back(i);
                if (vi.size() > 2)
                    return false;
            }
        }
        if (vi.empty())
            return true;
        if (vi.size() != 2)
            return false;
        return s1[vi[0]] == s2[vi[1]] && s1[vi[1]] == s2[vi[0]];
    }

};

int main()
{
    string s1 = "kelb", s2 = "kelb";

    LT1790 lt;

    cout<<lt.lt1790a(s1, s2);

    return 0;
}
