
#include "../../header/myheader.h"

class LT6919
{
public:





    // 最速传说，可惜压轴是一道medium。含金量拉了点。
    // 第一道错了一次， num 和 t 反了。。。

    // 这道题是看了 通过率，感觉有点低，所以选择差分数组，而不是直接算。估计直接算会tle。


    //User Accepted : 317
    //User Tried : 614
    //Total Accepted : 331
    //Total Submissions : 1016
    //Difficulty : Medium


    // AC
    bool lta(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
        vector<int> vi(sz1 + 1, 0);
        int dec = 0;

        for (int i = 0; i <= sz1 - k; ++i)
        {
            dec += vi[i];
            nums[i] -= dec;
            if (nums[i] < 0)
                return false;
            if (nums[i] == 0)
                continue;
            dec += nums[i];
            vi[min(sz1, i + k)] = -nums[i];
        }
        for (int i = sz1 - k + 1; i < sz1; ++i)
        {
            dec += vi[i];
            nums[i] -= dec;
            if (nums[i] != 0)
                return false;
        }
        return true;
    }

};

int main()
{

    LT6919 lt;

    myvi v = { 2,2,3,1,1,0 };
    int k = 3;

    cout << lt.lta(v, k) << endl;

    return 0;
}
