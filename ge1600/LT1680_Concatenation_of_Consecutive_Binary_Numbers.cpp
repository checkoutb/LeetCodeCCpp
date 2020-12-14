
#include "../header/myheader.h"

class LT1680
{
public:

// D D

//f(n) = (f(n-1) << len(n)) + n

//for (int i = 1; i <= n; ++i) ans = ((ans << (32 - __builtin_clz(i))) % mod + i) % mod;


// tle.
    int lt1680a(int n)
    {
        int ans = 0;
        int mod = int (1E9 + 7);
        stack<int> stk1;
        for (int i = 1; i <= n; ++i)
        {
            int t = i;
            while (t)
            {
                stk1.push(t % 2);
                t >>= 1;
            }
            while (!stk1.empty())
            {
                ans = ((ans << 1) + stk1.top()) % mod;
                stk1.pop();
            }
        }
        return ans;
    }

};

int main()
{

    myvi v = {1,3,12};

    LT1680 lt;

    for (int i : v)
        cout<<lt.lt1680a(i)<<endl;;

    return 0;
}
