
#include "../header/myheader.h"

#include <thread>
#include <mutex>
#include <functional>

class LT1116
{
public:



};

// D D

//this_thread::yield();
// 配合 while bool， 不用 互斥，信号量。


//        while (tot <= 2*n) {
//            unique_lock<mutex> lk(m);
//            cv.wait(lk, [this](){ return tot%4 == 0; });
//            if (tot <= 2*n) printNumber(tot/2);
//            tot++;
//            lk.unlock();
//            cv.notify_all();
//        }


//        int numTimes = this.n / 2;
//
//        int nextEvenNum = 2;
//        for(int i = 0; i < numTimes; i++){
//            semaphoreEven.acquire();
//
//            printNumber.accept(nextEvenNum);
//            nextEvenNum += 2;
//
//            semaphoreZero.release();
//        }
// java


//5 Python solutions using threading (Barrier, Condition, Event, Lock, Semaphore) with explanation
//https://leetcode.com/problems/print-zero-even-odd/discuss/337499/5-Python-solutions-using-threading-(Barrier-Condition-Event-Lock-Semaphore)-with-explanation





//Runtime: 44 ms, faster than 67.84% of C++ online submissions for Print Zero Even Odd.
//Memory Usage: 6.8 MB, less than 98.68% of C++ online submissions for Print Zero Even Odd.

function<void(int)> printNumber = [](const int n){ cout<<n<<", "; };

class ZeroEvenOdd {
private:
    int n;
    std::mutex m0;
    std::mutex m1;
    std::mutex m2;
    int val;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->val = 1;
        m1.lock();
        m2.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while (true)
        {
            m0.lock();
            if (this->val > this->n)
            {
                m0.unlock();
                m1.unlock();
                m2.unlock();
                return;
            }
            printNumber(0);
            if (this->val % 2 == 1)
            {
                m1.unlock();
            }
            else
            {
                m2.unlock();
            }
        }

//        m0.lock();
//        if (this->val > this->n)
//        {
//            m0.unlock();
//            m1.unlock();
//            m2.unlock();
//            return;
//        }
//        printNumber(0);
//        if (this->val % 2 == 1)
//        {
//            m1.unlock();
//        }
//        else
//        {
//            m2.unlock();
//        }
    }

    void even(function<void(int)> printNumber) {
        while (true)
        {
            m2.lock();
            if (this->val > this->n)
            {
                m2.unlock();
                m0.unlock();
                return;
            }
            printNumber(this->val);
            this->val++;
            m0.unlock();
        }
//        m2.lock();
//        if (this->val > this->n)
//        {
//            m2.unlock();
//            return;
//        }
//        printNumber(this->val);
//        this->val++;
//        m0.unlock();
    }

    void odd(function<void(int)> printNumber) {
        while (true)
        {
            m1.lock();
            if (this->val > this->n)
            {
                m1.unlock();
                m0.unlock();
                return;
            }
            printNumber(this->val);
            this->val++;
            m0.unlock();
        }
//        m1.lock();
//        if (this->val > this->n)
//        {
//            m1.unlock();
//            return;
//        }
//
//        printNumber(this->val);
//        this->val++;
//        m0.unlock();

    }
};


int main()
{
    int n = 2;

    ZeroEvenOdd zeo(n);
//    function<void(int)> printNumber = [](const int n){ cout<<n<<", "; };

//    std::thread t1(zeo.zero(printNumber));
//    std::thread t2(zeo.even(printNumber));
//    std::thread t3(zeo.even())

    thread t0(&ZeroEvenOdd::zero, &zeo, printNumber);
    thread t1(&ZeroEvenOdd::odd, &zeo, printNumber);
    thread t2(&ZeroEvenOdd::even, &zeo, printNumber);

    t0.join();
    t1.join();
    t2.join();


    LT1116 lt;


    return 0;
}
