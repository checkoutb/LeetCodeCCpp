
#include "../header/myheader.h"

class LT1736
{
public:

// D D

//        time[0] = time[0] != '?' ? time[0]:(time[1] == '?' || time[1] <='3')? '2':'1';
//        time[1] = time[1] != '?' ? time[1]:(time[0] == '2')? '3':'9';
//        time[3] = time[3] != '?' ? time[3]:'5';
//        time[4] = time[4] != '?' ? time[4]:'9';




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Latest Time by Replacing Hidden Digits.
//Memory Usage: 5.9 MB, less than 64.46% of C++ online submissions for Latest Time by Replacing Hidden Digits.
    string lt1736a(string time)
    {
        for (int i = 0; i < time.size(); ++i)
        {
            if (time[i] == '?')
            {
                switch (i)
                {
                case 0:
                    if (time[1] > '3' && time[1] != '?')
                    {
                        time[0] = '1';
                    }
                    else
                    {
                        time[0] = '2';
                    }
                    break;
                case 1:
                    if (time[0] == '2')
                    {
                        time[1] = '3';
                    }
                    else
                    {
                        time[1] = '9';
                    }
                    break;
                case 3:
                    time[3] = '5';
                    break;
                case 4:
                    time[4] = '9';
                    break;
                }
            }
        }
        return time;
    }

};

int main()
{
    string s = "?4:03";

    LT1736 lt;

    cout<<lt.lt1736a(s)<<endl;

    return 0;
}
