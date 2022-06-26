
#include "../header/myheader.h"

class LT2317
{
public:

    // D D


    // return reduce(nums.begin(), nums.end(), 0, bit_or());
    // cpp

    // return accumulate(begin(nums), end(nums), 0, bit_or<int>());



//Runtime: 113 ms, faster than 50.00 % of C++ online submissions for Maximum XOR After Operations .
//Memory Usage : 48.1 MB, less than 50.00 % of C++ online submissions for Maximum XOR After Operations .
    // 感觉 只要 这个 bit 出现过，那么肯定能存在于 ans中。
    // 确实，只需要 这个 bit 出现过， 把 其它数字的 该bit 设置成0 就ok 了。
    int lt2317a(vector<int>& nums)
    {
        int ans = 0;
        for (int n : nums)
        {
            ans |= n;
        }
        return ans;
    }

};

int main()
{

    LT2317 lt;

    //myvi v = { 3,2,4,6 };
    myvi v = { 1,2,3,9,2 };

    cout << lt.lt2317a(v) << endl;

    return 0;
}
