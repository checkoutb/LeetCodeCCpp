
#include "../header/myheader.h"

class LT2909
{
public:




// Runtime112 ms
// Beats
// 81.74%
// Memory78.1 MB
// Beats
// 88.53%
    // there is a smaller in prefix and a smaller in suffix
    int minimumSum(vector<int>& nums)
    {
        size_t sz1{nums.size()};
        vector<int> vi(sz1, 0);
        vi[0] = nums[0];
        for (size_t i = 1; i < sz1; ++i)
        {
            vi[i] = std::min(vi[i - 1], nums[i - 1]);
        }
        int mn = nums[sz1 - 1];
        int ans = INT_MAX;

        for (auto i = sz1 - 1; i >= 1; --i)
        {
            if (nums[i] > vi[i] && nums[i] > mn)
            {
                ans = std::min(ans, nums[i] + mn + vi[i]);
            }
            else
            {
                mn = std::min(mn, nums[i]);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }

};

int main()
{

    LT2909 lt;


    return 0;
}














