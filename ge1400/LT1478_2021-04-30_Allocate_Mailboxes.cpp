
#include "../header/myheader.h"

class LT1478
{
public:

// 1 4 6 7
// 0 3 5 6
// 3 0 2 3
// 5 2 0 1
// 中间2家人 中间。

// 1 4 6 7 9
// 3 0 2 3 5    13
// 5 2 0 1 3    11
// 6 3 1 0 2    12

// 1 100 101 102
// 0 99 100 101
// 99 0 1 2         102
// 100 1 0 1        102
// 101 2 1 0

// 那就是 dfs 分组，

// 增加一个mailbox
// 是从 间距最大的 地方切分？ 不
// 1 2 3 4 5 6 7 8   100 103   1个邮箱的情况下肯定是中间， 2个看到是 1-8, 100-103 。 3个呢？
// 还是把 路程最长的切分，并且是从中间切分？ . bu， 如果1,2,3,4,5,6,7,8,9,   有2个邮箱呢。


// 39 / 69  tle.
// dp应该不行吧， 毕竟  加一个house，或者加一个邮箱， 是没有办法基于之前的结果 计算的。
// 难道memo？
// 还是说 有个切分的规则？

// D
// dp。。。

//        for (int k = 1; k <= K; ++k)
//            for (int j = n - 1; j > k - 2; --j)
//                for (int i = k - 2; i < j; ++i) {


    int lt1478a(vector<int>& houses, int k)
    {
        std::sort(begin(houses), end(houses));
        dfsa1(houses, k, 0, 0);
        return ans;
    }
    int ans = INT_MAX;
    void dfsa1(vector<int>& vi, int k, int idx, int sum2)
    {
        if (k < 0)
        {
            return;
        }
        if (sum2 > ans)
            return;
        if (idx >= vi.size())
        {
            ans = min(ans, sum2);
            return;
        }
        for (int i = idx; i < vi.size(); ++i)
        {
            int mid = (idx + i) / 2;
            int sum3 = 0;
            for (int j = idx; j <= i; ++j)
            {
                sum3 += abs(vi[mid] - vi[j]);
            }
            dfsa1(vi, k - 1, i + 1, sum2 + sum3);
        }
    }

};

int main()
{
//    myvi v = {1,4,8,10,20};
//    int k = 3;

//    myvi v = {2,3,5,12,18};
//    int k = 2;

//    myvi v = {7,4,6,1};
//    int k = 1;

    myvi v = {3,6,14,10};
    int k = 4;

    LT1478 lt;

    cout<<lt.lt1478a(v, k)<<endl;

    return 0;
}
