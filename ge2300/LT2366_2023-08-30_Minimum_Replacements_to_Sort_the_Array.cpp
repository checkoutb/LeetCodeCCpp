

Runtime
100 ms
Beats
56.76%
Memory
54.6 MB
Beats
42.4%

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int sz1 = nums.size();
        long long ans = 0LL;
        int mx = nums[sz1 - 1];
        for (int i = sz1 - 2; i >= 0; --i)
        {
            if (nums[i] > mx)
            {
                if (nums[i] % mx == 0)
                {
                    ans += nums[i] / mx - 1;
                }
                else
                {
                    ans += (nums[i] / mx);
                    mx = nums[i] / (nums[i] / mx + 1);
                }
            }
            else
            {
                mx = nums[i];
            }
        }
        return ans;
    }
};
