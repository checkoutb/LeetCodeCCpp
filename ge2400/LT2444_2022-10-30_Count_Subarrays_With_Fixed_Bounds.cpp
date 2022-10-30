
#include "../header/myheader.h"

class LT2444
{
public:

    // D D

    //long res = 0, jbad = -1, jmin = -1, jmax = -1, n = A.size();
    //for (int i = 0; i < n; ++i) {
    //    if (A[i] < minK || A[i] > maxK) jbad = i;
    //    if (A[i] == minK) jmin = i;
    //    if (A[i] == maxK) jmax = i;
    //    res += max(0L, min(jmin, jmax) - jbad);
    //}
    //return res;


    //long long res = 0, n = nums.size();
    //for (int i = 0, j = 0; i <= n; ++i)
    //    if (i == n || nums[i] < minK || nums[i] > maxK)
    //        for (int p1 = j, p2 = j; j <= i; ++j) {
    //            while (p1 < i && (p1 < j || nums[p1] != minK))
    //                ++p1;
    //            while (p2 < i && (p2 < j || nums[p2] != maxK))
    //                ++p2;
    //            res += i - max(p1, p2);
    //        }
    //return res;


//Runtime: 118 ms, faster than 95.19 % of C++ online submissions for Count Subarrays With Fixed Bounds.
//Memory Usage : 70.7 MB, less than 26.06 % of C++ online submissions for Count Subarrays With Fixed Bounds.
    // 
    long long lt2444a(vector<int>& nums, int minK, int maxK)
    {
        nums.push_back(minK - 1);
        int sz1 = nums.size();

        long long ans = 0LL;

        if (minK == maxK)
        {
            int cnt = 0;
            for (int i = 0; i < sz1; ++i)
            {
                if (nums[i] == minK)
                    cnt++;
                else
                {
                    ans += 1LL * cnt * (cnt + 1) / 2;
                    cnt = 0;
                }
            }
            return ans;
        }

        vector<int> vmn;
        vector<int> vmx;

        int lmt = -1;

        for (int i = 0; i < sz1; ++i)
        {
            if (nums[i] > maxK || nums[i] < minK)
            {
                if (vmn.empty() || vmx.empty())
                {
                    ;
                }
                else
                {
                    int mni = 0;
                    int mxi = 0;

                    while (mni < vmn.size() && mxi < vmx.size())
                    {
                        if (vmn[mni] > vmx[mxi])
                        {
                            //int t2 = mxi == 0 ? (vmx[mxi] - lmt) : (vmx[mxi] - vmx[mxi - 1]);
                            int t2 = vmx[mxi] - lmt;
                            int t3 = i - vmn[mni];
                            ans += 1LL * t2 * t3;
                            lmt = vmx[mxi];
                            ++mxi;
                        }
                        else
                        {
                            //int t2 = mni == 0 ? (vmn[mni] - lmt) : (vmn[mni] - vmn[mni - 1]);
                            int t2 = vmn[mni] - lmt;
                            int t3 = i - vmx[mxi];
                            ans += 1LL * t2 * t3;
                            lmt = vmn[mni];
                            ++mni;
                        }
                    }

                }
                lmt = i;
                vmn.clear();
                vmx.clear();
            }
            else
            {
                if (nums[i] == maxK)
                    vmx.push_back(i);
                if (nums[i] == minK)
                    vmn.push_back(i);
            }
        }
        return ans;
    }

};

int main()
{

    LT2444 lt;

    //myvi v = { 1,3,5,2,8,5 };
    //int mnk = 1;
    //int mxk = 5;

    //myvi v = { 1,1,1,1 };
    //int mnk = 1;
    //int mxk = 1;


    // 81
    myvi v = { 35054, 398719, 945315, 945315, 820417, 945315, 35054, 945315, 171832, 945315, 35054, 109750, 790964, 441974, 552913 };
    int mnk = 35054;
    int mxk = 945315;


    cout << lt.lt2444a(v, mnk, mxk) << endl;

    return 0;
}
