
#include "../header/myheader.h"

class LT1954
{
public:

// D D

// details 没有足够的样本。。


//        long long l = 1,  r = 100000, m;
//        while (l < r) {
//            m = (l + r) / 2;
//            if (m * m * m * 4 + m * m * 6 + m * 2 >= x)
//                r = m;
//            else
//                l = m + 1;
//        }
//        return l * 8;
// 看到 100000, 以为 是 后续加了test case 。。。。
// r 是 右上角的x 。。 所以没有问题。


//        long long a = pow(x * 2, 1.0 / 3);
//        a += a * (a + 1) * (a + 2) / 2 < x;
//        a += a % 2;
//        return a * 4;


//        long long i=1;
//        for(;neededApples>0;i++){
//            neededApples-=3*i*4; // i*4+2*i*4
//            neededApples-=(((2*i)*(2*i-1))/2-(i*(i+1))/2)*8; // summation using (n*(n+1))/2
//        }
//        return (i-1)*8;
// 扩张，每次加一个周长的苹果数量。


//        long r = 0;
//        long total = 0;
//        while (total < neededApples) {
//            r++;
//            total += 12 * r * r;
//        }
//        return r * 8;


//    long long n = 0;
//    while (2 * n * (n + 1) * (1 + 2 * n) < neededApples)
//        ++n;
//    return  n * 8;


//https://oeis.org/A300758



//Runtime: 164 ms, faster than 100.00% of C++ online submissions for Minimum Garden Perimeter to Collect Enough Apples.
//Memory Usage: 6 MB, less than 100.00% of C++ online submissions for Minimum Garden Perimeter to Collect Enough Apples.
// 每个坐标都有一棵， 并且 树上的苹果数量是 下标和。
// 方形土地
// 返回周长
// 二分。。 上限是多少。  Example 3, 10^9 -> 5040, 给个INT_MAX。
// 得是平方。。所以算边长吧， 不，边长得是 奇数。。。 算 右上角的x坐标。
// 22 12 02 12 22
// 21 11 01 11 21
// 20 10 00 10 20
// 21 11 01 11 21
// 22 12 02 12 22
// 对称
// 4 3 2 3 4
// 3 2 1 2 3
// 2 1 0 1 2
// 3 2 1 2 3
// 4 3 2 3 4
// 从中间往外 bfs
// 转45度的正方形。
//
//       2 3 4
// 4 3   1 2 3
// 3 2
// 2 1 0   1 2
//         2 3
// 3 2 1   3 4
// 4 3 2
// 4个。
// INT_MAX 太慢了。本地都看得出卡顿。
//Input
//692631832592697
//Expected
//445896
    long long lt1954a(long long neededApples)
    {
        long long l = 1;
//        long long r = INT_MAX;
//        long long r = 50400;
        long long r = 545896;
        while (l < r)
        {
            #ifdef __test
//            cout<<l<<", "<<r<<endl;
//            getchar();
            #endif // __test
            long long mid = (l + r) / 2;
            long long sum2 = geta1(mid);
            if (sum2 >= neededApples)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l * 8;
    }


    // t2 == 2
//       2 3 4
// 4 3   1 2 3
// 3 2
// 2 1 0   1 2
//         2 3
// 3 2 1   3 4
// 4 3 2
// 等差的等差。
    long long geta1(long long t2)
    {
        long long a1 = 0;
        for (int i = 1; i <= t2 + 1; ++i)               // 估计INT_MAX慢在这个上。。等差。不需要for。。
        {
            a1 += i;
        }
        long long a2 = a1 + ((t2 - 1) * (t2 + 1));
        long long sum2 = (a1 + a2) * (t2) / 2;
        return sum2 * 4;
    }

};

int main()
{
    vector<long long> v = {1, 13, 1000000000};

    LT1954 lt;

    for (long long ll : v)
        cout<<lt.lt1954a(ll)<<endl;

    return 0;
}
