
#include "../header/myheader.h"

class LT0376
{
public:

//        if(nums.size() <= 1) return nums.size();
//        int count = 1;
//        int i = 1;
//        while(i < nums.size() && nums[i] == nums[i-1]) {      // 跳过前导的 相同数。
//            ++i;
//        }
//        if(i == nums.size()) return 1;
//        bool positive = nums[i] - nums[i-1] > 0;
//        for(++i; i < nums.size(); ++i) {
//            if(nums[i] == nums[i-1]) continue;
//            bool direction = nums[i] - nums[i-1] > 0;
//            if(positive != direction) {                       // 发生转折时，++。！！！
//                positive = !positive;
//                ++count;
//            }
//        }
//        return count+1;


//        int up = 1;
//        int down = 1;
//
//        for (int i = 1; i < nums.length; i++) {
//            if (nums[i] > nums[i - 1]) {
//                up = down + 1;
//            }
//            else if (nums[i] < nums[i - 1]) {
//                down = up + 1;
//            }
//        }
//
//        return Math.max(up, down);



//    Runtime: 4 ms, faster than 95.54% of C++ online submissions for Wiggle Subsequence.
//    Memory Usage: 8.8 MB, less than 14.36% of C++ online submissions for Wiggle Subsequence.

    int lt0376a(vector<int>& nums)
    {
        int result = 0;
        int sz1 = nums.size();
        if (sz1 == 0)
            return result;
        int arr1[2][sz1] = {{1},{1}};       // 0，大于前一个，1，小于前一个
        result = 1;
//        int max1 = min1 = nums[0];        // 保存之前的最大，最小值，优化 单调递增/减 nums。
        for (int i = 1; i < sz1; i++)
        {
            arr1[0][i] = 1;
            arr1[1][i] = 1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[j] == nums[i])
                    continue;
                if (nums[j] < nums[i])
                {
                    arr1[0][i] = max(arr1[1][j] + 1, arr1[0][i]);
                }
                else
                {
                    arr1[1][i] = max(arr1[0][j] + 1, arr1[1][i]);       // result 在这里 ++ 也可以。
                }
            }
            result = max(result, max(arr1[0][i], arr1[1][i]));
        }

        #ifdef __test
        for (auto& p : arr1)
        {
            for (auto& p1 : p)
            {
                cout<<p1<<", ";
            }
            cout<<endl;
        }
        #endif // __test

        return result;
    }
};

int main()
{
    vector<int> v = {1,7,4,9,2,5};

    LT0376 lt;
    cout<<endl<<lt.lt0376a(v)<<endl;
    return 0;
}
