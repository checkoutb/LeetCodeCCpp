
#include "../header/myheader.h"

class LT1685
{
public:

// D D

//        int ans = 0;
//        for(int i = 0;i < nums.size();++i){
//            ans += nums[i] - nums[0];
//        }
//        vector<int> go;
//        for(int i = 0;i < nums.size();++i){
//            if(i != 0){
//                ans += (2*i - nums.size()) * (nums[i] - nums[i-1]);
//            }
//            go.push_back(ans);
//        }
//        return go;
// 这里的ans 是 之前的值， 所以 每次增加的就是 一个 矩形。


//    int left = 0, right = accumulate(begin(n), end(n), 0), sz = n.size();
//    for (int i = 0; i < sz; ++i) {
//        right -= n[i];
//        left += n[i];
//        n[i] = right - n[i] * (sz - i - 1) - left + n[i] * (i + 1);
//    }



//Runtime: 192 ms, faster than 14.29% of C++ online submissions for Sum of Absolute Differences in a Sorted Array.
//Memory Usage: 86 MB, less than 14.29% of C++ online submissions for Sum of Absolute Differences in a Sorted Array.
    vector<int> lt1685a(vector<int>& nums)
    {
        int sz1 = nums.size();
        vector<int> sum2(nums.size());
        vector<int> ans(nums.size());
        sum2[0] = nums[0];
        for (int i = 1; i < sz1; ++i)
            sum2[i] = nums[i] + sum2[i - 1];
        for (int i = 0; i < sz1; ++i)
        {
            int t1 = nums[i] * (i + 1) - sum2[i];
            int t2 = sum2[sz1 - 1] - sum2[i] - nums[i] * (sz1 - i - 1);
            ans[i] = t1 + t2;
        }
        return ans;
    }

};

int main()
{
//    myvi v = {2,3,5};
    myvi v = {1,4,6,8,10};

    LT1685 lt;

    myvi v2 = lt.lt1685a(v);
    showVectorInt(v2);

    return 0;
}
