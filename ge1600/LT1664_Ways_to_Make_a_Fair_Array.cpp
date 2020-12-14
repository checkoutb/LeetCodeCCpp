
#include "../header/myheader.h"

class LT1664
{
public:

// D D


//        int res = 0, n = A.size(), left[2] = {}, right[2] = {};
//        for (int i = 0; i < n; ++i)
//            right[i % 2] += A[i];
//        for (int i = 0; i < n; ++i) {
//            right[i % 2] -= A[i];
//            res += left[0] + right[1] == left[1] + right[0];
//            left[i % 2] += A[i];
//        }

//    int sum[2] = {}, res = 0;
//    for (auto i = 0; i < nums.size(); ++i)
//        sum[i % 2] += nums[i];
//    for (auto i = 0; i < nums.size(); ++i) {
//        sum[i % 2] -= nums[i];
//        res += sum[0] == sum[1];
//        sum[!(i % 2)] += nums[i];
//    }
//




//Runtime: 400 ms, faster than 17.09% of C++ online submissions for Ways to Make a Fair Array.
//Memory Usage: 99.1 MB, less than 60.25% of C++ online submissions for Ways to Make a Fair Array.
    int lt1664a(vector<int>& nums)
    {
        int sz1 = nums.size();
        if (sz1 <= 1)       // ...
            return sz1;     // ...
        vector<int> vi(sz1);
        vi[sz1 - 1] = nums[sz1 - 1];
        vi[sz1 - 2] = nums[sz1 - 2];
        for (int i = sz1 - 3; i >= 0; --i)
        {
            vi[i] = nums[i] + vi[i + 2];
        }
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            int odd = i / 2 * 2 - 1;
            int even = i - 1 - (i + 1) % 2;
            odd = odd < 0 ? 0 : nums[odd];
            even = even < 0 ? 0 : nums[even];
            int t1 = (i + 2) / 2 * 2;      // even == odd
            int t2 = i + 1 + i % 2;
            t1 = t1 >= sz1 ? 0 : vi[t1];
            t2 = t2 >= sz1 ? 0 : vi[t2];
            odd += t1;
            even += t2;
            if (odd == even)
                ans++;
            nums[i] += (i - 2 >= 0 ? nums[i - 2] : 0);
        }
        return ans;
    }

};

int main()
{
//    myvi v = {2,1,6,4};
//    myvi v = {1,1,1};
    myvi v = {1,2,3};

    LT1664 lt;

    cout<<lt.lt1664a(v);

    return 0;
}
