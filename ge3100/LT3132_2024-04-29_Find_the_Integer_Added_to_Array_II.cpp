
#include "../header/myheader.h"

class LT3132
{
public:

    // D D

    // 应该 第一次 canEqual 就可以返回了。




// Runtime
// 3ms
// Beats100.00%of users with C++
// Memory
// 32.14MB
// Beats100.00%of users with C++
    // remove 2, and add a fixed int
    // 找3个，    nums2的数字必然是存在的， 那么 对比 nums1 的3个就必然可以得到了啊。
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2)
    {
        std::ranges::sort(nums1);
        std::ranges::sort(nums2);

        int ans = INT_MAX;
        if (canEqual(nums1, nums2, nums2[0] - nums1[0]))
        {
            ans = min(ans, nums2[0] - nums1[0]);
        }
        if (canEqual(nums1, nums2, nums2[0] - nums1[1]))
        {
            ans = min(ans, nums2[0] - nums1[1]);
        }
        if (canEqual(nums1, nums2, nums2[0] - nums1[2]))
        {
            ans = min(ans, nums2[0] - nums1[2]);
        }
        return ans;
    }

    bool canEqual(vector<int>& vi, vector<int>& v2, int diff)
    {
        int st1 = 0;
        int st2 = 0;
        while (st1 < vi.size() && st2 < v2.size())
        {
            if (vi[st1] + diff == v2[st2])
            {
                ++st1;
                ++st2;
            }
            else
                ++st1;
        }
        return st2 == v2.size();
    }

};

int main()
{

    LT3132 lt;


    return 0;
}
