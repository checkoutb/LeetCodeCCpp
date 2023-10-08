
#include "../header/myheader.h"

class LT2856
{
public:

// D D

//        int n = nums.size();
//        int c = 0;
//        int k = n/2;
//        for(int i = 0;i < k; i++)
//        {
//            int val1 = nums[i];
//            int val2 = nums[n-k+i];
//            if(val1 < val2)
//                c++;
//        }
//        return  n - 2*c;





//Runtime221 ms
//Beats
//51.4%
//Memory165.5 MB
//Beats
//29.62%
    // distinct
    int minLengthAfterRemovals(vector<int>& nums)
    {
        int sz1 = nums.size();
        map<int, int> map2;
        for (int i : nums)
            ++map2[i];

        int mxcnt = 0;
        for (auto& p : map2)
        {
            mxcnt = max(mxcnt, p.second);
        }
        int t2 = sz1 - mxcnt;

        if (mxcnt <= t2)
        {
            return sz1 % 2;
        }
        else
        {
            return mxcnt - t2;
        }

//        int cnt2 = sz1 - map2.size();


//        int sz1 = nums.size();
//        int cnt1 = 0;
//        int cnt2 = 0;   // not distinct
//
//        for (int i = 1; i < sz1; ++i)
//        {
//            if (nums[i] != nums[i - 1])
//            {
//                ++cnt1;
//            }
//            else
//            {
//                while (i)
//            }
//        }

    }



    // 2,3,4,4,4
    // 2 3 3 3 4
    int minLengthAfterRemovals___(vector<int>& nums)
    {
        int lo = 0;
        int hi = 1;

        while (hi < nums.size())
        {
            if (nums[lo] < nums[hi])
            {
                nums[lo] = nums[hi] = -1;
                while (lo < nums.size() && nums[lo] == -1)
                {
                    ++lo;
                }
            }
            hi = max(lo + 1, hi + 1);
        }
        int ans = 0;
        for (int i : nums)
            ans += i != -1;

        return ans;
    }

};

int main()
{

    LT2856 lt;


    return 0;
}
