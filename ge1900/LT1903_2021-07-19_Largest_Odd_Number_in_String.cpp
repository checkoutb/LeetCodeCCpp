
#include "../header/myheader.h"

class LT1903
{
public:

// D D

//return string();

//return num.substr(0, num.find_last_not_of("0|2|4|6|8") + 1);






//Runtime: 28 ms, faster than 84.24% of C++ online submissions for Largest Odd Number in String.
//Memory Usage: 14.8 MB, less than 71.39% of C++ online submissions for Largest Odd Number in String.
    string lt1903a(string num)
    {
        for (int i = num.size() - 1; i >= 0; --i)
        {
            if ((num[i] - '0') % 2 == 1)
            {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }

};

int main()
{
    string s = "354272";

    LT1903 lt;

    cout<<lt.lt1903a(s)<<endl;

    return 0;
}
