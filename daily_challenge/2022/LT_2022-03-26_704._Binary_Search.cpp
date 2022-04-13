
#include "../../header/myheader.h"

class LT
{
public:

// D D

//https://leetcode.com/problems/binary-search/discuss/423162/Binary-Search-101

//        while (left <= right) {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] == target) return mid;
//            if (nums[mid] > target) right = mid - 1;
//            else left = mid + 1;
//        }


//        while (start < end) {
//            int mid = start + (end - start) / 2;
//            if (nums[mid] < target) start = mid + 1;
//            else    end = mid;
//        }


//        while (start + 1 < end) {
//            int mid = start + (end - start) / 2;
//            if (nums[mid] < target) start = mid;
//            else    end = mid;
//        }
//        if (nums[start] == target)  return start;
//        if (nums[end] == target)    return end;


//Runtime: 32 ms, faster than 95.57% of C++ online submissions for Binary Search.
//Memory Usage: 27.4 MB, less than 92.40% of C++ online submissions for Binary Search.
    int lta(vector<int>& nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            int t2 = nums[mid];
            if (t2 >= target)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return nums[l] == target ? l : -1;
    }

};

int main()
{

    LT lt;

    myvi v = {-1,0,3,5,9,12};
//    int t = 9;
    int t = 2;

    cout<<lt.lta(v, t)<<endl;

    return 0;
}
