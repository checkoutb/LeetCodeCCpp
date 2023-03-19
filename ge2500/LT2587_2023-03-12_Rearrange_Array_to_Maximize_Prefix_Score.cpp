
#include "../header/myheader.h"

class LT2587
{
public:

    // D D

    // sort(nums.rbegin(),nums.rend());

    // sort(begin(n), end(n), greater<>());


    //Runtime164 ms
    //    Beats
    //    100 %
    //    Memory83.2 MB
    //    Beats
    //    25 %
    int lt2587a(vector<int>& nums)
    {
        int sz1 = nums.size();

        std::sort(std::begin(nums), end(nums), std::greater<int>());
        long long sum2 = 0LL;
        for (int i = 0; i < sz1; ++i)
        {
            sum2 += nums[i];
            if (sum2 <= 0LL)
                return i;
        }
        return sz1;
    }

};

int main()
{

    LT2587 lt;


    return 0;
}
