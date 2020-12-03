
#include "../header/myheader.h"

class LT1551
{
public:

// D D

//return n * n / 4;



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Operations to Make Array Equal.
//Memory Usage: 6.1 MB, less than 81.04% of C++ online submissions for Minimum Operations to Make Array Equal.
// 1 3 5 7
    int lt1551a(int n)
    {
        int ans = 0;
        if (n % 2)
        {
            ans = (2 + n / 2 * 2) * (n / 2) / 2;
        }
        else
        {
            ans = -n / 2 + (2 + n / 2 * 2) * (n / 2) / 2;
        }
        return ans;
    }

};

int main()
{
//    int n{3};
    int n{6};

    LT1551 lt;

    cout<<lt.lt1551a(n);

    return 0;
}
