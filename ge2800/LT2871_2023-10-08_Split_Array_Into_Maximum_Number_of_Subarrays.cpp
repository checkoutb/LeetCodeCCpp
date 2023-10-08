
#include "../header/myheader.h"

class LT2871
{
public:

// D D

//        for(auto it: nums)
//        {
//            if(currAnd==-1)
//                currAnd=it;
//            else
//                currAnd=currAnd&it;
//
//            if(currAnd==0)
//            {
//                ans++;
//                currAnd=-1;
//            }
//        }


//        for (auto num : nums) {
//            currentAnd &= num;
//
//            // if currentAnd becomes 0, it's time to split into a new subarray.
//            if (currentAnd == totalAnd) {
//                subarrayCount++;
//                currentAnd = INT_MAX;
//            }
//        }



//Runtime131 ms
//Beats
//22.60%
//Memory105 MB
//Beats
//64.84%
    // all &
    // sum of subarray is min
    // calculate max subarray count
    // min ? all subarray are 0, no other.  if not 0, just one subarray
    int maxSubarrays(vector<int>& nums)
    {
        int sz1 = nums.size();
        int ad = nums[0];
        for (int i = 1; i < sz1; ++i)
            ad &= nums[i];

        if (ad != 0)
            return 1;

        int ans = 0;
        int mnad = ad;      // mnad == 0, always
        ad = nums[0];
        for (int i = 0; i < sz1; ++i)       // maybe nums[0] == 0, so index from 0.
        {
            ad &= nums[i];
            if (ad == mnad && i != sz1 - 1)
            {
                ++ans;
                ad = nums[i + 1];
            }
        }
        ans += ad == 0;
        return ans;
    }
};

int main()
{

    LT2871 lt;


    return 0;
}
