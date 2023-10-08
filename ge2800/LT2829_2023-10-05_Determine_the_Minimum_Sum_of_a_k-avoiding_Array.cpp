
#include "../header/myheader.h"

class LT2829
{
public:

// D D

//        int middle = k/2;
//        if(n <= middle){
//            return (1 + n) * n / 2;
//        }
//        int ans = (1 + middle) * middle / 2;
//        ans += (k + k + (n - middle - 1)) * (n - middle) / 2;
//        return ans;


//Runtime4 ms
//Beats
//88.1%
//Memory6.3 MB
//Beats
//83.3%

    // 1,2,3,...n
    // remove k-1, k-2, k-3  .. k-((k+1)/2)
    // add n+1,n+2...n+(((k+1)/2))
    // n+1 - (k-1) == n-k+2
    //
    // 5 - 2
    // 4 - 1        2 is distinct    k/2 is distinct
    // (k + 1) / 2 - 1
    // k-1/2
    //
    // 5 9   1,2,3,4,9
    //
    // 1 2 3 4 5
    // remove [k/2+1 .. k-1]
    int minimumSum(int n, int k)
    {
        int ans = n * (1 + n) / 2;
        int t2 = (k - 1) / 2;
        t2 = k / 2 + 1;

        if (t2 > n)
            return ans;

        int t3 = min(k-1, n);               // ...

        #ifdef __test
        cout<<ans<<", "<<t2<<", "<<t3<<endl;
        #endif // __test

        n = max(n, k - 1);              // ...

        ans -= (t3 - t2 + 1) * (t2 + t3) / 2;
        ans += (t3 - t2 + 1) * (n + 1 + n + t3 - t2 + 1) / 2;
        return ans;
    }
};

int main()
{

    LT2829 lt;

    int n = 22;
    int k = 25;

    cout<<lt.minimumSum(n,k)<<endl;

    return 0;
}
