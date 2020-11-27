
#include "../header/myheader.h"

class LT1523
{
public:

// D D

//return (high + 1) / 2 - low / 2;


// 800
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count Odd Numbers in an Interval Range.
//Memory Usage: 6.3 MB, less than 18.21% of C++ online submissions for Count Odd Numbers in an Interval Range.
    int lt1523a(int low, int high)
    {
        if (low % 2 == 0)
            low++;
        if (high % 2 == 0)
            high--;
        return (high - low) / 2 + 1;
    }

};

int main()
{

    LT1523 lt;


    return 0;
}
