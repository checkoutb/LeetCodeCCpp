
#include "../header/myheader.h"

class LT0473
{
public:


// D && D
// new int[4]...


//Runtime: 56 ms, faster than 48.83% of C++ online submissions for Matchsticks to Square.
//Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Matchsticks to Square.

    bool lt0473a(vector<int>& nums)
    {
        if (nums.size() < 4)
            return false;
        std::sort(nums.begin(), nums.end());
        int sum1 = std::accumulate(nums.begin(), nums.end(), 0);

        if (sum1 % 4 != 0 || nums[nums.size() - 1] > sum1 / 4)
            return false;

        return dfsa1(0, 0, 0, 0, sum1 / 4, nums, nums.size() - 1);
    }

    bool dfsa1(int a1, int a2, int a3, int a4, int tar, vector<int>& nums, int i)
    {
        if (a1 > tar || a2 > tar || a3 > tar || a4 > tar)
        {
            return false;
        }
        if (a1 == tar && a2 == tar && a3 == tar && a4 == tar)
        {
            return true;
        }
        if (dfsa1(a1 + nums[i], a2, a3, a4, tar, nums, i - 1))
            return true;
        if (dfsa1(a1, a2 + nums[i], a3, a4, tar, nums, i - 1))
            return true;
        if (dfsa1(a1, a2, a3 + nums[i], a4, tar, nums, i - 1))
            return true;
        if (dfsa1(a1, a2, a3, a4 + nums[i], tar, nums, i - 1))
            return true;
        return false;
    }

};

int main()
{
    vector<int> v = {1,2,1,2,2};

    LT0473 lt;
    cout<<lt.lt0473a(v)<<endl;

    return 0;
}
