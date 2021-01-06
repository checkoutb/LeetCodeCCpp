
#include "../header/myheader.h"

class LT1360
{
public:

// D D

//    int leapyearstillnow(int y, int m)
//    {
//        if(m <= 2) y--;
//        return (y/4)-(y/100)+(y/400);
//    }



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Days Between Two Dates.
//Memory Usage: 6.2 MB, less than 92.57% of C++ online submissions for Number of Days Between Two Dates.
    int lt1360a(string date1, string date2)
    {
        int y1 = std::stoi(date1.substr(0, 4));
        int m1 = stoi(date1.substr(5, 2));
        int d1 = stoi(date1.substr(8, 2));
        int y2 = stoi(date2.substr(0, 4));
        int m2 = stoi(date2.substr(5, 2));
        int d2 = stoi(date2.substr(8, 2));

        for (int i = 1971; i < y1; ++i)
            d1 += isLeap(i) ? 366 : 365;
        for (int i = 1; i < m1; ++i)
            d1 += arr[i];
        if (m1 > 2 && isLeap(y1))
            d1++;

        for (int i = 1971; i < y2; ++i)
            d2 += isLeap(i) ? 366 : 365;
        for (int i = 1; i < m2; ++i)
            d2 += arr[i];
        if (m2 > 2 && isLeap(y2))
            d2++;
        return abs(d2 - d1);
    }
    int arr[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    bool isLeap(int y)
    {
        return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
    }

};

int main()
{
//    string date1 = "2019-06-29", date2 = "2019-06-30";
    string date1 = "2020-01-15", date2 = "2019-12-31";

    LT1360 lt;

    cout<<lt.lt1360a(date1, date2);

    return 0;
}
