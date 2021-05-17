
#include "../header/myheader.h"

class LT1862
{
public:

// D

//Solution 1: Prefix Sum + Line Sweep

//Solution 2: Fenwick Tree

//Solution 3: Sort
//    for (int i = 0, k = 1; i < nums.size(); i += k) {
//        k = 1;
//        while (i + k < nums.size() && nums[i] == nums[i + k])
//            ++k;
//        auto prev = end(nums);
//        for (long f = max_n / nums[i]; f > 0; --f) {
//            auto it = lower_bound(begin(nums) + i, prev, f * nums[i]);
//            res = (res + k * f * (prev - it)) % 1000000007;
//            prev = it;
//        }
//    }
// 用map<value, count> 能更快一点吗？ 快不了多少， lower_bound 也很快了。

//Solution 4: Sieve




//        for (int i = 0; i < N; ) {
//            long j = i + 1;
//            while (j < N && A[j] == A[j - 1]) ++j; // skip the duplicates of `A[i]`
//            long dup = j - i;
//            ans = (ans + dup * dup % mod) % mod; // the `dup` duplicates add `dup * dup` to the answer
//            while (j < N) {
//                long div = A[j] / A[i], bound = A[i] * (div + 1);
//                long next = lower_bound(begin(A) + j, end(A), bound) - begin(A); // find the first number `A[next] >= A[i] * (div + 1)`
//                ans = (ans + (next - j) * div % mod * dup % mod) % mod; // Each A[t] (j <= t < next) will add `div * dup` to the answer.
//                j = next;
//            }
//            i += dup;
//        }



// tle.
    int lt1862a(vector<int>& nums)
    {
        int ans = 0;
        const int MOD = 1E9 + 7;
        unordered_map<int, int> map2;
        std::sort(begin(nums), end(nums));
        for (int i = 0; i < nums.size(); ++i)
        {
            int val = nums[i];
            if (map2.find(val) != map2.end())
            {
                ans = (ans + map2[val]) % MOD;
                continue;
            }
            else
            {
                int cnt = 1;        // self
                for (int j = i + 1; j < nums.size(); ++j)
                {
                    cnt += (nums[j] / val);
                }
                cnt %= MOD;
                map2[val] = cnt;
                ans = (ans + cnt) % MOD;
                #ifdef __test
//                cout<<val<<", "<<cnt<<endl;
                #endif // __test
            }
        }
        return ans;
    }

};

int main()
{
//    myvi v = {2,5,9};
    myvi v = {7,7,7,7,7,7,7};

    LT1862 lt;

    cout<<lt.lt1862a(v)<<endl;

    return 0;
}
