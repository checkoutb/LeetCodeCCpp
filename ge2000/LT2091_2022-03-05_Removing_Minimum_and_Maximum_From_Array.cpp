
#include "../header/myheader.h"

class LT2091
{
public:

// D D


//    auto [it1, it2] = minmax_element(begin(n), end(n));
//    int i = min(it1, it2) - begin(n), j = max(it1, it2) - begin(n);
//    return min({ j + 1, (int)n.size() - i, i + 1 + (int)n.size() - j });



//Runtime: 198 ms, faster than 69.92% of C++ online submissions for Removing Minimum and Maximum From Array.
//Memory Usage: 88.3 MB, less than 35.38% of C++ online submissions for Removing Minimum and Maximum From Array.
// 2ce, zuoce, youce...
    int lt2091a(vector<int>& nums)
    {
        int mn = nums[0];
        int mx = mn;
        int mni = 0;
        int mxi = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] < mn)
            {
                mn = nums[i];
                mni = i;
            }
            if (nums[i] > mx)
            {
                mx = nums[i];
                mxi = i;
            }
        }
        int tmn = min(mni, mxi);
        int tmx = max(mni, mxi);
        return min(tmx + 1, (int) min(nums.size() - tmn, tmn + 1 + nums.size() - tmx));
//        return min(min(max(mni, mxi), nums.size() - min(mni, mxi)), min());
    }

};

int main()
{

    LT2091 lt;

//    myvi v = {2,10,7,5,4,1,8,6};
//    myvi v = {0,-4,19,1,8,-2,-3,5};
    myvi v = {123};

    cout<<lt.lt2091a(v)<<endl;

    return 0;
}
