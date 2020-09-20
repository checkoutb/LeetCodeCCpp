
#include "../header/myheader.h"

class LT0560
{
public:



// D D
//        int n = N.size(), r = 0;
//        unordered_map<int, int> H{{0, 1}};                // ...!zzz
//        for (int i = 0, s = 0; i < n; ++i) {
//            s += N[i];
//            if (H.count(s-k))                         // ...!zzz
//                r += H[s-k];
//            ++H[s];
//        }
//        return r;

// count or find!=end, avoid generating too many keys in hashmap.



//Runtime: 92 ms, faster than 60.85% of C++ online submissions for Subarray Sum Equals K.
//Memory Usage: 26.6 MB, less than 32.55% of C++ online submissions for Subarray Sum Equals K.
    int lt0560b(vector<int>& nums, int k)
    {
        int sum{0}, ans{0};
        unordered_map<int, int> map2;
        map2[0]++;
        for (int& n : nums)
        {
            sum += n;
            ans += map2[sum - k];
            map2[sum]++;
        }
        return ans;
    }


// 5477 个赞。。。
// 最多20亿
// 不行，有负数，所以没有办法 双指针窗口移动。
    int lt0560a(vector<int>& nums, int k)
    {
        int st{0}, en{0};
        int sumst{0}, sumen{0};
        for (; st < nums.size(); st++)
        {
//            sumst += nums[st];
            nums[st] = nums[st] + nums[st - 1];
            if (nums[st] - nums[en] == k)
            {
//                ans++;
            }
            else if (nums[st] - nums[en] > k)
            {
//                while (nums[st] - nums[en] > k && st)
            }
        }
    }


};

int main()
{

    vector<int> v = {1,1,1};
    int k = 2;

    LT0560 lt;

    cout<<lt.lt0560b(v, k)<<endl;

    return 0;
}
