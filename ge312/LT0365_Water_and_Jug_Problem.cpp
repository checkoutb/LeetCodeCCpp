
#include "../header/myheader.h"

class LT0365
{
public:



// discuss
// return z == 0 or x + y >= z and z % gcd(x, y) == 0

//    //limit brought by the statement that water is finallly in one or both buckets
//    if(x + y < z) return false;
//    //case x or y is zero
//    if( x == z || y == z || x + y == z ) return true;
//
//    //get GCD, then we can use the property of Bézout's identity
//    return z%GCD(x, y) == 0;


//Bézout's identity (also called Bézout's lemma) is a theorem in the elementary theory of numbers:
//
//let a and b be nonzero integers and let d be their greatest common divisor. Then there exist integers x
//and y such that ax+by=d
//
//In addition, the greatest common divisor d is the smallest positive integer that can be written as ax + by
//
//every integer of the form ax + by is a multiple of the greatest common divisor d.
// ?? gcd 必然小于等于min(x,y),怎么可能 ax+by=d 成立
// 若a,b是整数,且gcd(a,b)=d，那么对于任意的整数x,y,ax+by都一定是d的倍数，特别地，一定存在整数x,y，使ax+by=d成立。
// 负数。。。。
// 一个重要推论是：a,b互质的充要条件是存在整数x,y使ax+by=1.

// z是 x y 不停操作的。a，b可以看作操作这个动作。



    // ..gg.....
    // 穷举所有可能的升数，然后看z是否在其中？,,1,21亿，20亿2千万，就。。。
    // 只能一个个测过去。。
    bool lt0365a(int x, int y, int z)
    {
        if (z == 0)
            return true;
        if (x == 0)
            return y == z;
        if (y == 0)
            return x == z;
        if (x > y)
        {
            x = x + y;
            y = x - y;
            x = x - y;
        }
        if (z > x + y)
            return false;
        if (z % x == 0)
            return true;
        if (z % y == 0)
            return true;
        int t1 = y - x;
        if (t1 == 0)
            return false;

        int t2 = x - (y % x);
        int t3 = y % x;
        if (z % x == t3)
            return true;
        if (z == (y + t3))
            return true;
        if (z == (x + t3))
            return true;

        if (z == (y + t2) || z == (x + t2))
            return true;

        return false;
    }
};

int main()
{
//    int x = 3, y = 5, z = 4;
//    int x = 34, y = 5, z = 6;
    int x = 13, y = 11, z = 1;

    LT0365 lt;
    cout<<endl<<lt.lt0365a(x,y,z)<<endl;
    return 0;
}
