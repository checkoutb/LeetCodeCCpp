
#include "../../header/myheader.h"

class LT
{
public:

// D D

// 快慢指针，成环


//    while (low <= high) {
//        int mid = (int) (low + (high - low) * 0.5);
//        int cnt = 0;
//        for (int a : nums) {
//            if (a <= mid) ++cnt;
//        }
// 二分



// 好像可以： accumulate - (1+n)*n/2
// 1,2,3...n + x    1,2,5,6,7...n + x+x+x
// 1,2,3..n+x - n(n+1)/2 = x
// 1,2,5,6..n + x*3 - n*(n+1)/2 = -3,-4 + x*3
    int ltb(vector<int>& nums)
    {

    }



// tle...
// sort
// map / arr[10^5]      // nums 就可以作为 arr
// for for
    int lta(vector<int>& nums)
    {
        int sz1 = nums.size();
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = i + 1; j < sz1; ++j)
                if (nums[i] == nums[j])
                    return nums[i];
        }
        return -1;
    }

};

int main()
{

    LT lt;


    return 0;
}
