
#include "../header/myheader.h"

class LT1332
{
public:

// D D

// reverse(begin, end)...

//return 2 - (s == string(s.rbegin(), s.rend())) - s.empty();

//return 2 - equal(s.begin(), s.end(), s.rbegin()) - s.empty();




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Palindromic Subsequences.
//Memory Usage: 6.4 MB, less than 52.31% of C++ online submissions for Remove Palindromic Subsequences.
    int lt1332a(string s)
    {
        if (s.size() == 0)
            return 0;
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            if (s[l] == s[r])
            {
                l++, r--;
            }
            else
                break;
        }
        if (l >= r)
        {
            return 1;
        }
        return 2;
    }

};

int main()
{

    LT1332 lt;


    return 0;
}
