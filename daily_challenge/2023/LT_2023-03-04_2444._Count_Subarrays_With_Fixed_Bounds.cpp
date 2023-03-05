
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //for (int i = 0, j = 0, p = -1, q = -1, curMax = INT_MIN, curMin = INT_MAX; i < nums.size(); ++i) {
    //    curMax = max(curMax, nums[i]);
    //    curMin = min(curMin, nums[i]);
    //    if (curMax > maxK || curMin < minK) {
    //        curMax = INT_MIN, curMin = INT_MAX;
    //        p = q = j = i + 1;
    //    }
    //    else {
    //        p = nums[i] == maxK ? i : p;
    //        q = nums[i] == minK ? i : q;
    //        if (curMax == maxK && curMin == minK)
    //            res += min(p, q) - j + 1;
    //    }
    //}


    //long res = 0, jbad = -1, jmin = -1, jmax = -1, n = A.size();
    //for (int i = 0; i < n; ++i) {
    //    if (A[i] < minK || A[i] > maxK) jbad = i;
    //    if (A[i] == minK) jmin = i;
    //    if (A[i] == maxK) jmax = i;
    //    res += max(0L, min(jmin, jmax) - jbad);
    //}



    // 2022-10-30 accepted， 但是还是 好费力。 本次和上次的 不同。。

    //Runtime133 ms
    //    Beats
    //    39.18 %
    //    Memory73.5 MB
    //    Beats
    //    20.41 %
    long long lta(vector<int>& nums, int minK, int maxK)
    {
        int sz1 = nums.size();
        vector<int> vi(sz1);
        int t2 = sz1;
        for (int i = sz1 - 1; i >= 0; --i)
        {
            if (nums[i] < minK || nums[i] > maxK)
            {
                t2 = i;
            }
            else if (nums[i] == minK || nums[i] == maxK)
            {
                vi[i] = t2 - i;
            }
        }

        long long ans = 0LL;
        int lstmn = -1;
        int lstmx = -1;
        t2 = -1;
        for (int i = 0; i < sz1; ++i)
        {
            if (nums[i] < minK || nums[i] > maxK)
            {
                lstmn = lstmx = t2 = i;
                //continue;
            }
            else if (nums[i] == minK && nums[i] == maxK)
            {
                ans += vi[i];
            }
            else if (nums[i] == minK)
            {
                if (lstmx > t2 && lstmx > lstmn)
                {
                    ans += 1LL * (lstmx - lstmn) * vi[i];
                }
                lstmn = i;
            }
            else if (nums[i] == maxK)
            {
                if (lstmn > t2 && lstmn > lstmx)
                {
                    ans += 1LL * (lstmn - lstmx) * vi[i];
                }
                lstmx = i;
            }


            //if (nums[i] < minK || nums[i] > maxK)
            //{
            //    lstmn = lstmx = i;
            //}
            //else if (nums[i] == minK)
            //{
            //    // (lstmn/mx, vi[i])
            //    if (nums[lstmx] == maxK)
            //    {
            //        ans += 1LL * (lstmx - lstmn) * (vi[i] - i);
            //    }
            //    lstmn = i;
            //}
            //else if (nums[i] == maxK)
            //{
            //    if (nums[lstmn] == minK)
            //    {
            //        ans += 1LL * (lstmn - lstmx) * (vi[i] - i);
            //    }
            //    lstmx = i;
            //}
        }

        return ans;
    }

};

int main()
{

    LT lt;

    //myvi v = { 1,3,5,2,7,5 };
    //int mn = 1, mx = 5;

    myvi v = { 1,1,1,1 };
    int mn = 1, mx = 1;

    cout << lt.lta(v, mn, mx) << endl;

    return 0;
}
