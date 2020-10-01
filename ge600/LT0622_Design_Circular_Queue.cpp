
#include "../header/myheader.h"

class LT0622
{
public:

// 直接一个queue，然后加个int限制长度。。

};


// D D

// baocun length, er bushi noEle

// arr.size() ...




//Runtime: 36 ms, faster than 97.91% of C++ online submissions for Design Circular Queue.
//Memory Usage: 16.9 MB, less than 32.49% of C++ online submissions for Design Circular Queue.
class MyCircularQueue {

    int fro = 0;
    int rear = 0;           // the position of next insert
    int* arr = nullptr;
    int sz = 0;
    bool noEle = true;

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        arr = new int[k];
        sz = k;
        fro = 0;
        rear = 0;
        noEle = true;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull())
            return false;
        arr[rear] = value;
        rear = (rear + 1) % sz;
        noEle = false;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty())
            return false;
        fro = (fro + 1) % sz;
        noEle = true;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty())
            return -1;
        return arr[fro];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty())
            return -1;
        return arr[(rear - 1 + sz) % sz];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return fro == rear && noEle;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return rear == fro && !noEle;
    }

    ~MyCircularQueue() {
        delete[] arr;
    }
};

int main()
{

    MyCircularQueue circularQueue(3); // set the size to be 3
    cout<<endl<<circularQueue.enQueue(1);  // return true
    cout<<endl<<circularQueue.enQueue(2);  // return true
    cout<<endl<<circularQueue.enQueue(3);  // return true
    cout<<endl<<circularQueue.enQueue(4);  // return false, the queue is full
    cout<<endl<<circularQueue.Rear();  // return 3
    cout<<endl<<circularQueue.isFull();  // return true
    cout<<endl<<circularQueue.deQueue();  // return true
    cout<<endl<<circularQueue.enQueue(4);  // return true
    cout<<endl<<circularQueue.Rear();  // return 4


    LT0622 lt;


    return 0;
}
