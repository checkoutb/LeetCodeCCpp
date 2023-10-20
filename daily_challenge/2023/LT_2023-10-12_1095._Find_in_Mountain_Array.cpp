
#include "../../header/myheader.h"

class LT
{
public:

// D D






//    Runtime6 ms
//    Beats
//    44.79%
//    Memory7.5 MB
//            Beats
//    14.97%
    // <, not <= .
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int len = mountainArr.length();
        int mxi = dfsa1(mountainArr, len);

        int t2 = dfsa2(mountainArr, 0, mxi, target);
        if (t2 != -1)
            return t2;
        return funa3(mountainArr, mxi + 1, len - 1, target);
    }

    // down
    int funa3(MountainArray &ma, int st, int en, int target)
    {
        while (st <= en)
        {
            int md = (st + en) / 2;
            int t2 = ma.get(md);
            if (t2 == target)
            {
                return md;
            }
            else if (t2 < target)
            {
                en = md - 1;
            }
            else
            {
                st = md + 1;
            }
        }
        return -1;
    }

    // up
    int dfsa2(MountainArray &ma, int st, int en, int target)
    {
        while (st <= en)
        {
            int md = (st + en) / 2;
            int t2 = ma.get(md);
            if (t2 == target)
            {
                return md;
            }
            else if (t2 < target)
            {
                st = md + 1;
            }
            else
            {
                en = md - 1;
            }
        }
        return -1;
    }

    // find max value
    int dfsa1(MountainArray &ma, int len)
    {
        int st = 0;
        int en = len - 1;
        while (st < en)
        {
            int md = (st + en) / 2;
            int md1 = md + 1;
            int t2 = ma.get(md);
            int t3 = ma.get(md1);
            if (t2 < t3)
            {
                st = md1;
            }
            else
            {
                en = md;
            }
        }
        return st;
    }

//    int divide(int st, int en, MountainArray &ma, int mn, int mx, int target)
//    {
//        if (mn > target || mx < target)
//            return INT_MAX;
//        if (st > en)
//            return INT_MAX;
//
//        int md = (st + en) / 2;
//        int t2 = ma.get(md);
//        int ans = INT_MAX;
//        if (t2 >= target)
//        {
//            int t3 = divide(st, md - 1, ma, mn, t2, target);
//            ans = min(t2, t3);
//        }
//        else
//        {
//            if (md + 1 <= en)
//            {
//                int t3 = ma.get(md + 1);
//                if (t3 > t2)
//                {
//
//                }
//            }
//        }
//        return ans;
//    }

};

int main()
{

    LT lt;

    cout<<"1"<<endl;

    return 0;
}
