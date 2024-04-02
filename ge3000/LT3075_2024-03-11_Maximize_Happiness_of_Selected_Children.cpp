
#include "../header/myheader.h"

class LT3075
{
public:




// Runtime
// 230ms
// Beats42.86%of users with C++
// Memory
// 108.82MB
// Beats28.57%of users with C++
    long long maximumHappinessSum(vector<int>& happiness, int k)
    {
        std::sort(std::rbegin(happiness), std::rend(happiness));
        long long ans = 0LL;

        for (int i = 0; i < k; ++i)
        {
            if (happiness[i] > i)
            {
                ans += happiness[i] - i;
            }
            else
                break;
        }

        return ans;
    }
};

int main()
{

    LT3075 lt;


    return 0;
}
