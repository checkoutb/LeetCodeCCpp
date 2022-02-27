
#include "../header/myheader.h"

class LT2057
{
public:





//Runtime: 22 ms, faster than 38.56% of C++ online submissions for Smallest Index With Equal Value.
//Memory Usage: 21.8 MB, less than 97.85% of C++ online submissions for Smallest Index With Equal Value.
    int smallestEqual(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 10 == nums[i])
                return i;
        }
        return -1;
    }

};

int main()
{

    LT2057 lt;


    return 0;
}
