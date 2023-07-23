
#include "../header/myheader.h"

class LT2787
{
public:


    // D D

//    for (int j = n - v; j >= 0; --j) {



// 234， 当计算到4的时候， 9已经生成一个了， 是 4+(2+3) 。

//Runtime96 ms
//Beats
//85.71%
//Memory7.5 MB
//Beats
//14.29%

    // 300 5
    // mod 1e9+7
    int numberOfWays(int n, int x)
    {
        vector<int> vi(n + 1, 0);
        const int MOD = 1000000007;
        for (int i = 1; i <= n; ++i)
        {
            int t2 = 1;
            for (int j = 0; j < x; ++j)
            {
                t2 *= i;
                if (t2 > n)
                    break;
            }
            if (t2 > n)
                break;

//            for (int j = 1; j <= n; ++j)           // <= , not <
            for (int j = n; j >= 1; --j)
            {
                if (j + t2 > n)
                    continue;

                if (vi[j] > 0)
                {
                    vi[j + t2] += vi[j];
                    vi[j + t2] %= MOD;
                }
            }
            vi[t2] = (vi[t2] + 1) % MOD;
            #ifdef __test
            cout<<i<<endl;
            showVectorInt(vi);
            #endif // __test
        }
        return vi[n];
    }


};

int main()
{

    LT2787 lt;

//    int n = 10;
//    int x = 2;

//    int n = 4;
//    int x = 1;

//    int n = 6;      // 4 ,  1+5,  2+4,  1+2+3, 6
//    int x = 1;

    int n = 9;  // 8,     18,27,36,45, 126, 135, 234, 9
    int x = 1;

    cout<<lt.numberOfWays(n, x)<<endl;

    return 0;
}
