
#include "../header/myheader.h"

class LT0334
{
public:


//Runtime: 16 ms, faster than 13.07% of C++ online submissions for Increasing Triplet Subsequence.
//Memory Usage: 9.1 MB, less than 98.24% of C++ online submissions for Increasing Triplet Subsequence.

// 。。。。确实，遍历保存，至今为止的第一小，第二小，如果自己比第一小和第二小都大，那么就说明满足。。。。。
// 。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。好简单。。。。。。。。。。。
//        int n1=INT_MAX,n2=INT_MAX;
//        for(auto i:nums)
//        {
//            if(i<=n1)n1=i;
//            else if(i<=n2)n2=i;
//            else return 1;
//        }

    // O(n)...怎么弄。。。从后往前找Max？剔除没有>它的，再反序遍历找Max？不对的。3.2.5.4。。不，对的。
    // AddressSanitizer: heap-buffer-overflow leetcode上 {5,4,3,2,1} 报这个错。。
    // 满足了时间O(n),但没有满足空间O(1)..不过空间O(1)，也简单。nums[i] = -1;....或者INT_MIN。。。而不是用bool[]。来判断是否已经被剔除。
    bool lt0334a(vector<int>& nums)
    {
        int sz1 = nums.size();
        if (sz1 < 3)
            return false;
        bool arr[sz1] = {};
        int max1 = nums[sz1 - 1];
        for (int i = sz1 - 2; i >= 0; i--)
        {
            if (nums[i] >= max1)
            {
                max1 = nums[i];
            }
            else
            {
                arr[i] = true;
            }
        }
        int i = sz1 - 1;
        for (; i >=0; i--)
        {
            if (arr[i])
                break;
        }
        if (i < 0)
            return false;
        max1 = nums[i];         // 。。。。AddressSanitizer: heap-buffer-overflow,,这里 i 可能是 -1.
        for (i--; i >= 0; i--)
        {
            if (!arr[i])
                continue;
            if (nums[i] >= max1)
            {
                max1 = nums[i];
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    LT0334 lt;
//    vector<int> v = {1,2,3,4,5};
//    vector<int> v = {5,4,3,2,1};
//    vector<int> v = {2,3,1,5,4};

    vector<int> v = {2,1,5,0,3};

    cout<<endl<<endl<<lt.lt0334a(v)<<endl;
    return 0;
}
