
#include "../header/myheader.h"

class LT1870
{
public:

// D D


//    while (l < r) {
//        int m = (l + r) / 2, time = 0;
//        for (int i = 0; i < dist.size() - 1; ++i)
//            time += dist[i] / m + (dist[i] % m ? 1 : 0);
//        if ((double)dist.back() / m + time <= hour)
//            r = m;
//        else
//            l = m + 1;
//    }


//        while (lo < hi)
//        {
//            mi = (lo + hi) / 2;
//            if (canReachInTime(dist, hour, mi))
//                hi = mi;
//            else
//                lo = mi + 1;
//        }
//    bool canReachInTime(const vector<int>& dist, const double hour, int speed)
//    {
//        double time = 0;
//        for (int i = 0; i < dist.size() - 1; ++i)
//            time += ((dist[i] + speed - 1) / speed);
//
//        time += ((double)dist.back()) / speed;
//        return time <= hour;
//    }


//        while(beg <= end){
//            mid = (beg+end)/2;
//            for(int i = 0;i < n-1;i++)
//                sum += ceil(double(dist[i])/mid);
//            sum += double(dist[n-1])/mid;
//            if(sum > hr)
//                beg = mid+1;
//            else
//                speed = mid, end = mid-1;
//            sum = 0;
//        }


//Runtime: 396 ms, faster than 29.22% of C++ online submissions for Minimum Speed to Arrive on Time.
//Memory Usage: 101.5 MB, less than 10.86% of C++ online submissions for Minimum Speed to Arrive on Time.
// 一堆条件，找数字， 二分。
    int lt1870a(vector<int>& dist, double hour)
    {
        int st = 1;
        int en = 1E7;
        while (st <= en)
        {
//            double speed = (0.0 + st + en) / 2;
            int speed = (st + en) / 2;
            double tm = 0.0;
            for (int i = 0; i < dist.size() - 1; ++i)
            {
                tm += (dist[i] / speed) + (dist[i] % speed == 0 ? 0 : 1);
            }
            tm += (1.0 * dist[dist.size() - 1] / speed);
            #ifdef __test
            // 后一半全是 2.01 <> 2.01 ... 后续的好像不展现了，但是还是存在的。怎么打印全部小数位？
            printf("%.15f\n", tm);      // haha.  cout好像没有。
            cout<<st<<", "<<en<<", "<<speed<<", "<<tm<<" <> "<<hour<<" ? "<<(tm == hour)<<endl;
            #endif // __test
            if (tm == hour)
//            if (std::abs(tm - hour) < 0.01)
            {
                st = speed;
                en = st - 1;
            }
            else if (tm > hour)
            {
                st = speed + 1;
            }
            else
            {
                en = speed - 1;
            }
        }
        return st > 1E7 ? -1 : st;
    }

};

int main()
{
//    myvi v = {1,3,2};
//    double h = 6;

//    myvi v = {1,3,2};
//    double h = 2.7;
//    double h = 1.9;

    myvi v = {1,1,100000};      // 10000000
    double h = 2.01;


    LT1870 lt;

    cout<<lt.lt1870a(v, h)<<endl;

    return 0;
}
