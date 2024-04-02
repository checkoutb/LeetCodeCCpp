
#include "../header/myheader.h"

class LT3082
{
public:


    // D






    // 和为k，长度szseq 的subseq， 可能出现 2^(sz1 - szseq) 次。
    //      不需要考虑 sz1-szseq 中出现的 其他 subseq



    // n <= 100  k <= 100
    int sumOfPower(vector<int>& nums, int k)
    {




        // const int MOD = 1e9 + 7;
        // // int ans = 0;
        // std::vector<int> vi(k + 1, 0);
        // vi[0] = 1;
        // int sz1 = nums.size();
        // for (int i = 0; i < sz1; ++i)
        // {
        //     for (int j = k; j >= 0; --j)
        //     {
        //         if (vi[j] != 0)
        //         {
        //             if (j + nums[i] <= k)
        //             {
        //                 vi[j + nums[i]] = (vi[j] + vi[j + nums[i]]) % MOD;
        //             }
        //         }
        //     }
        // }
        // // return ans;
        // return vi[k];
    }
};

int main()
{

    LT3082 lt;


    return 0;
}
