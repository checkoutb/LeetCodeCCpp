
#include "../header/myheader.h"

class LT1498
{
public:


    // D D

    //vector<int> pows(n, 1);
    //for (int i = 1; i < n; ++i)
    //    pows[i] = pows[i - 1] * 2 % mod;
    //while (l <= r) {
    //    if (A[l] + A[r] > target) {
    //        r--;
    //    }
    //    else {
    //        res = (res + pows[r - l++]) % mod;
    //    }
    //}
    // 预先计算 2的次方。


    //vector<int> pre = { 0, 1 };
    //for (auto i = pre.size(); i <= nums.size(); ++i)
    //    pre.push_back((pre.back() << 1) % mod);
    //sort(begin(nums), end(nums));
    //for (int i = 0, j = nums.size() - 1; i <= j; ++i) {
    //    while (i <= j && nums[i] + nums[j] > target)
    //        --j;
    //    res = (res + pre[j - i + 1]) % mod;
    //}



//Runtime: 253 ms, faster than 19.29 % of C++ online submissions for Number of Subsequences That Satisfy the Given Sum Condition.
//Memory Usage : 47.7 MB, less than 92.46 % of C++ online submissions for Number of Subsequences That Satisfy the Given Sum Condition.
    int lt1498b(vector<int>& nums, int target)
    {
        sort(begin(nums), end(nums));

        int ans = 0;
        const int MOD = 1e9 + 7;
        int en = nums.size() - 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            int t2 = nums[i];
            while (en >= 0 && nums[en] + t2 > target)
                en--;

            if (en < i)
                break;

            int cnt2 = en - i;

            ans = (ans + pow2(cnt2)) % MOD;
        }
        return ans;
    }



    // tle
    // subseq  min+max <= target
    // min == 1 有多少种选择。 1 + { >= 1} = |{x|x>=1}| * |{x|x>=1}| + 1 / 2
    // 确定min==1， 那么max <= target-1,  这些元素 组成的 subseq 是可以的。
    // 重复。。 所以 min==1, max==target-1， 要搜索 {x|x>min and x<max} 。不能==， 然后 乘以 count(min), count(max)
    // min == max
    int lt1498a(vector<int>& nums, int target)
    {
        int ans = 0;
        const int MOD = 1e9 + 7;
        unordered_map<int, int> map2;
        for (int n : nums)
            map2[n]++;

        vector<vector<int>> vvi;
        for (auto& p : map2)
            vvi.push_back({ p.first, p.second });

        //for (int i = 1; i < vvi.size(); ++i)
        //    vvi[i][1] += vvi[i - 1][1];

        sort(begin(vvi), end(vvi));

#ifdef __test
        for (myvi& vi : vvi)
            cout << vi[0] << " - " << vi[1] << endl;
#endif

        for (int i = 0; i < vvi.size(); ++i)
        {
            int n1 = vvi[i][0];
            int cnt1 = vvi[i][1];
            if (n1 > target)
                break;

            if (n1 * 2 <= target)
            {
                //ans = (ans + (1LL * cnt1 * (cnt1 + 1)) / 2) % MOD;
                
                ans = (ans + pow2(cnt1) - 1) % MOD;

                int t2 = 0;
                for (int j = i + 1; j < vvi.size(); ++j)
                {
                    int n2 = vvi[j][0];
                    int cnt2 = vvi[j][1];

                    if ((n1 + n2) > target)
                        break;

                    ans = (ans + (1LL * ((pow2(cnt1) - 1) * (pow2(cnt2) - 1) % MOD) * pow2(t2)) % MOD) % MOD;
#ifdef __test
                    cout << t2 << ".. " << ans << endl;
#endif
                    t2 += cnt2;
                }
            }

#ifdef __test
            cout << i << " ? " << ans << endl;
#endif
        }
        return ans;
    }


    int pow2(int n)
    {
        if (n == 0)
            return 1;

        int orin = n;
        long long ans = 1LL;
        const long long MOD = 1e9 + 7;
        int pw = 1;
        long long mul = 2LL;

        while (n > 0)
        {
            if (n % 2 == 1)
            {
                ans = ans * mul % MOD;
#ifdef __test
                cout << " .... " << endl;
#endif
            }
            mul = (mul * mul) % MOD;
            n >>= 1;
        }
#ifdef __test
        cout << orin << ", " << ans << endl;
#endif
        return (int)ans;
    }


    // ^2 ... not !
    //int factorial(int n)
    //{
    //    const int MOD = 1e9 + 7;
    //    int ans = 1;
    //    while (n > 0)
    //    {
    //        ans = (ans * n) % MOD;
    //        n--;
    //    }
    //    return ans;
    //}

};

int main()
{

    LT1498 lt;

    //myvi v = { 3,5,6,7 };
    //int t = 9;

    //myvi v = { 3,3
    //    ,6,8 
    //};
    //int t = 10;

    myvi v = { 2,3,3,4,6,7 };
    int t = 12;

    cout << lt.lt1498b(v, t) << endl;

    return 0;
}
