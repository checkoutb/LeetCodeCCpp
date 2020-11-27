
#include "../header/myheader.h"

class LT1508
{
public:

// D D

// priority_queue
//            if (i >= left)
//                res = (res + sum) % kMod;
//            if (index + 1 < n)
//                q.push({sum + nums[index + 1], index + 1});
// 400ms 左右。


// 暴力是660ms 左右。
//Runtime: 24 ms, faster than 97.24% of C++ online submissions for Range Sum of Sorted Subarray Sums.
//Memory Usage: 10.8 MB, less than 82.72% of C++ online submissions for Range Sum of Sorted Subarray Sums.
    int lt1508a(vector<int>& nums, int n, int left, int right)
    {
        int mxele = *max_element(begin(nums), end(nums));
        vector<int> v(mxele * nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i)
        {
            int sum2 = 0;
            for (int j = i; j < nums.size(); ++j)
            {
                sum2 += nums[j];
                v[sum2]++;
            }
        }
        int ans = 0;
        int sz2 = 0;
        int mod = 1E9 + 7;
        right = right + 1 - left;
        for (int i = 1; i < v.size(); ++i)
        {
            int cnt = v[i];
            if (left > 0)
            {
                if (left > cnt)
                {
                    left -= cnt;
                    continue;
                }
                else
                {
                    cnt -= left;
                    left = 0;
                    cnt++;
                }
            }
            if (sz2 + cnt <= right)
            {
                sz2 += cnt;
                ans = (ans + cnt * i % mod) % mod;
            }
            else
            {
                cnt = right - sz2;
                ans = (ans + cnt * i % mod) % mod;
                break;
            }
        }
        return ans;
    }

};

int main()
{

    myvi v = {1,2,3,4};
//    int l{1}, r{5};
//    int l{3}, r{4};
    int l{1}, r{10};

    LT1508 lt;

    cout<<lt.lt1508a(v,1,l,r);

    return 0;
}
