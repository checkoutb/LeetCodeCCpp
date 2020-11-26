
#include "../header/myheader.h"
#include <utility>

class LT1480
{
public:

// D D
//partial_sum(begin(nums), end(nums), begin(nums));


//Runtime: 4 ms, faster than 83.26% of C++ online submissions for Running Sum of 1d Array.
//Memory Usage: 8.8 MB, less than 91.70% of C++ online submissions for Running Sum of 1d Array.
// ???... 为什么没有 exchange，  有__exchange。。。
    vector<int> lt1480a(vector<int>& nums)
    {
        for (int sum = 0, i = 0, mxi = nums.size(); i < mxi; ++i)
            nums[i] = (sum = sum + nums[i]);
//            nums[i] = std::__exchange(sum, sum + nums[i]);
        return nums;
    }

};

int main()
{

//    vector<int> v = {1,2,3,4};
    vector<int> v = {3,1,2,10,1};

    LT1480 lt;

    vector<int> ans = lt.lt1480a(v);

    showVectorInt(ans);

    return 0;
}
