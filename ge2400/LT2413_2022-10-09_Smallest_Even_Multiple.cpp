
#include "../header/myheader.h"

class LT2413
{
public:




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Smallest Even Multiple.
//Memory Usage: 5.9 MB, less than 70.43% of C++ online submissions for Smallest Even Multiple.
    int lt2413a(int n)
    {
        if (n % 2)
        {
            return n * 2;
        }
        else
        {
            return n;
        }
    }

};

int main()
{

    LT2413 lt;


    return 0;
}
