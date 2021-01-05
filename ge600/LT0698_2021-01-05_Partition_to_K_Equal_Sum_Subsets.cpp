
#include "../header/myheader.h"

class LT0698
{
public:

// D

// 我的是 dfs()+dfs()+dfs()+dfs()， 所以 不够全。
// discuss的是  dfs(dfs(dfs(dfs()))) , 满足以后  dfs内部开一个 dfs。   k 是参数。标记是第几个 dfs。



// error
    bool lt0698a(vector<int>& nums, int k)
    {
        int sum2 = 0;
        int mx = 0;
        for (int& i : nums)
        {
            sum2 += i;
            mx = max(mx, i);
        }
        if (sum2 % k != 0)
            return false;
        int tar = sum2 / k;
        if (mx > tar)
            return false;

        sort(begin(nums), end(nums), std::greater<int>());

        while (k-- > 0)
        {
//            int i = 0;
//            for (; i < nums.size() && nums[i] == -1; ++i)
//                ;
//            if (i == nums.size())
//                return false;
            int i = nums.size() - 1;
            for (; i >= 0 && nums[i] == -1; --i)
                ;
            if (i < 0)
                return false;
            if (dfsa1(nums, i, tar - nums[i]))
            {
                nums[i] = -1;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    bool dfsa1(vector<int>& nums, int idx, int remain)
    {
        if (remain <= 0)
            return remain == 0;
        for (int i = idx; i < nums.size(); ++i)
        {
            if (nums[i] == -1)
                continue;
            if (dfsa1(nums, idx + 1, remain - nums[i]))
            {
                nums[i] = -1;
                return true;
            }
        }
        return false;
    }

};

int main()
{
//    myvi v = {4, 3, 2, 3, 5, 2, 1};
//    int k = 4;

    myvi v = {10,10,10,7,7,7,7,7,7,6,6,6};
    int k = 3;

    LT0698 lt;

    cout<<lt.lt0698a(v, k);

    return 0;
}
