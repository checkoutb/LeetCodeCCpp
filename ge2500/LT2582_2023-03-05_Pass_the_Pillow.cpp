
#include "../header/myheader.h"

class LT2582
{
public:

    // D D

    // return n - abs(n - 1 - time % (n * 2 - 2));



    //Runtime0 ms
    //    Beats
    //    100 %
    //    Sorry, there are not enough accepted submissions to show data
    //    Memory6 MB
    //    Beats
    //    100 %
    // 1000
    int lt2582a(int n, int time)
    {
        time %= (n - 1) * 2;

        if (time > n - 1)
        {
            time -= n - 1;
            return n - 1 - time + 1;
        }
        else
        {
            return 1 + time;
        }

    }

};

int main()
{

    LT2582 lt;

    int n = 4;
    int tm = 5;

    cout << lt.lt2582a(n, tm) << endl;

    return 0;
}
