
#include "../header/myheader.h"

class LT1262
{
public:

// D
//        vector<int> dp = {0, 0, 0}, dp2;
//        for (int a : A) {
//            dp2 = dp;
//            for (int i: dp2) {
//                dp[(i + a) % 3] = max(dp[(i + a) % 3], i + a);
//            }
//        }
//        return dp[0];
// ....


// tle.
// .....xiededuo, cuodeduo...
// nums.size() < 4*10^4,  max_element() < 10^4
// 可以先剔除一些 必然 可以 /3 的值。
    int lt1262a(vector<int>& nums)
    {
//        unordered_map<int, int> map2;
//        for (int n : nums)
//            map2[n]++;
//
//        vector<int> nums2;
//        for (unordered_map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
//        {
//            if (it->first % 3 == 0)
//            {
//                ans += it->first * it->second;
////                it->second = 0;
//            }
//            else if (it->second % 3 == 0)
//            {
//                ans += it->first * it->second;
////                it->second = 0;
//            }
//            else
//            {
//                if (it->second > 3)
//                {
//                    ans += it->first * (it->second / 3 * 3);
//                    it->second = it->second % 3;
//                }
//                for (int i = 0; i < it->second; ++i)
//                {
//                    nums2.push_back(it->first);
//                }
//            }
//        }
//        #ifdef __test
//        cout<<ans<<endl;
//        showVectorInt(nums2);
//        cout<<" = = = ="<<endl;
//        #endif // __test
//        dfsa1(nums2, ans, -1);

        dfsa1(nums, 0, -1);

        return ans;
    }
    int ans = 0;
    void dfsa1(vector<int>& nums, int val, int idx)
    {
        if (val % 3 == 0)
            ans = max(ans, val);
        for (++idx; idx < nums.size(); ++idx)
        {
            dfsa1(nums, val + nums[idx], idx);
        }
    }
};

int main()
{

//    vector<int> v = {3,6,5,1,8};
//    vector<int> v = {4};
//    vector<int> v = {1,2,3,4,4};
    vector<int> v = {2,6,2,2,7};

    LT1262 lt;

    cout<<lt.lt1262a(v)<<endl;

    return 0;
}
