
#include "../header/myheader.h"

class LT2962
{
public:

    // D D





    // 实际上，直接把 mx 的下标 放到 数组中，然后 a[i]-a[i-1] * a[i+k+1]-a[i+k]

// Runtime135 ms
// Beats
// 83.22%
// Memory117.2 MB
// Beats
// 82.97%
    long long countSubarrays(vector<int>& nums, int k)
    {
        int mx = *std::max_element(begin(nums), end(nums));
        long long ans = 0LL;

        int st = -1;
        int cnt = 0;
        for (int en = 0; en < nums.size(); ++en)
        {
            if (nums[en] == mx)
            {
                ++cnt;
                if (cnt == k)
                {
                    int t2 = st;
                    st += 1;
                    while (nums[st] != mx)
                    {
                        ++st;
                    }
                    --cnt;
                    ans += 1LL * (st - t2) * (nums.size() - en);
                }
            }
        }

        return ans;
    }

};

int main()
{

    LT2962 lt;


    return 0;
}
