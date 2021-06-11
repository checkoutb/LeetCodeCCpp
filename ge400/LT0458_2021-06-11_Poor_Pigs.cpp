
#include "../header/myheader.h"

class LT0458
{
public:

// D

// bucket   0   1   2   3
// pig      -   a   b   a,b
// .............................................



// gg
// example 1 也不知道怎么来的。

// 搞不懂example 2： 4-15-15 怎么会得到2的。
    int lt0458a(int buckets, int minutesToDie, int minutesToTest)
    {
        int pw = minutesToTest / minutesToDie;
//        for (int i = 1; i <= buckets; ++i)
//        {
////            if (std::pow((i + 1), pw) >= buckets)
////            {
////                return i;
////            }
//            // 会死一头。。。
//            // 最好的最差， 每次是等分剩下的桶， 每次都会死一头。 直到猪数量 > 剩下的桶-1, 这样只需要再一次。
//            // 最后一次是 x桶， 那么需要x-1头， 每次死一头，所以 原本有 x-1+pw(-1/0)头。
//            // 只能二分。计算不出来
//        }

        int l = 1;
        int r = buckets;

        while (l < r)
        {
            #ifdef __test
            cout<<l<<", "<<r<<endl;
            getchar();
            #endif // __test
            int mid = (l + r) / 2;
            int tmd = mid;
            int t2 = buckets;
            int cnt = 0;
            while (t2 > 1)
            {
                if (mid == 0)
                    break;
                if (cnt >= pw)
                    break;
                t2 = t2 / (mid + 1) + ((t2 % (mid + 1)) > 0 ? 1 : 0);
//                mid--;      // one pig die
                cnt++;
                #ifdef __test
                cout<<t2<<endl;
                #endif // __test
            }
            #ifdef __test
            cout<<mid<<", "<<cnt<<", "<<t2<<", "<<tmd<<endl;
            #endif // __test
            if (t2 == 1)
            {
//                if (cnt == pw)
//                {
//
//                }
                r = tmd;
            }
            else
            {
                l = tmd + 1;
            }
//            if (mid == 0)
//            {
//                if (t2 == 1)
//                    l = r = tmd;
//                else
//                    l = tmd + 1;
//            }
//            else
//            {
//                if (cnt > pw)
//                {
//                    l = tmd;
//                }
//                else
//                {
//                    r = tmd;
//                }
//            }
//            while (mid + 1 < t2)
//            {
//
//            }
        }

        return l;
    }

};

int main()
{
//    int a{1000},b{15},c{60};  // 5      // ??? 感觉好像是猪足够幸运。。
    int a{4},b{15},c{30};       // 2        // 不，幸运的话，一头就够了。。
//    int a{4},b{15},c{15};         // 我感觉是3, 但是 怎么是2.

    LT0458 lt;

    cout<<lt.lt0458a(a,b,c)<<endl;

    return 0;
}
