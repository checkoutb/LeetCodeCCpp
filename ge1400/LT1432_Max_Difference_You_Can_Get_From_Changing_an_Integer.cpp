
#include "../header/myheader.h"

class LT1432
{
public:


// D D






//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Max Difference You Can Get From Changing an Integer.
//Memory Usage: 6.4 MB, less than 19.46% of C++ online submissions for Max Difference You Can Get From Changing an Integer.
// mn
// 123456   923456  103456
// error.... 始终是对 num操作，  第二步的操作对象也是 num， 不是 第一步的结果。
// 9888   9999 1111
//        9888

// 1222  1000 9000    8000
//     1111  9999       8888
    int lt1432a(int num)
    {
        int mx1 = num, mn1 = num;
        int t = num;
        vector<int> v;
        while (num > 0)
        {
            v.push_back(num % 10);
            num /= 10;
        }
        int mxchg = -1;
        int mnchg = v[v.size() - 1] == 1 ? -1 : v[v.size() - 1];
        int mnt = v[v.size() - 1] == 1 ? 0 : 1;
        for (int i = v.size() - 1; i >= 0; --i)
        {
            if (mxchg == -1 && v[i] != 9)
            {
                mxchg = v[i];
            }
//            if (i == v.size() - 1)
            if (mnchg == -1 && v[i] != 0 && (i != v.size() - 1) && v[i] != v[v.size() - 1])
            {
                mnchg = v[i];
            }
        }
        if (mxchg != -1)
        {
            mx1 = 0;
            for (int i = v.size() - 1; i >= 0; --i)
            {
                mx1 *= 10;
                if (v[i] == mxchg)
                    mx1 += 9;
                else
                    mx1 += v[i];
            }
        }
        if (mnchg != -1)
        {
            mn1 = 0;
            for (int i = v.size() - 1; i >= 0; --i)
            {
                mn1 *= 10;
                mn1 += (v[i] == mnchg ? mnt : v[i]);
            }
        }
//        cout<<mx1<<" - "<<mn1<<" , "<<mnchg<<" - "<<mnt<<endl;
//        mn1 = min(mn1, t);
        return mx1 - mn1;
//        int mn2 = 0;
//        for (int i = v.size() - 1; i >= 0; --i)
//        {
//            mn2 *= 10;
//            int val = v[i] == mxchg ? 9 : v[i];
//            mn2 += val == 9 ? 1 : val;
//        }
//        int mx2 = 0;
//        for (int i = v.size() - 1; i >= 0; --i)
//        {
//            mx2 *= 10;
//            int val = v[i] == mnchg ? 1 : v[i];
//            mx2 += val == 1 ? 9 : val;
//        }
//        return max(mx1 - mn2, mx2 - mn1);
    }

};

int main()
{
    vector<int> v = {555,9,123456,10000,9288,111};

    LT1432 lt;

    for (int i : v)
        cout<<lt.lt1432a(i)<<endl;

    return 0;
}
