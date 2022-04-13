
#include "../../header/myheader.h"

class LT
{
public:

// D D


//        int low=0,high=nums.size()-1;
//        while(low<=high)
//        {
//            while(low<high && nums[low]==nums[low+1])
//                low++;
//            while(low<high && nums[high]==nums[high-1])
//                high--;
//            int mid=(low+high)/2;
//            if(nums[mid]==target)
//                return true;
//            else if(nums[low]<=nums[mid])
//            {
//                if(target<=nums[mid] && target>=nums[low])
//                    high=mid-1;
//                else
//                    low=mid+1;


//        while(s<=e){
//            m=s+(e-s)/2;
//            if(nums[m]==target)
//                return 1;
//            if(nums[m]==nums[s] && nums[m]==nums[e]){
//                s++;
//                e--;
//            }
//            else if(nums[m]>=nums[s]){
//                if(nums[m]>target && nums[s]<=target)
//                    e=m-1;
//                else
//                    s=m+1;
//



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



//Runtime: 8 ms, faster than 60.28% of C++ online submissions for Search in Rotated Sorted Array II.
//Memory Usage: 14 MB, less than 71.85% of C++ online submissions for Search in Rotated Sorted Array II.
// 2 2 2 2 2 2 1 2 2
    bool lta(vector<int>& nums, int target)
    {
//        int l = 0, r = nums.size();
//        while (l < r)
//        {
//
//        }
        return bsa1(nums, 0, nums.size() - 1, target);
    }

    // [st, en]
    bool bsa1(vector<int>& nums, int st, int en, int tar)
    {
        if (st > en)
            return false;
        int mid = (st + en) / 2;
        if (nums[mid] == tar)
            return true;
        else if (nums[mid] < tar)       // 1 1 1 1 1 1 2 1 , tar=2 ,  1 2 1 1 1 1 1 1
        {
            if (nums[en] >= tar)        // [mid] < tar <= [en]
            {
                return bsa1(nums, mid + 1, en, tar);
            }
            else        // [mid] < tar && [en] < tar
            {
                return bsa1(nums, st, mid - 1, tar) || bsa1(nums, mid + 1, en, tar);
//                if (nums[st] < tar)        // st <= tar, mid < tar, en < tar
//                {
//                    return bsa1(nums, st, mid - 1, tar);
//                }
            }
        }
        else    // mid > tar
        {
            if (nums[st] <= tar)
            {
                return bsa1(nums, st, mid - 1, tar);
            }
            else
                return bsa1(nums, st, mid - 1, tar) || bsa1(nums, mid + 1, en, tar);
        }
    }

};

int main()
{

    LT lt;

    myvi v = {2,5,6,0,0,1,2};
    int tar = 3;

    cout<<lt.lta(v, tar)<<endl;

    return 0;
}
