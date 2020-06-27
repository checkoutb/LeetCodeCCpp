
#include "../header/myheader.h"

class LT0991
{
public:

// D
// y->x   even/2 or odd-1


// .. gg

    int lt0991b(int X, int Y)
    {

    }


// error
// *2, -1
// 4种可能，2^N 大于/小于 X，   2^M 大于或小于 Y。
    int lt0991a(int X, int Y)
    {
        if (Y <= X)
            return X - Y;

        int ans1 = 0;       // xiao xiao
        int ans2 = 0;       // xiao da
        int ans3 = 0;       // da xiao
        int ans4 = 0;       // da da

        int xiaox = 0;
        int dax = 0;
        int xiaoy = 0;
        int day = 0;
        int x1, x2, y1, y2;


        int t2 = 1;
        int i = -1;
        while (true)
        {
            i++;
            if (t2 <= X)
            {
                xiaox = t2;
                x1 = i;
            }
            if (dax == 0 && t2 >= X)
            {
                dax = t2;
                x2 = i;
            }
            if (t2 <= Y)
            {
                xiaoy = t2;
                y1 = i;
            }
            if (day == 0 && t2 >= Y)
            {
                day = t2;
                y2 = i;
                break;
            }
            t2 <<= 1;
        }


//        ans1 = (X - xiaox) + (Y - xiaoy) + y1 - x1;
        ans2 = (X - xiaox) + (day - Y) + y2 - x1;
//        ans3 = (dax - X) + (Y - xiaoy) + y1 - x2;
        ans4 = (dax - X) + (day - Y) + y2 - x2;

        ans1 = INT_MAX;
        ans3 = INT_MAX;

        #ifdef __test
        cout<<xiaox<<", "<<dax<<", "<<xiaoy<<", "<<day<<endl;
        cout<<x1<<", "<<x2<<", "<<y1<<", "<<y2<<endl;
        cout<<ans1<<", "<<ans2<<", "<<ans3<<", "<<ans4<<endl;
        #endif // __test

        int ans = std::min(ans1, min(ans2, min(ans3, ans4)));
        return ans;
    }


};

int main()
{

//    int x = 2, y = 3;
//    int x = 5, y = 8;

    int x = 3, y = 10;

    LT0991 lt;

    cout<<lt.lt0991a(x, y)<<endl;

    return 0;
}
