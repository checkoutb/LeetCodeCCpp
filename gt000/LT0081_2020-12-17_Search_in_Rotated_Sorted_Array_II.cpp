
#include "../header/myheader.h"

class LT0081
{
public:


// D

//            // the only difference from the first one, trickly case, just updat left and right
//            if( (nums[left] == nums[mid]) && (nums[right] == nums[mid]) ) {++left; --right;}
//
//            else if(nums[left] <= nums[mid])
//            {
//                if( (nums[left]<=target) && (nums[mid] > target) ) right = mid-1;
//                else left = mid + 1;
//            }
//            else
//            {
//                if((nums[mid] < target) &&  (nums[right] >= target) ) left = mid+1;
//                else right = mid-1;
//            }

// error
// zhen de nan...
// 竟然没有 brute-force (tle.)
//03/03/2018 17:03	Wrong Answer	N/A	N/A	java
//03/03/2018 16:57	Wrong Answer	N/A	N/A	java
//03/03/2018 16:47	Wrong Answer	N/A	N/A	java
//03/03/2018 16:45	Wrong Answer	N/A	N/A	java
//03/03/2018 16:31	Wrong Answer	N/A	N/A	java
//03/03/2018 16:18	Wrong Answer	N/A	N/A	java
//03/03/2018 16:15	Runtime Error	N/A	N/A	java
    bool lt0081a(vector<int>& nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            if (nums[mid] > target)     // mid > tar
            {
                if (nums[l] > target)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid;
                }
            }
            else            // mid < tar
            {
//                if (nums[l] >= nums[r])
//                {
                    if (nums[l] > target)
                    {
                        l = mid + 1;
                    }
                    else
                    {
                        r = mid;
                    }
//                }
//                else
//                {
//                    if (nums[r] > target)
//                    {
//                        l = mid + 1;
//                    }
//                    else
//                    {
//                        r = mid;
//                    }
//                }
            }
        }
        return false;
    }

};

int main()
{

    myvi v = {5,6,0,0,1,2};
    int t{2};

    LT0081 lt;

    cout<<lt.lt0081a(v, t);

    return 0;
}
