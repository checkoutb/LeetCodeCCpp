
#include "../header/myheader.h"

class LT2873
{
public:

// D D

//        for (int&a : A) {
//            res = max(res, 1LL * maxab * a);
//            maxab = max(maxab, maxa - a);
//            maxa = max(maxa, a);
//        }




// for II
//Runtime125 ms
//Beats
//61.80%
//Memory86.6 MB
//Beats
//96.28%


//Runtime3 ms
//Beats
//95.71%
//Memory18 MB
//Beats
//66.8%
    // ([i]-[j]) * [k]    i<j<k
    long long maximumTripletValue(vector<int>& nums)
    {
        int sz1 = nums.size();
        int mxv = nums[0];          // max value
        int mxg = nums[0] - nums[1];    // max gap/difference
        long long ans = 0LL;
        for (int i = 2; i < sz1; ++i)
        {
            ans = max(ans, 1LL * nums[i] * mxg);
            mxv = max(mxv, nums[i - 1]);
            mxg = max(mxg, mxv - nums[i]);
        }
        return ans;
    }

};

int main()
{

    LT2873 lt;


    return 0;
}
