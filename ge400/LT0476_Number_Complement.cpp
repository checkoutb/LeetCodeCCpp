
#include "../header/myheader.h"

class LT0476
{
public:


// dd

//        unsigned mask = ~0;
//        while (num & mask) mask <<= 1;
//        return ~mask & ~num;
// mask 从全1，变成 num最高位之前是1，最高位及之后是0。

//        int i = 0;
//        int j = 0;
//        while (i < num)
//        {
//            i += Math.pow(2, j);
//            j++;
//        }
//        return i - num;
// 最高位及之后全1，减去 num 就是 按位取反？。是的，1111 - 1010 就是 101。因为每个位只有2个选择，所以能这样减去。

//    return ~num & ((Integer.highestOneBit(num) << 1) - 1);
// & 后面 就是 第一个的 ~mask

//    int mask = num;
//    mask |= mask >> 1;
//    mask |= mask >> 2;
//    mask |= mask >> 4;
//    mask |= mask >> 8;
//    mask |= mask >> 16;
//    return num ^ mask;
// 这个就是靠最高位的1，把低于它的位全刷成1。第一次刷1个，这样最开始的2位就全1，然后刷2个，刷4个。。。

//    int x=1,i=1;
//    while(x<=num && i<32)
//    {
//        num=num^x;
//        x=x<<1;
//        i++;
//    }
//    return num;
// 每位取反。




    // Integer.toBinaryString ?

    // bitset ...

//Runtime: 4 ms, faster than 52.61% of C++ online submissions for Number Complement.
//Memory Usage: 8.3 MB, less than 58.33% of C++ online submissions for Number Complement.

    int lt0476a(int num)
    {
        const int len1 = sizeof(int) * 8;
        bitset<len1> bs(num);

        bool flag1 = false;

        for (int i = len1 - 1; i >= 0; i--)
        {
            if (!flag1 && bs[i])
            {
                flag1 = true;
            }
            if (flag1)
            {
                bs[i] = (bs[i] ^ 1);
            }
        }
        return (int) bs.to_ulong();
    }
};

int main()
{

    int num = 16;

    LT0476 lt;

    cout<<lt.lt0476a(num)<<endl;

    return 0;
}
