
#include "../header/myheader.h"

class LT1185
{
public:

// D D


//    vector<string> days= {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
//    string dayOfTheWeek(int d, int m, int y, int c = 0) {
//        if (m < 3) m += 12, y -= 1;
//        c = y / 100, y = y % 100;
//        int w = (c / 4 - 2 * c + y + y / 4 + 13 * (m + 1) / 5 + d - 1) % 7;
//        return days[(w + 7) % 7];
//    }
//The formula for this problem is Zelle formula
//Another name: Zeller's congruence or Kim larsen calculation formula.




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Day of the Week.
//Memory Usage: 6.2 MB, less than 60.57% of C++ online submissions for Day of the Week.
// 1971-1-1 Friday
    string lt1185(int day, int month, int year)
    {
        int days = day - 1;
        int st = 1971;
        while (st < year)
            days += isleap(st++) ? 366 : 365;

        st = 1;
        while (st < month)
            days += arr2[st++];

        if (month > 2 && isleap(year))
            days++;

        return arr[days % 7];
    }
    bool isleap(int year)
    {
        if (year % 4 != 0)
            return false;
        if (year % 400 == 0)
            return true;
        if (year % 100 == 0)
            return false;
        return true;
    }
    int arr2[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    string arr[7] = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};

};

int main()
{
//    int a{31}, b{8}, c{2019};
//    int a{1},b{1},c{1971};
//    int a{18},b{7},c{1999};
    int a{15},b{8},c{1993};

    LT1185 lt;

    cout<<lt.lt1185(a,b,c);

    return 0;
}
