
#include "../header/myheader.h"

class LT1784
{
public:

// D D

//return string::npos == s.find("01");



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Check if Binary String Has at Most One Segment of Ones.
//Memory Usage: 6.1 MB, less than 100.00% of C++ online submissions for Check if Binary String Has at Most One Segment of Ones.
// 1st 0, last 1
    bool lt1784a(string s)
    {
        int fst0 = 0;
        int lst1 = s.size() - 1;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '0')
            {
                fst0 = i;
                break;
            }
        }
//        for (int i = s.size() - 1; )
        while (lst1 >= 0)
        {
            if (s[lst1] == '1')
            {
                break;
            }
            lst1--;
        }
        return fst0 == 0 || fst0 > lst1;
    }

};

int main()
{
//    string s = "1001";
//    string s = "110";
    string s = "1";

    LT1784 lt;

    cout<<lt.lt1784a(s)<<endl;

    return 0;
}
