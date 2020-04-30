
#include "../header/myheader.h"





//Runtime: 252 ms, faster than 39.71% of C++ online submissions for My Calendar II.
//Memory Usage: 30.7 MB, less than 100.00% of C++ online submissions for My Calendar II.
// vector<pair<int, int>> 是抄 1 的discuss的。。。

class MyCalendarTwo {

    vector<pair<int, int>> v2;
public:
    MyCalendarTwo() {

    }

    bool book(int start, int end) {
        int t = 0;
        vector<pair<int, int>> v3;
        for (pair<int, int> p : v2)
        {
            int max_st = max(p.first, start);
            int min_en = min(p.second, end);
            if (max_st < min_en)
            {
                for (pair<int, int> p3 : v3)
                {
                    if (max(p3.first, max_st) < min(p3.second, min_en))
                    {
                        return false;
//                        t++;
                    }
                }
                v3.push_back({max_st, min_en});
            }
            if (t >= 2)
                break;
        }
//        if (t >= 2)
//            return false;
        v2.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */



class LT0731
{
public:



};

int main()
{

    MyCalendarTwo mct;
    cout<<mct.book(10, 20)<<endl;
    cout<<mct.book(50, 60)<<endl;
    cout<<mct.book(10, 40)<<endl;
    cout<<mct.book(5, 15)<<endl;
    cout<<mct.book(5, 10)<<endl;
    cout<<mct.book(25, 55)<<endl;


    LT0731 lt;


    return 0;
}
