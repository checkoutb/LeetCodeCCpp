
#include "../header/myheader.h"

class LT2119
{
public:

// D D

//return num == 0 || num % 10;



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for A Number After a Double Reversal.
//Memory Usage: 5.9 MB, less than 20.40% of C++ online submissions for A Number After a Double Reversal.
    bool lt2119a(int num)
    {

        return (num % 10) != 0 || num == 0;

    // 。。。
//        int ans = 0;
//        while (num > 0)
//        {
//            ans = ans * 10 + (num % 10);
//            num /= 10;
//        }
//        return ans;
    }

};

int main()
{

    LT2119 lt;


    return 0;
}
