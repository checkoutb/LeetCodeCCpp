
#include "../header/myheader.h"

class LT2108
{
public:

// D D

//        if (w == string(rbegin(w), rend(w)))
//            return w;


//        if (equal(begin(w), end(w), rbegin(w)))
//            return w;


//Runtime: 56 ms, faster than 89.84% of C++ online submissions for Find First Palindromic String in the Array.
//Memory Usage: 19.8 MB, less than 85.57% of C++ online submissions for Find First Palindromic String in the Array.
    string firstPalindrome(vector<string>& words)
    {
        for (string& s : words)
        {
            int l = 0, r = s.size() - 1;
            while (l < r)
            {
                if (s[l++] != s[r--])
                {
                    goto AAA;
                }
            }
            return s;
            AAA:
            continue;
        }
        return "";
    }

};

int main()
{

    LT2108 lt;


    return 0;
}
