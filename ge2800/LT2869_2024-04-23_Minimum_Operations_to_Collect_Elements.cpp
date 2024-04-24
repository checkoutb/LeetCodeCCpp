
#include "../header/myheader.h"

class LT2869
{
public:




// Runtime
// 6ms
// Beats39.01%of users with C++
// Memory
// 21.42MB
// Beats86.53%of users with C++
    int minOperations(vector<int>& nums, int k)
    {
        bool arr[55] = {false};
        int cnt = 0;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            if (nums[i] <= k && !arr[nums[i]])
            {
                arr[nums[i]] = true;
                ++cnt;
                if (cnt == k)
                    return nums.size() - i;
            }
        }
        return -1;
    }
};

int main()
{

    LT2869 lt;


    return 0;
}
