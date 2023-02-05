
#include "../header/myheader.h"

class LT2528
{
public:

    // D D

    // long long right = accumulate(stations.begin(), stations.end(), 0LL) + k;






    // en 的取值。 全都 long long
    //Runtime313 ms
    //    Beats
    //    67.71 %
    //    Memory66.9 MB
    //    Beats
    //    96.13 %
    long long lt2528a(vector<int>& stations, int r, int k)
    {
        int sz1 = stations.size();
        vector<int> vi(sz1, 0);

        long long st = 0LL, en = 1LL << 35;
        long long ans = 0LL;

        while (st <= en)
        {
            long long md = (st + en) / 2LL;
            bool can = true;
            long long used = 0LL;

            fill(begin(vi), end(vi), 0);

            int idx = 0;    // power station
            long long pw = 0LL;
            for (int i = 0; i < sz1; ++i)
            {
                while (idx < sz1 && idx <= i + r)
                {
                    pw += vi[idx] + stations[idx];
                    ++idx;
                }
                if (pw < md)
                {
                    vi[idx - 1] = md - pw;
                    used += md - pw;
                    pw = md;
                    if (k < used)
                    {
                        can = false;
                        break;
                    }
                }
                if (i >= r)
                {
                    pw -= (vi[i - r] + stations[i - r]);
                }
            }

            if (can)
            {
                ans = md;
                st = md + 1;
            }
            else
            {
                en = md - 1;
            }
        }
        return ans;
    }

};

int main()
{

    LT2528 lt;

    myvi v = { 1,2,4,5,0 };
    int r = 1, k = 2;

    //myvi v = { 4,4,4,4 };
    //int r = 0, k = 3;

    //myvi v = 

    cout << lt.lt2528a(v, r, k) << endl;

    return 0;
}
