
#include "../header/myheader.h"

class LT1674
{
public:




//[20744,7642,19090,9992,2457,16848,3458,15721]
//22891
// 有没有 只改前一半的？ 即  最终的 nums[0]+nums[sz1 - 1], 这个值不会出现在 原数组的任何可能值中？
    int lt1674a(vector<int>& nums, int limit)
    {
        int sz1 = nums.size();
        int ans = sz1;
        unordered_set<int> set2;
        for (int i = 0; i < sz1 / 2; ++i)
        {
            set2.insert(nums[i] + nums[sz1 - i - 1]);
        }
        for (int tar : set2)
        {
            int chg = 0;
            for (int i = 0; i < sz1 / 2; ++i)
            {
                int t2 = funa1(tar, nums[i], nums[sz1 - i - 1], limit);
                if (t2 == -1)
                    goto AAA;
                chg += t2;
                if (chg >= ans)
                    goto AAA;
            }
            ans = chg;
//            ans = min(ans, chg);
            AAA:
            continue;
        }
        return ans;
    }
    int funa1(int tar, int a, int b, int lmt)
    {
        if (tar == a + b)
            return 0;
        if ((a + 1 <= tar && a + lmt >= tar) || (b + 1 <= tar && b + lmt >= tar))
            return 1;
        if (2 <= tar && lmt * 2 >= tar)
            return 2;
        return -1;
    }

};

int main()
{
//    myvi v = {1,2,4,3};
//    int lmt{4};

//    myvi v = {1,2,2,1};
//    int lmt{2};

    myvi v = {1,2,1,2};
    int lmt{2};

    LT1674 lt;

    cout<<lt.lt1674a(v, lmt);

    return 0;
}
