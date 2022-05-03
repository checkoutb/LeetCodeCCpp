
#include "../header/myheader.h"

class LT2249
{
public:

// D D

//        for (int i = 0; i <= 200; i++)
//            for (int j = 0; j <= 200; j++) {
//                for (auto& c : circles) {
//                    if ((c[0] - i) * (c[0] - i) + (c[1] - j) * (c[1] - j) <= c[2] * c[2]) {
//                        res++;
//                        break;
// O(1) space


//For a specific dx, since dx*dx+dy*dy <= r*r, then dy*dy <= r*r-dx*dx.
//So we just need to search dy from -sqrt(r*r-dx*dx) to sqrt(r*r-dx*dx)
//for (int dx = -r; dx <= r; dx++)
//{
//	int mxdy = sqrt(r*r-dx*dx)
//	for (int dy = -mxdy; dy <= mxdy; dy++)
//	{ ... }
//}
// 根据 r 和 y，可以直接计算出 x。。



// (y0 - y) + (y0 - y) .....
//Runtime: 371 ms, faster than 100.00% of C++ online submissions for Count Lattice Points Inside a Circle.
//Memory Usage: 22.8 MB, less than 18.18% of C++ online submissions for Count Lattice Points Inside a Circle.
// 圆覆盖的点
// 200 * 200
// 计算圆的"第二象限"
// 没有负数坐标
    int lt2249a(vector<vector<int>>& circles)
    {
//        unordered_map<short, unordered_map<short, bool>> map2;
        int sz1 = circles.size();
        unordered_set<int> set2;

        for (vector<int>& vi : circles)
        {
            int x = vi[0], y = vi[1], r = vi[2];
            int x0 = x - r, y0 = y;
            int rr = r * r;
            while (y0 < (y + r))              // x,y,r are int, so (x,y+r) is 1 point.
            {
//                cout<<" --- "<<((x - x0) * (x - x0) + (y0 - y) + (y0 - y))<<endl;
                while (((x - x0) * (x - x0) + (y0 - y) * (y0 - y)) > rr)                // not if, circle & horizon's tangent point
                {
                    ++x0;
                }
//                cout<<" ---2 "<<((x - x0) * (x - x0) + (y0 - y) * (y0 - y))<<endl;
//                cout<<" ? "<<(x - x0)<<", "<<(y0 - y)<<endl;
                int t2 = x + (x - x0);
                for (int i = x0; i <= t2; ++i)
                {
                    set2.insert(i * 1000 + y0);
                    set2.insert(i * 1000 + (y - (y0 - y)));

//                    if (i == 2 && (y0 == 3 || (y - (y0 - y) == 3)))
//                    {
//                        cout<<i<<" ------------------"<<x0<<", "<<", "<<t2<<",,,"<<y0<<", "<<x<<", "<<y<<", "<<r<<", "<<rr<<endl;
//                    }
// 2,11  6,7 5
// 4 4 32 > 25 ..
                }
//                if (y0 != y)
//                {
//
//                }

                #ifdef __test
                cout<<y0<<", "<<x0<<endl;
                #endif // __test

                ++y0;
            }
            set2.insert(x * 1000 + y + r);
            set2.insert(x * 1000 + y - r);
        }

        # ifdef __test
        unordered_set<int> set3 = getall4test(circles);
        cout<<set2.size()<<", "<<set3.size()<<endl;
        vector<int> diff;
        set<int> set21(begin(set2), end(set2));
        set<int> set31(begin(set3), end(set3));
//        std::set_difference(begin(set21), end(set21), begin(set31), end(set31), std::inserter(diff, begin(diff)));        // ok
//        std::set_difference(begin(set21), end(set21), begin(set31), end(set31), begin(diff));         // error
        std::set_difference(begin(set21), end(set21), begin(set31), end(set31), std::back_inserter(diff));      // ok
        cout<<diff.size()<<endl;
        showVectorInt(diff);
        #endif // __test


        return (int) set2.size();
    }

    unordered_set<int> getall4test(myvvi vv)
    {
        unordered_set<int> set2;
        for (myvi& vi : vv)
        {
            int x = vi[0], y = vi[1], r = vi[2];
            int xst = x - r, xen = x + r, yst = y - r, yen = y + r;
            for (int i = xst; i <= xen; ++i)
            {
                for (int j = yst; j <= yen; ++j)
                {
                    if (((i - x) * (i - x) + (j - y) * (j - y)) <= r * r)
                    {
                        set2.insert(i * 1000 + j);
                    }
                }
            }
        }
        return set2;
    }

};

int main()
{

    LT2249 lt;

//    myvvi vv = {{2,2,1}};
//    myvvi vv = {{2,2,2},{3,4,1}};

    myvvi vv = {{8,9,6},{9,8,4},{4,1,1},{8,5,1},{7,1,1},{6,7,5},{7,1,1},{7,1,1},{5,5,3}};       // 141

    cout<<lt.lt2249a(vv);

    return 0;
}
