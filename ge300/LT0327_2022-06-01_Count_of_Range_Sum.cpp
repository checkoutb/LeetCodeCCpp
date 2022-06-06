
#include "../header/myheader.h"

class LT0327
{
public:


    // D

    // mergeSort

    //int mid = (low + high) / 2, m = mid, n = mid, count = 0;
    //count = mergeSort(sum, lower, upper, low, mid) + mergeSort(sum, lower, upper, mid, high);
    //for (int i = low; i < mid; i++)
    //{
    //    while (m < high && sum[m] - sum[i] < lower) m++;
    //    while (n < high && sum[n] - sum[i] <= upper) n++;
    //    count += n - m;
    //}
    //inplace_merge(sum.begin()+low, sum.begin()+mid, sum.begin()+high);
    //
    // m，n是mid，且只有++
    // 所以保证for循环中是 跨区的结果。
    // amazing
    // 不不不，有个问题，之前由于 存在负数，所以 prefix sum不是 严格递增的，所以我选择 + INT_MAX 。。。不过，错了。。
    // 那么这里怎么计算：[1,1,-2,1,1], lower=upper=2。因为这里的 m，n 看起来无法多个区间啊。。。不。。能计算的。。
    // [0]+[1] 和 [3]+[4] 会在 下一层/下下层 的mergeSort中计算出来， 本层计算的是 for(0-1) { +[2-4] }. 本层能计算到[0]+[1]+[2]..+[4]


    // gg


    //.... lower upper 不可以直接+的。。
    // 大数，是否应该全部+INT_MAX，转成正数。 正数之后，prefix sum就是 非降， 得+INT_MAX+2，+1是非降，+2是升序 。。 |INT_MAX| + 1 = |INT_MIN|
    // 升序就可以 lower_bound ...
    int lt0327a(vector<int>& nums, int lower, int upper)
    {
        int sz1 = nums.size();
        long add = 2L + INT_MAX;
#ifdef __test
        add = 10;
#endif

        long low = lower + add;
        long up = upper + add;
        vector<long> vl(sz1, 0L);
        vl[0] = nums[0];
        for (int i = 1; i < sz1; ++i)
        {
            vl[i] = vl[i - 1] + nums[i];
        }
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            long l2 = low + nums[i];
            long u2 = up + nums[i];
            vector<long>::iterator ita = std::lower_bound(begin(vl), end(vl), l2);      // >= l2
            auto itb = upper_bound(begin(vl), end(vl), u2);     // > u2
            ans += std::distance(itb, ita);
#ifdef __test
            cout << ans << ", " << i << endl;
#endif
        }
        return ans;
    }

};

int main()
{

    LT0327 lt;

    vector<int> vi{ -2,5,-1 };
    int l{ -2 }, u{ 2 };

    cout << lt.lt0327a(vi, l, u) << endl;

    return 0;
}
