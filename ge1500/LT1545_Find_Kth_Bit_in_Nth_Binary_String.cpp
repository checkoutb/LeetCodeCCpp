
#include "../header/myheader.h"

class LT1545
{
public:

// D D

//        int flip = 0, l = (1 << n) - 1;
//        while (k > 1) {
//            if (k == l / 2 + 1)
//                return '0' + (flip ^ 1);
//            if (k > l / 2) {
//                k = l + 1 - k;
//                flip ^= 1;
//            }
//            l /= 2;
//        }
//        return '0' + flip;


//return '0' + (k / (k & -k) >> 1 & 1) ^ (k & 1 ^ 1);


//        if (n == 1) {
//            return '0';
//        }
//        int len = (1 << n) - 1;
//        if (k == len / 2 + 1) {
//            return '1';
//        } else if (k > len / 2 + 1) {
//            return findKthBit(n - 1, len - k + 1) == '0' ? '1' : '0';
//        } else {
//            return findKthBit(n - 1, k);
//        }


//        if (k == 1) return '0';
//
//        int count = 0;
//        while (k > count) count = 2 * count  + 1;
//
//        count >>= 1;
//        if (k == count + 1) return '1';
//
//        k = 2 * count - k + 2;
//        return findKthBit(n, k) == '0' ? '1' : '0';




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find Kth Bit in Nth Binary String.
//Memory Usage: 6.3 MB, less than 77.07% of C++ online submissions for Find Kth Bit in Nth Binary String.
//    S1 = "0"
//    S2 = "011"
//    S3 = "0111001"
//    S4 = "011100110110001"
// a
//   ab rra
// abrra b rr(abrra)
    char lt1545a(int n, int k)
    {
        bool rev = false;
        k--;
        int len = 1;
        int cnt = 1;
        while (cnt++ < n)
        {
            len = len * 2 + 1;
        }
        char ans = '0';
        while (cnt-- > 0)
        {
            #ifdef __test
            cout<<cnt<<", "<<k<<", "<<len<<endl;
            #endif // __test
            if (k == len / 2)
            {
                ans = k == 0 ? '0' : '1';
                break;
            }
            if (k > len / 2)
            {
                k = len - k - 1;
                rev = !rev;
            }
            len /= 2;
        }
        return rev ? (ans == '1' ? '0' : '1') : ans;
    }

};

int main()
{
    int n{3}, k{1};     // 0
//    int n{4}, k{11};        // 1
//    int n{1}, k{1};     // 0
//    int n{2}, k{3};         // 1
//    int n{3}, k{5};     // 0

    LT1545 lt;

    cout<<lt.lt1545a(n,k);

    return 0;
}
