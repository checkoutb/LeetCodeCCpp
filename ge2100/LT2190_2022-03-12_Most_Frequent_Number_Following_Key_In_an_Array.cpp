
#include "../header/myheader.h"

class LT2190
{
public:

// D D

//    int cnt[1001] = {}, res = 0;
//    for (int i = 1; i < nums.size(); ++i)
//        if (nums[i - 1] == key && ++cnt[nums[i]] > cnt[res])
//            res = nums[i];
//    return res;


//Runtime: 15 ms, faster than 54.98% of C++ online submissions for Most Frequent Number Following Key In an Array.
//Memory Usage: 12.8 MB, less than 30.01% of C++ online submissions for Most Frequent Number Following Key In an Array.
    int lt2190a(vector<int>& nums, int key)
    {
//        unordered_set<int> set2;
        unordered_map<int, int> map2;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i - 1] == key)
            {
                map2[nums[i]]++;
            }
        }
        int mx = -1;
        int mxcnt = -1;
        for (auto& [k, v] : map2)
        {
            if (v > mxcnt)
            {
                mx = k;
                mxcnt = v;
            }
        }
        return mx;
    }

};

int main()
{

    LT2190 lt;


    return 0;
}
