
#include "../header/myheader.h"

class LT0693
{
public:

// D D

// n = n>>1;

//        int d = n&1;
//        while ((n&1) == d) {
//            d = 1-d;
//            n >>= 1;
//        }
//        return n == 0;


//        /*
//        n =         1 0 1 0 1 0 1 0
//        n >> 1      0 1 0 1 0 1 0 1
//        n ^ n>>1    1 1 1 1 1 1 1 1
//        n           1 1 1 1 1 1 1 1
//        n + 1     1 0 0 0 0 0 0 0 0
//        n & (n+1)   0 0 0 0 0 0 0 0
//        */
//
//        n = n ^ (n>>1);
//        return (n & n+1) == 0;


// https://leetcode.com/problems/binary-number-with-alternating-bits/discuss/108427/Oneliners-(C%2B%2B-Java-Ruby-Python)
//return !((n ^= n/4) & n-1);

//return !((n ^= n/2) & n+1);

//return Integer.toBinaryString(n).matches("(10)*1?");

//n.to_s(2) !~ /00|11/

//return '00' not in bin(n) and '11' not in bin(n)

//(n^=n/2)&n+1<1

//n < 3 || n%2 != n/2%2 && has_alternating_bits(n/2)

//return Integer.toBinaryString(n ^ n/2).matches("1+");



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Number with Alternating Bits.
//Memory Usage: 6.1 MB, less than 24.60% of C++ online submissions for Binary Number with Alternating Bits.
    bool lt0693a(int n)
    {
        int lst = n % 2;
        n /= 2;
        while (n > 0)
        {
            int t2 = n % 2;
            n /= 2;
            if (t2 == lst)
                return false;
            lst = t2;
        }
        return true;
    }

};

int main()
{

    LT0693 lt;


    return 0;
}
