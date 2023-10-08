
#include "../header/myheader.h"

class LT2762
{
public:

// D D
//        int l = nums[0] - 2, r = nums[0] + 2;
//        int j = 0;
//
//        for (int i = 1; i < N; i++) {
//            if (nums[i] >= l && nums[i] <= r) {
//                l = max(l, nums[i] - 2);
//                r = min(r, nums[i] + 2);
//            }
//            else {
//                j = i - 1;                // ...
//                l = nums[i] - 2;
//                r = nums[i] + 2;
//                while (nums[j] >= l && nums[j] <= r) {
//                    l = max(l, nums[j] - 2);
//                    r = min(r, nums[j] + 2);
//                    j--;
//                }
//
//                j++;
//            }
//
//            result += i - j + 1;
//        }







//Runtime109 ms
//Beats
//81.95%
//Memory107.2 MB
//Beats
//73.44%
    long long continuousSubarrays(vector<int>& nums)
    {
        long long ans = 0LL;
        int sz1 = nums.size();
        int st = 0;
        map<int, int> map2;
        map2[nums[0]] = 1;
        for (int i = 1; i < sz1; ++i)
        {
            ++map2[nums[i]];
            while (map2.rbegin()->first - map2.begin()->first > 2)
            {
                ans += i - st;
                --map2[nums[st]];
                if (map2[nums[st]] == 0)
                    map2.erase(nums[st]);
                ++st;
            }
            #ifdef __test
            cout<<i<<", "<<ans<<endl;
            cout<<(map2.rbegin()->first)<<" - "<<(map2.begin()->first)<<endl;
            #endif // __test
        }
        st = sz1 - st;
        ans += 1LL * st * (st + 1) / 2;
        return ans;
    }

};

int main()
{

    LT2762 lt;

    myvi v = {5,4,2,4};

    cout<<lt.continuousSubarrays(v)<<endl;

    return 0;
}
