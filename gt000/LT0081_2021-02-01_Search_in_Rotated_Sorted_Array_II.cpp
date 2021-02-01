
#include "../header/myheader.h"

class LT0081
{
public:

// D

//            //If we know for sure right side is sorted or left side is unsorted
//            if (nums[mid] < nums[end] || nums[mid] < nums[start]) {
//                if (target > nums[mid] && target <= nums[end]) {
//                    start = mid + 1;
//                } else {
//                    end = mid - 1;
//                }
//            //If we know for sure left side is sorted or right side is unsorted
//            } else if (nums[mid] > nums[start] || nums[mid] > nums[end]) {
//                if (target < nums[mid] && target >= nums[start]) {
//                    ....
//            else { end--; }




// error
    bool lt0081a(vector<int>& nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            int mid = (l + r + 1) / 2;
            int val = nums[mid];
            #ifdef __test
            cout<<l<<", "<<mid<<", "<<r<<", "<<val<<" - "<<val<<endl;
//            getchar();
            #endif // __test
            if (target == val)
                return true;
            if (val > target)
            {
                if (nums[r] > target)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
            {
                if (nums[r] > target)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        #ifdef __test
        cout<<r<<endl;
        #endif // __test
        return nums[r] == target;
    }

};

int main()
{
//    myvi v = {2,5,6,0,0,1,2};
//    int tar = 0;
//    int tar = 3;

    myvi v = {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
    int tar = 2;

    LT0081 lt;

    cout<<lt.lt0081a(v, tar)<<endl;

    return 0;
}
