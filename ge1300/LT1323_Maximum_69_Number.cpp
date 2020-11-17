
#include "../header/myheader.h"

class LT1323
{
public:

// D D

//string number = to_string(num);


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum 69 Number.
//Memory Usage: 6.2 MB, less than 45.24% of C++ online submissions for Maximum 69 Number.
    int lt1323a(int num)
    {
        int t = 1E4;
        while (t > 0)
        {
            if ((num % (t * 10)) / t == 6)
            {
                num += t * 3;
                break;
            }
            t /= 10;
        }
        return num;
    }

};

int main()
{
//    int n = 9669;
//    int n = 9999;
    int n = 6;

    LT1323 lt;

    cout<<lt.lt1323a(n)<<endl;

    return 0;
}
