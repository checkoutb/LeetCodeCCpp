
#include "../header/myheader.h"

class LT0457
{
public:

// d && d:
// 快慢指针。。。不成环的时候元素设置为0。。while代替dfs。


//Runtime: 1048 ms, faster than 5.09% of C++ online submissions for Circular Array Loop.
//Memory Usage: 168.6 MB, less than 10.00% of C++ online submissions for Circular Array Loop.

    bool lt0457a(vector<int>& nums)
    {
        int sz1 = nums.size();
        if (sz1 <= 1)
            return false;

        set<int> indeies;
        for (int i = 0; i < sz1; i++)
        {
            indeies.insert(i);
            if (dfsa1(nums, indeies, next(i, nums[i], sz1), nums[i] > 0, sz1, i) && indeies.size() > 1)
                return true;
            indeies.clear();
        }

        return false;
    }

    bool dfsa1(vector<int>& nums, set<int>& indeies, int i, bool positive, int sz1, int start)
    {
        if (i == start)
            return true;
        if (indeies.find(i) != indeies.end())
            return false;
        indeies.insert(i);
        if (nums[i] > 0 != positive)
            return false;

        return dfsa1(nums, indeies, next(i, nums[i], sz1), positive, sz1, start);
    }

    int next(int i, int v, int sz1)
    {
        return (i + v % sz1 + sz1) % sz1;
    }
};

int main()
{
    vector<int> n = {2,-1,1,2,2};
//    vector<int> n = {-2,1,-1,-2,-2};
//    vector<int> n = {-1,2};
//    vector<int> n = {3,1,2};

    LT0457 lt;
    cout<<"result : "<<lt.lt0457a(n)<<endl;

    return 0;
}
