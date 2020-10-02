
#include "../header/myheader.h"

class LT0641
{
public:



};

// D D
// chabuduo.


//Runtime: 40 ms, faster than 98.55% of C++ online submissions for Design Circular Deque.
//Memory Usage: 16.9 MB, less than 33.88% of C++ online submissions for Design Circular Deque.
class MyCircularDeque {

    vector<int> v;
    int len;
    int st;     // st-1 is the position of next insert
    int en;     // position of next insert

    inline int chg(int a, int b)
    {
        return (a + b + v.size()) % v.size();
    }

public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        v = vector<int>(k, 0);
        len = 0;
        st = 0;
        en = 0;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull())
            return false;
        st = chg(st, -1);
        v[st] = value;
        len++;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull())
            return false;
        v[en] = value;
        en = chg(en, 1);
        len++;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty())
            return false;
        st = chg(st, 1);
        len--;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty())
            return false;
        en = chg(en, -1);
        len--;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty())
            return -1;
        return v[st];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty())
            return -1;
        return v[(en - 1 + v.size()) % v.size()];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return len == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return len == v.size();
    }
};



int main()
{

    LT0641 lt;


    MyCircularDeque circularDeque(3); // set the size to be 3
    cout<<endl<<circularDeque.insertLast(1);			// return true
    cout<<endl<<circularDeque.insertLast(2);			// return true
    cout<<endl<<circularDeque.insertFront(3);			// return true
    cout<<endl<<circularDeque.insertFront(4);			// return false, the queue is full
    cout<<endl<<circularDeque.getRear();  			// return 2
    cout<<endl<<circularDeque.isFull();				// return true
    cout<<endl<<circularDeque.deleteLast();			// return true
    cout<<endl<<circularDeque.insertFront(4);			// return true
    cout<<endl<<circularDeque.getFront();			// return 4


    return 0;
}
