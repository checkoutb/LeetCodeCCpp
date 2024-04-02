
#include "../header/myheader.h"

class LT3038
{
public:



// Runtime
// 7ms
// Beats100.00%of users with C++
// Memory
// 20.02MB
// Beats100.00%of users with C++

    int maxOperations(vector<int>& nums)
    {
        int ans = 1;
        const int t2 = nums[0] + nums[1];
        for (int i = 3; i < nums.size(); i += 2)
        {
            if (t2 == nums[i] + nums[i - 1])
                ++ans;
            else
                break;
        }
        return ans;
    }

};

int main()
{

    LT3038 lt;


    return 0;
}
