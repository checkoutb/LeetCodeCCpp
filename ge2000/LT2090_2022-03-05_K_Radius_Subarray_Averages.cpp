
#include "../header/myheader.h"

class LT2090
{
public:

// D D


//    for (int i = 0; i < nums.size(); ++i) {
//        sum += nums[i];
//        if (i + 1 >= d) {
//            if (i >= d)
//                sum -= nums[i - d];
//            res[i - d / 2] = sum / d;
//        }
//    }


//Runtime: 365 ms, faster than 32.22% of C++ online submissions for K Radius Subarray Averages.
//Memory Usage: 129.8 MB, less than 85.02% of C++ online submissions for K Radius Subarray Averages.
    vector<int> lt2090a(vector<int>& nums, int k)
    {
        vector<int> ans(nums.size(), -1);
        long long sum2 = 0;
        for (int i = 0; i < k * 2 && i < nums.size(); ++i)
        {
            sum2 += nums[i];
        }
        for (int i = 0; i + k * 2 < nums.size(); i++)
        {
            sum2 += nums[i + k * 2];
            ans[i + k] = sum2 / (k * 2 + 1);
            sum2 -= nums[i];
        }
        return ans;
    }

};

int main()
{

    LT2090 lt;

//    myvi v = {7,4,3,9,1,8,5,2,6};
//    int k = 3;

//    myvi v = {123123};
//    int k = 0;

    myvi v = {123};
    int k = 123;

//    cout<<lt.lt2090a(v, k)<<endl;
    myvi v2 = lt.lt2090a(v, k);

    showVectorInt(v2);

    return 0;
}
