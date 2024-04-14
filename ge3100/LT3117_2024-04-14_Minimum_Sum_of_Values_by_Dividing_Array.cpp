
#include "../header/myheader.h"

class LT3117
{
public:




    // g


    // hint1: Let dp[i][j] be the optimal answer to split nums[0..(i - 1)] into the first j andValues.
    int minimumValueSum(vector<int>& nums, vector<int>& andValues)
    {
        int sz1 = nums.size();
        int sz2 = andValues.size();
        vector<vector<int>> vvi(sz1, vector<int>(sz2, INT_MAX));

        vector<int> vi(sz1, INT_MAX);

    }



    // g
    //
    // Accepted 200 Submissions 3.6K Acceptance Rate 5.5%
    // m <= 10
    // dfs 硬算啊。  可能tle， n<=10^4    & 的快速计算。 。。 bit prefix sum
    // 应该是取  满足 andValues 的区间中的 最小值，如果这个最小值是 区间的最后一个 且 前面一个也符合 andValue，那么可能要 往前一位。
    //      不，直接就往前一位。 因为可能 最小值 是后面的 需要的 。  所以不需要 bit prefix sum 来 二分吧。
    //
    // ... 多个 min，。。。
    int minimumValueSum_error(vector<int>& nums, vector<int>& andValues)
    {
        int ans = -1;

        return ans == INT_MAX ? -1 : ans;
    }

    int dfsa1(vector<int>& vi, vector<int>& v2, int viidx, int v2idx, int ans2)
    {
        if (v2idx == v2.size() || viidx == vi.size())
        {
            if (v2idx == v2.size() && viidx == vi.size())
            {
                return ans2;
            }
            else
            {
                return INT_MAX;
            }
        }

        int t2 = vi[viidx];
        int t3 = v2[v2idx];
        int st = -1;
        int en = -1;
        for (int i = viidx; i < vi.size(); ++i)
        {
            t2 &= vi[viidx];
            if (t2 == t3)
            {
                if (st == -1)
                    st = i;
                en = i;
            }
            else if (t2 < t3)
            {
                break;
            }
        }

    }

};

int main()
{

    LT3117 lt;


    return 0;
}
