
#include "../header/myheader.h"

class LT1800
{
public:

// D D

//        for (int i = 1; i < nums.size(); ++i) {
//            if (nums[i] > nums[i-1])
//                cur += nums[i];
//            else
//                cur = nums[i];
//            res = max(res, cur);
//        }


//    int res = 0, sum = nums[0];
//    for (auto i = 1; i < nums.size(); ++i) {
//        if (nums[i] <= nums[i - 1]) {
//            res = max(res, sum);
//            sum = 0;
//        }
//        sum += nums[i];
//    }
//    return max(res, sum);



//Runtime: 4 ms, faster than 57.17% of C++ online submissions for Maximum Ascending Subarray Sum.
//Memory Usage: 8.4 MB, less than 78.97% of C++ online submissions for Maximum Ascending Subarray Sum.
    int lt1800a(vector<int>& nums)
    {
        int ans = nums[0];
        int t2 = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                t2 += nums[i];
            }
            else
            {
                ans = max(ans, t2);
                t2 = nums[i];
            }
        }
        ans = max(ans, t2);
        return ans;
    }

};

int main()
{
    myvi v = {10,20,30,5,10,50};

    LT1800 lt;

    cout<<lt.lt1800a(v)<<endl;

    return 0;
}
