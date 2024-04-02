
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    // int s = (n + 1) * n / 2;
    // return sqrt(s) == int(sqrt(s)) ?  int(sqrt(s)) : -1;




// Runtime
// 0ms
// Beats100.00%of users with C++
// Memory
// 7.33MB
// Beats15.68%of users with C++
    // 1..n
    int pivotInteger(int n)
    {
        int ans = -1;
        int st = 1;
        int en = n;
        while (st <= en)
        {
            int md = (st + en) / 2;
            int t2 = (1 + md) * md / 2;
            int t3 = (md + n) * (n - md + 1) / 2;
            if (t2 == t3)
            {
                ans = md;
                break;
            }
            else if (t2 < t3)
            {
                st = md + 1;
            }
            else
            {
                en = md - 1;
            }
        }
        return ans;
    }

};

int main()
{

    LT lt;


    return 0;
}
