
#include "../header/myheader.h"
#include <mutex>
#include <thread>
#include <functional>
#include <pthread.h>
#include <chrono>


class LT1115
{
public:



};



// D
// 双sem_t ,就是 semaphore
// 双mutex， m1.lock + m2.unlock.  m2.lock + m1.unlock .  不过好像 没有锁的时候 unlock 是未定义的。


// tle..
class FooBar {
private:
    int n;
    mutex lk;
    bool c;

public:
    FooBar(int n) {
        this->n = n;
        this->c = true;
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {

            lk.lock();
            if (c)
            {
                printFoo();
                c = !c;
            }
            else
            {
                i--;
            }
            lk.unlock();

        	// printFoo() outputs "foo". Do not change or remove this line.
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {
            lk.lock();
            if (c)
            {
                i--;
            }
            else
            {
        	// printBar() outputs "bar". Do not change or remove this line.
                printBar();
                c = !c;
        	}
        	lk.unlock();
        }
    }
};


int main()
{

    LT1115 lt;
    FooBar fb(4);

    std::thread th1(&FooBar::foo, &fb, [](){cout<<"foo"<<endl;});
    std::thread th2(&FooBar::bar, &fb, [](){cout<<"bar"<<endl;});

    th1.join();
    th2.join();

    return 0;
}
