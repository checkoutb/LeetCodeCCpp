
#include "../header/myheader.h"

class LT1154
{
public:


// D D
//        Y, M, D = map(int, date.split('-'))
//        return int((datetime.datetime(Y, M, D) - datetime.datetime(Y, 1, 1)).days + 1)




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Day of the Year.
//Memory Usage: 6.2 MB, less than 100.00% of C++ online submissions for Day of the Year.
    int lt1154a(string date)
    {
        int year = std::stoi(date.substr(0, 4));
        int month = std::stoi(date.substr(5, 2));
        int day = std::stoi(date.substr(8, 2));
        int ans = day;
        int arr1[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
//        cout<<year<<" - "<<month<<" - "<<day<<endl;
        if (month > 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
        {
            ans++;
        }
        month--;
        for (; month > 0; month--)
        {
            ans += arr1[month];
        }
        return ans;
    }


};

int main()
{

//    string s = "2019-02-10";
//    string s = "2019-01-09";
    string s = "2003-03-01";

    LT1154 lt;

    cout<<lt.lt1154a(s)<<endl;

    return 0;
}
