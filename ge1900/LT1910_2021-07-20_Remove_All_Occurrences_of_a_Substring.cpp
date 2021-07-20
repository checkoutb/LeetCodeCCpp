
#include "../header/myheader.h"

class LT1910
{
public:

// D D

// kmp





//Runtime: 4 ms, faster than 89.60% of C++ online submissions for Remove All Occurrences of a Substring.
//Memory Usage: 6.6 MB, less than 87.39% of C++ online submissions for Remove All Occurrences of a Substring.
    string lt1910a(string s, string part)
    {
        int idx;
        while ((idx = s.find(part)) != std::string::npos)
        {
            s.erase(idx, part.size());
        }
        return s;
    }

};

int main()
{
//    string s = "daabcbaabcbc";
//    string p = "abc";

    string s = "axxxxyyyyb";
    string p = "xy";

    LT1910 lt;

    cout<<lt.lt1910a(s, p)<<endl;

    return 0;
}
