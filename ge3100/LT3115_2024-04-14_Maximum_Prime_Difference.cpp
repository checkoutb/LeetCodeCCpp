
#include "../header/myheader.h"

class LT3115
{
public:



// Runtime
// 95ms
// Beats66.67%of users with C++
// Memory
// 107.26MB
// Beats100.00%of users with C++
    int maximumPrimeDifference(vector<int>& nums)
    {
        bool arrb[101] = {false};   // not prime / be divided
        arrb[0] = arrb[1] = true;
        for (int i = 2; i <= 100; ++i)
        {
            if (!arrb[i])
            {
                for (int j = i + i; j <= 100; j += i)
                {
                    arrb[j] = true;
                }
            }
        }
        int st = -1;
        int en = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!arrb[nums[i]])
            {
                st = i;
                break;
            }
        }
        for (int j = nums.size() - 1; j >= 0; --j)
        {
            if (!arrb[nums[j]])
            {
                en = j;
                break;
            }
        }
        return en - st;
    }
};

int main()
{

    LT3115 lt;


    return 0;
}
