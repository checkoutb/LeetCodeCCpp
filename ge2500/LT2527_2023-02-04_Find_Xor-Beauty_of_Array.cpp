
#include "../header/myheader.h"

class LT2527
{
public:

    // D D

    // 。。。。。。？？？？

    //int res{ 0 };
    //for (int i : nums) {
    //    res = res ^ i;
    //}

    // 下标都相同 -> a
    // 2个下标 -> ^ = 0
    // 3个下标 -> (a|b)&c ^ (b|a)&c = 0



    //Runtime147 ms
    //    Beats
    //    5.33 %
    //    Memory39.8 MB
    //    Beats
    //    31.95 %
    int lt2527a(vector<int>& nums)
    {
        int arr[32] = { 0 };        // 1 << idx
        int t2;
        for (int i = 0; i < nums.size(); ++i)
        {
            t2 = nums[i];
            for (int j = 0; j < 32 && t2 > 0; ++j)
            {
                if ((t2 & (1 << j)) != 0)
                {
                    ++arr[j];
                }
            }
        }

        int ans = 0;
        long long cnt = 1LL * (nums.size()) * (nums.size()) * (nums.size());
        long long cnt2;
        long long cnt22 = 1LL * (nums.size()) * (nums.size());
        for (int i = 0; i < 32; ++i)
        {
            //cnt2 = 1LL * arr[i] * (nums.size()) * arr[i];
            cnt2 = 1LL * arr[i] * (cnt22 - 1LL * (nums.size() - arr[i]) * (nums.size() - arr[i]));
            if (cnt2 % 2 == 1)
            {
                ans |= (1 << i);
            }
        }

        return ans;
    }

};

int main()
{

    LT2527 lt;

    //myvi v = { 1,4 };
    myvi v = { 15,45,20,2,34,35,5,44,32,30 };

    cout << lt.lt2527a(v) << endl;

    return 0;
}
