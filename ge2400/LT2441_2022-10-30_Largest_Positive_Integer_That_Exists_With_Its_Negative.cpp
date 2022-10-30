
#include "../header/myheader.h"

class LT2441
{
public:

    // D D

    //int arr[2001] = {}, res = -1;
    //for (int n : nums) {
    //    if (arr[-n + 1000])
    //        res = max(res, abs(n));
    //    ++arr[n + 1000];
    //}


    //sort(nums.begin(), nums.end());
    //int low = 0, high = nums.size() - 1;

    //while (low < high)
    //{
    //    if ((nums[low] + nums[high]) == 0)
    //    {
    //        return  nums[high];
    //    }

    //    else if ((nums[low] + nums[high]) < 0)
    //        low++;

    //    else high--;
    //}



//Runtime: 22 ms, faster than 98.15 % of C++ online submissions for Largest Positive Integer That Exists With Its Negative.
//Memory Usage : 19.6 MB, less than 95.27 % of C++ online submissions for Largest Positive Integer That Exists With Its Negative.
    int lt2441a(vector<int>& nums)
    {
        int arr[1001] = { 0 };

        for (int i : nums)
        {
            if (i > 0)
            {
                arr[i] |= 1;
            }
            else
            {
                arr[-i] |= 2;
            }
        }

        for (int i = 1000; i > 0; --i)
        {
            if (arr[i] == 3)
                return i;
        }
        return -1;
    }

};

int main()
{

    LT2441 lt;

    myvi v = { 1,2,-3,3 };

    cout << lt.lt2441a(v) << endl;

    return 0;
}
