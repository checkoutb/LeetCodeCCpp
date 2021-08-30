
#include "../../header/myheader.h"

class LT
{
public:

// D D

//    while (miss <= n) {
//        if (i < nums.size() && nums[i] <= miss) {
//            miss += nums[i++];
//        } else {
//            miss += miss;
//            added++;
//        }
//    }
// if已经足够了。





// AC
// 前面已经能获得的情况下，+一个数，会导致 最大数+ 增加的那个数。
    int lta(vector<int>& nums, int n)
    {
        long t2 = 0;            // ..
        int ans = 0;
        int idx = 0;
//        int mx2 = 0;
        while (t2 < n)
        {
            while (idx < nums.size() && nums[idx] <= (t2 + 1))
            {
                t2 += nums[idx];
                idx++;
            }
            if (t2 < n)
            {
                ans++;
                t2 += t2 + 1;
            }
        }
        return ans;
    }

};

int main()
{
//    myvi v = {1,3};
//    int n = 6;

//    myvi v = {1,5,10};
//    int n = 20;

    myvi v = {1,2,2};
    int n = 5;

    LT lt;

    cout<<lt.lta(v, n)<<endl;

    return 0;
}
