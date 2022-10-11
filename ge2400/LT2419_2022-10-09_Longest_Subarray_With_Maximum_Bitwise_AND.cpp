
#include "../header/myheader.h"

class LT2419
{
public:

// D D

//        int maxEle = *max_element(nums.begin(), nums.end());
//        int subarrayLen = 0, ans = 1;
//
//        for(int i = 0; i < N; i++) {
//            if (nums[i] == maxEle) {
//                subarrayLen++;
//                ans = max(ans, subarrayLen);
//            } else {
//                subarrayLen = 0;
//            }
//        }

//        int n = nums.size(), maxi = *max_element(nums.begin(),nums.end()),count=0,res=1;
//        for(int i=0;i<n;i++)
//        {
//            if(nums[i]==maxi)
//                count++;
//            else
//                count = 0;
//            res = max(res,count);
//        }


//    int max_n = 0, cnt = 0, res = 0;
//    for (int n : nums) {
//        if (max_n < n) {
//            max_n = n;
//            res = cnt = 0;
//        }
//        cnt = n == max_n ? cnt + 1 : 0;
//        res = max(res, cnt);
//    }


//Runtime: 251 ms, faster than 73.16% of C++ online submissions for Longest Subarray With Maximum Bitwise AND.
//Memory Usage: 82.3 MB, less than 58.86% of C++ online submissions for Longest Subarray With Maximum Bitwise AND.
    int lt2419a(vector<int>& nums)
    {
        int mx = *max_element(begin(nums), end(nums));
        int ans = 0;
        int t2 = 0;
        int sz1 = nums.size();
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == mx)
            {
                t2 = 1;
                while ((i + 1) < sz1 && nums[i + 1] == mx)
                {
                    ++i;
                    ++t2;
                }
                ans = max(ans, t2);
            }
        }
        return ans;
    }

};

int main()
{

    LT2419 lt;


    return 0;
}
