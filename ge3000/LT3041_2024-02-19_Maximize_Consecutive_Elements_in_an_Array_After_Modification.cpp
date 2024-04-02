
#include "../header/myheader.h"

class LT3041
{
public:

// D D

//         sort(nums.begin(),nums.end());
//         unordered_map<int,int> m;
//
//         int ans=0;
//
//         for(auto x:nums)
//         {
//             m[x + 1] = max(m[x + 1], m[x] + 1);
//             ans = max(ans, m[x+1]);
//             m[x] = max(m[x], m[x - 1] + 1);
//             ans = max(ans, m[x]);
//         }


        // for (int& a : A) {
        //     res = max(res, dp[a + 1] = dp[a] + 1);
        //     res = max(res, dp[a] = dp[a - 1] + 1);
        // }



        // for (int& a : A) {
        //     if (a == pre) {
        //         c2 = c1 + 1;
        //     } else if (a == pre + 1) {
        //         c1++;
        //         c2++;
        //     } else if (a == pre + 2) {
        //         c1 = c2 + 1;
        //         c2 = 1;
        //     } else {
        //         c1 = c2 = 1;
        //     }
        //     res = max(res, max(c1, c2));
        //     pre = a;
        // }


// the gap is so big.   !!!




// Runtime
// 116ms
// Beats100.00%of users with C++
// Memory
// 79.86MB
// Beats100.00%of users with C++




    // gap is 1
    int maxSelectedElements(vector<int>& nums)
    {
        std::sort(std::begin(nums), std::end(nums));
        int sz1 = nums.size();
        std::vector<int> pfx(sz1, 0), sfx(sz1, 0);
        pfx[0] = 1;
        int cnt = 0;
        int fix_idx = -1;
        bool fixed = false;
        for (int i = 1; i < sz1; ++i)
        {
            if (nums[i] == nums[i - 1])
            {
                pfx[i] = pfx[i - 1];
                cnt = 1;
                fixed = false;
                fix_idx = -1;
            }
            else if (nums[i] == nums[i - 1] + 1)
            {
                pfx[i] = pfx[i - 1] + 1;
            }
            else if (
                //(!fixed || i - 1 == fix_idx) &&
                nums[i] == nums[i - 1] + 2)
            {
                pfx[i] = pfx[i - 1] + 1 + cnt;
                // if (i - 1 == fix_idx)           // [1,3,5]  3 is fixed by 1
                // {
                //     pfx[i] = 2;
                // }

                if (fixed)
                {
                    pfx[i] = pfx[i - 1] + 1 + cnt - pfx[fix_idx] + 1;
                }

                cnt = 0;
                fix_idx = i;
                fixed = true;       // .
            }
            else
            {
                pfx[i - 1] += cnt;
                pfx[i] = 1;
                cnt = 0;
                fixed = false;
            }
        }
        if (!fixed)
            pfx[sz1 - 1] += cnt;

#ifdef __test
        showVectorInt(nums);
        showVectorInt(pfx);
#endif

        int ans = *max_element(begin(pfx), end(pfx));
        return ans;

        // sfx[sz1 - 1] = 1;
        // for (int i = sz1 - 2; i >= 0; --i)
        // {
        //     if (nums[i] == nums[i + 1])
        //     {
        //         cnt = 1;
        //         sfx[i] = sfx[i + 1];
        //     }
        //     else if (nums[i] == nums[i + 1] - 1)
        //         sfx[i] = sfx[i + 1] + 1;
        //     else
        //     {
        //         sfx[i + 1] += cnt;
        //         sfx[i] = 1;
        //         cnt = 0;
        //     }
        //
        // }
/*
#ifdef __test
        showVectorInt(nums);
        showVectorInt(pfx);
        showVectorInt(sfx);
#endif


        int ans = 0;
        for (int i = 0; i < sz1; )
        {
            // int i2 = i;
            cnt = 0;
            // while (i + 1 < sz1 && pfx[i + 1] >= pfx[i])
            // {
            //     ++i;
            //     if (pfx[i + 1] == pfx[i])
            //         cnt = 1;
            // }
            while (i + 1 < sz1 && (nums[i + 1] <= nums[i] + 1 + cnt))
            {
                if (nums[i] == nums[i + 1])
                    cnt = 1;
                ++i;
            }
            cnt = 0;

#ifdef __test
            cout<<i<<" -- "<<ans<<endl;
#endif
            if (i + 1 == sz1)
            {
                ans = max(ans, pfx[i] + cnt);
                break;
            }

            // cnt = 0;
            // if (i > 0 && nums[i] == nums[i - 1])
            //     cnt = 1;

            // cnt =

            ++i;

            ans = max(ans, pfx[i - 1] + cnt + ((nums[i] == nums[i - 1] + 2) ? sfx[i] : 0));

#ifdef __test
            cout<<" -- "<<ans<<", "<<pfx[i - 1]<<", "<<cnt<<", "<<sfx[i]<<endl;
#endif

            // cnt = 0;
            // while (i + 1 < sz1 && nums[i] == nums[i + 1])
            // {
            //     ++i;
            //     ++cnt;
            // }
            // if (i + 1 == sz1)
            // {
            //     ans = max(ans, pfx[i]);
            //     break;
            // }
            // ++i;

        }

        return ans;*/

//         std::sort(std::begin(nums), std::end(nums));
//         int idxgap = -1;
//         int ans = 0;
//         int len1 = 0;    // prev
//         int len2 = 1;    // now   [0]
//         for (int i = 1; i < nums.size(); ++i)
//         {
//             if (nums[i] > nums[i - 1] + 2)
//             {
//                 ans = std::max();
//                 len1 = 0;
//                 len2 = 1;       // [i]
//                 idxgap = -1;
//             }
//             else if (nums[i] == nums[i - 1] + 2)
//             {
//
//             }
//             else if (nums[i] == nums[i - 1] + 1)
//             {
//                 ++len2;
//             }
//             else
//             {
//                 // [i] == [i - 1]
//                 ;
//             }
//         }
//         return ans;
    }

};

int main()
{

    LT3041 lt;

    // myvi v {1,1,1,2,5};
    // myvi v {1,4,5,7,11};
    // myvi v {8,10,6,12,9,12,2,3,13,19,11,18,10,16};      // 8    // [7,14] .. 6-7,  12,13 -> 13,14
                                        // sfx
    // myvi v {8,13,18,10,16,19,11,17,15,18,9,12,15,8,9,14,7};     // 14
    // myvi v = {4,20,16,2,15,14};
    // myvi v = {12,13};
    // myvi v {4,12,8,14,14,12,11,20,17,17,4,10,10,18,1,16};       // 12
    // myvi v {9,8,8,5,15,9,12,5,1,3,7,18,10};     // 9
    // myvi v {13,1,10,11,15,12,7,17,20,16,19,4,12};       // 8
    myvi v {7,9,20,4,10,19,13,15,12,12,15,14};      // 7

    cout<<lt.maxSelectedElements(v)<<endl;

    return 0;
}
