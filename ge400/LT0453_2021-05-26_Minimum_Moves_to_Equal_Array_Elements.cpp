
#include "../header/myheader.h"

class LT0453
{
public:

// D

// sum + m * (n - 1) = x * n
// x = minNum + m
// 数组和 + m次move * (每次增加的值) = 最终长度 * 宽度          -- 面积相等
// 每次move的时候，最小值必然会增加。 所以  最终长度 = 最小值 + move次数
// sum + m * (n - 1) = (minNum + m) * sz1



// ... 有印象，是面积相等。
    int lt0453a(vector<int>& nums)
    {
        int sz1 = nums.size();
        int t2 = sz1 - 1;
        int sum2 = std::accumulate(begin(nums), end(nums), 0);
        int mx = *std::max_element(begin(nums), end(nums));
        int ans = 0;
        // ans * t2 + sum2 == sz1 * N   N>=max_element
        // budui. 面积可以折叠的。
    }

};

int main()
{

    LT0453 lt;


    return 0;
}
