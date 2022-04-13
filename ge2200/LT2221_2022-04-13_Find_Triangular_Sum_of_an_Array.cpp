
#include "../header/myheader.h"

class LT2221
{
public:

// D D

//def triangularSum(self, nums: List[int]) -> int:
//    result = 0
//    m = len(nums) - 1
//    mCk = 1
//    for k, num in enumerate(nums):
//        result = (result + mCk * num) % 10
//        mCk *= m - k
//        mCk //= k + 1
//    return result


//int triangularSum(vector<int>& nums) {
//    int result = 0;
//    int m = nums.size() - 1;
//    int mck = 1, exp2 = 0, exp5 = 0;
//    int inv[] = {0, 1, 0, 7, 0, 0, 0, 3, 0, 9};
//    int pow2mod10[] = {6, 2, 4, 8};
//    for (int k = 0; true; k++) {
//        if (!exp2 || !exp5) {
//            int mCk_ = exp2 ? mck * pow2mod10[exp2 % 4] :
//                       exp5 ? mck * 5 : mck;
//            result = (result + mCk_ * nums[k]) % 10;
//        }
//        if (k == m)
//            return result;
//
//        // mCk *= m - k
//        int mul = m - k;
//        while (mul % 2 == 0) {
//            mul /= 2;
//            exp2++;
//        }
//        while (mul % 5 == 0) {
//            mul /= 5;
//            exp5++;
//        }
//        mck = mck * mul % 10;
//
//        // mCk /= k + 1
//        int div = k + 1;
//        while (div % 2 == 0) {
//            div /= 2;
//            exp2--;
//        }
//        while (div % 5 == 0) {
//            div /= 5;
//            exp5--;
//        }
//        mck = mck * inv[div % 10] % 10;
//    }
//}


//      for (int i = static_cast<int>(nums.size()) - 1; i > 0; --i)
//        for (int j = 0; j < i; ++j)
//          nums[j] = (nums[j] + nums[j+1]) % 10;


//Runtime: 247 ms, faster than 92.14% of C++ online submissions for Find Triangular Sum of an Array.
//Memory Usage: 19.4 MB, less than 58.07% of C++ online submissions for Find Triangular Sum of an Array.
                                                                    // 1
                                                                //   1   1
// f4(0) = f3(0) + f3(1) = f2(0) + f2(1) + f2(1) + f2(2)            // 1 2 1
// = f1(0) + f1(1) + 2 * (f11 + f12) + f12 + f13
// = f10 + 3 * (f11 + f12) + f13                                // 1 3 3 1
// = f00 + f01 + 3 * (f01 + f02 + f02 + f03) + f03 + f04
// = f00 + 4*f01 + 6*f02 + 4*f03 + f04                      // 1 4 6 4 1
// yanghuisanjiao
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
    int lt2221a(vector<int>& nums)
    {
        int sz1 = nums.size();
        vector<int> vi(nums.size());
        vi[0] = 1;
        for (int i = 1; i < sz1; ++i)
        {
            int j = i;
            vi[j--] = 1;
            while (j > 0)
            {
                vi[j] = (vi[j - 1] + vi[j]) % 10;
                j--;
            }
            vi[0] = 1;
            #ifdef __test
//            showVectorInt(vi);
            #endif // __test
        }
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            ans += vi[i] * nums[i];
        }
        ans %= 10;
        return ans;
    }

};

int main()
{

    LT2221 lt;

//    myvi v = {1,2,3,4,5};
    myvi v = {5};

    cout<<lt.lt2221a(v)<<endl;

    return 0;
}
