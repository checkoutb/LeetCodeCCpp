
#include "../../header/myheader.h"

class LT
{
public:



};


// D D

// 只需要检查2个。


// map<int,int>events;
// events.insert({end,start});




//Runtime: 229 ms, faster than 27.01% of C++ online submissions for My Calendar I.
//Memory Usage: 37.7 MB, less than 87.88% of C++ online submissions for My Calendar I.
class MyCalendar {

    vector<pair<int, int>> vp;          // <start, end>         // [st, en)

public:
    MyCalendar() {

    }

    bool book(int start, int end2) {
        vector<pair<int, int>>::iterator it = std::lower_bound(begin(vp), end(vp), std::make_pair(end2, -1));
        for (int i = std::distance(begin(vp), it) - 1; i >= 0; --i)
        {
            if (vp[i].first < end2 && vp[i].second > start)
                return false;
            if (vp[i].second <= start)
                break;
        }
        vp.insert(it, {start, end2});           // vp 没有重叠，所以可以用 end2 的 iterator.
        return true;
    }
};


int main()
{

    LT lt;

    MyCalendar mc;

    cout<<endl<<mc.book(10,20);
    cout<<endl<<mc.book(15,22);
    cout<<endl<<mc.book(20,23);


    return 0;
}
