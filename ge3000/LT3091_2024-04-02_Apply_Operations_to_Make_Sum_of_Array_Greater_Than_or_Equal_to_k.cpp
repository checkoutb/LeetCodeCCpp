
#include "../header/myheader.h"

class LT3091
{
public:

    // D D

        // int m = ceil(sqrt(k));
        // return m - 1 + (k - 1) / m;

    // 1-m 用了 m-1 步， m - k 用了 (k+(0-1))/m 步
    // a^2 + b^2 >= 2sqrt(a*b)    a==b is min
    // m-1 == (k-1)/m


// Runtime
// 6ms
// Beats27.55%of users with C++
// Memory
// 7.40MB
// Beats44.58%of users with C++
    // +1...  +x...
    int minOperations(int k)
    {
        int ans = INT_MAX;
        for (int i = 0; i < k; ++i) // +1 's count
        {
            int t2 = i + ((k - i - 1) / (1 + i)) + ((k - i - 1) % (1 + i) != 0);
            ans = min(t2, ans);
        }
        return ans;
    }
};

int main()
{

    LT3091 lt;


    return 0;
}
