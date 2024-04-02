
#include "../header/myheader.h"

class LT3040
{
public:


    // D D

        // for (int s : unordered_set<int>({nums[0] + nums[1], nums[n - 1] + nums[n - 2], nums[0] + nums[n - 1]})) {
        //     vector<vector<int>> dp(n, vector<int>(n, -1));
        //     r = max(r, get(nums, s, 0, n - 1, dp));
        // }




        // std::vector<std::vector<int>> memoization(len, std::vector<int>(len, 0));
        // int start = 0;
        // int end = len - 1;
        //
        // maxOperations = std::max(maxOperations,
        //         findMaxOpsHelper(nums, start + 2, end, nums[start] + nums[start + 1], memoization) + 1);
        // maxOperations = std::max(maxOperations,
    // [][] is enough
//
//     Using only one dynamic programming (DP) table suffices because the paths corresponding to different previous sum values never collide within the DP table.
    // At any given point where paths might intersect, only one path can pass through, and it will correspond to a specific previous sum value.
    // Consequently, the calculated answer at that point is only relevant for future paths with the same previous sum value.
    // Therefore, a single DP table effectively stores the results for all cases, ensuring accurate memoization and preventing interference between different cases.
// because of this one dp table is suffice
//
    // .. 挺难理解的。 总感觉会有 特例。。



// Runtime
// 1685ms
// Beats16.67%of users with C++
// Memory
// 188.24MB
// Beats50.00%of users with C++

    // remove map2.clear();  AC ...

    // tle...
    int maxOperations(vector<int>& nums)
    {
        std::map<long long, int> map2 {};
        int ans = 0;
        // ans = std::max(dfsa1(nums, 2, nums.size() - 1, map2, ), dfsa1());
        // ans = std::max(ans, dfsa1());
        ans = dfsa1(nums, 2, nums.size() - 1, map2, nums[0] + nums[1]);
        // map2.clear();            // ...
        ans = max(ans, dfsa1(nums, 1, nums.size() - 2, map2, nums[0] + nums[nums.size() - 1]));
        // map2.clear();            // ...
        ans = max(ans, dfsa1(nums, 0, nums.size() - 3, map2, nums[nums.size() - 1] + nums[nums.size() - 2]));
        return ans + 1;
    }

    // [st, en]
    int dfsa1(vector<int>& vi, int st, int en, map<long long, int>& map2, int val)
    {
        if (st >= en)
            return 0;
        long long key = make_key(st, en, val);
        if (map2.contains(key))
        {
            return map2[key];
        }

        int ans = 0;

        if (vi[st] + vi[st + 1] == val)
        {
            ans = std::max(ans, dfsa1(vi, st + 2, en, map2, val) + 1);
        }
        if (vi[st] + vi[en] == val)
        {
            ans = std::max(ans, dfsa1(vi, st + 1, en - 1, map2, val) + 1);
        }
        if (vi[en - 1] + vi[en] == val)
        {
            ans = std::max(ans, dfsa1(vi, st, en - 2, map2, val) + 1);
        }

        map2[key] = ans;
        return ans;
    }

    inline long long make_key(int i, int j, int sum2)
    {
        long long key = i;
        key <<= 11;
        key += j;
        key <<= 12;
        key += sum2;
        return key;
    }

};

int main()
{

    LT3040 lt;

    myvi vi {3,2,1,2,3,4};

    cout<<lt.maxOperations(vi)<<endl;

    return 0;
}
