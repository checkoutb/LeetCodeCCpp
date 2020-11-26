
#include "../header/myheader.h"

class LT1492
{
public:

// D D

//    for (int d = 1; d <= n / 2; ++d)
//        if (n % d == 0 && --k == 0)
//            return d;
//    return k == 1 ? n : -1;

//    int d = 1;
//    for (; d * d <= n; ++d)
//        if (n % d == 0 && --k == 0)
//            return d;
//    for (d = d - 1; d >= 1; --d) {
//        if (d * d == n)
//            continue;
//        if (n % d == 0 && --k == 0)
//            return n / d;
//    }
//    return -1;

//Runtime: 4 ms, faster than 9.60% of C++ online submissions for The kth Factor of n.
//Memory Usage: 6.2 MB, less than 83.88% of C++ online submissions for The kth Factor of n.
    int lt1492a(int n, int k)
    {
        int ans = 1;
        k--;
        for (int i = 2; i <= n && k > 0; ++i)
        {
            if (n % i == 0)
            {
                k--;
                ans = i;
            }
        }
        return k == 0 ? ans : -1;
    }

};

int main()
{
//    int n{12}, k{3};
//    int n{7}, k{2};
    int n{200}, k{3};

    LT1492 lt;

    cout<<lt.lt1492a(n, k)<<endl;

    return 0;
}
