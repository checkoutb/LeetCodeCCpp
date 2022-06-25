
#include "../../header/myheader.h"

class LT
{
public:

    // D D



//Runtime: 32 ms, faster than 78.06 % of C++ online submissions for Non - decreasing Array.
//Memory Usage : 27 MB, less than 81.98 % of C++ online submissions for Non - decreasing Array.
    // <=    如果有 a>b 出现，改a，改b。 改a为 a前， 如果还不行，那么就要改b为a.
    // b 和 a前 对比 b>=a前， a=a前； else b=a;
    // 或者，前面有2个比它大的 or 出现2个元素(这2个元素前面有比它大的) 就不行。 bu,4,2,3，， 4>2, 3>2
    bool lta(vector<int>& nums)
    {
        nums.insert(begin(nums), INT_MIN);
        nums.push_back(INT_MAX);
        int sz1 = nums.size();
        bool chg = false;
        for (int i = 2; i < sz1; ++i)
        {
            if (nums[i - 1] > nums[i])
            {
                if (chg)
                    return false;
                chg = true;

                if (nums[i] >= nums[i - 2])
                {
                    ;
                }
                else
                {
                    nums[i] = nums[i - 1];
                }
            }
        }
        return true;
    }

};

int main()
{

    LT lt;

    //myvi v = { 4,2,3 };

    myvi v = { 4,2,1 };

    cout << lt.lta(v) << endl;

    return 0;
}
