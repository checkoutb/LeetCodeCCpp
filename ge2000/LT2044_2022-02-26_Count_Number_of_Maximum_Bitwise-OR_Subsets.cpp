
#include "../header/myheader.h"

class LT2044
{
public:

// D D

//    public void dfs(int[] nums, int idx, int mask) {
//        if (mask == target) res++;
//
//        for (int i = idx; i < nums.length; i++)
//            dfs(nums, i + 1, mask | nums[i]);
//    }


//        vector<int> dp(1 << N);
//        for (int n : A) goal |= n;
//        for (int m = 1; m < 1 << N; ++m) {
//            int lowbit = m & -m;
//            dp[m] = dp[m - lowbit] | A[__builtin_ctz(lowbit)];
//            if (dp[m] == goal) ++ans;
//        }
// ？ A 是形参。


//Runtime: 12 ms, faster than 97.27% of C++ online submissions for Count Number of Maximum Bitwise-OR Subsets.
//Memory Usage: 10 MB, less than 32.29% of C++ online submissions for Count Number of Maximum Bitwise-OR Subsets.
// 全 | 最大。 dp？  每次加一个数字进去。
// 加上现有的次数。
    int lt2044a(vector<int>& nums)
    {
        map<int, int> map2;
        for (int i = 0; i < nums.size(); i++)
        {
            unordered_map<int, int> tmap;
            for (auto& p : map2)
            {
                tmap[p.first | nums[i]] += p.second;
            }
            for (auto& p : tmap)
            {
                map2[p.first] += p.second;
            }
            map2[nums[i]]++;
        }
        return rbegin(map2)->second;
    }

};

int main()
{

    LT2044 lt;

//    myvi v = {2,2,2,};
    myvi v = {3,2,1,5};

    cout<<lt.lt2044a(v)<<endl;


    return 0;
}
