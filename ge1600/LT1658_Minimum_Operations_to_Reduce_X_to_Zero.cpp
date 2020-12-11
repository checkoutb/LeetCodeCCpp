
#include "../header/myheader.h"

class LT1658
{
public:

// D D

//        while(left <= right && right <= N){
//            //找到子数组， 更新ans
//            if(cur == target){
//                ans = max(ans, right - left);
//            }
//            if(cur <= target){
//                cur += nums[right++];
//            }
//            else{
//                cur -= nums[left++];
//            }
//        }


//for (int i = 0; i < nums.length; ++i) {
//
//	sum += nums[i];
//	if (map.containsKey(sum - target)) {
//		res = Math.max(res, i - map.get(sum - target));
//	}
//
//    // no need to check containsKey since sum is unique
//	map.put(sum, i);
//}


//    unordered_map<int, int> left;
//    int res = INT_MAX;
//    for (auto l = 0, sum = 0; l < nums.size() && sum <= x; ++l) {
//        left[sum] = l;
//        sum += nums[l];
//    }
//    for (int r = nums.size() - 1, sum = 0; r >= 0 && sum <= x; --r) {
//        auto it = left.find(x - sum);
//        if (it != end(left) && r + 1 >= it->second) {
//            res = min(res, (int)nums.size() - r - 1 + it->second);
//        }
//        sum += nums[r];
//    }
//    return res == INT_MAX ? -1 : res;


//    int sum = accumulate(begin(nums), end(nums), 0);
//    int l = 0, r = 0, res = INT_MAX, sz = nums.size();
//    while (l <= r)
//        if (sum >= x) {
//            if (sum == x)
//                res = min(res, l + sz - r);
//            if (r < sz)
//                sum -= nums[r++];
//            else
//                break;
//        }
//        else
//            sum += nums[l++];
//    return res == INT_MAX ? -1 : res;



//Runtime: 312 ms, faster than 87.02% of C++ online submissions for Minimum Operations to Reduce X to Zero.
//Memory Usage: 98.5 MB, less than 100.00% of C++ online submissions for Minimum Operations to Reduce X to Zero.
// 之前有个题目， 和这个差不多， 跨头尾的窗口 之和 == x 。   或者 sum - 窗口 == x。。后者吧，前者不好写。。
    int lt1658a(vector<int>& nums, int x)
    {
        int ans = -1;
        int sz1 = nums.size();
        int sum2 = 0;
        int sum = accumulate(begin(nums), end(nums), 0);
        x = sum - x;

        int en = 0;
        int len = 0;
        for (int i = 0; i < sz1; ++i)
        {
            sum2 += nums[i];
            if (sum2 >= x)
            {
                en = i;
                if (sum2 == x)
                    ans = i + 1;
                break;
            }
        }

        for (int i = 1; i < sz1; ++i)
        {
            sum2 -= nums[i - 1];
            while (sum2 < x && en < sz1 - 1)
                sum2 += nums[++en];
            if (sum2 == x)
                ans = max(ans, en - i + 1);
        }

        return ans == -1 ? -1 : sz1 - ans;
    }

};

int main()
{
//    myvi v = {1,1,4,2,3};
//    int x = 5;

//    myvi v = {5,6,7,8,9};
//    int x = 4;

    myvi v = {3,2,20,1,1,3};
    int x = 10;

    LT1658 lt;

    cout<<lt.lt1658a(v, x);

    return 0;
}
