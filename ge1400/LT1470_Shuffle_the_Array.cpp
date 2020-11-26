
#include "../header/myheader.h"

class LT1470
{
public:

// D D

//const num1 = nums[j] & 1023
//const num2 = nums[j] >> 10
// 用位来保存信息。

// 。。。 也是， 实际上 num*10000 + 原值， 是很容易的，因为 原值还是存在的所以只需要 简单遍历下就可以了。
// 变负的话， 原值会丢失，所以 下一步必须寻找 原值 应该在的地方， 就难了。



//Runtime: 8 ms, faster than 87.54% of C++ online submissions for Shuffle the Array.
//Memory Usage: 10.3 MB, less than 21.78% of C++ online submissions for Shuffle the Array.
// 原地写不出，一种是 取负数，当值在合适的位置，就变成负数，然后被覆盖的值继续找它合适的位置，   最后全部再取负数。
// 合适的位置  num*10000 + 原值。
    vector<int> lt1470a(vector<int>& nums, int n)
    {
        vector<int> cp(begin(nums), begin(nums) + n);
        int idxnum = n;
        int idxcp = 0;
        for (int i = 0; idxcp < n; ++idxcp, ++idxnum)
        {
            nums[i++] = cp[idxcp];
            nums[i++] = nums[idxnum];
        }
        return nums;
    }

};

int main()
{
//    myvi v = {2,5,1,3,4,7};
//    int n{3};

//    myvi v = {1,2,3,4,4,3,2,1};

    myvi v = {1,1,2,2};

    int n = v.size() / 2;
    LT1470 lt;

    myvi ans = lt.lt1470a(v, n);
    showVectorInt(ans);

    return 0;
}
