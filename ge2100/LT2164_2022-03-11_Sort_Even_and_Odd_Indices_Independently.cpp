
#include "../header/myheader.h"

class LT2164
{
public:

// D D


//1 <= nums[i] <= 100




//Runtime: 7 ms, faster than 81.59% of C++ online submissions for Sort Even and Odd Indices Independently.
//Memory Usage: 11.9 MB, less than 93.19% of C++ online submissions for Sort Even and Odd Indices Independently.
    vector<int> lt2164a(vector<int>& nums)
    {
        int sz1 = nums.size();
        for (int i = 0; i < sz1; i += 2)
        {
            for (int j = i + 2; j < sz1; j += 2)
            {
                if (nums[i] > nums[j])
                {
                    swap(nums[i], nums[j]);
                }
            }
        }
        for (int i = 1; i < sz1; i += 2)
        {
            for (int j = i + 2; j < sz1; j += 2)
            {
                if (nums[i] < nums[j])
                {
                    swap(nums[i], nums[j]);
                }
            }
        }
        return nums;
    }

};

int main()
{

    LT2164 lt;


    return 0;
}
