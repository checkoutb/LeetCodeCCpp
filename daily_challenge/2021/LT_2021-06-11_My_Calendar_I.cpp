
#include "../../header/myheader.h"

class LT
{
public:



};

// D D

//        map<int, int>::iterator it = cal.upper_bound(start);
//        if (it==cal.end() || end <= it->second){
//            cal[end] = start;
//            return true;
//        }
//        return false;


//set<pair<int, int>> books;
//
//        auto next = books.lower_bound({s, e}); // first element with key not go before k (i.e., either it is equivalent or goes after).
//        if (next != books.end() && next->first < e) return false; // a existing book started within the new book (next)
//        if (next != books.begin() && s < (--next)->second) return false; // new book started within a existing book (prev)
//        books.insert({ s, e });


// TreeMap
//        Integer floorKey = calendar.floorKey(start);
//        if (floorKey != null && calendar.get(floorKey) > start) return false;
//        Integer ceilingKey = calendar.ceilingKey(start);
//        if (ceilingKey != null && ceilingKey < end) return false;
//        calendar.put(start, end);

//    Integer low = map.lowerKey(end);
//
//    if(low == null || map.get(low) <= start) {
//        map.put(start, end);
//        return true;
//    }
//    return false;



// 感觉 我的book，只需要一半就可以了。。。


// AC
class MyCalendar {
//    vector<int[]> varr;
//    vector<int>
//    map<int, int> map2;     // <st, en>
//    map<int, int> map3;     // <en, st>
    vector<int> st;
    vector<int> en;
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        if (st.size() == 0)
        {
            st.push_back(start);
            en.push_back(end);
            return true;
        }
        vector<int>::iterator it1 = std::lower_bound(begin(st), std::end(st), end);     // end is int, std::end is function.
        if (it1 == begin(st)) {
            st.insert(begin(st), start);
            en.insert(begin(en), end);
            return true;
        } else {
            it1--;
            int idx2 = std::distance(begin(st), it1);
            if (st[idx2] < end && en[idx2] > start)
                return false;
        }
        vector<int>::iterator it2 = std::upper_bound(begin(en), std::end(en), start);
        if (it2 == std::end(en)) {
            st.push_back(start);
            en.push_back(end);
            return true;
        } else {
            int idx2 = distance(begin(en), it2);
            if (st[idx2] < end && en[idx2] > start)
                return false;
            st.insert(begin(st) + idx2, start);
            en.insert(begin(en) + idx2, end);
            return true;
        }
    }
};


int main()
{

    MyCalendar mc;

    cout<<endl<<mc.book(10, 20);
    cout<<endl<<mc.book(15, 22);
    cout<<endl<<mc.book(20, 26);


    LT lt;


    return 0;
}
