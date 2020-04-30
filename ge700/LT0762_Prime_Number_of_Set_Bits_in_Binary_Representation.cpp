
#include "../header/myheader.h"

class LT0762
{

    int cnt1[8] = {2,3,5,7,11,13,17,19};

public:



// discuss
// StefanPochmann
//    while (L <= R)
//        count += 665772 >> __builtin_popcount(L++) & 1;


//        for (int i = l; i <= r; i++) {
//            int bits = 0;
//            for (int n = i; n; n >>= 1)
//                bits += n & 1;
//            cnt += primes.count(bits);
//        }
// ...

// detail
// 基本都是遍历L->R，判断数值是否符合。  __builtin_popcount


//Runtime: 1236 ms, faster than 5.10% of C++ online submissions for Prime Number of Set Bits in Binary Representation.
//Memory Usage: 6 MB, less than 100.00% of C++ online submissions for Prime Number of Set Bits in Binary Representation.
// 2^20 > 10^6   2,3,5,7,11,13,17,19.
    int lt0762a(int L, int R)
    {
        int ans = 0;
        for (int cnt : cnt1)
        {
            ans += dfsa1(cnt - 1, 1, L, R);
        }
        return ans;
    }

    int dfsa1(int cnt, int num, int& L, int& R)
    {
        if (num > R)
            return 0;
        if (cnt < 0)
            return 0;
        int ans = 0;
        if (cnt == 0 && num >= L && num <= R)
        {
            ans++;
        }

        num *= 2;
        ans += (dfsa1(cnt, num, L, R) + dfsa1(cnt - 1, num + 1, L, R));
        return ans;
    }

};

int main()
{

    int L = 10, R = 15;

    LT0762 lt;

    cout<<lt.lt0762a(L, R)<<endl;

    return 0;
}
