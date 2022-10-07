
#include "../header/myheader.h"

class LT2395
{
public:

// D D

    //vector<int> sum;
    //for (int i = 0; i < nums.size() - 1; i++) {
    //    sum.push_back(nums[i] + nums[i + 1]);
    //}
    //sort(sum.begin(), sum.end());

    //unordered_set<int> s;
    //for (int i = 1; i < nums.size(); ++i)
    //    if (!s.insert(nums[i - 1] + nums[i]).second)
    //        return true;


//Runtime: 3 ms, faster than 91.06 % of C++ online submissions for Find Subarrays With Equal Sum.
//Memory Usage : 8 MB, less than 16.11 % of C++ online submissions for Find Subarrays With Equal Sum.
    bool lt2395a(vector<int>& nums)
    {
        int sz1 = nums.size();
        map<int, int> map2;
        int t2;
        for (int i = 1; i < sz1; ++i)
        {
            t2 = nums[i] + nums[i - 1];
            if (map2.find(t2) != map2.end())
            {
                return true;
            }
            map2[t2] = 1;
        }
        return false;
    }

};

int main()
{

    LT2395 lt;


    return 0;
}
