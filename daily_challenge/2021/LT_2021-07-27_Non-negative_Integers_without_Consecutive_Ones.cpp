
#include "../../header/myheader.h"

class LT
{
public:

// Discuss


//Why can I use fibonacci numbers?
//a(n) = the number of valid integers less than 2^n
//a(5) = the number of valid integers less than 0b100000
//It equals to the number of valid integers in [0b0, 0b10000[ and in [0b10000, 0b11000[.
//The number of valid integers [0b0, 0b10000[, which is like '0b0XXXX', equals to a(4).
//The number of valid integers [0b10000, 0b11000[, which is like '0b101XX', equals to a(3).
//So a(5) = a(4) + a(3).
//        x, y = 1, 2
//        res = 0
//        num += 1
//        while num:
//            if num & 1 and num & 2:
//                res = 0
//            res += x * (num & 1)
//            num >>= 1
//            x, y = y, x + y
//        return res


//f(n) = "0" f(n - 1) + "10" f(n - 2).
//    static int fb[31] = { 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946,
//        17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578 };
//    if (num < 3) return num + 1;
//    for (int bt = 29; bt >= 0; --bt) // bt should start from 30, but OJ accepts it from 29.
//        if (num & (1 << bt)) return num & (1 << (bt - 1)) ? fb[bt] : fb[bt - 1] + findIntegers((num & ~(1 << bt)));



// https://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/



// g



// dp,感觉和dfs差不多啊。 不 。。 唯一的问题是，怎么判断越界。。
// 还是说，反向？计算 有多少个值 是存在 连续1的 ？
// 9 99 999 9999   1 11 111 1111
// 。。。 这道题是600题 hard。。 还没有AC过。。
// 没有hint 。。 关联的topic 是 dp
// 1 11 111 1111
// 1
// 应该是dp： 下标是首位1,  1xxxx 的情况是 1xx + 1x + 1 的 和。
    int ltb(int n)
    {
        int arr[32] = {0};          // 下标所代表的bit为1的，并且这个bit是首位的 值的个数。
        arr[0] = 1;  // 0,1  ..0不能算，因为下标所代表的bit为1....         // 和bit的顺序反的，有点。。bit最右是第一个， 数组最左是第一个。
        arr[1] = 1;         // 只有 10
        int mxi = 1;
        while (mxi < n)
        {
            mxi <<= 1;
        }
        // 好像还是不对的。完全不对的，， 越界没有办法  试试
        for (int i = 2; i < mxi; ++i)
        {
            for (int j = i - 2; j >= 0; --j)
            {
                arr[i] += arr[j];
            }
        }
        // 但是合并不了。。难道直接在上面 计算 是否越界？ 。。
        // 5  101
        // 1x +  1
        //  1    1      10  1                -0
        // 100  1
        // 11001101
        //  1111111   =  1 + 10 + 100 + 1000 ...
        // 1xxxxxxx  = 1

        // 1000001
        int ans = 0;
//        while (n > 0)
//        {
//            while (mxi > )
//        }

//        int t2 = 0;
//        while (t2 < n)
//        {
//            for (int i = 0; i > )
//        }

        for (int i = 0; i < mxi - 1; ++i)
        {
            ans += arr[i];
        }
        int t2 = (1 << (mxi - 1));


        return ans + 1;
    }



// tle...
// dfs, 感觉会tle(n <= 10^9)，又不会tle (最多30层，并且中间提前return)。。。
    int lta(int n)
    {
        ans = 0;
        dfsa1(n, 0, 0);
        return ans + 1;         // 0
    }
    int ans = 0;
    void dfsa1(int n, int bits, int val)
    {
//        if ((val & (1 << (bits - 1))) == 0)
//        {
            int t2 = val | (1 << bits);
            if (t2 <= n)
            {
                if (bits == 0 || ((val & (1 << (bits - 1))) == 0))         // << -1
                {
                    ans++;
                    dfsa1(n, bits + 1, t2);         // 1
                }
                dfsa1(n, bits + 1, val);        // 0
            }
//        }
//        else
//        {
//            // .. 也需要 | (1<<bits) 来判断是否越界。 所以合并。。
//        }
    }

};

int main()
{
//    int i = 0b111;
//    cout<<i<<endl;

    myvi v = {5,1,2,823123123,999999921};           // 后2个，都13ms左右。

    LT lt;

    for (int i : v)
    {
        clock_t st = clock();
        cout<<lt.lta(i)<<endl;
        clock_t en = clock();
        cout<<" = = = = == = = = = "<<(en - st) * 1000.0 / CLOCKS_PER_SEC<<endl;

        st = clock();
        cout<<endl<<endl<<lt.ltb(i)<<endl;
        en = clock();
        cout<<" - -- - - "<<(en - st) * 1000.0 / CLOCKS_PER_SEC<<endl;
    }

    return 0;
}
