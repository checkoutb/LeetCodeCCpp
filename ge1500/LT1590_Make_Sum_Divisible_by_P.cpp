
#include "../header/myheader.h"

class LT1590
{
public:

// D

// 遍历获得 余数1
// 遍历，计算 从头到现在的余数， 根据p，余数1，计算 余数的补， 从map里 根据 补 找到 最近一次出现的位置， 最近的补 到 现在 组成的subarr，删除，剩下的就能被整除。

// tle
    int lt1590a(vector<int>& nums, int p)
    {
        int sz1 = nums.size();
        int sum2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            nums[i] = nums[i] % p;
            sum2 = (sum2 + nums[i]) % p;
        }
        if (sum2 % p == 0)
            return 0;
        int ans = -1;
        for (int i = 1; i < sz1 - 1; ++i)
        {
            int j = 0;
            int rmv = 0;
            for (; j < i; ++j)
            {
                rmv = (rmv + nums[j]) % p;
            }
            if ((sum2 - rmv) % p == 0)
            {
                return i;
            }
            for (; j < sz1; ++j)
            {
                rmv = (nums[j] - nums[j - i] + rmv) % p;
                if ((sum2 - rmv) % p == 0)
                    return i;
            }
        }
        return -1;
    }

};

int main()
{
//    cout<<(-2 % 2)<<endl;

//    myvi v = {3,1,4,2};
//    int p = 6;

//    myvi v = {1,2,3};
//    int p = 3;

//    myvi v = {1,2,3};
//    int p{7};

    myvi v = {1000000, 1000000, 1000000};
    int p{3};

    LT1590 lt;

    cout<<lt.lt1590a(v, p);

    return 0;
}
