
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
    // ��low��ֻ��Ҫ�� 2��Ԫ�� ������ȣ� �� �� high �ĸ����� ���� low ��Ȼ0
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
