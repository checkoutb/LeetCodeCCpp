
#include "../header/myheader.h"

#include <mutex>
#include <thread>
#include <functional>
#include <pthread.h>
#include <chrono>

class LT1114
{
public:



};



// D D

//  std::promise<void> p1;
//  std::promise<void> p2;
//  void second(function<void()> printSecond) {
//    p1.get_future().wait();
//    printSecond();
//    p2.set_value();
//  }


//    private final CountDownLatch l2;
//    private final CountDownLatch l3;
//    public Foo() {
//        l2 = new CountDownLatch(1);
//        l3 = new CountDownLatch(1);
//    }
//    public void second(Runnable printSecond) throws InterruptedException {
//        l2.await();
//        printSecond.run();
//        l3.countDown();
//    }


//    mutex m1, m2;
//public:
//    Foo() {
//        m1.lock(), m2.lock();
//    }
//        m1.lock();
//        // printSecond() outputs "second". Do not change or remove this line.
//        printSecond();
//        m1.unlock();
//        m2.unlock();


//    final Semaphore hasFirstRun = new Semaphore(0);
//    final Semaphore hasSecondRun = new Semaphore(0);
//        hasFirstRun.acquire();
//        printSecond.run();
//        hasSecondRun.release();


//        printFirst.run();
//        onePrinted = true;
//        notifyAll();
//
//        while(!onePrinted) {
//            wait();
//        }
//        // printSecond.run() outputs "second". Do not change or remove this line.
//        printSecond.run();
//        twoPrinted = true;
//        notifyAll();
//
//        while(!twoPrinted) {
//            wait();
//        }
//        // printThird.run() outputs "third". Do not change or remove this line.
//        printThird.run();
// 3个方法 全部 synchronized...




// 最快的是 mutex m1,m2 ，构造器直接 lock 。   基本8-30
// 30左右 还有 std::condition_variable m_cv; 。。。。 condition_variable v1, v2;
// 不，好像 测试案例 改过，后面的也是 双mutex。
// 不过 双mutex 基本最快。

//    sem_t firstJob;
//    sem_t secondJob;
//    Foo() {
//        sem_init(&firstJob, 0, 0);
//        sem_init(&secondJob, 0, 0);
//    }
//        sem_wait(&firstJob);
//        sem_destroy(&firstJob);
//        // printSecond() outputs "second". Do not change or remove this line.
//        printSecond();
//        sem_post(&secondJob);

// atomic<int> who{1};
//        while(who!=3){
//            this_thread::yield();
//        }

//    condition_variable cv;
//    mutex m;
//    atomic_int i = 1;
//        std::unique_lock<std::mutex> lk(m);
//        cv.wait(lk, [&]{ return i == 2;});
//        // printSecond() outputs "second". Do not change or remove this line.
//        printSecond();
//        ++i;
//        cv.notify_all();

// 1400 - 1600
//    int count = 0;
//        while(!count);
//        // printSecond() outputs "second". Do not change or remove this line.
//        printSecond();
//        count++;

// atomic
// 双bool。



//Runtime: 724 ms, faster than 21.94% of C++ online submissions for Print in Order.
//Memory Usage: 7.6 MB, less than 50.81% of C++ online submissions for Print in Order.

// -pthread  linker

// kao, break qian meiyou unlock, suoyi sisuo le....

class Foo {

    mutex mine;

    int cnt = 1;

public:
    Foo() {

    }

//    void first(function<void()> printFirst) {
    void first() {

        while (true)
        {
//            cout<<" . . "<<endl;
            mine.lock();
            if (cnt == 1){
        cout<<"this : "<<1<<endl;
        cnt = 2;
        mine.unlock();
                break;
                }

        // printFirst() outputs "first". Do not change or remove this line.
//        printFirst();

//        mine.lock();
//        cout<<"111"<<endl;
            mine.unlock();
//        mine.unlock();
//        cout<<"111"<<endl;
        }
    }

//    void second(function<void()> printSecond) {
    void second() {
        while (true)
        {
            mine.lock();
            if (cnt == 2)
            {
        cout<<"this : "<<2<<endl;

        cnt = 3;
        mine.unlock();
                break;
            }
//            cout<<" . 222. "<<endl;
//            this_thread::sleep_for(chrono::seconds(1));

        // printSecond() outputs "second". Do not change or remove this line.
//        printSecond();

//        mine.lock();            // ? need?
//        mine.unlock();
            mine.unlock();
        }

    }

//    void third(function<void()> printThird) {
    void third() {

        while (true)
        {
            mine.lock();
            if (cnt == 3){
//            cout<<" .333 . "<<endl;
        cout<<"this : "<<3<<endl;
mine.unlock();
                break;
                }
            mine.unlock();
//            this_thread::sleep_for(chrono::seconds(1));
        // printThird() outputs "third". Do not change or remove this line.
//        printThird();
        }

    }
};

int main()
{

    LT1114 lt;

    Foo foo;

//    std::thread th1(foo.first());
//    std::thread th2(foo.third());
//    std::thread th3(foo.second());

    std::thread th2(&Foo::third, &foo);
    std::thread th1(&Foo::first, &foo);
    std::thread th3(&Foo::second, &foo);

    th3.join();
    th2.join();
    th1.join();

    return 0;
}
