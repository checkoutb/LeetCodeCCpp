
#include "../header/myheader.h"

class LT0581
{
public:

// D D
//    int n = A.length, beg = -1, end = -2, min = A[n-1], max = A[0];
//    for (int i=1;i<n;i++) {
//      max = Math.max(max, A[i]);
//      min = Math.min(min, A[n-1-i]);
//      if (A[i] < max) end = i;
//      if (A[n-1-i] > min) beg = n-1-i;
//    }
//    return end - beg + 1;
// 2步合一了， 找到 从end之后的所有元素 都大于 max(end之前的元素)。
//        beg之前的所有元素 都小于 min(beg之后的元素)。


//Runtime: 80 ms, faster than 62.56% of C++ online submissions for Shortest Unsorted Continuous Subarray.
//Memory Usage: 27.7 MB, less than 13.51% of C++ online submissions for Shortest Unsorted Continuous Subarray.
// sort, first difference.
    int lt0581a(vector<int>& nums)
    {
        vector<int> cp(begin(nums), end(nums));
        std::sort(begin(nums), end(nums));
        int st{0}, en{(int) nums.size() - 1};
        for (; st < nums.size(); st++)
        {
            if (nums[st] != cp[st])
            {
                break;
            }
        }
        for (; en >= 0; en--)
        {
            if (nums[en] != cp[en])
            {
                break;
            }
        }

        return max(0, en - st + 1);
    }

};

int main()
{
    vector<int> v = {2, 6, 4, 8, 10, 9, 15};

    LT0581 lt;

    cout<<lt.lt0581a(v)<<endl;

    return 0;
}
