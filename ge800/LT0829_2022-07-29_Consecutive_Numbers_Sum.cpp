
#include "../header/myheader.h"

class LT0829
{
public:




    // ... D
    // ... 差为1的等差数列。 的和 等于 整数n。


/*



1: {1}
2: {2}
3: {1,2}  {3}
4: {4}
5: {2,3} {5}
6: {1,2,3}
7: {3,4}
8: {8}

... 能被多少整除 就有多少种方法。。。

9 能被 3整除，所以 必然有  a * 整数 == 9

A 能被 Q 整除， 必然有 Q * 整数 == A == Q + Q + Q + ... + Q
== (Q-x1) + (Q-x2) + ... + Q + ... + (Q + x2) + (Q + x1)
== (Q-x1) + (Q-x2) + (Q-2) + (Q-1) + Q + (Q + 1) + (Q + 2) + .. Q+x2 + Q+x1


A = A * 1 = 1 + 1 +...+1  != (1-x1)...


A = A/2 + A/2+1     A奇数


4 ， 所以 被偶数 / ，需要 得到 x.5     所以是 A*2 能被 偶数 除净 ？  且 A 无法被 偶数除净
A / 偶数 == Z ， Z-0.5 + (Z+0.5)
  Z-1.5 + Z-0.5 + Z+0.5 + Z+1.5





*/
    int lt0829a(int n)
    {

    }

};

int main()
{

    LT0829 lt;


    return 0;
}
