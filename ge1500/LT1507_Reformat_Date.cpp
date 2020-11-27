
#include "../header/myheader.h"

class LT1507
{
public:

// D D

//class Solution {
//public:
//    string reformatDate(string date) {
//        const char* mon[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
//        const char* p = date.c_str();
//        const char* q = strchr(p, ' ');
//        int len = q - p;
//        string dayStr = date.substr(0, len);
//        p = q + 1;
//        q = strchr(p, ' ');
//        len = q - p;
//        string monStr = string(p, len);
//        string yrStr = string(q+1);
//        int monNumber = -1;
//        for (int i=0; i < 12; ++i) {
//            if (monStr == mon[i]) {
//                monNumber = i + 1;
//                break;
//            }
//        }
//        char buf[40];
//        sprintf(buf, "%d", monNumber);
//        string ret = yrStr;
//        ret += "-";
//        if (buf[1] == '\0')
//            ret += "0";
//        ret += buf;
//        ret += "-";
//        string ds = dayStr.substr(0, dayStr.length()-2);
//        if (ds.length() == 1)
//            ret += "0";
//        ret += ds;
//        return ret;
//    }
//};
//




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reformat Date.
//Memory Usage: 6.3 MB, less than 70.27% of C++ online submissions for Reformat Date.
//"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    string lt1507a(string date)
    {
        string day = date.substr(0, std::isdigit(date[1]) ? 2 : 1);
        string year = date.substr(date.size() - 4);
        int arr[26] = {0};
        arr['c' - 'a'] = 12;
        arr['v' - 'a'] = 11;
        arr['t' - 'a'] = 10;
        arr['p' - 'a'] = 9;
        arr['g' - 'a'] = 8;
        arr['l' - 'a'] = 7;
        arr['y' - 'a'] = 5;
        arr['b' - 'a'] = 2;
        // 1+6, 3+4
        char ch = date[date.size() - 6];
        string month;
        if (arr[ch - 'a'] != 0)
        {
            month = std::to_string(arr[ch - 'a']);
        }
        else
        {
            switch (date[date.size() - 8])
            {
            case 'J':
                if (date[date.size() - 7] == 'a')
                    month = '1';
                else month = '6';
                break;
            case 'M':
                month = "3";
                break;
            case 'A':
                month = "4";
                break;
            }
        }
        return year + "-" + (month.size() < 2 ? "0" : "") + month + "-" + (day.size() < 2 ? "0" : "") + day;
    }

};

int main()
{

    LT1507 lt;


    return 0;
}
