
#include "../header/myheader.h"

class LT2289
{
public:


    // g



    // i-1 > i,  remove i
    // 前面有更大的， 且 本序列 是 上升的 ？  序列上升，那么 每次只能 删除一个。 前面有更大的， 最终要被删完。
    // 只要一次， 下降序列 就全部 杀光了。
    // 如果 1000, 2,3,4,5, 2,3,4,5,6,7,8
    //  1000, 4,5,6,7, 2,3,4,5,6,7,8,9
    // 1000, 2,3,4,5, 4,5,6,7,8,9
    // 所以就是 < 前缀max 的 最长 非下降。？
    // 不， 1000, 7,7,7,7,7,7,7,7,5,6,7,8,9,10,11
    //  1000, 7,7,3,4,5,6,7,8,9
    int totalSteps(vector<int>& nums)
    {
        vector<int> vi;
        vi.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] < nums[i - 1])
            {
                ;
            }
            else
            {
                vi.push_back(nums[i]);
            }
        }
        int ans = 0;
        if (vi.size() == nums.size())
            return ans;

        // bs ?

        int st = 0;
        int en = nums.size();
        while (st <= en)
        {
            int md = (st + en) / 2;
            bool can = cala1(vi, md);
            if (can)
            {
                ans = md;
                en = md - 1;
            }
            else
            {
                st = md + 1;
            }
        }
        return ans + 1;
    }

    bool cala1(vector<int>& vi, int tm)
    {

    }
};

int main()
{

    LT2289 lt;


    return 0;
}
