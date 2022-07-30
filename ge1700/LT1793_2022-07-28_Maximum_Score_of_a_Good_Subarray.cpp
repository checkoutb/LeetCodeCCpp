
#include "../header/myheader.h"

class LT1793
{
public:

    // D D

    //int res = A[k], mini = A[k], i = k, j = k, n = A.size();
    //while (i > 0 or j < n - 1) {
    //    if ((i > 0 ? A[i - 1] : 0) < (j < n - 1 ? A[j + 1] : 0))
    //        mini = min(mini, A[++j]);
    //    else
    //        mini = min(mini, A[--i]);
    //    res = max(res, mini * (j - i + 1));
    //}




//Runtime: 394 ms, faster than 37.33 % of C++ online submissions for Maximum Score of a Good Subarray.
//Memory Usage : 89.6 MB, less than 73.73 % of C++ online submissions for Maximum Score of a Good Subarray.
    // hint 1 & 2 ...
    int lt1793a(vector<int>& nums, int k)
    {
        int lft = k;
        int rgh = k;
        int ans = nums[k];
        int sz1 = nums.size();
        int a = nums[k];
        while (lft != 0 || rgh != sz1 - 1)
        {
            a = min(a, max(lft == 0 ? -1 : nums[lft - 1], (rgh == sz1 - 1 ? -1 : nums[rgh + 1])));
            while (lft > 0 && nums[lft - 1] >= a)
                lft--;
            while (rgh < sz1 - 1 && nums[rgh + 1] >= a)
                rgh++;

#ifdef __test
            cout << lft << " - " << rgh << ", " << a << endl;
#endif

            ans = max(ans, a * (rgh - lft + 1));
        }
        return ans;
    }

};

int main()
{

    LT1793 lt;

    //myvi v = { 1,4,3,7,4,5 };
    //int k = 3;

    myvi v = { 5,5,4,5,4,1,1,1,1,1 };
    int k = 0;

    cout << lt.lt1793a(v, k) << endl;

    return 0;
}
