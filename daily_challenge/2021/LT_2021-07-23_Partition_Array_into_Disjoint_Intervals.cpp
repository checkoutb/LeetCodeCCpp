
#include "../../header/myheader.h"

class LT
{
public:

// D D

//        int maxLeft = nums[0];
//        int maxRight = 0;
//
//        for (int i = 1; i < nums.size(); i++)
//        {
//            maxRight = max(nums[i], maxRight);
//            if (nums[i] < maxLeft)
//            {
//                maxLeft = max(maxRight, maxLeft);
//                firstPartitionEndIndex = i;
//                maxRight = 0;
//            }
//        }


//        int localMax = a[0], partitionIdx = 0, max = localMax;
//        for (int i = 1; i < a.length; i++)
//            if (localMax > a[i]) {
//                localMax = max;
//                partitionIdx = i;
//            } else max = Math.max(max, a[i]);
//        return partitionIdx + 1;
// localMax 保存 左侧(部分)最大， 如果 在localMax 大于 某个数， 说明 左侧 并不全是小于 右侧的
//                                    更新左侧最大值 为 到这个数的 最大值。



// AC
    int lta(vector<int>& nums)
    {
        int sz1 = nums.size();
        vector<int> vi(sz1, 0);
        vi[0] = nums[0];
        for (int i = 1; i < sz1; ++i)
        {
            vi[i] = max(vi[i - 1], nums[i]);
        }
        int ans = 0;
        int mn = nums[sz1 - 1];
        for (int i = sz1 - 1; i > 0; --i)
        {
            mn = min(mn, nums[i]);
            if (mn >= vi[i - 1])
            {
                ans = i;
            }
        }
        return ans;
    }

};

int main()
{
//    myvi v = {5,0,3,8,6};
    myvi v = {1,1,1,0,6,12};

    LT lt;

    cout<<lt.lta(v)<<endl;

    return 0;
}
