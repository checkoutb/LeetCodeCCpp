
#include "../../header/myheader.h"

class LT
{
public:

// D D


// reverse

// swap


//Runtime: 44 ms, faster than 16.74% of C++ online submissions for Reverse String.
//Memory Usage: 23.1 MB, less than 76.65% of C++ online submissions for Reverse String.
    void lta(vector<char>& s)
    {
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            char ch = s[l];
            s[l++] = s[r];
            s[r--] = ch;
        }
    }

};

int main()
{

    LT lt;


    return 0;
}
