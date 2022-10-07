
#include "../header/myheader.h"

class LT2401
{
public:

    // D D

    //int used = 0, j = 0, res = 0;
    //for (int i = 0; i < nums.size(); ++i) {
    //    while ((used & nums[i]) != 0)
    //        used ^= nums[j++];
    //    used |= nums[i];
    //    res = max(res, i - j + 1);
    //}

    // 因为 只需要 在 加 [i] 之前 判断下 是否 已经存在bit， 所以 用 &
    // 而且 bit 本身就 0，1 ， 0代表之前不存在， 1代表之前存在， 所以 可以 ^
    // 


//Runtime: 756 ms, faster than 15.48 % of C++ online submissions for Longest Nice Subarray.
//Memory Usage : 57.1 MB, less than 87.26 % of C++ online submissions for Longest Nice Subarray.
    // 1<<1 & 1<<2 & 1<<3
    int lt2401a(vector<int>& nums)
    {
        int arr[32] = { 0 };
        int ans = 1;
        int sz1 = nums.size();
        int st = 0;
        int cnt2 = 0;

        for (int i = 0; i < sz1; ++i)
        {
            int t2 = nums[i];
            for (int j = 0; j < 32; ++j)
            {
                if (t2 & (1 << j))
                {
                    ++arr[j];
                    if (arr[j] == 2)
                    {
                        cnt2++;
                    }
                }
            }
            while ((st < i - 1) && cnt2 > 0)
            {
                t2 = nums[st];
                for (int j = 0; j < 32; ++j)
                {
                    if (t2 & (1 << j))
                    {
                        --arr[j];
                        if (arr[j] == 1)
                        {
                            cnt2--;
                        }
                    }
                }
                ++st;
            }
            if (cnt2 == 0)
            {
                ans = max(ans, i - st + 1);
            }
        }

        return ans;
    }

};

int main()
{

    LT2401 lt;

    //myvi v = { 1,3,8,48,10 };

    //myvi v = { 3,1,5,11,13 };

    myvi v = { 744437702, 379056602, 145555074, 392756761, 560864007, 934981918, 113312475, 1090, 16384, 33, 217313281, 117883195, 978927664 };


    cout << lt.lt2401a(v) << endl;
    return 0;
}
