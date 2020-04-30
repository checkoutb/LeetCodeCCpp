
#include "../header/myheader.h"


class MyCalendarThree {

    vector<pair<int, int>> books;

public:
    MyCalendarThree() {

    }

// discuss
// ... map<int, int>   key代表start/end这些点， value是key的(start的个数-end的个数)
// map[start]++, map[end]--,cnt=0, for(pair<int, int> map : map) { ans = max(ans, cnt+=map.second)}
// 按照时间轴，value为正，就是有多少个event从这里开始，value为负，就是多少个event结束。



//Runtime: 1528 ms, faster than 5.22% of C++ online submissions for My Calendar III.
//Memory Usage: 25.3 MB, less than 25.00% of C++ online submissions for My Calendar III.
    int book(int start, int end)
    {
        pair<int, int> p2(start, end);
        vector<pair<int, int>>::iterator it = std::lower_bound(books.begin(), books.end(), p2, [](pair<int, int> p11, pair<int, int>p22)->bool{
            if (p11.first == p22.first)
                return p11.second < p22.second;
            else
                return p11.first < p22.first;
        });

        books.insert(it, p2);

        priority_queue<int, vector<int>, std::greater<int>> pri;
        int ans = 0;
        for (pair<int, int> p3 : books)
        {
            pri.push(p3.second);
            int top = pri.top();
            while (top <= p3.first)
            {
                pri.pop();
                if (pri.empty())
                    break;
                top = pri.top();
            }
            ans = std::max(ans, (int) pri.size());
        }
        return ans;
    }

//    int book(int start, int end) {
//        map<pair<int, int>, int> map1;
//        for (pair<int, int> p1 : books)
//        {
//            int max_st = max(p1.first, start);
//            int min_en = min(p1.second, end);
//            if (max_st < min_en)
//            {
//                for (map<pair<int, int>, int>::iterator it = map1.begin(); it != map1.end(); it++)
//                {
//                    pair<int, int> p2 = it->first;
//                    if ()
//                }
//            }
//        }
//    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */


class LT0732
{
public:



};

int main()
{

    LT0732 lt;

    MyCalendarThree MyCalendarThree;
    cout<<MyCalendarThree.book(10, 20); // returns 1
    cout<<endl;
    cout<<MyCalendarThree.book(50, 60); // returns 1
    cout<<endl;
    cout<<MyCalendarThree.book(10, 40); // returns 2
    cout<<endl;
    cout<<MyCalendarThree.book(5, 15); // returns 3
    cout<<endl;
    cout<<MyCalendarThree.book(5, 10); // returns 3
    cout<<endl;
    cout<<MyCalendarThree.book(25, 55); // returns 3
    cout<<endl;

    return 0;
}
