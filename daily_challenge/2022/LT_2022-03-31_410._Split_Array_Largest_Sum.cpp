
#include "../../header/myheader.h"

class LT
{
public:

// D D

//            int m_mid = getNumPartitions(nums, mid);
//            if (m_mid <= m) {
//                high = mid;
//            } else {
//                low = mid + 1;
//            }
//返回 low

//        while (l <= r) {
//            long mid = (l + r)/ 2;
//            if (valid(mid, nums, m)) {
//                r = mid - 1;
//            } else {
//                l = mid + 1;
//            }
//        }
//        return (int)l;


//        while(l<h)
//        {
//            int mid=l+(h-l)/2;
//            ispossible(nums,m,mid)?h=mid:l=mid+1;
//        }
//        return l;


// dp 都很慢。。
// ..速度慢。。。
//Runtime: 1182 ms, faster than 5.88% of C++ online submissions for Split Array Largest Sum.
//Memory Usage: 8.1 MB, less than 13.69% of C++ online submissions for Split Array Largest Sum.
    int ltb(vector<int>& nums, int m)
    {
        int sz1 = nums.size();
        vector<vector<int>> vvi(sz1, vector<int>(m + 1, INT_MAX));
        for (int i = 0; i < sz1; ++i)
        {
            int t2 = nums[i];
            for (int x = i - 1; x >= 0; --x)
            {
                for (int y = m - 1; y >= 1; --y)
                {
                    if (vvi[x][y] != INT_MAX)
                    {
                        vvi[i][y + 1] = min(vvi[i][y + 1], max(t2, vvi[x][y]));
                    }
                }
                t2 += nums[x];
            }
            vvi[i][1] = t2;
        }
        #ifdef __test
        for (myvi& vi : vvi)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test
        return vvi[sz1 - 1][m];
    }


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Split Array Largest Sum.
//Memory Usage: 7.2 MB, less than 43.47% of C++ online submissions for Split Array Largest Sum.
// 分成 m 份， 和的最大值 最小
// split，顺序不变。
// 能二分吧。
// dp： [x][y]  x下标为止，分为y份 的 最小的 最大值。   dp[x][y] = min(dpxy, max(sum[i..x], dp[i][y-1]))   i-1
    int lta(vector<int>& nums, int m)
    {
//        auto [x, y] = std::minmax_element(begin(nums), end(nums));
//        int l = *x, r = *y;
        int l = *max_element(begin(nums), end(nums));
        int r = l * (nums.size());
        int ans = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;          // mx
            int t2 = 0;
            int sum2 = 0;
            for (int n : nums)
            {
                if (sum2 + n > mid)
                {
                    sum2 = n;
                    t2++;
                }
                else
                {
                    sum2 += n;
                }
            }
            t2++;
            if (t2 == m)
            {
                ans = mid;
                r = mid - 1;
            }
            else if (t2 > m)
            {
                l = mid + 1;
            }
            else
            {
                ans = mid;
                r = mid - 1;
            }
        }
        return ans;
    }

};

int main()
{

    LT lt;

    myvi v = {7,2,5,10,8};
    int t = 2;

//    myvi v = {1,2,3,4,5};
//    int t = 2;

//    myvi v = {1,4,4};
//    int t = 3;

    cout<<lt.ltb(v, t)<<endl;

    return 0;
}
