
#include "../header/myheader.h"

class LT2602
{
public:




//Runtime280 ms
//Beats
//79.4%
//Memory77.2 MB
//Beats
//98.66%
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries)
    {
        vector<pair<int, int>> vp(queries.size());
        for (int i = 0; i < queries.size(); ++i)
        {
            vp[i].first = queries[i];
            vp[i].second = i;
        }
        std::sort(begin(vp), end(vp));
        std::sort(begin(nums), end(nums));

        vector<long long> ans(vp.size());

        long long sum2 = std::accumulate(begin(nums), end(nums), 0LL);
        int idx = 0;
        long long sum3 = 0LL;

        for (int i = 0; i < vp.size(); ++i)
        {
            int t2 = vp[i].first;
            while (idx < nums.size() && nums[idx] < t2)
            {
                sum3 += nums[idx];
                sum2 -= nums[idx++];
            }
            ans[vp[i].second] = 1LL * t2 * idx - sum3 + sum2 - 1LL * t2 * (nums.size() - idx);
        }
        return ans;
    }

};

int main()
{

    LT2602 lt;


    return 0;
}
