
#include "../header/myheader.h"

class LT2963
{
public:


    // D D

        // int mod=1e9+7, n=nums.size();
        // unordered_map<int, int>e;
        // for(int i=0;i<n;i++)e[nums[i]]=i;
        // int ans=1, last=0;
        // for(int i=0;i<n;i++) {
        //     if(i>last)ans=ans*2%mod;
        //     last=max(last, e[nums[i]]);
        // }return ans;
    // .....







//     Runtime549 ms
// Beats
// 18.24%
// Memory182.5 MB
// Beats
// 20.35%

    // 最下面有一些思路。


    // 值只能出现在一个subarr中。 subarr中可以重复。
    int numberOfGoodPartitions(vector<int>& nums)
    {
        map<int, int> fstmp;    // first appear... index
        map<int, int> lstmp;    // last
        const long long MOD = 1e9 + 7;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (!fstmp.contains(nums[i]))
                fstmp[nums[i]] = i;
            lstmp[nums[i]] = i;
        }

        vector<pair<int, int>> vp;
//         for (map<int, int>::iterator it = fstmp.begin(); it != fstmp.end(); ++it)
//         {
//
//         }
        for (auto [k, v] : fstmp)
        {
            vp.push_back(std::make_pair(v, lstmp[k]));
        }

        sort(begin(vp), end(vp));

        // long long ans = vp[0].first + 1;
        // long long ans = 1LL;
//         int lst = -1;
//         int t2 = 0;
//         for (int i = 0; i < vp.size(); ++i)
//         {
//             ans = (ans * (vp[i].first - lst)) % MOD;
//             t2 = vp[i].second;
//
//             while (i < vp.size() && vp[i].first < t2)
//             {
//                 t2 = max(t2, vp[i].second);
//                 ++i;
//             }
//             lst = t2;
//         }

        long long ans = 1LL;
        int t2 = 0;
        int cnt = 0;
        for (int i = 0; i < vp.size(); )
        {
            t2 = vp[i].second;
            ++i;
            while (i < vp.size() && vp[i].first < t2)
            {
                t2 = max(t2, vp[i].second);
                ++i;
            }
            ++cnt;
        }

        // ??? 知道有cnt 个元素， 有多少种 split方法？
        // 。。是昨天的 Leetcode 的题目 (2954, 感染序列个数) ， rust写的。 用到了 nCr .. 结果 hint 是 2^x
        // 这里也是这种情况， cnt个元素，那么有 (cnt-1)个可以切的间隙， 所以 一刀不切， 切1刀，切2刀，分别就是 nC0, nC1, nC2...
        // 所以这里也是 2^x 次方， 想了下，确实， 这里的 含义是： 这个元素 是不是新的subarr 的头。
        //  由于 第一个元素 必然是 subarr的头，所以指数-1
        // 还有刚才的 快速幂。

        --cnt;
        long long t3 = 2LL;
        while (cnt > 0)
        {
            if (cnt & 1)
            {
                ans = (ans * t3) % MOD;
            }
            cnt >>= 1;
            t3 = (t3 * t3) % MOD;
        }

        return static_cast<int>(ans);
    }

};

int main()
{

    LT2963 lt;

    myvi v = {1,2,4,3};

    cout<<lt.numberOfGoodPartitions(v)<<endl;

    return 0;
}
