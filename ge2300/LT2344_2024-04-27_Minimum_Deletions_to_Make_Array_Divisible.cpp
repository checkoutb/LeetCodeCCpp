
#include "../header/myheader.h"

class LT2344
{
public:

    // D D

    // __gcd




// Runtime
// 108ms
// Beats72.30%of users with C++
// Memory
// 90.32MB
// Beats98.92%of users with C++
    int minOperations(vector<int>& nums, vector<int>& numsDivide)
    {
        int t2 = numsDivide[0];
        for (int i : numsDivide)
        {
            t2 = gcda1(max(t2, i), min(t2, i));
        }

        std::ranges::sort(nums);

        for (int i = 0; i < nums.size() && nums[i] <= t2; ++i)
        {
            if (t2 % nums[i] == 0)
            {
                return i;
            }
        }
        return -1;
    }

    int gcda1(int a, int b)
    {
        return b == 0 ? a : gcda1(b, a % b);
    }
};

int main()
{

    LT2344 lt;


    return 0;
}
