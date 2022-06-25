
#include "../header/myheader.h"

class LT2310
{
public:

    // D D

    // dp...不过很慢。


    // 不清楚通过率为什么这么低。。
//Runtime: 0 ms, faster than 100.00 % of C++ online submissions for Sum of Numbers With Units Digit K.
//Memory Usage : 5.8 MB, less than 81.14 % of C++ online submissions for Sum of Numbers With Units Digit K.
    int lt2310a(int num, int k)
    {
        if (num == 0)
            return 0;

        //int mnsum = k;
        for (int i = 1; i <= 10; ++i)
        {
            if (num % 10 == (k * i) % 10)
            {
                if (k * i <= num)
                    return i;
                else
                    return -1;
            }
        }
        return -1;
    }

};

int main()
{

    LT2310 lt;

    //myvi v = { 0,7 };

    //myvi v = { 37,2 };

    myvi v = { 58,9 };

    cout << lt.lt2310a(v[0], v[1]) << endl;

    return 0;
}
