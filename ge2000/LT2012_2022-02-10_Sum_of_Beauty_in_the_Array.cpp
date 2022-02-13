
#include "../header/myheader.h"

class LT2012
{
public:

// D D




//Runtime: 223 ms, faster than 47.72% of C++ online submissions for Sum of Beauty in the Array.
//Memory Usage: 85.3 MB, less than 63.31% of C++ online submissions for Sum of Beauty in the Array.
// 先看 是不是 前面的全部小于自己，后面的全部大于自己       // 单调。
// 前一个，后一个
// 0
    int lt2012a(vector<int>& nums)
    {
        int sz1 = nums.size();
        vector<int> arr(sz1, 0);            // >= idx 's min
        arr[sz1 - 1] = nums[sz1 - 1];
        for (int i = sz1 - 2; i >= 0; --i)
        {
            arr[i] = min(nums[i], arr[i + 1]);
        }
        int preMx = nums[0];
        int ans = 0;
        #ifdef __test
        showVectorInt(arr);
        #endif // __test
        for (int i = 1; i < sz1 - 1; ++i)
        {
            int t2 = nums[i];
            if (preMx < t2 && t2 < arr[i + 1])
            {
//                preMx = t2;       //...
                ans += 2;
            }
            else if (nums[i - 1] < t2 && nums[i + 1] > t2)
            {
                ++ans;
            }
            preMx = max(t2, preMx);
        }
        return ans;
    }

};

int main()
{

    LT2012 lt;

    // 21
    myvi v = {3,48,33,17,21,95,24,67,89,1,50,76,6,32,20,5,1,45,79,81,96,96,15,37,44,63,4,40,58,71,99,78,95,6,34,97,52,80,91,20,61,29,
    12,85,88,41,14,4,58,17,67,75,100,51,63,66,42,19,44,34,34,78,54,84,3,90,72,18,86,8,33,5,17,21,22,13,59,82,30,66,91,5,32,30,92,57,
    10,33,11,76,30,80,80,91,47,33};

    cout<<lt.lt2012a(v)<<endl;

    return 0;
}
