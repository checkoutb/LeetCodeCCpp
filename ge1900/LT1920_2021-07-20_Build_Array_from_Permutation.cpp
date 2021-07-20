
#include "../header/myheader.h"

class LT1920
{
public:

// D D

//        for (int i = 0; i < q; ++i){
//            int b = nums[nums[i]] % q;
//            nums[i] += q * b;
//        }
//        for (int i = 0; i < q; ++i){
//            nums[i] = nums[i]/q;
//        }






//Runtime: 16 ms, faster than 64.06% of C++ online submissions for Build Array from Permutation.
//Memory Usage: 16.2 MB, less than 51.13% of C++ online submissions for Build Array from Permutation.
// 送分题。
//Input: nums = [5,0,1,2,3,4]
//Output: [4,5,0,1,2,3]
//Explanation: The array ans is built as follows:
//ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
//    = [nums[5], nums[0], nums[1], nums[2], nums[3], nums[4]]
//    = [4,5,0,1,2,3]
// 空间O(1)的话，时间得O(n*n) 啊。。
    vector<int> lt1920a(vector<int>& nums)
    {
        int mod = 10000;
        int sz1 = nums.size();
        for (int i = 0; i < sz1; ++i)
        {
            nums[i] += (nums[nums[i] % mod] % mod) * mod;
        }
        #ifdef __test
//        showVectorInt(nums);
        #endif // __test
        for (int i = 0; i < sz1; ++i)
        {
            nums[i] = nums[i] / mod;
        }
        return nums;

//        int t2 = nums[0];
//        int ti = 0;
//        nums[0] = nums[t2];
//        int sz1 = nums.size();
//        while (sz1-- > 1)
//        {
//            for (int i = 0; i < sz1; ++i)
//            {
//                // 会出现重复的。。。
//            }
//        }
    }

};

int main()
{
//    myvi v = {0,2,1,5,3,4};
    myvi v = {5,0,1,2,3,4};

    LT1920 lt;

    myvi v2 = lt.lt1920a(v);

    showVectorInt(v2);

    return 0;
}
