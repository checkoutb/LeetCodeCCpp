
#include "../../header/myheader.h"

class LT
{
public:

    // D D

        // int ans=0;
        // int val=0;
        // for(auto x:nums)val^=x;
        // val^=k;
        // while(val){
        //     ans++;
        //     val=val&(val-1);
        // }
        // return ans;


        // for (int a : A)
        //     k ^= a;
        // return __builtin_popcount(k);



// Runtime
// 108ms
// Beats64.05%of users with C++
// Memory
// 91.58MB
// Beats12.57%of users with C++
    int minOperations(vector<int>& nums, int k)
    {
        array<int, 32> arr;
        for (int i = 0; i < nums.size(); ++i)
        {
            int t2 = nums[i];
            int idx = 0;
            while (t2 > 0)
            {
                arr[idx++] += t2 % 2;
                t2 >>= 1;
            }
        }
        int idx = 0;
        int ans = 0;
        // while (k > 0)
        for (int i = 0; i <= 20; ++i)
        {
            ans += (k % 2) ^ (arr[idx] % 2);
            k >>= 1;
        }
        return ans;
    }
};

int main()
{

    LT lt;


    return 0;
}
