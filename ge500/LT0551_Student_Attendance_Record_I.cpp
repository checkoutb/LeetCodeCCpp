
#include "../header/myheader.h"

class LT0551
{
public:


// D D

//        if (s.find("LLL") != string::npos) {
//            return false;
//        }

// return !s.matches(".*LLL.*|.*A.*A.*");
// java


//        if(s.indexOf("A") != s.lastIndexOf("A") || s.contains("LLL"))
//            return false;
//        return true;


// II 直接起飞，靠。


// continue L...
//Runtime: 4 ms, faster than 67.71% of C++ online submissions for Student Attendance Record I.
//Memory Usage: 6.4 MB, less than 33.51% of C++ online submissions for Student Attendance Record I.
    bool checkRecord(string s)
    {
        int num1{0}, num2{0};
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'L')
            {
                if (num2 > 1)
                    return false;
                num2++;
            }
            else
            {
                num2 = 0;
                if (s[i] == 'A')
                {
                    if (num1 > 0)
                        return false;
                    num1++;
                }
            }
        }
        return true;
    }

};

int main()
{

    LT0551 lt;


    return 0;
}
