
#include "../header/myheader.h"

class LT1856
{
public:


    // D

    // monostack, stack顶就是上一个比自己小的， 那么从它后一个 开始 到现在， min 就是 自己。





    // tle
    // prefix sum, segment tree。。。 不过。。。
    // 而且 即使 segment tree， 依然需要 for for。
    // 感觉应该是 整个数组， 然后 split by 最小的值， 然后 继续按照 次小的值 进行切分。 但是什么时候结束?
    // 还是 for for dp？ 记录[i][j] 范文内的 sum 和 min， 然后 [i][j+1] 就能计算出 sum 和 min 了。 但是也得 for for
    // 还是说 forfor 是正常的？  dp 是上三角
    int lt1856a(vector<int>& nums)
    {
        int64_t ans = 0;
        vector<pair<int64_t, int64_t>> vp;               // <sum, min>
        size_t sz1 = nums.size();
        for (size_t i = 0; i < sz1; ++i)
        {
            vector<pair<int64_t, int64_t>> vp2;

            int val = nums[i];

            for (pair<int64_t, int64_t>& p : vp)
            {
                ans = max(ans, p.first * p.second);
                vp2.emplace_back(std::make_pair(p.first + val, min(p.second, (int64_t) val)));
            }

            vp2.emplace_back(make_pair((int64_t) val, (int64_t) val));

            swap(vp, vp2);
        }
        for (auto& p : vp)
        {
            ans = max(ans, p.first * p.second);
        }
        return ans % 1000000007;
    }

};

int main()
{

    LT1856 lt;

    //myvi v = { 1,2,3,2 };
    //myvi v = { 2,3,3,1,2 };
    myvi v = { 3,1,5,6,4,2 };

    cout << lt.lt1856a(v) << endl;

    return 0;
}
