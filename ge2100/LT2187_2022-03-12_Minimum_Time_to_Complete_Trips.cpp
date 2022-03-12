
#include "../header/myheader.h"

class LT2187
{
public:

// D D


//    long long l = 0, r = LLONG_MAX / time.size();
//    while (l < r) {
//        long long m = (l + r) / 2, trips = 0;
//        for (int t : time)
//            trips += m / t;
//        if (trips < totalTrips)
//            l = m + 1;
//        else
//            r = m;
//    }
//    return l;


//Runtime: 595 ms, faster than 25.99% of C++ online submissions for Minimum Time to Complete Trips.
//Memory Usage: 94.5 MB, less than 8.33% of C++ online submissions for Minimum Time to Complete Trips.
//
    long long lt2187a(vector<int>& time, int totalTrips)
    {
        long long l = 0, r = 1LL * time[0] * totalTrips;
        long long ans = 0LL;
        while (l <= r)
        {
            long long mid = (l + r) / 2;
            long long t2 = 0;
            for (int i = 0; i < time.size(); ++i)
            {
                t2 += mid / time[i];
            }
            #ifdef __test
            cout<<l<<"m "<<mid<<", "<<r<<", "<<t2<<endl;
            #endif // __test

            if (t2 > totalTrips)
            {
                ans = mid;
                r = mid - 1;
            }
            else if (t2 == totalTrips)
            {
                ans = mid;
                r = mid - 1;
//                l++;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }

};

int main()
{

    LT2187 lt;

    myvi v = {3,3,8};
    int t2 = 6;

//    myvi v = {8,9,10,2};
//    int t2 = 2;

    cout<<lt.lt2187a(v, t2)<<endl;

    return 0;
}
