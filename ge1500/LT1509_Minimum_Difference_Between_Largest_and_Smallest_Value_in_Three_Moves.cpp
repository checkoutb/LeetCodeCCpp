
#include "../header/myheader.h"

class LT1509
{
public:

// D D

//        partial_sort(nums.begin(), nums.begin() + 4, nums.end());
//        nth_element(nums.begin() + 4, nums.end() - 4, nums.end());
//        sort(nums.end()-5, nums.end());



//Runtime: 272 ms, faster than 5.04% of C++ online submissions for Minimum Difference Between Largest and Smallest Value in Three Moves.
//Memory Usage: 35.7 MB, less than 27.85% of C++ online submissions for Minimum Difference Between Largest and Smallest Value in Three Moves.
    int lt1509a(vector<int>& nums)
    {
        if (nums.size() <= 4)
            return 0;
        sort(begin(nums), end(nums));
        int ans = nums[nums.size() - 1] - nums[0];
        for (int i = 0; i <= 3; ++i)
        {
            ans = min(ans, nums[nums.size() - 4 + i] - nums[i]);
        }
        return ans;
    }

};

int main()
{
//    myvi v = {5,3,2,4};
//    myvi v = {1,5,0,10,14};
    myvi v = {6,6,0,1,1,4,6};
//    myvi v = {1,5,6,14,15};

    LT1509 lt;

    cout<<lt.lt1509a(v);

    return 0;
}
