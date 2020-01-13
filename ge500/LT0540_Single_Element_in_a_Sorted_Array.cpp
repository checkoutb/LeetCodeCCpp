
#include "../header/myheader.h"

class LT0540
{
public:



// 全部 ^

// nums[i] != nums[i^1]

//        if (nums[mid] == nums[mid ^ 1])
//            lo = mid + 1;
//        else
//            hi = mid;


//            int mid = (start + end) / 2;
//            if (mid % 2 == 1) mid--;


//        int n=nums.length, lo=0, hi=n/2;
//        while (lo < hi) {
//            int m = (lo + hi) / 2;
//            if (nums[2*m]!=nums[2*m+1]) hi = m;
//            else lo = m+1;
//        }
//        return nums[2*lo];



//Runtime: 12 ms, faster than 59.58% of C++ online submissions for Single Element in a Sorted Array.
//Memory Usage: 9.6 MB, less than 21.43% of C++ online submissions for Single Element in a Sorted Array.


// sort + forEach
// sort + quickSeach, 有序的情况下，查看中间2个数字就能知道 single 是出现在哪侧了。
// 已经有序了。。。logn
    int lt0540a(vector<int>& nums)
    {
        int ans = -1;
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            int mid = (i + j) / 2;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            {
                ans = nums[mid];
                break;
            }
            if (nums[mid] != nums[mid - 1])
            {
                if ((j - i) / 2 % 2 != 0)
                    j = mid - 1;
                else
                    i = mid + 2;
            }
            else
            {
                if ((j - i) / 2 % 2 != 0)
                    i = mid + 1;
                else
                    j = mid - 2;
            }
        }
        if (ans == -1)
            ans = nums[i];

        return ans;
    }
};

int main()
{
    vector<int> v = {3,3,7,  7  ,10,11,11};
//    vector<int> v = {1,1,2,3,  3  ,4,4,8,8};

//    vector<int> v = {1,1, 2 ,2,3};

    LT0540 lt;

    cout<<lt.lt0540a(v)<<endl;

    return 0;
}
