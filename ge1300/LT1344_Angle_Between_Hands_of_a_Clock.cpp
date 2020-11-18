
#include "../header/myheader.h"

class LT1344
{
public:

// D D

//        double angle = Math.abs(30.0 * hour + 0.5  * minutes - 6 * minutes);
//        return angle <= 180.0 ? angle : 360 - angle;

//        int hr = 60 * h + m;
//        int min = 12 * m;
//        int angle = Math.abs(hr - min);
//        return Math.min(angle, 720 - angle)/2.0;



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Angle Between Hands of a Clock.
//Memory Usage: 6.3 MB, less than 39.26% of C++ online submissions for Angle Between Hands of a Clock.
    double lt1344a(int hour, int minutes)
    {
        double ah = hour * 360 / 12 + (1.0 * minutes * 360 / 60 / 12);
        double am = minutes * 360 / 60;
        double mx = max(ah, am);
        double mn = min(ah, am);
        double t1 = mx - mn;
        double t2 = 360 - (mx - mn);
        return min(t1, t2);
    }

};

int main()
{

    int h{3}, m{15};

    LT1344 lt;

    cout<<lt.lt1344a(h, m);

    return 0;
}
