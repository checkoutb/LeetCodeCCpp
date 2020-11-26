
#include "../header/myheader.h"

class LT1493
{
public:

// D D


//        int i = 0, j, k = 1;
//        for (j = 0; j < A.size(); ++j) {
//            if (A[j] == 0) k--;
//            if (k < 0 && A[i++] == 0) k++;
//        }
//        return j - i - 1;
// 窗口滑动， 还有之前的  只大不小， 就是不用while，而是if。


//    int max_sz = 0;
//    for (int i = 0, j = 0, skip = 0; i < nums.size(); ++i) {
//        skip += nums[i] == 0;
//        if (skip > 1)
//            skip -= nums[j++] == 0;
//        max_sz = max(max_sz, i - j + 1);
//    }
//    return max_sz - 1;


//Runtime: 104 ms, faster than 11.38% of C++ online submissions for Longest Subarray of 1's After Deleting One Element.
//Memory Usage: 36.8 MB, less than 84.04% of C++ online submissions for Longest Subarray of 1's After Deleting One Element.
    int lt1493a(vector<int>& nums)
    {
        int llst0 = -1;
        int lst0 = -1;
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                ans = max(ans, i - llst0 - 2);
//                cout<<ans<<", "<<i<<", "<<llst0<<" , "<<lst0<<endl;
                llst0 = lst0;
                lst0 = i;
            }
        }
//        cout<<ans<<endl;
        ans = max(ans, int (nums.size()) - llst0 - 2);
        return ans;
    }

};

int main()
{

//    myvi v = {1,1,0,1};
//    myvi v = {0,1,1,1,0,1,1,0,1};
//    myvi v = {1,1,1};
//    myvi v = {0,0,0};
    myvi v = {1,1,0,0,1,1,1,0,1};

    LT1493 lt;

    cout<<lt.lt1493a(v)<<endl;

    return 0;
}
