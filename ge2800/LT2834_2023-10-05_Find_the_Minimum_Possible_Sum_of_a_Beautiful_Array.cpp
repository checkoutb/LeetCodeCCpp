
#include "../header/myheader.h"

class LT2834
{
public:







//Runtime0 ms
//Beats
//100%
//Memory6.5 MB
//Beats
//77.88%

    // ? jiushi qian jige a.
    int minimumPossibleSum(int n, int target)
    {
        const int MOD = 1e9 + 7;

        int mid = target / 2 + 1;       // min value   delete

        if (mid > n)
        {
            return (1LL * (n + 1) * n / 2) % MOD;
        }

                            // long long ...
        long long t2 = target + n - mid;      // last element's value

        #ifdef __test
        cout<<mid<<", "<<t2<<", "<<target<<endl;
        #endif // __test

        return ((1LL * (mid - 1) * (mid) / 2) % MOD
            + (1LL * (t2 + target) * (t2 - target + 1) / 2 % MOD))% MOD;

    }

};

int main()
{

    LT2834 lt;

    int n{2}, tar{3};

    cout<<lt.minimumPossibleSum(n, tar)<<endl;

    return 0;
}
