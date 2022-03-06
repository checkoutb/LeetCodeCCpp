
#include "../header/myheader.h"

class LT2150
{
public:

// D D


//    unordered_map<int, int> m;
//    vector<int> res;
//    for (int n : nums)
//        ++m[n];
//    for (const auto [n, cnt] : m)
//        if (cnt == 1 && m.count(n + 1) == 0 && m.count(n - 1) == 0)
//            res.push_back(n);
//    return res;


//Runtime: 433 ms, faster than 78.05% of C++ online submissions for Find All Lonely Numbers in the Array.
//Memory Usage: 116 MB, less than 97.10% of C++ online submissions for Find All Lonely Numbers in the Array.
    vector<int> lt2150a(vector<int>& nums)
    {
        nums.push_back(-123);
        nums.push_back(INT_MAX);
        sort(begin(nums), end(nums));
        vector<int> ans;
        for (int i = 1; i < nums.size() - 1; ++i)
        {
            if ((nums[i - 1] < nums[i] - 1) && (nums[i + 1] > nums[i] + 1))
                ans.push_back(nums[i]);
        }
        return ans;
    }

};

int main()
{

    LT2150 lt;

    myvi v = {10,6,5,8};

    myvi v2 = lt.lt2150a(v);

    showVectorInt(v2);

    return 0;
}
