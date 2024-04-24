
#include "../header/myheader.h"

class LT1117
{
public:



};




// 不理解， hydrogen 中有2种 cv.wait，  cnto > cnth / 2 的，提交了5次，3次可以。 2次tle。
                            // cnto * 2 > cnth, 提交了5次， 都是 tle
            // 不知道 哪里死锁了。
    // test 是都可以 过的。
// 而且，那个 water 是怎么起效的？



// Runtime
// 7ms
// Beats44.57%of users with C++
// Memory
// 11.12MB
// Beats9.45%of users with C++

class H2O {
    std::mutex mtx;
    std::condition_variable cv;
    volatile int cnto = 0;
    volatile int cnth = 0;
public:
    H2O() {

    }

    void hydrogen(function<void()> releaseHydrogen) {

        std::unique_lock<mutex> lck(mtx);

        // cv.wait(lck, [&]{ return cnto * 2 >= cnth;});
        cv.wait(lck, [&]{ return cnto >= cnth / 2;});

        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        ++cnth;
        cv.notify_one();
    }

    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock<mutex> lck(mtx);
        cv.wait(lck, [&]{ return cnto * 2 <= cnth;});
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        ++cnto;
        cv.notify_one();
    }
};

int main()
{

    LT1117 lt;


    return 0;
}
