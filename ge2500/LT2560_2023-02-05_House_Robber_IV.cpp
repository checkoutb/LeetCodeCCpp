
#include "../header/myheader.h"

class LT2560
{
public:

    // D D

    //int lo = 0, hi = 1e9;
    //while (lo < hi) {
    //    int mid = (lo + hi) / 2, cnt = 0, prev = INT_MIN;
    //    for (int i = 0; i < nums.size(); ++i)
    //        if (nums[i] <= mid && prev + 1 < i) {
    //            ++cnt;
    //            prev = i;
    //        }
    //    if (cnt < k) lo = mid + 1;
    //    else hi = mid;
    //}
    //return lo;


    // lee215:
    //When use binary search,
    //I suggest you using my template
    //
    //while (left < right) {
    //    int mid = (left + right) / 2;
    //    if (condition)
    //        right = mid;
    //    else
    //        left = mid + 1;
    //}
    //return left;



    //Runtime163 ms
    //    Beats
    //    100 %
    //    Memory57.1 MB
    //    Beats
    //    66.67 %
    int lt2560a(vector<int>& nums, int k)
    {
        int sz1 = nums.size();

        int st = 1;
        int en = *max_element(begin(nums), end(nums));
        int ans = -1;
        while (st <= en)
        {
            int md = (st + en) / 2;
            int cnt = 0;
            int lst = -5;

            for (int i = 0; i < sz1 && cnt < k; ++i)
            {
                if (nums[i] <= md)
                {
                    if (lst + 1 < i)
                    {
                        ++cnt;
                        lst = i;
                    }
                }
            }

            if (cnt >= k)
            {
                ans = md;
                en = md - 1;
            }
            else
            {
                st = md + 1;
            }
        }
        return ans;
    }

};

int main()
{

    LT2560 lt;

    //myvi v = { 2,3,5,9 };
    //int k = 2;

    myvi v = { 2,7,9,3,1 };
    int k = 2;

    cout << lt.lt2560a(v, k) << endl;

    return 0;
}
