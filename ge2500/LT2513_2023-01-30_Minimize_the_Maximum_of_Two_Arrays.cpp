
#include "../header/myheader.h"

class LT2513
{
public:


    // D D

    //int getMax(int cnt, long long d1, long long d2 = 1) {
    //    long long d = lcm(d1, d2);
    //    return cnt + cnt / (d - 1) - (cnt % (d - 1) ? 0 : 1);
    //}
    //int minimizeSet(int d1, int d2, int cnt1, int cnt2) {
    //    return max({ getMax(cnt1, d1), getMax(cnt2, d2), getMax(cnt1 + cnt2, d1, d2) });
    //}




    //Runtime0 ms
    //    Beats
    //    100 %
    //    Memory6 MB
    //    Beats
    //    7.48 %

    int gcda(int a, int b)
    {
        return b == 0 ? a : gcda(b, a % b);
    }
    int lt2513a(int d1, int d2, int c1, int c2)
    {
        long long st = 1LL;
        long long en = INT_MAX;
        long long ans = -1LL;

        int gd = gcda(max(d1, d2), min(d1, d2));
        long long lcm = 1LL * d1 * d2 / gd;
        long long t2, t1, t3;
        while (st <= en)
        {
            long long md = (st + en) / 2;

#ifdef __test
            cout << st << " + " << en << " /2 -> " << md << endl;
#endif

            t1 = md - (md / d1);
            t2 = md - (md / d2);
            //t3 = md - (md / d1) - (md / d2) + (md / lcm);
            t3 = md - (md / lcm);
            if (t1 >= c1 && t2 >= c2 && t3 >= (c1 + c2))
            {
                ans = md;
                en = md - 1;
            }
            else
            {
                st = md + 1;
            }
        }

        return static_cast<int>(ans);

        // will tle.
        //int ans = 1;
        //while (c1 != 0 || c2 != 0)
        //{
        //    
        //}
        //return ans;
    }

};

int main()
{

    LT2513 lt;

    //myvi v = { 2,7,1,3 };
    myvi v = { 2,4,8,2 };

    cout << lt.lt2513a(v[0], v[1], v[2], v[3]) << endl;

    return 0;
}
