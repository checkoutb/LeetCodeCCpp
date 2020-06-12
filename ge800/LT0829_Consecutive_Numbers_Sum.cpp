
#include "../header/myheader.h"

class LT0829
{
public:





// tle. 151 / 170. 933320757
// /2, /3, /4, /5... /(N/2)
// 2个连续数之和必然奇数，4个连续数之和必然偶数，6个奇数，8个偶数
// 奇数个连续数，和的奇偶性 和 中间的数一致。  并且奇数个，必须能整除(N%mid == 0)。
// md，还是得暴力。。。
    int lt0829a(int N)
    {
        int ans = 0;
        int div = 2;
        for (; div <= N / 2 + 1; div++)
        {
            if (div % 2 == 1)
            {
                int t2 = N / div;
                if (t2 * div == N && t2 > div / 2)
                    ans++;
            }
            else
            {
                int t2 = N / div;
                #ifdef __test
                cout<<t2<<", "<<div<<endl;
                #endif // __test
                if (t2 * div + div / 2 == N && t2 >= div / 2)        // (t2 + t2 + 1) / 2 * div
                {
                    ans++;
                }
            }
        }
        return ans + 1;
    }

};

int main()
{

    int n = 3;

    LT0829 lt;

    cout<<lt.lt0829a(n)<<endl;

    return 0;
}
