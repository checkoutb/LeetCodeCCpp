
#include "../header/myheader.h"

class LT2566
{
public:

    // D D

    //int minMaxDifference(int num) {
    //    int min_v = num, max_v = num;
    //    for (int i = 0; i < 10; ++i) {
    //        int lo = 0, hi = 0, mul = 1;
    //        for (int n = num; n; n /= 10) {
    //            bool replace = n % 10 == i;
    //            lo += (replace ? 0 : n % 10) * mul;
    //            hi += (replace ? 9 : n % 10) * mul;
    //            mul *= 10;
    //        }
    //        min_v = min(min_v, lo);
    //        max_v = max(max_v, hi);
    //    }
    //    return max_v - min_v;
    //}



    //Runtime0 ms
    //    Beats
    //    100 %
    //    Memory6.1 MB
    //    Beats
    //    25 %
    int lt2566a(int num)
    {
        vector<int> vi;
        while (num > 0)
        {
            vi.push_back(num % 10);
            num /= 10;
        }

        //std::reverse(begin(vi), end(vi));

        int mn = 0;
        int mx = 0;
        int t2 = 1;
        for (int i = 0; i < vi.size() - 1; ++i, t2 *= 10)
        {
            if (vi[i] != vi[vi.size() - 1])
            {
                mn += vi[i] * t2;
            }
        }

        t2 = 1;
        int val = -1;
        for (int i = vi.size() - 1; i >= 0; --i)
        {
            if (vi[i] != 9)
            {
                val = vi[i];
                break;
            }
        }

        for (int i = 0; i < vi.size(); ++i, t2 *= 10)
        {
            mx += t2 * (vi[i] == val ? 9 : vi[i]);
        }

        return mx - mn;
    }

};

int main()
{

    LT2566 lt;

    int n = 11891;


    cout << lt.lt2566a(n) << endl;

    return 0;
}
