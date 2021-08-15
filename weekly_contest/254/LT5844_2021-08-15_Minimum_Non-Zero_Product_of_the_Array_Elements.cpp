
#include "../../header/myheader.h"

class LT5844
{
public:






// AC

// 1 10  11 100 101 110 111   交换某一个bit， 任意次数， 最小的积。  minimum non-zero product。。 !0
// 应该是差异越大越好， 毕竟 a^2 + b^2 >= 2ab 只有a=b时，= 。
// 任意swap，是不是 只需要考虑 这个位上有多少个1 多少个0，  应该是一半一半吧。
// 1 * 6 * 1 * 6 * 1 * 6 * 7
// 最后一个(n)不改， 其他的 变成  1  n-1 ?
// 0001 0010 0011 0100
// 0001, 0010, 0011, 0100, 0101, 0110, 0111     1000
// 1001, 1010, 1011, 1100, 1101, 1110, 1111

// 0010   1101        0011 1100      0100 1011   取反 必然有的。  所以 可以 1    2^x-1

// 2^60 次 * 。。。 不可能的。  ok。 2^x...
    int lta(int p)
    {
        long long t2 = 0L;          // 2^p - 1 - 1
        int t4 = p - 1;
        while (t4 >= 1)
        {
            t2 += 1L << t4;
            t4--;
        }
        long long t3 = t2 + 1;      // 2^p - 1
        #ifdef __test
        cout<<t2<<", "<<t3<<" . . "<<(1<<1)<<endl;
        #endif // __test
        long long arr[61] = {0};    // arr[2^index] = t2^(2^index);
        long long cnt = t2 / 2;     // t2 ^ cnt  * t3 == ans
        const int MOD = 1E9 + 7;
        long long ans = t3 % MOD;
        arr[0] = t2 % MOD;          // t2 ^ (2^0)
        arr[1] = arr[0] * arr[0] % MOD;     // t2 ^ (2^1)
        for (int i = 2; i <= p; ++i)
        {
            arr[i] = arr[i - 1] * arr[i - 1] % MOD;
        }
        #ifdef __test
        cout<<cnt<<" ........ "<<endl;
        for (int i = 0; i < 10; ++i)
        {
            cout<<arr[i]<<", ";
        }
        cout<<endl;
        #endif __test
        int mxi = p;
        while (cnt > 0)
        {
            for (int i = mxi; i >= 0; --i)
            {
                if ((1L << i) <= cnt)
                {
                    cnt -= 1L << i;
                    ans = ans * arr[i] % MOD;
                    mxi = i;
                }
            }
        }
        return (int) ans;
    }

};

int main()
{
    myvi v = {1,2,3};

    LT5844 lt;

    for (int i : v)
    {
        cout<<lt.lta(i)<<endl;
        cout<<" ====================== "<<endl;
    }

    return 0;
}
