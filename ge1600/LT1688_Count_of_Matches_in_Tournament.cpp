
#include "../header/myheader.h"

class LT1688
{
public:

// D D

// Just return n-1;



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count of Matches in Tournament.
//Memory Usage: 6.2 MB, less than 75.00% of C++ online submissions for Count of Matches in Tournament.
    int lt1688a(int n)
    {
        int ans = 0;
        while (n > 1)
        {
            ans += n / 2;
            n = n / 2 + n % 2;
        }
        return ans;
    }

};

int main()
{
    myvi v = {7,14};

    LT1688 lt;

    for (int i : v)
        cout<<lt.lt1688a(i)<<endl;

    return 0;
}
