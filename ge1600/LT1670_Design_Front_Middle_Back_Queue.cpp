
#include "../header/myheader.h"

class LT1670
{
public:



};


// D D





//Runtime: 64 ms, faster than 40.00% of C++ online submissions for Design Front Middle Back Queue.
//Memory Usage: 20.6 MB, less than 62.50% of C++ online submissions for Design Front Middle Back Queue.
class FrontMiddleBackQueue {
//    vector<int> vi;
    list<int> list2;
public:
    FrontMiddleBackQueue() {

    }

    void pushFront(int val) {
        list2.push_front(val);
    }

    void pushMiddle(int val) {
        auto it = list2.begin();
        for (int i = 0; i < list2.size() / 2; ++i)
            it++;
        list2.insert(it, val);
    }

    void pushBack(int val) {
        list2.push_back(val);
    }

    int popFront() {
        if (list2.empty())
            return -1;
        int fnt = list2.front();
        list2.pop_front();
        return fnt;
    }

    int popMiddle() {
        if (list2.empty())
            return -1;
        auto p = list2.begin();
        for (int i = 0; i < (list2.size() - 1) / 2; ++i)
            p++;
        int ans = *p;
        list2.erase(p);
        return ans;
    }

    int popBack() {
        if (list2.empty())
            return -1;
        int bak = list2.back();
        list2.pop_back();
        return bak;
    }
};




// error .    pop后，没有办法平衡 2个队列。  也不是，需要 自己 while (size > size) { push(pop)} 来平衡。
class FrontMiddleBackQueue2 {
    deque<int> fdeq;
    deque<int> bdeq;

public:
    FrontMiddleBackQueue2() {
        this->fdeq = deque<int>();
        this->bdeq = deque<int>();
    }

    void pushFront(int val) {
        this->fdeq.push_front(val);
    }

    void pushMiddle(int val) {
        if (fdeq.size() < bdeq.size())
        {
            fdeq.push_back(val);
        }
        else
        {
            bdeq.push_front(val);
        }
    }

    void pushBack(int val) {
        this->bdeq.push_back(val);
    }

    int popFront() {
//        if (this->fdeq.empty())
//            return -1;
//        int ans = this->fdeq.front();
//        this->fdeq.pop_front();
//        return ans;
        if (this->fdeq.empty())
        {
            if (this->bdeq.empty())
                return -1;
            else
            {
                int ans = this->bdeq.front();
                this->bdeq.pop_front();
                return ans;
            }
        }
        else
        {
            int ans = this->fdeq.front();
            this->fdeq.pop_front();
            return ans;
        }
    }

    int popMiddle() {
        if (this->fdeq.empty() && this->bdeq.empty())
            return -1;
        if (this->fdeq.size() >= this->bdeq.size())
        {
            int ans = this->fdeq.back();
            this->fdeq.pop_back();
            return ans;
        }
        else
        {
            int ans = bdeq.front();
            bdeq.pop_front();
            return ans;
        }
    }

    int popBack() {
//        if (this->bdeq.empty())
//            return -1;
//        int ans = this->bdeq.back();
//        this->bdeq.pop_back();
//        return ans;
        if (this->bdeq.empty())
        {
            if (this->fdeq.empty())
                return -1;
            else
            {
//                int ans =
            }
        }
        else
        {
            int ans = this->bdeq.back();
            this->bdeq.pop_back();
            return ans;
        }
    }
};


int main()
{

    LT1670 lt;

    FrontMiddleBackQueue q;
    q.pushFront(1);   // [1]
    q.pushBack(2);    // [1, 2]
    q.pushMiddle(3);  // [1, 3, 2]
    q.pushMiddle(4);  // [1, 4, 3, 2]
    cout<<endl<<q.popFront();     // return 1 -> [4, 3, 2]
    cout<<endl<<q.popMiddle();    // return 3 -> [4, 2]
    cout<<endl<<q.popMiddle();    // return 4 -> [2]
    cout<<endl<<q.popBack();      // return 2 -> []
    cout<<endl<<q.popFront();     // return -1 -> [] (The queue is empty)


    return 0;
}
