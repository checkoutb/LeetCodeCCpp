
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //partial_sum(begin(nums), end(nums), begin(nums));
    //return nums;



//Runtime: 3 ms, faster than 76.46 % of C++ online submissions for Running Sum of 1d Array.
//Memory Usage : 8.5 MB, less than 38.06 % of C++ online submissions for Running Sum of 1d Array.
    vector<int> lta(vector<int>& nums)
    {
        for (int i = 1; i < nums.size(); ++i)
            nums[i] += nums[i - 1];
        return nums;
    }

};

int main()
{

    LT lt;


    return 0;
}
