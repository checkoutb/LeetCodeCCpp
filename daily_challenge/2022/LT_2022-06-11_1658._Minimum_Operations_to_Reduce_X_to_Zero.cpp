
#include "../../header/myheader.h"

class LT
{
public:

// D D

//        for (int right = 0; right < n; right++) {
//            sum += nums[right];
//
//            while(sum > target && left <= right) {
//                sum -= nums[left++];
//            }
//
//            if (sum == target) {
//                res = max(res, right - left + 1);
//            }
//
//        }
// 找最大的 连续subarray，且sum(subarray) == (sum(array) - x)


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
// prefix sum, suffix sum
// map<prefixSum, index>
// 计算 suffix sum 的时候 搜索下 有没有 x-sum的 prefix sum。


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
// 。。。666。。 sum 从头减，从头加。


    int lta(vector<int>& nums, int x)
    {
        int sz1 = nums.size();
        int en = -1;
        int st = sz1 - 1;
        int ans = INT_MAX;
        int t2 = 0;

        while (t2 < x && en < sz1 - 1)
        {
            t2 += nums[++en];
        }
        if (t2 == x)
            ans = en + 1;
        if (t2 < x)
            return -1;

        while (en >= 0)
        {
            if (t2 + nums[st] <= x)
            {
                t2 += nums[st--];
                if (t2 == x)
                {
                    ans = min(ans, en + 1 + (sz1 - st - 1));
                    #ifdef __test
                    cout<<st<<", "<<en<<endl;
                    #endif // __test
                }
            }
            else
            {
                t2 -= nums[en--];
            }
        }
        while (t2 < x)
        {
            t2 += nums[st--];
        }
        if (t2 == x)
        {
            ans = min(ans, sz1 - st - 1);
            #ifdef __test
            cout<<".. "<<st<<", "<<en<<endl;
            #endif // __test
        }

        return ans == INT_MAX ? -1 : ans;
    }

};

int main()
{

    LT lt;

//    myvi v = {1,1,4,2,3};
//    int x = 5;

//    myvi v = {5,6,7,8,9};
//    int x = 2;

    myvi v = {3,2,20,1,1,3};
    int x = 10;

    cout<<lt.lta(v, x)<<endl;

    return 0;
}
