
#include "../header/myheader.h"

class LT2437
{
public:

    // D D

    //int res = 1;
    //if (t[0] == '?')
    //    res = t[1] == '?' ? 24 : t[1] < '4' ? 3 : 2;
    //else if (t[1] == '?')
    //    res = t[0] < '2' ? 10 : 4;
    //return res * (t[3] == '?' ? 6 : 1) * (t[4] == '?' ? 10 : 1);





//Runtime: 0 ms, faster than 100.00 % of C++ online submissions for Number of Valid Clock Times.
//Memory Usage : 6 MB, less than 7.72 % of C++ online submissions for Number of Valid Clock Times.
    int lt2437a(string time)
    {
        int ans = 0;

        int t2 = 1;
        int t3 = 1;

        if (time[0] == '?' || time[1] == '?')
        {
            if (time[0] != '?')
            {
                if (time[0] == '2')
                {
                    t2 = 4;         // 20 21 22 23
                }
                else
                {
                    t2 = 10;        // x0 x1 x2 .. x9    x is 0 or 1
                }
            }
            else if (time[1] != '?')
            {
                if (time[1] >= '4')
                {
                    t2 = 2;     // 04 14,   not 24
                }
                else
                {
                    t2 = 3;             // 03 13 23
                }
            }
            else
            {
                t2 = 24;
            }
        }

        if (time[3] == '?' || time[4] == '?')
        {
            if (time[3] != '?')
            {
                t3 = 10;
            }
            else if (time[4] != '?')
            {
                t3 = 6;
            }
            else
            {
                t3 = 60;
            }
        }

        ans = t2 * t3;
        return ans;
    }

};

int main()
{

    LT2437 lt;


    return 0;
}
