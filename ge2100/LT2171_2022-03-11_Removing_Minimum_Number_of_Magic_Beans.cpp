
#include "../header/myheader.h"

class LT2171
{
public:

// D D

//long long minimumRemoval(vector<int>& b) {
//    sort(begin(b), end(b));
//    long long remaining = 0, sz = b.size();
//    for (int i = 0; i < sz; ++i)
//        remaining = max(remaining, b[i] * (sz - i));
//    return accumulate(begin(b), end(b), 0LL) - remaining;
//}
// 。。。 排序后， 剩余的就是 以自己的值为边长 * 自己的下标到最后的 矩阵面积。其他的要删掉。
/*

                *
            *   *
        *   *   *
        *   *   *
        *   *   *
    *   *   *   *

*/



//Runtime: 292 ms, faster than 68.46% of C++ online submissions for Removing Minimum Number of Magic Beans.
//Memory Usage: 100.8 MB, less than 48.63% of C++ online submissions for Removing Minimum Number of Magic Beans.
// 变成0 或变成 最小的。
// sort， 然后 这个是最小值，那么小于它的 都变成0， 大于它的 都变成它。 或许 map
    long long lt2171a(vector<int>& beans)
    {
        int sz1 = beans.size();
        sort(begin(beans), end(beans));
        long long sum2 = std::accumulate(begin(beans), end(beans), 0LL);
        long long ans = sum2;
        long long sum3 = 0LL;       // to be 0
        int sum3idx = 0;
        for (int i = 0; i < sz1; ++i)
        {
//            sum3 += beans[i];
            sum2 -= beans[i];
            while ((i + 1 < sz1) && beans[i] == beans[i + 1])
            {
                i++;
                sum2 -= beans[i];
//                sum3 += beans[i];
            }
            while (beans[sum3idx] < beans[i])
            {
                sum3 += beans[sum3idx++];
            }
            ans = min(ans, sum3 + sum2 - 1LL * (sz1 - i - 1) * beans[i]);
        }
        return ans;
    }

};

int main()
{

    LT2171 lt;

//    myvi v = {4,1,6,5};
    myvi v = {2,11,3,2};

    cout<<lt.lt2171a(v)<<endl;

    return 0;
}
