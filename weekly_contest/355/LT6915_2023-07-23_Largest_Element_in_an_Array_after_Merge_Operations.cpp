
#include "../../header/myheader.h"

class LT6915
{
public:



    // AC
    long long maxArrayValue(vector<int>& nums) {
        long long t2 = nums[nums.size() - 1];
        long long ans = t2;
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            if (t2 >= nums[i])
            {
                t2 += nums[i];
            }
            else
            {
                t2 = nums[i];
            }
            ans = max(ans, t2);
        }

        return ans;
    }

};

int main()
{

    LT6915 lt;


    return 0;
}
