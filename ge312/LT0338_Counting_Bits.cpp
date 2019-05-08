
#include "../header/myheader.h"

class LT0338
{
public:




//Runtime: 56 ms, faster than 75.54% of C++ online submissions for Counting Bits.
//Memory Usage: 10.3 MB, less than 5.42% of C++ online submissions for Counting Bits.


// 并不需要v3，直接result的重复就可以了。


// ret[i] = ret[i&(i-1)] + 1;       // 。。无法理解。前n个不变，+1.。。
                            // 可能是：i，i-1，前面相同部分 的bit1个数 + 1.。。归纳能得出这个结果。但是无法推导出来。
                    // i 和 i - 1，的相同部分的 1 的个数已经知道了。。 由于只是+1，所以是个循环。
                    // 0000
                    // 0001
                    // 0011
                    // 0100
                    // 0101
                    // 0110
                    // 0111
                    // 不同部分只是一个1.

                    // i+1，要么是 1111，变成 10000.产生进位。。要么就是简单的末尾0变成1，1100->1101.
                    // 产生进位的话，不同部分的1的个数是1.。。0变1，不同部分也是+1。


// f[i] = f[i >> 1] + (i & 1);      // i 和 >>1 的各自从第一个1开始的n个bit位是相同的，只是i会多一位。


    // 0 0 0 0 1        1

    // 0 0 0 1 0        1       第1行的1
    // 0 0 0 1 1        2         1  的1 + 1

    // 0 0 1 0 0        1         2  的1
    // 0 0 1 0 1        2         3  的2
    // 0 0 1 1 0        2         2    1 + 1
    // 0 0 1 1 1        3         3  的2 + 1

    // 0 1 0 0 0        1         4  1
    // 0 1 0 0 1        2         5  2
    // 0 1 0 1 0        2         6
    // 0 1 0 1 1        3         7
    // 0 1 1 0 0        2         4  1 + 1          // 或者就是第8行+1
    // 0 1 1 0 1        3         5  2 + 1
    // 0 1 1 1 0        3         6  2 + 1
    // 0 1 1 1 1        4         7  3 + 1

    // 1 0 0 0 0        1
    // 似乎是重复之前的 + 重复之前的+1.
    vector<int> lt0338a(int num) {

        vector<int> result(num + 1);
        if (num == 0)
            return result;
        result[1] = 1;
        if (num == 1)
        {
            return result;
        }
        vector<int> v3;
        v3.push_back(1);

        #ifdef __test
        for_each(v3.begin(), v3.end(), fun_cout);
        cout<<endl;
        #endif // __test

        result[0] = 0;

        int i = 2;
        int sz2 = 0;
        int j = 0;
        int t1 = 0;
        int sz1 = 0;
        while (i <= num)
        {
            sz1 = v3.size();            // << 1 ?
            sz2 = sz1 * 2;
            j = 0;
            while (j < sz2 && i <= num)
            {
                if (j < sz1)
                    v3.push_back(v3[j] + 1);
                result[i] = v3[j];
                j++;
                i++;
            }
        }
        return result;
    }
};

int main()
{
    LT0338 lt;
//    int n = 5;
    int n = 2;

    vector<int> v = lt.lt0338a(n);
    cout<<endl;
    for_each(v.begin(), v.end(), fun_cout);
    cout<<endl;

//    cout<<endl;
//    vector<int> v2(10);
//    cout<<v2.size();
//    for_each(v2.begin(), v2.end(), fun_cout);

    return 0;
}
