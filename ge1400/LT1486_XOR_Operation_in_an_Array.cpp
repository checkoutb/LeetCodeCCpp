
#include "../header/myheader.h"

class LT1486
{
public:

// D D

//        last = start + 2 * (n - 1)
//        if start % 4 < 2:
//            start = 0
//        else:
//            n -= 1
//        if n % 2 == 0: return start ^ (n & 2)
//        return start ^ last ^ (n & 2)
// py



//int XORforN(int val)
//{
//    switch(val & 3)
//    {
//        case 0:
//            return val;
//        case 1:
//            return 1;
//        case 2:
//            return (val + 1);
//        case 3:
//            return 0;
//    }
//    // printf("\n\tshouldn't reach here!");
//    return 0;
//}
//int xorOperation(int n, int start){
//    return (start & 1 & n) | ((XORforN((start >> 1) + n - 1) ^ XORforN((start >> 1) - 1)) << 1);
//}



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for XOR Operation in an Array.
//Memory Usage: 6.2 MB, less than 80.86% of C++ online submissions for XOR Operation in an Array.
    int lt1486a(int n, int start)
    {
        int ans = start;
        for (int i = 1; i < n; ++i)
        {
            ans ^= (start + 2 * i);
        }
        return ans;
    }

};

int main()
{

    LT1486 lt;


    return 0;
}
