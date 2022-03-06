
#include "../header/myheader.h"

class LT2124
{
public:


// D D

//            if(s[i-1]=='b'&&s[i]=='a')
//                return false;

//return "ba" not in s

//return s.find("ba")==string::npos;

//return is_sorted(begin(s), end(s));


//Runtime: 5 ms, faster than 17.62% of C++ online submissions for Check if All A's Appears Before All B's.
//Memory Usage: 6.1 MB, less than 55.54% of C++ online submissions for Check if All A's Appears Before All B's.
    bool lt2124a(string s)
    {
        bool b = false;
        for (char ch : s)
        {
            if (ch == 'a')
            {
                if (b)
                    return false;
            }
            else
            {
                b = true;
            }
        }
        return true;
    }

};

int main()
{

    LT2124 lt;


    return 0;
}
