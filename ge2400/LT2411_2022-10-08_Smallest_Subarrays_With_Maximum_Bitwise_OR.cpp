
#include "../header/myheader.h"

class LT2411
{
public:

    // D D

    //for (int j = 0; j < 30; ++j) {
    //    if (A[i] & (1 << j))
    //        last[j] = i;
    //    res[i] = max(res[i], last[j] - i + 1);
    //}





//Runtime: 186 ms, faster than 95.75 % of C++ online submissions for Smallest Subarrays With Maximum Bitwise OR.
//Memory Usage : 55.8 MB, less than 95.03 % of C++ online submissions for Smallest Subarrays With Maximum Bitwise OR.
    vector<int> lt2411a(vector<int>& nums)
    {
        int sz1 = nums.size();

        int arr[32] = { 0 };
        vector<int> vi(sz1);
        memset(arr, -1, sizeof(arr));
        int t2 = 0;
        int mx = 0;
        for (int i = sz1 - 1; i >= 0; --i)
        {
            t2 = nums[i];
            mx = -1;
            for (int j = 0; j < 32; ++j)
            {
                if ((t2 & (1 << j)) != 0)
                {
                    arr[j] = i;
                    //t2 ^= (1 << j);
                }
                if (arr[j] > mx)
                    mx = arr[j];
            }
            if (mx == -1)           // ...    5,6,4,0,0
                vi[i] = 1;
            else
                vi[i] = mx - i + 1;
        }
        return vi;
    }

};

int main()
{

    LT2411 lt;

    myvi vi = { 1,0,2,1,3 };

    myvi v2 = lt.lt2411a(vi);

    showVectorInt(v2);

    return 0;
}
