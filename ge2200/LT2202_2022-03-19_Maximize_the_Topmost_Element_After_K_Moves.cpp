
#include "../header/myheader.h"

class LT2202
{
public:






//Runtime: 143 ms, faster than 70.53% of C++ online submissions for Maximize the Topmost Element After K Moves.
//Memory Usage: 63.5 MB, less than 68.45% of C++ online submissions for Maximize the Topmost Element After K Moves.
    int lt2202b(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
        if ((sz1 == 1) && (k % 2 == 1))
            return -1;
        if (k <= 1)
            return nums[k];

        if (k > sz1)
            return *max_element(begin(nums), end(nums));

        int mx = *max_element(begin(nums), begin(nums) + (k - 1));
        int ans = max(k < sz1 ? nums[k] : 0, mx);
        return ans;
    }



// error
// 奇数 k， 如果 sz1 == 1 是 -1 。
// 其他的应该 只是 max( [0, k-1], [k]) 吧。  。 当 k 大于 sz1 也无所谓，可以下面放一个。
    int lt2202a(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
        int ans = 0;
        if ((sz1 == 1) && (k % 2 == 1))
            return -1;

        if (k <= 1)
            return nums[k];

        if (k >= sz1)
            return *max_element(begin(nums), end(nums));

        int mx = *max_element(begin(nums), begin(nums) + (k - 1));
        ans = max(mx, nums[k]);
        return ans;
    }

};

int main()
{

    LT2202 lt;

//    myvi v = {5,2,2,4,0,6};
//    int k = 4;

//    myvi v = {0,1,2};
//    int k = 3;

    myvi v = {35,43,23,86,23,45,84,2,18,83,79,28,54,81,12,94,14,0,0,29,94,
    12,13,1,48,85,22,95,24,5,73,10,96,97,72,41,52,1,91,3,20,22,41,98,70,
    20,52,48,91,84,16,30,27,35,69,33,67,18,4,53,86,78,26,83,13,96,29,15,34,80,16,49};
    int k = 15;     // 94


    cout<<lt.lt2202b(v, k)<<endl;

    return 0;
}
