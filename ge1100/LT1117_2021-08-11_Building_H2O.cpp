
#include "../header/myheader.h"

class LT1117
{
public:



};

// 看了discuss，估计是希望： O方法等待H方法，或者H方法等待O方法。

// sem_wait
// condition_variable



// 。。 不好测。。而且。。没有说 是一个 H2O instance，然后不同线程调用，还是 每个线程一个 H2O 对象。
// 而且好像是 多个H， 多个O 线程。。
// ReentrantLock、CountDownLatch、CyclicBarrier
// Semaphore

// mutex
// 。。。 还有c++20 加入的 2个。。。

// 是外部无限调用，还是 只调用一次。 当外部无线调用吧。不然停不下来。。。

// 。。。。看懂了。。。 Input: water = "OOHHHH"   是外部调用。。不，应该。。
//Input //"OOHHHH"
//Output //"OHHHH"
//Expected //"HHOHHO"
// 根据这个，感觉是 外部是 OOHHHH的 调用顺序，  按照这个顺序，确实我这段代码输出OHHHH。
// 但是这样的话，和多线程有什么关系。。  最多就是一个锁来保护no nh 的读写，  atomic 就可以了。
// 而且OOHHHH的话， 内部需要一个 while true， 不然就跳过了。。



class H2O {

//    std::mutex mxo;
//    std::mutex mxh;
    std:: mutex mx;
    int no = 0;
    int nh = 0;

public:
    H2O() {

    }

    void hydrogen(function<void()> releaseHydrogen) {

        mx.lock();

        if ((no + 1) * 2 >= nh)
        {
            releaseHydrogen();
            nh++;
        }

        mx.unlock();

        // releaseHydrogen() outputs "H". Do not change or remove this line.
//        releaseHydrogen();
    }

    void oxygen(function<void()> releaseOxygen) {

        mx.lock();
        if (no * 2 <= nh)
        {
            releaseOxygen();
            no++;
        }
        mx.unlock();

        // releaseOxygen() outputs "O". Do not change or remove this line.
//        releaseOxygen();
    }
};


int main()
{

    LT1117 lt;


    return 0;
}
