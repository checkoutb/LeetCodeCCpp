
#include "../header/myheader.h"

class LT0793
{
public:



// Detail
// 二分硬算 某个数!有多少个0。。。
// 上限有 LLONG_MAX, 50亿，100亿，(4LL*K+1) / 5


// discuss
//        int sum[13]={1};
//        for (int i=1; i<13; i++) sum[i]=sum[i-1]*5+1;
//        for (int i=12; i>=0; i--) {
//            if (K/sum[i]==5) return 0;
//            K=K%sum[i];
//        }
//        return 5;
// 10^9 可能一次性跳过最多的是 sum[12]



// 。。 1.5s 是最快的一档。。。。不，没有足够的提交数据来画出分布图。。 估计没有足够数据，就直接是100% ？ 恩，discuss里有40ms的。。
//Runtime: 1492 ms, faster than 100.00% of C++ online submissions for Preimage Size of Factorial Zeroes Function.
//Memory Usage: 6.2 MB, less than 100.00% of C++ online submissions for Preimage Size of Factorial Zeroes Function.

// 5 10
// ...反向求。。根据0，得知5。10的个数，大约确定起始，到下个5/10就结束。
// 。。还有100，1000，10000。。。100有几个0，1000有几个0。
// K / 5
// K <= 10 ^ 9...
// 10 = 5*2   15 = 5*3   1000 = 5*200.
// 感觉必然5或者0。。？
// 20！ 4个0， 25！ 6个0 ，因为 25=5*5。，， 125=5*5*5  50=5*5*2
//  5   10  15  20  25  30  35  40  45  50  55  60  65  70  75  80  85  90  95  100 105 110
//  1   2   3   4   6   7   8   9   10  12  13  14  15  16  17  18  19  20  21  23  25  25
// 每次+1，每隔5次额外+1，每隔25次额外+1，
    int lt0793a(int K)
    {
        int i = 1;
        while (K > 0)
        {
            K -= 1;
            if (i % 5 == 0)
            {
                int j = i;
                while (j > 0 && j % 5 == 0)           // 5*13, need j % 5 == 0
                {
                    j /= 5;
                    K -= 1;
                }
            }
            i++;
        }
        if (K == 0)
            return 5;
        return 0;
    }

};

int main()
{
// 24/44 45-5;        26/44 79-0            21/44 60-0
    vector<int> arr = {0, 5, 45, 79, 60};

    LT0793 lt;

    for (int i : arr)
    {
        cout<<lt.lt0793a(i)<<endl;
    }

    return 0;
}
