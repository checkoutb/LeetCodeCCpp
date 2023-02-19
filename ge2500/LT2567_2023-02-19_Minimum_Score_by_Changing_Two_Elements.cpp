
#include "../header/myheader.h"

class LT2567
{
public:





    //Runtime108 ms
    //    Beats
    //    44.44 %
    //    Memory34.1 MB
    //    Beats
    //    66.67 %
    // 改low，只需要把 2个元素 设置相等， 是 改 high 的附属。 所以 low 必然0
    int lt2567a(vector<int>& nums)
    {
        int sz1 = nums.size();
        sort(begin(nums), end(nums));

        //if (sz1 <= 3)
        //    return 0;

        return min(min(nums[sz1 - 2] - nums[1], nums[sz1 - 3] - nums[0]), nums[sz1 - 1] - nums[2]);

    }

};

int main()
{

    LT2567 lt;


    return 0;
}
