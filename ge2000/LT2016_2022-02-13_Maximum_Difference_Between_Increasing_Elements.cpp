
#include "../header/myheader.h"

class LT2016
{
public:

// D D

//        for(int i=0;i<nums.size()-1;i++){
//           if(nums[i+1]>nums[i]){
//               ans=max(ans,nums[i+1]-nums[i]);
//               nums[i+1]=nums[i];
//           }
//        }

//    for (int i = 1; i < nums.size(); ++i) {
//        res = max(res, nums[i] - mn);
//        mn = min(mn, nums[i]);
//    }


//Runtime: 7 ms, faster than 49.42% of C++ online submissions for Maximum Difference Between Increasing Elements.
//Memory Usage: 8.3 MB, less than 39.95% of C++ online submissions for Maximum Difference Between Increasing Elements.
    int lt2016a(vector<int>& nums)
    {
        int ans = -1;
        int mn = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > mn)
            {
                if (nums[i] - mn > ans)
                    ans = nums[i] - mn;
            }
            else
            {
                mn = nums[i];
            }
        }
        return ans;
    }

};

int main()
{

    LT2016 lt;


    return 0;
}
