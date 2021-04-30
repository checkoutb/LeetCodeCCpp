
#include "../header/myheader.h"

class LT1109
{
public:

// D

// ......

// 从[0]开始，以后的每个都需要+[2], 从[1]开始,每个都减去[2]
// 只记录 [0]时需要+[0]， [1]是需要-[2].


// : for(0; n) {for (vi) {if vi[0]<i<vi[1]}} 估计也肯定是 超时
// 排序，然后遍历一遍。
// 似乎得 2个数组吧？  一个按[0]排序，  一个按[1]排序。
    vector<int> lt1109b(vector<vector<int>>& bookings, int n)
    {
//        vector<int> ans(n);
//        std::sort(begin(bookings), end(bookings), [](const vector<int>& v1, const vector<int>& v2)
//        {
//            return v1[0] != v2[0] ? v1[0] < v2[0] : v1[1] < v1[1];
//        });
//        int val = 0;
//        int sz1 = bookings.size();
//        for (int i = 0; i < sz1; )
//        {
//            while ((i + 1 < sz1) && bookings[i + 1][0])
//        }
    }

// tle....
    vector<int> lt1109a(vector<vector<int>>& bookings, int n)
    {
        vector<int> ans(n);
        for (vector<int>& vi : bookings)
        {
            for (int i = vi[0] - 1, mx = vi[1], t2 = vi[2]; i < mx; ++i)
            {
                ans[i] += t2;
            }
        }
        return ans;
    }

};

int main()
{
    myvvi vv = {{1,2,10},{2,3,20},{2,5,25}};
    int n{5};

    LT1109 lt;

    myvi v = lt.lt1109a(vv, n);

    showVectorInt(v);

//    for (myvi vi : vv)                // & 引用。
//    {
//        for (int& i : vi)
//        {
//            i = 1111;
//        }
//    }
//
//    for (myvi& vi : vv)
//    {
//        showVectorInt(vi);
//
//    }

    return 0;
}
