
#include "../header/myheader.h"

class LT2972
{
public:


    // D D

    // prefix, suffix, 2stack. ,, 2 pointer.




// Runtime
// 136ms
// Beats38.76%of users with C++
// Memory
// 95.02MB
// Beats46.54%of users with C++


    // sz1 <= 10^5
    // but in question I,  i have seen the first down, last down... it is O(n)
    long long incremovableSubarrayCount(vector<int>& nums)
    {
        int fst = -1;       // [fst - 1] >= [fst]
        int lst = -1;       //     [lst] >= [lst + 1]
        int sz1 = nums.size();
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] <= nums[i - 1])
            {
                fst = i;
                break;
            }
        }

        if (fst == -1)
        {
            return 1LL * sz1 * (sz1 + 1) / 2;
        }

        for (int i = sz1 - 2; i >= 0; --i)
        {
            if (nums[i] >= nums[i + 1])
            {
                lst = i;
                break;
            }
        }

        long long ans = 0LL;
        ++lst;

#ifdef __test
        cout<<fst<<" - "<<lst<<endl;
#endif

        for (int i = 0; i <= fst; ++i)      // remove [i, lst]
        {
            if (i == 0) {
                ans += sz1 - lst + 1;
                continue;
            }
            // int t2 = i == fst ? nums[fst - 1] : nums[fst];       // ...
            int t2 = nums[i - 1];
            while (lst < sz1 && nums[lst] <= t2)
                ++lst;
            ans += sz1 - lst + 1;

#ifdef __test
            cout<<"  "<<ans<<" ,, "<<i<<", "<<lst<<endl;
#endif
        }
        return ans;
    }

};

int main()
{

    LT2972 lt;

    // vector vi{8,7,6,6};

    // vector vi{1,2,3,4};

    // vector vi{6,5,7,8};

    vector vi{1,2,10,6};        // 7

    cout<<lt.incremovableSubarrayCount(vi)<<endl;

    return 0;
}
