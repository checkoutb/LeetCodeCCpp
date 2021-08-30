
#include "../header/myheader.h"

class LT1984
{
public:

// D D

//        while(i <= n){
//            ans = min(ans, nums[i-1] - nums[i-k]);
//            i++;
//        }

//        for(int i = 0; i + k - 1 < n; i++) {
//            ans = min(ans, nums[i + k - 1] - nums[i]);
//        }



//Runtime: 20 ms, faster than 29.41% of C++ online submissions for Minimum Difference Between Highest and Lowest of K Scores.
//Memory Usage: 13.6 MB, less than 17.65% of C++ online submissions for Minimum Difference Between Highest and Lowest of K Scores.
    int lt1984a(vector<int>& nums, int k)
    {
        std::sort(begin(nums), end(nums));
        int mn = nums[0];
        int mx = nums[k - 1];
        int t2 = k - 1;
        int t3 = 0;
        int ans = mx - mn;
        while (t2 + 1 < nums.size())
        {
            mn = nums[++t3];
            mx = nums[++t2];
            ans = min(ans, mx - mn);
        }
        return ans;
    }

};

int main()
{
    myvi v = {90};
    int k = 1;

//    myvi v = {9,4,1,7};
//    int k = 2;

    LT1984 lt;

    cout<<lt.lt1984a(v, k)<<endl;

    return 0;
}
