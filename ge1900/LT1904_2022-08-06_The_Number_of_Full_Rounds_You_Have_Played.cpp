
#include "../header/myheader.h"

class LT1904
{
public:

    // D D

    //int start = 60 * stoi(s.substr(0, 2)) + stoi(s.substr(3)), finish = 60 * stoi(f.substr(0, 2)) + stoi(f.substr(3));
    //if (start > finish) finish += 60 * 24; // If `finishTime` is earlier than `startTime`, add 24 hours to `finishTime`.
    //return max(0, finish / 15 - (start + 14) / 15); // max(0, floor(finish / 15) - ceil(start / 15))







//Runtime: 0 ms, faster than 100.00 % of C++ online submissions for The Number of Full Rounds You Have Played.
//Memory Usage : 5.9 MB, less than 92.44 % of C++ online submissions for The Number of Full Rounds You Have Played.
//Runtime: 5 ms, faster than 12.89 % of C++ online submissions for The Number of Full Rounds You Have Played.
//Memory Usage : 5.9 MB, less than 92.44 % of C++ online submissions for The Number of Full Rounds You Have Played.
    int lt1904a(string loginTime, string logoutTime)
    {
        int st = (toint(loginTime[0]) * 10 + toint(loginTime[1])) * 60 + toint(loginTime[3]) * 10 + toint(loginTime[4]);
        int en = (toint(logoutTime[0]) * 10 + toint(logoutTime[1])) * 60 + toint(logoutTime[3]) * 10 + toint(logoutTime[4]);
        if (st > en)
            en += 24 * 60;

#ifdef __test
        cout << st << " - " << en << endl;
#endif

        st = st / 15 + (st % 15 != 0);
        en = en / 15;

#ifdef __test
        cout << st << " /// " << en << endl;
#endif

        return max(en - st, 0);         // . when st = (en = 11) - 1
    }

    int toint(char ch)
    {
        return ch - '0';
    }

};

int main()
{

    LT1904 lt;

    //string s = "00:31";
    //string t = "01:14";

    string s = "21:30";
    string t = "03:00";

    cout << lt.lt1904a(s, t) << endl;

    return 0;
}
