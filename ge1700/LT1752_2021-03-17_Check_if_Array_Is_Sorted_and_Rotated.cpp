
#include "../header/myheader.h"

class LT1752
{
public:

// D D

//if (A[i] > A[(i + 1) % A.size()] && ++k > 1)



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Check if Array Is Sorted and Rotated.
//Memory Usage: 8.4 MB, less than 47.78% of C++ online submissions for Check if Array Is Sorted and Rotated.
    bool lt1752a(vector<int>& nums)
    {
        bool b2 = nums[nums.size() - 1] > nums[0];         // has decreased
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] < nums[i - 1])
            {
                if (!b2)
                {
                    b2 = true;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }

};

int main()
{

    LT1752 lt;


    return 0;
}
