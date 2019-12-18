
#include "../header/myheader.h"

class LT0485
{
public:

//            if (nums[i] == 1) {
//                count++;
//                result = Math.max(count, result);
//            }
//            else count = 0;
// 不需要额外的一次max。


//Runtime: 36 ms, faster than 83.69% of C++ online submissions for Max Consecutive Ones.
//Memory Usage: 11.6 MB, less than 100.00% of C++ online submissions for Max Consecutive Ones.

    int lt0485a(vector<int>& nums)
    {
        int ans = 0;
        int t1 = 0;
        for (int n : nums)
        {
            if (n == 0)
            {
                ans = std::max(ans, t1);
                t1 = 0;
            }
            else
            {
                t1++;
            }
        }
        ans = max(t1, ans);
        return ans;
    }
};

int main()
{
    vector<int> v = {1,1,0,1,1,1};

    LT0485 lt;

    cout<<lt.lt0485a(v)<<endl;

    return 0;
}
