
#include "../header/myheader.h"

class LT0553
{
public:

// D D

//a1/(a2/a3/a4/...) = (a1*a3*a4*....)/a2.

// dfs + memo,  分割。



//Runtime: 4 ms, faster than 54.14% of C++ online submissions for Optimal Division.
//Memory Usage: 8 MB, less than 100.00% of C++ online submissions for Optimal Division.
// 感觉就是 第一个数字 后加个 (，然后 string最后加 ) 就可以了啊。
    string lt0553a(vector<int>& nums)
    {
        string ans = to_string(nums[0]) + (nums.size() > 1 ? "/" : "") + (nums.size() > 2 ? "(" : "");
        for (int i = 1; i < nums.size(); i++)
            ans += to_string(nums[i]) + (i == nums.size() - 1 ? "" : "/");
        ans += (nums.size() > 2 ? ")" : "");
        return ans;
    }

};

int main()
{
    myvi v = {1000,100,10,2};

    LT0553 lt;

    cout<<lt.lt0553a(v);

    return 0;
}
