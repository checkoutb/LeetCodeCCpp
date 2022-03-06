
#include "../header/myheader.h"

class LT2134
{
public:


// D D


//    int ones = count(begin(nums), end(nums), 1), n = nums.size(), res = n;
//    for (int i = 0, j = 0, cnt = 0; i < n; ++i) {
//        while (j - i < ones)
//            cnt += nums[j++ % n];
//        res = min(res, ones - cnt);
//        cnt -= nums[i];
//    }


//Runtime: 88 ms, faster than 93.88% of C++ online submissions for Minimum Swaps to Group All 1's Together II.
//Memory Usage: 80.3 MB, less than 99.70% of C++ online submissions for Minimum Swaps to Group All 1's Together II.
    int lt2134a(vector<int>& nums)
    {
        int sz1 = nums.size();
        int cnt1 = count(begin(nums), end(nums), 1);
        int ans = sz1;
        int cnt = 0;
        for (int i = 0; i < cnt1; i++)
        {
            if (nums[i] == 0)
                cnt++;
        }
        ans = cnt;
        for (int i = 1; i < sz1; ++i)
        {
            cnt -= (nums[i - 1] == 0);
            cnt += (nums[(i + cnt1 - 1) % sz1] == 0);
//            cout<<i<<", "<<cnt<<", "<<ans<<endl;
            ans = min(ans, cnt);
        }
        return ans;
    }

};

int main()
{

    LT2134 lt;

    myvi v = {0,1,1,1,0,0,1,1,0};

    cout<<lt.lt2134a(v)<<endl;

    return 0;
}
