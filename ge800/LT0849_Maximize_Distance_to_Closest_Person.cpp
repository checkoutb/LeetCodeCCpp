
#include "../header/myheader.h"

class LT0849
{
public:

// discuss
//        int res = 0, n = seats.size(), last = -1;
//        for (int i = 0; i < n; ++i) {
//            if (seats[i] == 1) {
//                res = last < 0 ? i : max(res, (i - last) / 2);
//                last = i;
//            }
//        }
//        res = max(res, n - last - 1);
//        return res;


//Runtime: 60 ms, faster than 5.10% of C++ online submissions for Maximize Distance to Closest Person.
//Memory Usage: 17.3 MB, less than 5.88% of C++ online submissions for Maximize Distance to Closest Person.
    int lt0849b(vector<int>& seats)
    {
        int last1 = 0;
        int i = 0;
        while (seats[i] == 0)
        {
            i++;
        }
        int mxdis = i;
        if (seats[i] == 0)
        {
            i++;
            last1 = i;
        }
        else
        {
            last1 = i;
        }
        i++;
        while (i < seats.size())
        {
            if (seats[i] == 1)
            {
//            cout<<i<<", "<<last1<<endl;
                int t2 = (i - last1) / 2;
                mxdis = max(mxdis, t2);
                last1 = i;
            }
            i++;
        }
//        cout<<last1<<endl;
        mxdis = max(mxdis, (int) seats.size() - 1 - last1);
        return mxdis;
    }

// error
// 现有的最大距离。
    int lt0849a(vector<int>& seats)
    {
        int mxdis = 0;
        int mxindex = 0;
        int l = 0;
        int r = 0;
        while (seats[r] == 0)
        {
            r++;
        }
        mxdis = r;
        mxindex = l;

        r++;
        l = r;
        while (r < seats.size())
        {
            if (seats[r] == 1)
            {
                if (r - l > mxdis * 2)
                {
                    mxdis = (r - l + 1) / 2;
                    mxindex = (r + l) / 2;
                }
                l = r;
            }
            r++;
        }
        if (r - l > mxdis)
        {
            mxindex = r - 1;
            mxdis = r - l;
        }
        return mxdis;
    }

};

int main()
{

    vector<int> v = {1,0,0,0,1,0,1};
//    vector<int> v = {1,0,0,0};
//    vector<int> v = {0,0,0,1,0};
//    vector<int> v = {0,1};
//    vector<int> v = {0,1,0,1,0};

    LT0849 lt;

    cout<<lt.lt0849b(v)<<endl;

    return 0;
}
