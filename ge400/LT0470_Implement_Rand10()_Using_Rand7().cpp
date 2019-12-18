
#include "../header/myheader.h"

class LT0470
{
public:


// details
//        do {
//            ans = (rand7()-1)*7+(rand7()-1);
//            if (ans<40)
//                return ans%10+1;
//        } while (ans>=40);
// ..why?

// discuss
// (rand7() - 1) * 7 + rand7() - 1 will get random 0 ~ 48
// we need 49/40*2 = 2.45 calls of rand7() per rand10().

// (rand5 - 1) * 5 + rand5 - 1, 估计也是平均的。

// *7,这样就 0 7 14 21 28 35 42 是平均获得的。
// + rand7 - 1 后，就是0-48 平均获得。

// (randy - 1) * x + randx - 1 , 能获得 随机数。。

// 我这种是 7/6 + 7/5 次rand7，才能获得rand10。。 2.56666666666次


// 想到一种：
// 但是错了，，，因为 部分数字不可能出现。。4，5，6，7，8，两个控制变量不能一次得到。
    int lt0470b()
    {
        int t1 = 0;
        int ans = 0;
        while ((t1 = rand7()) == 7);
        ans += (t1 / 4) * 5;
        while (t1 > 5)
            t1 = rand7();
        return ans + t1;
    }

    // 也是错的，10没有，而且几率应该不相等。。
    int lt0470c()
    {
        int t1 = 0;
        int ans = 0;
        while ((t1 = rand7()) == 7);
        ans += (rand7() + t1 % 3);
        return ans;
    }

//Runtime: 72 ms, faster than 62.98% of C++ online submissions for Implement Rand10() Using Rand7().
//Memory Usage: 9.8 MB, less than 40.00% of C++ online submissions for Implement Rand10() Using Rand7().

    int lt0470a() {
        int t1 = 0;
        int t2 = 0;
        while ((t1 = rand7()) == 7);
        while ((t2 = rand7()) > 5);

        return (t1 / 4) * 5 + t2;
    }
};

