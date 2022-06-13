
#include "../header/myheader.h"

class LT2293
{
public:

    // D D

    //auto mn = [](int a, int b) { return min(a, b); };
    //auto mx = [](int a, int b) { return max(a, b); };
    //function<int(int, int, function<int(int, int)>)> op = [&](int i, int j, function<int(int, int)> f) {
    //    return j - i == 1 ? f(nums[i], nums[j]) : f(op(i, i + (j - i) / 2, mn), op(i + (j - i) / 2 + 1, j, mx));
    //};
    //return nums.size() == 1 ? nums.back() : op(0, nums.size() - 1, mn);





//Runtime: 4 ms, faster than 94.64 % of C++ online submissions for Min Max Game.
//Memory Usage : 9.7 MB, less than 96.01 % of C++ online submissions for Min Max Game.
    // ?
    int lt2293a(vector<int>& nums)
    {
        //return nums[0];

        //return nums.size() == 2 ? min(nums[0], nums[1]) : nums[0];


        int sz1 = nums.size();
        while (sz1 > 1)
        {
            sz1 = nums.size() >> 1;
            for (int i = 0; i < sz1; ++i)
            {
                nums[i] = (i % 2) ? max(nums[i * 2], nums[i * 2 + 1]) : min(nums[i * 2], nums[i * 2 + 1]);
            }
        }
        return nums[0];

    }

};

int main()
{

    LT2293 lt;


    return 0;
}
