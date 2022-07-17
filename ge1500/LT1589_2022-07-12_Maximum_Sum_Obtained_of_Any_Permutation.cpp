
#include "../header/myheader.h"

class LT1589
{
public:

    // D D

    //vector<int> cnt(nums.size());
    //for (auto& r : requests) {
    //    cnt[r[0]] += 1;
    //    if (r[1] + 1 < nums.size())
    //        cnt[r[1] + 1] -= 1;
    //}
    //partial_sum(begin(cnt), end(cnt), begin(cnt));
    //sort(begin(nums), end(nums));
    //sort(begin(cnt), end(cnt));
    //return inner_product(begin(nums), end(nums), begin(cnt), 0,
    //    [](int res, long long m) { return (res + m) % 1000000007; }, multiplies<long long>());




//Runtime: 880 ms, faster than 22.24 % of C++ online submissions for Maximum Sum Obtained of Any Permutation.
//Memory Usage : 120.6 MB, less than 74.08 % of C++ online submissions for Maximum Sum Obtained of Any Permutation.
    // 最多被查询的就是最大的
    int lt1589a(vector<int>& nums, vector<vector<int>>& requests)
    {
        int sz1 = nums.size();
        sort(rbegin(nums), rend(nums));
        vector<int> vi(sz1 + 1);

        for (vector<int>& v : requests)
        {
            vi[v[0]]++;
            vi[v[1] + 1]--;
        }

        int t2 = 0;
        for (int i = 0; i < vi.size(); ++i)
        {
            t2 += vi[i];
            vi[i] = t2;
        }

        sort(rbegin(vi), rend(vi));
        int ans = 0;
        const int MOD = 1e9 + 7;

        for (int i = 0; i < sz1; ++i)
        {
            if (vi[i] == 0)
                break;
            ans = (ans + 1LL * vi[i] * nums[i] % MOD) % MOD;
        }
        return ans;
    }

};

int main()
{

    LT1589 lt;


    return 0;
}
