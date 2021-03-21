
#include "../header/myheader.h"

class LT1796
{
public:

// D D

//    set<int> digits;
//    for (auto ch : s)
//        if (isdigit(ch))
//            digits.insert(ch - '0');
//    return digits.size() > 1 ? *next(rbegin(digits)) : -1;
//Might be more efficient to do - '0' only once, in the return line for the digit to be returned.
//And maybe that allows some fancy filter function usage like copy_if(begin(s), end(s), inserter(digits), isdigit);?
//(Don't know how to make that work.)


//        int first = -1, sec = -1;
//        for (int i = 0; i < s.length(); ++i) {
//            char c = s.charAt(i);
//            if (Character.isDigit(c)) {
//                int d = c - '0';
//                if (first < d) {
//                    sec = first;
//                    first = d;
//                }else if (sec < d && d < first) {
//                    sec = d;
//                }
//            }
//        }


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Second Largest Digit in a String.
//Memory Usage: 6.8 MB, less than 100.00% of C++ online submissions for Second Largest Digit in a String.
    int lt1796a(string s)
    {
        int arr[10] = {0};
        for (char c : s)
        {
            if (std::isdigit(c))
            {
                arr[c - '0']++;
            }
        }
        bool gotmax = false;
        for (int i = 9; i >= 0; --i)
        {
            if (arr[i] != 0)
            {
                if (gotmax)
                {
                    return i;
                }
                gotmax = true;
            }
        }
        return -1;
    }

};

int main()
{

    LT1796 lt;


    return 0;
}
