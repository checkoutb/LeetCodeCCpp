
#include "../../header/myheader.h"

class LT
{
public:

// D D

//        int take = 0, skip = 0;
//        for (int i = 0; i < n; i++) {
//            int takei = skip + values[i];
//            int skipi = max(skip, take);
//            take = takei;
//            skip = skipi;
//        }
//        return max(take, skip);



//Runtime: 4 ms, faster than 94.57% of C++ online submissions for Delete and Earn.
//Memory Usage: 9.1 MB, less than 90.77% of C++ online submissions for Delete and Earn.
// 选择一个数字后， 获得 数字*个数， 删除 (数字 +- 1)的 所有
// 转成 <value, total>  value 没有 +-1 ，就是孤立的， 可以直接拿。
// 如果是 2个数字， 不和其他数字连接， 那么就 取total 大。
// >=3 枚举？
// related topics : dp.... 那就只能试下dp了。。确实 [0,x] 最大已知的情况下， x+1进入的话， 要么 依然是 [0,x] 要么 [0,x-1] + x+1 .
//              topic： Array，确实， 10^4
// 而且，dp 也可以用在 孤立的数字上。。或者2个的
    int lta(vector<int>& nums)
    {
        int arr[10002] = {0};
        for (int i : nums)
        {
            arr[i] += i;
        }
        int ans = 0;
        for (int i = 2; i < 10002; ++i)     // 不存在0
        {
            if (arr[i] == 0)
            {
                ans += arr[i - 1];
                i++;
                continue;
            }
            arr[i] = max(arr[i - 1], arr[i - 2] + arr[i]);
        }
        return ans;
    }

};

int main()
{

    LT lt;

//    myvi v = {3,4,2};
    myvi v = {2,2,3,3,3,4,5,6,6,6,7};

    cout<<lt.lta(v)<<endl;

    return 0;
}
