
#include "../header/myheader.h"

class LT1195
{
public:



};


// D

//condition_variable cv;
//        while (true) {
//            unique_lock<mutex> lock(m);
//            while (count <= n && (count % 3 != 0 || count % 5 == 0))
//                cv.wait(lock);
//            if (count > n) return;
//            printFizz();
//            ++count;
//            cv.notify_all();
//        }


// tle.  thread 只调用一次方法。所以 方法内 需要结束。

// function<void(int)> printNumber
// 返回 void, 形参 int

// 3 fizz,  5 buzz
class FizzBuzz {
private:
    int n;
    mutex mtx;
    int i;
//    bool fz;
public:
    FizzBuzz(int n) {
        this->n = n;
        this->i = 1;
//        this->fz = false;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        mtx.lock();
        if (i % 3 == 0 && i % 15 != 0 && i <= n)
        {
            i++;
            printFizz();
        }
        mtx.unlock();
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        mtx.lock();
        if (i % 5 == 0 && i % 15 != 0 && i <= n)
        {
            i++;
            printBuzz();
        }
        mtx.unlock();
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        mtx.lock();
        if (i % 15 == 0 && i <= n)
        {
            i++;
            printFizzBuzz();
        }
        mtx.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        mtx.lock();
        if (i % 3 != 0 && i % 5 != 0 && i <= n)
        {
            printNumber(i);
            i++;
        }
        mtx.lock();
    }
};


int main()
{

    LT1195 lt;


    return 0;
}
