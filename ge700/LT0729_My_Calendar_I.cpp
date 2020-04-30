
#include "../header/myheader.h"


class MyCalendar {
private:

    map<int, int> map1;

public:
    MyCalendar() {

    }


// discuss
//        for (pair<int, int> p : books)
//            if (max(p.first, start) < min(end, p.second)) return false;
//        books.push_back({start, end});

// TreeMap, floorKey, ceilingKey, || lowerKey || floorKey(end - 1)

//


//Runtime: 160 ms, faster than 58.73% of C++ online submissions for My Calendar I.
//Memory Usage: 33.6 MB, less than 100.00% of C++ online submissions for My Calendar I.
    bool book(int start, int end) {
        map<int, int>::iterator it = map1.upper_bound(start);
        if (it == map1.begin())
        {
            if (it == map1.end())           // ...
            {
                map1[start] = end;
                return true;
            }
            int st = it->first;
            int en = it->second;
            if (start < en && end > st)         // ...
                return false;
            else
            {
                map1[start] = end;
                return true;
            }
        }
        else
        {
            if (it != map1.end())               // ...
            {
                int st = it->first;
                int en = it->second;
                if (start < en && end > st)
                {
                    return false;
                }
            }
            it--;
            int st = it->first;
            int en = it->second;

            if (start < en && end > st)
            {
                return false;
            }
            else
            {
                map1[start] = end;
                return true;
            }
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

class LT0729
{
public:



};

int main()
{

//["MyCalendar","book","book","book","book","book","book","book","book","book","book"]
//[[],[47,50],[33,41],[39,45],[33,42],[25,32],[26,35],[19,25],[3,8],[8,13],[18,27]]
//[null,true,  true,   false,  false,  true,   false,   true,  true,  true,  false]



    MyCalendar mc;
//    cout<<mc.book(10, 20)<<endl;
//    cout<<mc.book(15, 25)<<endl;
//    cout<<mc.book(20, 25)<<endl;

//    cout<<mc.book(47,50)<<endl;
//    cout<<mc.book(33,41)<<endl;
//    cout<<mc.book(39,45)<<endl;
//    cout<<mc.book(33,42)<<endl;
//    cout<<mc.book(25,32)<<endl;
//    cout<<mc.book(26,35)<<endl;
//    cout<<mc.book(19,25)<<endl;
//    cout<<mc.book(3,8)<<endl;
//    cout<<mc.book(8,13)<<endl;
//    cout<<mc.book(18,27)<<endl;
//    cout<<mc.book()<<endl;
//    cout<<mc.book(19, 25)<<endl;
//    cout<<mc.book(18, 27)<<endl;

    cout<<mc.book(37, 50)<<endl;
    cout<<mc.book(33, 44)<<endl;


    LT0729 lt;


    return 0;
}
